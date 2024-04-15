// PluginTBFF.hpp
// M. Josiah Sytsma (sytsma.music@icloud.com)

#include "TBFF.h"
#include "SC_PlugIn.h"
#include "SC_PlugIn.hpp"

static InterfaceTable* ft;

TBFF::TBFF() {
    reset();
    
    m_Freq = in0(FREQ_IN);
    m_Res = in0(RQ_IN);
    
    set_calc_function<TBFF, &TBFF::next>();
}

void TBFF::reset() {
    oversample.reset(sampleRate());
    z0 = z1 = z2 = z3 = 0.f;
}

void TBFF::next(int inNumSamples) {
    //input
    const float* xn = in(SIG_IN);
    SlopeSignal<float> slopedFreq = makeSlope(in0(FREQ_IN), m_Freq);
    SlopeSignal<float> slopedRes = makeSlope(in0(RQ_IN), m_Res);
    
    const float freq = slopedFreq.consume();
    const float res = slopedRes.consume();
    
    //output
    float* outBuf = out(0);
    
    for (int i = 0; i < inNumSamples; i++) {
        oversample.upsample(xn[i]);
        
        for (int j = 0; j < 2; j++) {
            oversample.osBuffer[j] = processSample(oversample.osBuffer[j], freq, res);
        }
        
        float outSample = oversample.downsample();
        
        outBuf[i] = outSample;
    }
    
    m_Freq = slopedFreq.value;
    m_Res = slopedRes.value;
}

float TBFF::processSample(const float inSample, const float freq, const float res){
    float y0, y1, y2, y3, y4;
    
    const float k = (1.f - sc_clip(res, 0.0, 1.0)) * 20.f;
    const float a = 1.f + 0.5 * k;
    
    float wc = M_PI * freq * sampleDur();
    
    const float wc2 = wc * wc;
    const float wc3 = wc2 * wc;
    const float wc4 = wc3 * wc;
    
    const float b = 1 / zapgremlins(1 + 8*wc + 20*wc2 + 16*wc3 + 2*wc4);
    const float g = 2 * wc4 * b;
    
    //calculate filter state
    const float s = (z0*wc3 + z1*(wc2 + 2*wc3) + z2*(wc + 4*wc2 + 2*wc3) + z3*(1 + 6*wc + 9*wc2 + 2*wc3)) * b;
    
    //solve feedback
    y4 = (g * inSample + s) / (1 + g * k);
    
    y0 = inSample - k * y4;
    //saturate output
//    y0 = tanh(y0);
    y0 = sc_clip2(y0, 3.f);
    y0 *= (27 + y0 * y0) / (27 + 9 * y0 * y0 );
    
    y1 = (y0 * (2*wc + 12*wc2 + 20*wc + 8*wc4) + z0*(1 + 6*wc + 10*wc2 + 4*wc3) + z1*(2*wc + 8*wc2 + 6*wc3) + z2*(2*wc2 + 4*wc3) + z3 * 2 * wc3) * b;
    y2 = (y0*(2*wc2 + 8*wc3 + 6*wc4) + z0*(wc + 4*wc + 3*wc3) + z1*(1 + 6*wc + 11*wc + 6*wc3) + z2*(wc + 4*wc2 + 4*wc3) + z3*(wc2 + 2*wc3)) * b;
    y3 = (y0*(2*wc3 + 4*wc4) + z0*(wc2 + 2*wc3) + z1*(wc + 4*wc2 + 4*wc3) + z2*(1 + 6*wc + 10*wc2 + 4*wc3) + z3*(wc + 4*wc2 + 2*wc3)) * b;
    y4 = g * y0 + s;
    
    //update filter states
    z0 += 4 * wc * (y0 - y1 + y2);
    z1 += 2 * wc * (y1 - 2 * y2 + y3);
    z2 += 2 * wc * (y2 - 2 * y3 + y4);
    z3 += 2 * wc * (y3 - 2 * y4);
    
    //output
    return y4 * a;
};

PluginLoad(TBFFUGens) {
    ft = inTable;
    registerUnit<TBFF>(ft, "TBFF", false);
}

// M. Josiah Sytsma (sytsma.music@icloud.com)

#include "TBFF.h"
#include "SC_PlugIn.hpp"

TBFF::TBFF() {
    reset();
    
    oversample.reset(sampleRate());
    osBuf = oversample.getOSBuffer();
    
    mHpFreq = 5.f;
    calcHpCoeffs(mHpFreq);
    
    mCalcFunc = make_calc_function<TBFF, &TBFF::next>();
    
    mPrevFreq = prewarpFc(in0(FREQ_IN));
    mPrevQ = in0(RES_IN);
    
    next(1);
}

void TBFF::calcHpCoeffs(float freq) {
    const float fs = sampleRate();
    const float fc = freq / (fs * 0.5);
    const float K = fc * M_PI;
    ah = (K - 2) / (K + 2);
    bh = 2 / (K + 2);
}

void TBFF::reset() {
    z0 = z1 = z2 = z3 = z4 = 0.f;
}

float TBFF::prewarpFc(const float x) {
    const float fs = sampleRate();
    const float nyquist = fs / 2.0;
    float clampedFreq = std::clamp(x, 5.0f, std::min(20000.0f, nyquist));
    const float normalizedFreq = clampedFreq / nyquist;
    const float t = 1 / fs;
    const float omega = 2.f * M_PI * normalizedFreq; // omega in radians
    const float y = (2.0 / t) * FastMath::tan(omega * t * 0.5);
    return y;
}

float TBFF::processSample(const float x, float freq, float q) {
    const float a = freq;
    const float ainv = 1 / zapgremlins(a);
    const float a2 = a * a;
    const float b = 2 * a + 1;
    const float b2 = b * b;
    const float c = 1 / zapgremlins(2 * a2 * a2 - 4 * a2 * b2 + b2 * b2);
    const float g0 = 2 * a2 * a2 * c;
    const float g = g0 * bh;
    
    //set filter resonance and gain compensation
    q = std::clamp(q, 0.f, 1.f);
    k = 20 * q;
    A = 1 + 0.5 * k;
    
    // Current state
    const float s0 = (a2 * a * z0 + a2 * b * z1 + z2 * (b2 - 2 * a2) * a + z3 * (b2 - 3 * a2) * b) * c;
    const float s = bh * s0 - z4;
    
    // Solve feedback loop
    float y5 = (g * x + s) / zapgremlins(1 + g * k);
    
    // Saturate input
    const float y0 = FastMath::tanh(x - k * y5);
    y5 = g * y0 + s;
    
    // Compute integrator outputs
    const float y4 = g0 * y0 + s0;
    const float y3 = (b * y4 - z3) * ainv;
    const float y2 = (b * y3 - a * y4 - z2) * ainv;
    const float y1 = (b * y2 - a * y3 - z1) * ainv;
    
    // Update filter state
    z0 += 4 * a * (y0 - y1 + y2);
    z1 += 2 * a * (y1 - 2 * y2 + y3);
    z2 += 2 * a * (y2 - 2 * y3 + y4);
    z3 += 2 * a * (y3 - 2 * y4);
    z4 = bh * y4 + ah * y5;
    
    return A * y4; // Return the filtered output
}

void TBFF::next(int nSamples) {
    const float *inBuf = in(SIG_IN);
    float *outBuf = out(0);
    const float fcParam = std::clamp(in0(FREQ_IN), 20.f, 18000.f);
    const float qParam = in0(RES_IN);
    
    SlopeSignal<float> slopedFreq = makeSlope(prewarpFc(fcParam), mPrevFreq);
    
    SlopeSignal<float> slopedQ = makeSlope(qParam, mPrevQ);
    
    for (int i = 0; i < nSamples; i++) {
        float sample = inBuf[i];
        float freq = slopedFreq.consume();
        float q = slopedQ.consume();
        
        oversample.upsample(sample);
        
        for(int j = 0; j < 2; j++) {
            osBuf[j] = processSample(osBuf[j], freq, q);
        }
        
        float y = oversample.downsample();
        outBuf[i] = sc_distort(y);
    }
    
    mPrevFreq = slopedFreq.value;
    mPrevQ = slopedQ.value;
}

#pragma once

#include "SC_PlugIn.hpp"
#include "Oversampling.h"
#include "MathApprox.h"

class TBFF : public SCUnit {
private:
    enum Inputs { SIG_IN, FREQ_IN, RES_IN, NUM_INS };
    
    float k, A;
    
    //integrators and feedback hpf
    float z0, z1, z2, z3, z4;
    
    float mPrevFreq, mPrevQ;
    float mHpFreq;
    
    //hpf coefficients
    float ah, bh;
    
    float* osBuf;
    
    void reset();
    void calcHpCoeffs(float freq);
    float prewarpFc(float x);
    void next(int nSamples);
    float processSample(const float x, float freq, float q);
public:
    TBFF();
    Oversampling<2> oversample;
    ~TBFF(){}; //default
};

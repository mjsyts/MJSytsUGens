#include "SC_PlugIn.hpp"
#include "Oversampling.h"
#include "PadeApprox.h"

class TBFF : public SCUnit {
private:
    enum Inputs { SIG_IN, FREQ_IN, RQ_IN, NUM_INS };
    
    const float omega;
    
    float m_Freq, m_Res;
    
    //integrator states
    float z0, z1, z2, z3, z4;
    
    float* osBuffer;
    
    // Calc functions
    void next(int inNumSamples);
    
    //reset integrator states
    void reset();
    
    float processSample(const float& inSample, float freq, float res);
public:
    TBFF();
    Oversampling<2> oversample; //fixed 2x oversample
    ~TBFF(){}; //default
};

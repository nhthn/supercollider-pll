// PluginPLL.cpp
// Nathan Ho (nathan.waikin.ho@gmail.com)

#include "SC_PlugIn.hpp"
#include "SCPLL.hpp"

static InterfaceTable* ft;

namespace SCPLL {

SCPLL::SCPLL() {
    mCalcFunc = make_calc_function<SCPLL, &SCPLL::next>();
    mCore = std::make_unique<PLL>(mWorld->mSampleRate);
    next(1);
}

void SCPLL::next(int nSamples) {
    const float* inBuf = in(0);
    int intAlgorithm = in0(1);
    float k = in0(2);
    float centerFrequency = in0(3);
    float frequencyGain = in0(4);
    float* outBuf = out(0);

    PLL::PhaseDetectorAlgorithm algorithm;
    switch (intAlgorithm) {
    case 1:
        algorithm = PLL::PhaseDetectorAlgorithm::JKFlipFlop;
        break;
    case 2:
        algorithm = PLL::PhaseDetectorAlgorithm::PFD;
        break;
    default:
        algorithm = PLL::PhaseDetectorAlgorithm::Multiplier;
    }

    mCore->setPhaseDetectorAlgorithm(algorithm);
    mCore->setLPFK(k);
    mCore->setVCOCenterFrequency(centerFrequency);
    mCore->setVCOFrequencyGain(frequencyGain);

    for (int i = 0; i < nSamples; ++i) {
        outBuf[i] = mCore->process(inBuf[i]);
    }
}

} // namespace SCPLL

PluginLoad(PLLUGens) {
    ft = inTable;
    registerUnit<SCPLL::SCPLL>(ft, "PLL", false);
}

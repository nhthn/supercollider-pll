// PluginPLL.cpp
// Nathan Ho (nathan.waikin.ho@gmail.com)

#include "SC_PlugIn.hpp"
#include "PLL.hpp"

static InterfaceTable* ft;

namespace SCPLL {

PLL::PLL() {
    mCalcFunc = make_calc_function<PLL, &PLL::next>();
    next(1);
}

void PLL::next(int nSamples) {
    const float* input = in(0);
    const float* gain = in(1);
    float* outbuf = out(0);

    // simple gain function
    for (int i = 0; i < nSamples; ++i) {
        outbuf[i] = input[i] * gain[i];
    }
}

} // namespace SCPLL

PluginLoad(PLLUGens) {
    // Plugin magic
    ft = inTable;
    registerUnit<SCPLL::PLL>(ft, "PLL", false);
}

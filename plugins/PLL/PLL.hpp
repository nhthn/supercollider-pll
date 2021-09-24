// PluginPLL.hpp
// Nathan Ho (nathan.waikin.ho@gmail.com)

#pragma once

#include "SC_PlugIn.hpp"

namespace SCPLL {

class PLL : public SCUnit {
public:
    PLL();

    // Destructor
    // ~PLL();

private:
    // Calc function
    void next(int nSamples);

    // Member variables
};

} // namespace SCPLL

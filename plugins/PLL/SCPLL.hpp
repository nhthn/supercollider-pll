// PluginPLL.hpp
// Nathan Ho (nathan.waikin.ho@gmail.com)

#pragma once

#include <memory>
#include "SC_PlugIn.hpp"
#include "PLL.hpp"

namespace SCPLL {

class SCPLL : public SCUnit {
public:
    SCPLL();

private:
    void next(int nSamples);

    std::unique_ptr<PLL> mCore;
};

} // namespace SCPLL

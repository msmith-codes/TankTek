#pragma once

#include <string>

namespace TankTek
{
    class Toolbox
    {
        public:
            static bool ends_with(const std::string& value, const std::string& ending);
    };
}
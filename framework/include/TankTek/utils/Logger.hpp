#ifndef TT_Logger_HPP
#define TT_Logger_HPP

#include <string>
#include <iostream>

namespace TankTek
{
    class Logger
    {
        public:
            static void info(const std::string& message);
            static void warn(const std::string& message);
            static void error(const std::string& message);
    };
}

#endif
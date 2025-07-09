#pragma once

#include <string>

namespace TankTek
{
    class Logger
    {
        public:
            static void info(const std::string& message);
            static void warn(const std::string& message);
            static void error(const std::string& message);
        private:
            static void log(const std::string& level, const std::string& message);
            static std::string get_current_time();

    };
}
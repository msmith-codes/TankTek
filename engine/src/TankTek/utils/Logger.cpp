#include <TankTek/utils/Logger.hpp>

#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <thread>

namespace TankTek 
{
    void Logger::info(const std::string& message) 
    {
        Logger::log("INFO", message);
    }

    void Logger::warn(const std::string &message)
    {
        Logger::log("WARN", message);
    }

    void Logger::error(const std::string &message)
    {
        Logger::log("ERROR", message);
    }

    void Logger::log(const std::string& level, const std::string& message)
    {
        std::cout << "[" << level << "]" << " " << "[Thread " << std::this_thread::get_id() << "]" << " " << Logger::get_current_time() << " : " << message << std::endl;
    }

    std::string Logger::get_current_time()
    {
        std::time_t now = std::time(nullptr);
        std::tm* local_time = std::localtime(&now);

        std::ostringstream oss;
        oss << "[" << std::put_time(local_time, "%H:%M:%S") << "]";
        return oss.str();
    }
}
#include <TankTek/utils/Time.hpp>

#include <GLFW/glfw3.h>

namespace TankTek
{
    float Time::getTime()
    {
        return glfwGetTime();
    }
}
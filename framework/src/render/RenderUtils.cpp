#include <TankTek/render/RenderUtils.hpp>

#include <glad/glad.h>

namespace TankTek
{
    void RenderUtils::setClearColor(float r, float g, float b)
    {
        RenderUtils::setClearColor(r, g, b, 1.0f);
    }

    void RenderUtils::setClearColor(float r, float g, float b, float a)
    {
        glClearColor(r, g, b, a);
    }

    void RenderUtils::clearScreen()
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }
}
#include <TankTek/core/Application.hpp>
#include <TankTek/core/Window.hpp>
#include <TankTek/core/GameLoop.hpp>
#include <TankTek/render/RenderUtils.hpp>

namespace TankTek
{
    Application::Application()
    {

    }

    Application::~Application()
    {
    }

    void Application::run()
    {
        if(!TankTek::Window::init()) {
            return;
        }

        this->onReady();

        TankTek::GameLoop::run();
    }
};
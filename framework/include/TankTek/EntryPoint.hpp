#ifndef TT_EntryPoint_HPP
#define TT_EntryPoint_HPP

#include "TankTek/core/Application.hpp"

extern TankTek::Application* TankTek::createApplication();

int main(int argc, char** argv)
{
    auto app = TankTek::createApplication();
    app->run();
    delete app;
    return 0;
}

#endif
#include <TankTek/core/GameLoop.hpp>
#include <TankTek/core/Window.hpp>
#include <TankTek/core/Scene.hpp>
#include <TankTek/utils/Time.hpp>
#include <TankTek/render/RenderUtils.hpp>


namespace TankTek
{
    // -- Singleton -- //
    GameLoop& GameLoop::getInstance()
    {
        static GameLoop instance;
        return instance;
    }

    // -- Constructor -- //
    GameLoop::GameLoop()
    {
        
    }

    // -- Destructor -- //
    GameLoop::~GameLoop()
    {
        
    }

    // -- Static Methods -- //
    void GameLoop::run()
    {
        GameLoop& instance = GameLoop::getInstance();

        if(instance.scene) {
            instance.scene->ready();
        }

        float lastTime = Time::getTime();

        while(!TankTek::Window::shouldClose()) {
            // Calculate delta time
            float currentTime = Time::getTime();
            float deltaTime = currentTime - lastTime;
            lastTime = currentTime;

            TankTek::Window::pollEvents();
            if(instance.scene) {
                instance.scene->update(deltaTime);
            }

            TankTek::RenderUtils::clearScreen();
            if(instance.scene) {
                instance.scene->render();
            }

            TankTek::Window::swapBuffers();
        }
    }

    void GameLoop::setDefaultScene(std::unique_ptr<Scene> scene)
    {
        GameLoop& instance = GameLoop::getInstance();
        instance.scene = std::move(scene);
    }

    void GameLoop::setScene(std::unique_ptr<Scene> scene)
    {
        GameLoop& instance = GameLoop::getInstance();
        instance.scene = std::move(scene);
        instance.scene->ready();
    }
};
#include "TankTek/core/Application.hpp"
#include "TankTek/input/MouseListener.hpp"
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
        delete this->scene;
        this->scene = nullptr;
    }

    // -- Static Methods -- //
    void GameLoop::run(Application* app)
    {
        GameLoop& instance = GameLoop::getInstance();
            
        instance.app = app;

        instance.app->ready();

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

            instance.app->update(deltaTime);

            TankTek::RenderUtils::clearScreen();
            if(instance.scene) {
                instance.scene->render();
            }

            TankTek::Window::swapBuffers();
            TankTek::MouseListener::endFrame();
        }
    }

    void GameLoop::setDefaultScene(Scene* scene)
    {
        GameLoop& instance = GameLoop::getInstance();
        instance.scene = scene;
    }

    void GameLoop::setScene(Scene* scene)
    {
        GameLoop& instance = GameLoop::getInstance();
        instance.scene = scene;
        instance.scene->ready();
    }
};

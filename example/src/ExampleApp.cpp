#include "TankTek/input/KeyListener.hpp"
#include "TankTek/input/MouseListener.hpp"
#include "TankTek/math/Math.hpp"
#include "TankTek/utils/Logger.hpp"
#include <TankTek.hpp>
#include <TankTek/EntryPoint.hpp>

#include <Example/HelloQuadScene.hpp>
#include <string>

class ExampleApp : public TankTek::Application
{
    public:
        ExampleApp() 
        {
            // Configure the window
            TankTek::Window::setTitle("Example Application");
            TankTek::Window::setSize(800, 600);
            TankTek::Window::setResizable(false);
            TankTek::Window::setVSync(true);
        }

        ~ExampleApp()
        {

        }
        
    protected:
        void loadAssets() override
        {

        }

        void registerVoxels() override
        {
            
        }

        void onReady() override
        {
            TankTek::RenderUtils::setClearColor(0.1f, 0.1f, 0.1f);
            TankTek::GameLoop::setDefaultScene(new HelloQuadScene());
        }

        void onUpdate(float dt) override
        {
            if(TankTek::MouseListener::isJustPressed(TankTek::MouseButton::LEFT)) {
                TankTek::Vec2f pos = TankTek::Vec2f(TankTek::MouseListener::getX(), TankTek::MouseListener::getY());
                std::string str = std::to_string(pos.x) + ", " + std::to_string(pos.y);
                TankTek::Logger::info("Left click pressed: (" + str + ")");
            }

            if(TankTek::KeyListener::isJustPressed(32)) {
                TankTek::Logger::info("Space pressed!");
            }
        }
};

TankTek::Application* TankTek::createApplication()
{
    return new ExampleApp();
}

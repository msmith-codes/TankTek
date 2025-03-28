#include <TankTek.hpp>
#include <TankTek/EntryPoint.hpp>

#include <Example/HelloQuadScene.hpp>

class ExampleApp : public TankTek::Application
{
    public:
        ExampleApp() 
        {
            // Configure the window
            TankTek::Window::setTitle("Example Application");
            TankTek::Window::setSize(1280, 720);
            TankTek::Window::setResizable(false);
            TankTek::Window::setVSync(true);
        }

        ~ExampleApp()
        {

        }
        
    protected:
        void onReady() override
        {
            TankTek::RenderUtils::setClearColor(0.1f, 0.1f, 0.1f);
            TankTek::GameLoop::setDefaultScene(std::make_unique<HelloQuadScene>());
        }
};

TankTek::Application* TankTek::createApplication()
{
    return new ExampleApp();
}
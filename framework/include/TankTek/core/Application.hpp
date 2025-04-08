#ifndef TT_Application_HPP
#define TT_Application_HPP

namespace TankTek
{
    class Application
    {
        public:
            Application();
            virtual ~Application();
        public:
            void run();
        public:
            void ready();
            void update(float dt);
        protected:
            virtual void onReady() = 0;
            virtual void onUpdate(float dt) = 0;
    };

    // Defined in client.
    Application* createApplication();
}

#endif

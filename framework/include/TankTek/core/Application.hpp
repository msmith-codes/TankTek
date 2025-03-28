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
        protected:
            virtual void onReady() = 0;
    };

    // Defined in client.
    Application* createApplication();
}

#endif
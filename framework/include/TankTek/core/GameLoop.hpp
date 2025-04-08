#ifndef TT_GameLoop_HPP
#define TT_GameLoop_HPP

#include "TankTek/core/Application.hpp"
#include <TankTek/core/Scene.hpp>

namespace TankTek
{
    class GameLoop
    {
        public: // -- Singleton -- //
            static GameLoop& getInstance();
        private: // -- Field Variables -- //
        private: // -- Utility Variables -- //
            Scene* scene;
            Application* app;
        private: // -- Constructor -- //
            GameLoop(); 
        public: // -- Destructor -- //
            ~GameLoop();
        public: // -- Static Methods -- //
            static void run(Application* app);
            static void setDefaultScene(Scene* scene);
            static void setScene(Scene* scene);
    };
};

#endif

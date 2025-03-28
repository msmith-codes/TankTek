#ifndef TT_GameLoop_HPP
#define TT_GameLoop_HPP

#include <TankTek/core/Scene.hpp>

#include <memory>

namespace TankTek
{
    class GameLoop
    {
        public: // -- Singleton -- //
            static GameLoop& getInstance();
        private: // -- Field Variables -- //
        private: // -- Utility Variables -- //
            std::unique_ptr<Scene> scene;
        private: // -- Constructor -- //
            GameLoop(); 
        public: // -- Destructor -- //
            ~GameLoop();
        public: // -- Static Methods -- //
            static void run();
            static void setDefaultScene(std::unique_ptr<Scene> scene);
            static void setScene(std::unique_ptr<Scene> scene);
    };
};

#endif
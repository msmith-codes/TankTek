#ifndef TT_KeyListener_HPP
#define TT_KeyListener_HPP

#include <array>

class GLFWwindow;

namespace TankTek
{
    class KeyListener
    {
        public: // -- Singleton -- //
            static KeyListener& getInstance();
        private: // --  Field Variables -- // 
            std::array<bool, 350> keyPressed;
        private: // -- Constructor -- //
            KeyListener();
        public: // -- Destructor -- //
            ~KeyListener();
        public: // -- Static Callbacks -- //
            static void keyCallback(GLFWwindow* windowPtr, int key, int scancode, int action, int mods);
        public: // -- Static Utilities -- // 
            static bool isPressed(int key);
            static bool isJustPressed(int key);

    };
}

#endif

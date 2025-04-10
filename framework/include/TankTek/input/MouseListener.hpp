#ifndef TT_MouseListener_HPP
#define TT_MouseListener_HPP

#include <array>

class GLFWwindow;

namespace TankTek 
{
    enum class MouseButton
    {
        LEFT = 0,
        RIGHT = 1,
        MIDDLE = 2,
    };

    class MouseListener
    {
        public: // -- Singleton -- //
            static MouseListener& getInstance();
        private: // -- Field Variables -- //
            double scrollX;
            double scrollY;
            double xPos;
            double yPos;
            double lastX;
            double lastY;
            std::array<bool, 3> mouseButtonPressed;
            bool dragging;
        private: // -- Constructor -- //
            MouseListener();
        public: // -- Destructor -- //
            ~MouseListener();
        public: // -- Static Callbacks -- //
            static void mousePosCallback(GLFWwindow* windowPtr, double xPos, double yPos);
            static void mouseButtonCallback(GLFWwindow* windowPtr, int button, int action, int mods);
            static void mouseScrollCallback(GLFWwindow* windowPtr, double xOffset, double yOffset);
        public: // -- Static Utilities -- //
            static void endFrame();
            static bool isPressed(MouseButton button);
            static bool isJustPressed(MouseButton button);
        public: // -- Static Getters -- //
            static float getX();
            static float getY();
            static float getDx();
            static float getDy();
            static float getScrollX();
            static float getScrollY();
            static bool isDragging();
    };
}

#endif

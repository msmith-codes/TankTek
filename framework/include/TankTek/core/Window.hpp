#ifndef TT_Window_HPP
#define TT_Window_HPP

#include <string>

struct GLFWwindow;

namespace TankTek
{
    class Window
    {
        public: // -- Singleton -- //
            static Window& getInstance();
        private: // -- Field Variables -- //
            unsigned int width;
            unsigned int height;
            std::string title;
            bool resizable;
            bool maximized;
            bool vsync;
        private: // -- Utility Variables -- //
            GLFWwindow* windowPtr;
        private: // -- Constructor -- //
            Window();
        public: // -- Destructor -- //
            ~Window();
        public: // -- Static Methods -- //
            static bool init();
            static bool shouldClose();
            static void pollEvents();
            static void swapBuffers();
        public: // -- Static Setters -- //
            static void setSize(unsigned int width, unsigned int height);
            static void setTitle(const std::string& title);
            static void setResizable(bool resizable);
            static void setMaximized(bool maximized);
            static void setVSync(bool vsync);
        public: // -- Static Getters -- //
            static unsigned int getWidth();
            static unsigned int getHeight();
            static const std::string& getTitle();
            static bool isResizable();
            static bool isMaximized();
            static bool isVSync();

    };
}

#endif
#include <TankTek/core/Window.hpp>
#include <TankTek/core/Application.hpp>
#include <TankTek/utils/Logger.hpp>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace TankTek
{
    // -- Singleton -- //
    Window& Window::getInstance()
    {
        static Window instance;
        return instance;
    }

    // -- Constructor -- //
    Window::Window()
    {
        // Default Field Variables
        this->width = 800;
        this->height = 600;
        this->title = "TankTek";
        this->resizable = false;
        this->maximized = false;
        this->vsync = true;
        
        // Default Utility Variables
        this->windowPtr = nullptr;
    }

    // -- Destructor -- //
    Window::~Window()
    {
        glfwDestroyWindow(this->windowPtr);
        glfwTerminate();
    }

    // -- Static Methods -- //
    bool Window::init()
    {
        Window& instance = Window::getInstance();
        if(!glfwInit()) {
            Logger::error("Failed to initialize GLFW.");
            return false;
        }

        glfwDefaultWindowHints();

        // Set the OpenGL version to 3.3
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        // Configure the window
        glfwWindowHint(GLFW_RESIZABLE, instance.resizable ? GLFW_TRUE : GLFW_FALSE);
        glfwWindowHint(GLFW_MAXIMIZED, instance.maximized ? GLFW_TRUE : GLFW_FALSE);
        glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
        glfwWindowHint(GLFW_FOCUSED, GLFW_TRUE);

        // Create the window
        instance.windowPtr = glfwCreateWindow(instance.width, instance.height, instance.title.c_str(), nullptr, nullptr);
        if(instance.windowPtr == nullptr) {
            Logger::error("Failed to create GLFW window.");
            glfwTerminate();
            return false;
        }

        // Position the window in the center of the screen
        GLFWmonitor* primaryMonitor = glfwGetPrimaryMonitor();
        if(primaryMonitor) {
            const GLFWvidmode* mode = glfwGetVideoMode(primaryMonitor);
            if(mode) {
                int xpos = (mode->width - instance.width) / 2;
                int ypos = (mode->height - instance.height) / 2;
                glfwSetWindowPos(instance.windowPtr, xpos, ypos);
            }
        }

        // Make the window's context current
        glfwMakeContextCurrent(instance.windowPtr);

        // Load OpenGL functions
        if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            Logger::error("Failed to initialize GLAD.");
            return false;
        }

        // Enable VSync
        glfwSwapInterval(instance.vsync ? 1 : 0);

        // Show the window
        glfwShowWindow(instance.windowPtr);

        return true;
    }

    bool Window::shouldClose()
    {
        Window& instance = Window::getInstance();
        if(instance.windowPtr == nullptr) {
            return true;
        }
        return glfwWindowShouldClose(instance.windowPtr);
    }

    void Window::pollEvents()
    {
        Window& instance = Window::getInstance();
        if(instance.windowPtr) {
            glfwPollEvents();
        }
    }

    void Window::swapBuffers()
    {
        Window& instance = Window::getInstance();
        if(instance.windowPtr) {
            glfwSwapBuffers(instance.windowPtr);
        }
    }

    // -- Static Setters -- //
    void Window::setSize(unsigned int width, unsigned int height)
    {
        Window& instance = Window::getInstance();
        instance.width = width;
        instance.height = height;

        if(instance.windowPtr) {
            glfwSetWindowSize(instance.windowPtr, width, height);
        }
    }

    void Window::setTitle(const std::string& title)
    {
        Window& instance = Window::getInstance();
        instance.title = title;

        if(instance.windowPtr) {
            glfwSetWindowTitle(instance.windowPtr, title.c_str());
        }
    }

    void Window::setResizable(bool resizable)
    {
        Window& instance = Window::getInstance();
        instance.resizable = resizable;

        if(instance.windowPtr) {
            glfwSetWindowAttrib(instance.windowPtr, GLFW_RESIZABLE, resizable ? GLFW_TRUE : GLFW_FALSE);
        }
    }

    void Window::setMaximized(bool maximized)
    {
        Window& instance = Window::getInstance();
        instance.maximized = maximized;

        if(instance.windowPtr) {
            glfwSetWindowAttrib(instance.windowPtr, GLFW_MAXIMIZED, maximized ? GLFW_TRUE : GLFW_FALSE);
        }
    }

    void Window::setVSync(bool vsync)
    {
        Window& instance = Window::getInstance();
        instance.vsync = vsync;

        if(instance.windowPtr) {
            glfwSwapInterval(vsync ? 1 : 0);
        }
    }

    // -- Static Getters -- //
    unsigned int Window::getWidth()
    {
        return Window::getInstance().width;
    }

    unsigned int Window::getHeight()
    {
        return Window::getInstance().height;
    }

    const std::string& Window::getTitle()
    {
        return Window::getInstance().title;
    }

    bool Window::isResizable()
    {
        return Window::getInstance().resizable;
    }

    bool Window::isMaximized()
    {
        return Window::getInstance().maximized;
    }

    bool Window::isVSync()
    {
        return Window::getInstance().vsync;
    }
}
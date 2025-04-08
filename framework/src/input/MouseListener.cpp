#include <TankTek/input/MouseListener.hpp>
#include <algorithm>
#include "GLFW/glfw3.h"

namespace TankTek 
{
    // -- Singleton -- //
    MouseListener& MouseListener::getInstance()
    {
        static MouseListener instance;
        return instance;
    }

    // -- Constructor -- //
    MouseListener::MouseListener()
    {
        this->scrollX = 0.0;
        this->scrollY = 0.0;
        this->xPos = 0.0;
        this->yPos = 0.0;
        this->lastX = 0.0;
        this->lastY = 0.0;
    }

    // -- Destructor -- //
    MouseListener::~MouseListener()
    {
        
    }

    // -- Static Callbacks -- //
    void MouseListener::mousePosCallback(GLFWwindow* windowPtr, double xPos, double yPos)
    {
        MouseListener& instance = MouseListener::getInstance();
        instance.lastX = instance.xPos;
        instance.lastY = instance.yPos;

        instance.xPos = xPos;
        instance.yPos = yPos;

        instance.dragging = std::any_of(instance.mouseButtonPressed.begin(), instance.mouseButtonPressed.end(), [](bool b) {
            return b;
        });
    }

    void MouseListener::mouseButtonCallback(GLFWwindow *windowPtr, int button, int action, int mods)
    {
        MouseListener& instance = MouseListener::getInstance();
        if(button < instance.mouseButtonPressed.size()) {
            if(action == GLFW_PRESS) {
                instance.mouseButtonPressed.at(button) = true;
            }
            else if(action == GLFW_RELEASE) {
                instance.mouseButtonPressed.at(button) = false;
                instance.dragging = false;
            }
        }
    }

    
    void MouseListener::mouseScrollCallback(GLFWwindow* windowPtr, double xOffset, double yOffset)
    {
        MouseListener& instance = MouseListener::getInstance();
        instance.scrollX = xOffset;
        instance.scrollY = yOffset;
    }

    // -- Static Utilities -- //    
    void MouseListener::endFrame()
    {
        MouseListener& instance = MouseListener::getInstance();
        instance.scrollX = 0.0;
        instance.scrollY = 0.0;

        instance.lastX = instance.xPos;
        instance.lastY = instance.yPos;
    }

    bool MouseListener::isButtonPressed(MouseButton button)
    {
        MouseListener& instance = MouseListener::getInstance();
        int btn = static_cast<int>(button);
        if(btn < instance.mouseButtonPressed.size()) {
            return instance.mouseButtonPressed.at(btn);
        }
        return false;
    }

    bool MouseListener::isButtonJustPressed(MouseButton button)
    {
        MouseListener& instance = MouseListener::getInstance();
        int btn = static_cast<int>(button);
        if(btn < instance.mouseButtonPressed.size()) {
            if(instance.mouseButtonPressed.at(btn)) {
                instance.mouseButtonPressed.at(btn) = false;
                return true;
            } else {
                return false;
            }
        }
        return false;
    }

    // -- Static Getters -- //
    float MouseListener::getX()
    {
        MouseListener& instance = MouseListener::getInstance();
        return (float)instance.xPos;
    }

    float MouseListener::getY()
    {
        MouseListener& instance = MouseListener::getInstance();
        return (float)instance.yPos;
    }

    float MouseListener::getDx()
    {
        MouseListener& instance =  MouseListener::getInstance();
        return (float)(instance.lastX - instance.xPos);
    }

    float MouseListener::getDy()
    {
        MouseListener& instance = MouseListener::getInstance();
        return (float)(instance.lastY - instance.yPos);
    }

    float MouseListener::getScrollX()
    {
        MouseListener& instance = MouseListener::getInstance();
        return (float)instance.scrollX;
    }

    float MouseListener::getScrollY()
    {
        MouseListener& instance = MouseListener::getInstance();
        return (float)instance.scrollY;
    }

    bool MouseListener::isDragging()
    {
        MouseListener& instance = MouseListener::getInstance();
        return instance.dragging;
    }


}

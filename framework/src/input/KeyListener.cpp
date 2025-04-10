#include <TankTek/input/KeyListener.hpp>
#include "GLFW/glfw3.h"

namespace TankTek 
{

    KeyListener& KeyListener::getInstance()
    {
        static KeyListener instance;
        return instance;
    }

    KeyListener::KeyListener()
    {

    }

    KeyListener::~KeyListener()
    {

    }

    void KeyListener::keyCallback(GLFWwindow *windowPtr, int key, int scancode, int action, int mods)
    {
        KeyListener& instance = KeyListener::getInstance();
        if(key < instance.keyPressed.size()) {
            if(action == GLFW_PRESS) {
                instance.keyPressed.at(key) = true;
            }
            else if(action == GLFW_RELEASE) {
                instance.keyPressed.at(key) = false;
            }
        }
    }

    bool KeyListener::isPressed(int key)
    {
        KeyListener& instance = KeyListener::getInstance();
        int code = static_cast<int>(key);
        if(code < instance.keyPressed.size()) {
            return instance.keyPressed.at(code); 
        }
        return false;
    }

    bool KeyListener::isJustPressed(int key)
    {
        KeyListener& instance = KeyListener::getInstance();
        int code = static_cast<int>(key);
        if(code < instance.keyPressed.size()) {
            if(instance.keyPressed.at(code)) {
                instance.keyPressed.at(code) = false;
                return true;
            } else {
                return false;
            }
        }
        return false;
    }
    
}

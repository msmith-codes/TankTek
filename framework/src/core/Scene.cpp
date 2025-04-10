#include <TankTek/core/Scene.hpp>

namespace TankTek
{
    Scene::Scene()
    {
        
    }

    Scene::~Scene()
    {

    }

    void Scene::ready()
    {
        this->onReady();
    }

    void Scene::update(float delta)
    {
        this->onUpdate(delta);
    }

    void Scene::render()
    {
        this->onRender();
    }
}

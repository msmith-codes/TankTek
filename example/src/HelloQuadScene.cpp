#include <Example/HelloQuadScene.hpp>

#include <vector>

HelloQuadScene::HelloQuadScene()
{
    
}

HelloQuadScene::~HelloQuadScene()
{
    delete this->quad;
    this->quad = nullptr;

    delete this->shader;
    this->shader = nullptr;

    delete this->camera;
    this->camera = nullptr;
}

void HelloQuadScene::onReady()
{
    std::vector<float> vertexArray = {
         0.5f, -0.5f, 0.0f,
        -0.5f,  0.5f, 0.0f,     
         0.5f,  0.5f, 0.0f,
        -0.5f, -0.5f, 0.0f,
    };

    std::vector<float> colorArray = {
        1.0f, 0.0f, 0.0f, 1.0f,
        0.0f, 1.0f, 0.0f, 1.0f,
        0.0f, 0.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 0.0f, 1.0f,
    };

    std::vector<unsigned int> indexArray = {
        2, 1, 0,
        0, 1, 3
    };

    this->z = 0.0f;
    this->camera = new TankTek::Camera3D(TankTek::Vec3f(0.0f, 0.0f, this->z));
    this->camera->setPerspective(TankTek::Math::toRadians(45.0f), (float)TankTek::Window::getWidth() / (float)TankTek::Window::getHeight(), 0.1f, 100.0f);

    this->quad = TankTek::ModelLoader::loadToVao(vertexArray, indexArray);
    this->quad->storeData(1, 4, colorArray);
    
    this->shader = new TankTek::ShaderProgram(ASSET_PATH "/shaders/default.glsl");
}

void HelloQuadScene::onUpdate(float delta)
{
    this->z += delta * 0.5f;
    if(this->z > 10.0f) {
        this->z = 0.0f;
    }
    this->camera->setPosition(TankTek::Vec3f(0.0f, 0.0f, this->z));
}

void HelloQuadScene::onRender()
{
    this->shader->bind();
        this->shader->setMat4f("uProjection", this->camera->getProjectionMatrix());
        this->shader->setMat4f("uView", this->camera->getViewMatrix());
        this->quad->render();
    this->shader->unbind();
}

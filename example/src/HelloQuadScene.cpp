#include <Example/HelloQuadScene.hpp>

#include <vector>

HelloQuadScene::HelloQuadScene()
{
    
}

HelloQuadScene::~HelloQuadScene()
{
    delete this->quad;
}

void HelloQuadScene::onReady()
{
    TankTek::RenderUtils::setClearColor(0.3f, 0.3f, 0.3f);

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

    this->quad = TankTek::ModelLoader::loadToVao(vertexArray, indexArray);
    this->quad->storeData(1, 4, colorArray);
    this->shader = new TankTek::ShaderProgram(ASSET_PATH "/shaders/default.tkshader");
}

void HelloQuadScene::onUpdate(float delta)
{
    
}

void HelloQuadScene::onRender()
{
    this->shader->bind();
        this->quad->render();
    this->shader->unbind();
}

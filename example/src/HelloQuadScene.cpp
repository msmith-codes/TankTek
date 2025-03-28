#include <Example/HelloQuadScene.hpp>

#include <vector>

HelloQuadScene::HelloQuadScene()
{
    
}

HelloQuadScene::~HelloQuadScene()
{
    delete this->triangle;
}

void HelloQuadScene::onReady()
{
    TankTek::RenderUtils::setClearColor(0.3f, 0.3f, 0.3f);

    std::vector<float> vertexArray = {
        // Positions            
         0.5f, -0.5f, 0.0f,
        -0.5f,  0.5f, 0.0f,     
         0.5f,  0.5f, 0.0f,
        -0.5f, -0.5f, 0.0f,
    };

    std::vector<unsigned int> indexArray = {
        2, 1, 0,
        0, 1, 3
    };

    this->triangle = TankTek::ModelLoader::loadToVao(vertexArray, indexArray);
    TankTek::Logger::info("Running Shader Program");
    this->shader = new TankTek::ShaderProgram(ASSET_PATH "/shaders/default.glsl");
}

void HelloQuadScene::onUpdate(float delta)
{

}

void HelloQuadScene::onRender()
{
    this->shader->bind();
    this->triangle->render();
    this->shader->unbind();
}
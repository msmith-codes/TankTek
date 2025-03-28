#include <TankTek/render/ModelLoader.hpp>

#include <glad/glad.h>

namespace TankTek
{

    ModelLoader& ModelLoader::getInstance()
    {
        static ModelLoader instance;
        return instance;
    }

    ModelLoader::ModelLoader()
    {
        this->vaos = std::vector<unsigned int>();
        this->vbos = std::vector<unsigned int>();   
    }

    ModelLoader::~ModelLoader()
    {
        for(unsigned int vao : this->vaos) {
            glDeleteVertexArrays(1, &vao);
        }

        for(unsigned int vbo : this->vbos) {
            glDeleteBuffers(1, &vbo);
        }
    }

    RawModel* ModelLoader::loadToVao(std::vector<float>& vertices, std::vector<unsigned int>& indices)
    {
        ModelLoader& instance = ModelLoader::getInstance();
        unsigned int vaoId = instance.createVao();
        instance.storeDataInAttributeList(0, 3, vertices);
        instance.bindIndicesBuffer(indices);
        instance.unbindVao();

        return new RawModel(vaoId, indices.size());
    }

    unsigned int ModelLoader::createVao()
    {
        unsigned int vaoId;
        glGenVertexArrays(1, &vaoId);   
        this->vaos.push_back(vaoId);

        glBindVertexArray(vaoId);
        return vaoId;
    }

    void ModelLoader::storeDataInAttributeList(int attributeNumber, int coordinateSize, std::vector<float>& data)
    {
        unsigned int vboId;
        glGenBuffers(1, &vboId);
        this->vbos.push_back(vboId);

        glBindBuffer(GL_ARRAY_BUFFER, vboId);
        glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(float), data.data(), GL_STATIC_DRAW);
        glVertexAttribPointer(attributeNumber, coordinateSize, GL_FLOAT, GL_FALSE, 0, 0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    void ModelLoader::bindIndicesBuffer(std::vector<unsigned int>& indices)
    {
        unsigned int vboId;
        glGenBuffers(1, &vboId);
        this->vbos.push_back(vboId);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vboId);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), indices.data(), GL_STATIC_DRAW);
    }

    void ModelLoader::unbindVao()
    {
        glBindVertexArray(0);
    }
}
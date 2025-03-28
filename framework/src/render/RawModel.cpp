#include <TankTek/render/RawModel.hpp>
#include <TankTek/utils/VaoUtils.hpp>

#include <glad/glad.h>
#include <vector>

namespace TankTek
{
    RawModel::RawModel(unsigned int vaoId, unsigned int vertexCount)
    {
        this->vaoId = vaoId;
        this->vertexCount = vertexCount;
        this->vbos = std::vector<unsigned int>();

        this->maxAttribs = 1;
    }

    RawModel::~RawModel()
    {
        for(unsigned int vbo : this->vbos) {
            glDeleteBuffers(1, &vbo);
        }
    }

    void RawModel::render()
    {
        VaoUtils::bind(this->vaoId);
        
        for(int i = 0; i <= this->maxAttribs; ++i) {
            VaoUtils::enableAttribute(i);
        }

        VaoUtils::drawElements(this->vertexCount);
        
        for(int i = 0; i <= this->maxAttribs; ++i) {
            VaoUtils::disableAttribute(i);
        }

        VaoUtils::unbind();
    }

    void RawModel::storeData(unsigned int attributeNumber, unsigned int coordinateSize, std::vector<float>& data)
    {
        VaoUtils::bind(this->vaoId);
        
        unsigned int vboId;
        glGenBuffers(1, &vboId);
        this->vbos.push_back(vboId);

        glBindBuffer(GL_ARRAY_BUFFER, vboId);
        glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(float), data.data(), GL_STATIC_DRAW);
        glVertexAttribPointer(attributeNumber, coordinateSize, GL_FLOAT, GL_FALSE, 0, 0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);

        VaoUtils::unbind();
        this->maxAttribs++;
    }

    unsigned int RawModel::getVaoId() const
    {
        return this->vaoId;
    }

    unsigned int RawModel::getVertexCount() const
    {
        return this->vertexCount;
    }
}

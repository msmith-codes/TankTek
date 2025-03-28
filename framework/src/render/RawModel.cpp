#include <TankTek/render/RawModel.hpp>
#include <TankTek/utils/VaoUtils.hpp>

#include <glad/glad.h>

namespace TankTek
{
    RawModel::RawModel(unsigned int vaoId, unsigned int vertexCount)
    {
        this->vaoId = vaoId;
        this->vertexCount = vertexCount;
    }

    void RawModel::render()
    {
        VaoUtils::bind(this->vaoId);
        
        VaoUtils::enableAttribute(0);

        VaoUtils::drawElements(this->vertexCount);
        
        VaoUtils::disableAttribute(0);
        
        VaoUtils::unbind();
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
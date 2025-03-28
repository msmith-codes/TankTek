#include <TankTek/utils/VaoUtils.hpp>

#include <glad/glad.h>

namespace TankTek
{
    void VaoUtils::bind(unsigned int vaoId)
    {
        glBindVertexArray(vaoId);
    }

    void VaoUtils::unbind()
    {
        glBindVertexArray(0);
    }

    void VaoUtils::enableAttribute(int attributeNumber)
    {
        glEnableVertexAttribArray(attributeNumber);
    }

    void VaoUtils::disableAttribute(int attributeNumber)
    {
        glDisableVertexAttribArray(attributeNumber);
    }

    void VaoUtils::drawElements(unsigned int vertexCount)
    {
        glDrawElements(GL_TRIANGLES, vertexCount, GL_UNSIGNED_INT, 0);
    }
}
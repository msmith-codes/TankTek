#ifndef TT_VaoUtils_HPP
#define TT_VaoUtils_HPP

namespace TankTek
{
    class VaoUtils
    {
        public:
            static void bind(unsigned int vaoId);
            static void unbind();
            static void enableAttribute(int attributeNumber);
            static void disableAttribute(int attributeNumber);
            static void drawElements(unsigned int vertexCount);
    };
}

#endif
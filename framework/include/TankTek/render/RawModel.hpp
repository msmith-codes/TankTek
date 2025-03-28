#ifndef TT_RawModel_HPP
#define TT_RawModel_HPP

namespace TankTek
{
    class RawModel
    {
        private:
            unsigned int vaoId;
            unsigned int vertexCount;
        public:
            RawModel(unsigned int vaoId, unsigned int vertexCount);
        public:
            void render();
        public:
            unsigned int getVaoId() const;
            unsigned int getVertexCount() const;
    };
}

#endif
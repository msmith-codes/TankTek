#ifndef TT_RawModel_HPP
#define TT_RawModel_HPP

#include <vector>

namespace TankTek
{
    class RawModel
    {
        private:
            unsigned int vaoId;
            unsigned int vertexCount;
            unsigned int maxAttribs;
            std::vector<unsigned int> vbos;
        public:
            RawModel(unsigned int vaoId, unsigned int vertexCount);
            ~RawModel();
        public:
            void render();
        public:
            void storeData(unsigned int attributeNumber, unsigned int coordinateSize, std::vector<float>& data);
        public:
            unsigned int getVaoId() const;
            unsigned int getVertexCount() const;
    };
}

#endif

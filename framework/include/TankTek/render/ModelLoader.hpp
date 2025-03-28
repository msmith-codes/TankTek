#ifndef TT_ModelLoader_HPP
#define TT_ModelLoader_HPP

#include <TankTek/render/RawModel.hpp>

#include <vector>

namespace TankTek
{
    class ModelLoader
    {
        public:
            static ModelLoader& getInstance();    
        private:
            std::vector<unsigned int> vaos;
            std::vector<unsigned int> vbos;
        private:
            ModelLoader();
            ~ModelLoader();
        public:
            static RawModel* loadToVao(std::vector<float>& vertices, std::vector<unsigned int>& indices);
        private:
            unsigned int createVao();
            void storeDataInAttributeList(int attributeNumber, int coordinateSize, std::vector<float>& data);
            void bindIndicesBuffer(std::vector<unsigned int>& indices);
            void unbindVao();
    };
}

#endif

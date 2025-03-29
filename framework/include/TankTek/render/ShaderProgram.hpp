#ifndef TT_ShaderProgram_HPP
#define TT_ShaderProgram_HPP

#include <string>
#include <TankTek/utils/ShaderSource.hpp>
#include <TankTek/math/Math.hpp>

namespace TankTek
{
    
    class ShaderProgram
    {
        private:
            unsigned int programId;
            unsigned int vertexId;
            unsigned int fragmentId;
        public:
            ShaderProgram(const std::string& path);
            virtual ~ShaderProgram();
        private:
            ShaderSource readShader(const std::string& path);
            unsigned int compileShader(unsigned int type, const std::string& source);
            unsigned int linkProgram(unsigned int vertexId, unsigned int fragmentId);
        public:
            void bind();
            void unbind();
        public:
            void setMat4f(const std::string& name, const Mat4x4f& matrix); 

    };
};

#endif

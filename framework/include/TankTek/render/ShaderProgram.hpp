#ifndef TT_ShaderProgram_HPP
#define TT_ShaderProgram_HPP

#include <string>

namespace TankTek
{
    struct ShaderSource
    {
        std::string vertex;
        std::string fragment;
    };

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

    };
};

#endif
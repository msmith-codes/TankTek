#include <TankTek/render/ShaderProgram.hpp>
#include <TankTek/utils/Logger.hpp>

#include <fstream>
#include <sstream>
#include <string>

#include <glad/glad.h>

namespace TankTek
{
    ShaderProgram::ShaderProgram(const std::string& path)
    {
        ShaderSource source = this->readShader(path);

        this->vertexId = this->compileShader(GL_VERTEX_SHADER, source.vertex);
        this->fragmentId = this->compileShader(GL_FRAGMENT_SHADER, source.fragment);

        this->programId = this->linkProgram(this->vertexId, this->fragmentId);
    }

    ShaderProgram::~ShaderProgram()
    {
        glDeleteShader(this->vertexId);
        glDeleteShader(this->fragmentId);
        glDeleteProgram(this->programId);
    }

    ShaderSource ShaderProgram::readShader(const std::string& path)
    {
        std::ifstream file(path);
        std::stringstream ss[2];
        std::string line;
        int type = -1;
        while(getline(file, line)) {
            if(line.find("#type") != std::string::npos) {
                if(line.find("vertex") != std::string::npos) {
                    type = 0;
                } else if(line.find("fragment") != std::string::npos) {
                    type = 1;
                }
            } else {
                ss[type] << line << '\n';
            }
        }

        ShaderSource source;
        source.vertex = ss[0].str();
        source.fragment = ss[1].str();

        return source;
    }

    unsigned int ShaderProgram::compileShader(unsigned int type, const std::string& source)
    {
        unsigned int id = glCreateShader(type);
        const char* src = source.c_str();
        glShaderSource(id, 1, &src, nullptr);
        glCompileShader(id);

        int result;
        glGetShaderiv(id, GL_COMPILE_STATUS, &result);
        if(result == GL_FALSE) {
            int length;
            glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
            char* message = (char*)alloca(length * sizeof(char));
            glGetShaderInfoLog(id, length, &length, message);
            Logger::error("Failed to compile shader!");
            Logger::error(message);
            glDeleteShader(id);
            return 0;
        }

        return id;
    }

    unsigned int ShaderProgram::linkProgram(unsigned int vertexId, unsigned int fragmentId)
    {
        unsigned int id = glCreateProgram();
        glAttachShader(id, vertexId);
        glAttachShader(id, fragmentId);
        glLinkProgram(id);
        glValidateProgram(id);

        int result;
        glGetProgramiv(id, GL_LINK_STATUS, &result);
        if(result == GL_FALSE) {
            int length;
            glGetProgramiv(id, GL_INFO_LOG_LENGTH, &length);
            char* message = (char*)alloca(length * sizeof(char));
            glGetProgramInfoLog(id, length, &length, message);
            Logger::error("Failed to link program!");
            Logger::error(message);
            glDeleteProgram(id);
            return 0;
        }

        return id;
    }

    void ShaderProgram::bind()
    {
        glUseProgram(this->programId);
    }

    void ShaderProgram::unbind()
    {
        glUseProgram(0);
    }
}
#include <TankTek/lang/tkshader/ShaderDSL.hpp>

#include <string>
#include <regex>
#include <utility>
#include <vector>
#include <map>

namespace TankTek
{
    std::string ShaderDLS::compileTkShader(const std::string& source)
    {
        std::string vertexSrc;
        std::string fragmentSrc;

        std::map<std::string, std::pair<std::string, std::string>> customFunctions;
        
        std::regex funcPattern("(\\w+)\\s+(\\w+)\\s*\\((.*?)\\)\\s*\\{([^}]*)\\}");
        std::regex mainFuncPattern("void\\s+(vertex|fragment)\\s*\\(\\)\\s*\\{([^}]*)\\}");

        std::smatch match;

        std::vector<std::string> vertexInputs;
        std::vector<std::string> vertexOutputs;
        std::vector<std::string> fragmentInputs;
        std::vector<std::string> fragmentOutputs;

        std::string tempShader = source;
        /*
        while(std::regex_search(tempShader, match, funcPattern)) {
            std::string returnType = match[1];
            std::string funcName = match[2];
            std::string funcParams = match[3];
            std::string funcBody = match[4];

            customFunctions[funcName] = { returnType, funcBody };

            tempShader = match.suffix();
        }
        */

        while(std::regex_search(tempShader, match, mainFuncPattern)) {
            std::string stage = match[1];
            std::string body = match[2];
                        
            if(stage == "vertex") {
                vertexSrc += "#type vertex\n";
                vertexSrc += "#version 330 core\n";

                vertexSrc += "layout (location=0) in vec3 VERTEX;\n";
                vertexSrc += "layout (location=1) in vec4 COLOR;\n";
                
                vertexSrc += "out vec4 fColor;\n";
                
                vertexSrc += "void main() \n";
                vertexSrc += "{\n";
                vertexSrc += body + "\n";
                vertexSrc += "}\n";
            } 
            else if(stage == "fragment") {
                fragmentSrc += "#type fragment\n";
                fragmentSrc += "#version 330 core\n";
                
                fragmentSrc += "in vec4 fColor;\n";
                fragmentSrc += "out vec4 COLOR;\n";
                

                fragmentSrc += "void main() \n";
                fragmentSrc += "{\n";
                fragmentSrc += body + "\n";
                fragmentSrc += "}\n";
            }

            tempShader = match.suffix();

        }
        
        std::string result = vertexSrc + "\n" + fragmentSrc;

        return result;
    }
}

#ifndef TT_ShaderDSL_HPP
#define TT_ShaderDSL_HPP

#include <string>

namespace TankTek
{
    class ShaderDLS
    {
        public:
            static std::string compileTkShader(const std::string& source); 
    };
}

#endif

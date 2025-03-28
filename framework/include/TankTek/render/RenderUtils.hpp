#ifndef TT_RenderUtils_HPP
#define TT_RenderUtils_HPP

namespace TankTek
{
    class RenderUtils
    {
        public:
            static void setClearColor(float r, float g, float b);
            static void setClearColor(float r, float g, float b, float a);
            static void clearScreen();
    };
}

#endif
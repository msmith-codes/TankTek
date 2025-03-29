#ifndef TT_Math_HPP
#define TT_Math_HPP

#include <glm/glm.hpp>

namespace TankTek
{
    class Math
    {
        public:
            static const float PI;
        public:
            static float sqrt(float value);
            static float toRadians(float degrees);
            static float toDegrees(float radians);
            static float cos(float radians);
            static float sin(float radians);
            static float tan(float radians);
    };

    using Vec2f = glm::vec2;
    using Vec3f = glm::vec3;
    using Mat4x4f = glm::mat4x4;

}

#endif
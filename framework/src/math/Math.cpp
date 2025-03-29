#include <TankTek/math/Math.hpp>

#include <cmath>

namespace TankTek
{
    const float Math::PI = 3.14159265358979323846f;

    float Math::sqrt(float value)
    {
        return std::sqrt(value);
    }

    float Math::toRadians(float degrees)
    {
        return degrees * (PI / 180.0f);
    }

    float Math::toDegrees(float radians)
    {
        return radians * (180.0f / PI);
    }

    float Math::cos(float radians)
    {
        return std::cos(radians);
    }

    float Math::sin(float radians)
    {
        return std::sin(radians);
    }

    float Math::tan(float radians)
    {
        return std::tan(radians);
    }
}
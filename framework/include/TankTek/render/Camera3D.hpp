#ifndef TT_Camera3D_HPP
#define TT_Camera3D_HPP

#include <TankTek/math/Math.hpp>

namespace TankTek
{
    class Camera3D
    {
        private:
            Mat4x4f projectionMatrix;
            Mat4x4f viewMatrix;
            Mat4x4f viewProjectionMatrix;
        private:
            Vec3f position;
            float fov;
            float nearPlane;
            float farPlane;
        public:
            Camera3D();
            Camera3D(const Vec3f& position);
        public:
            Mat4x4f& getProjectionMatrix();
            Mat4x4f& getViewMatrix();
        public:
            void setOrthographic(float left, float right, float bottom, float top, float nearPlane, float farPlane);
            void setPerspective(float fov, float aspectRatio, float nearPlane, float farPlane);
        public:
            void setPosition(const Vec3f& position);
            void setFov(float fov);
            void setNearPlane(float nearPlane);
            void setFarPlane(float farPlane);
            
    };
}

#endif
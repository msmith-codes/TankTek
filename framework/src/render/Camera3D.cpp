#include <TankTek/render/Camera3D.hpp>
#include <TankTek/core/Window.hpp>

#include <TankTek/math/Math.hpp>

#include <glm/gtc/matrix_transform.hpp>

namespace TankTek
{
    Camera3D::Camera3D()
    {
        this->position = Vec3f(0.0f, 0.0f, 0.0f);
        this->fov = Math::toRadians(45.0f);
        this->nearPlane = 0.1f;
        this->farPlane = 100.0f;

        this->projectionMatrix = glm::mat4(1.0f);
        this->viewMatrix = glm::mat4(1.0f);
        this->viewProjectionMatrix = glm::mat4(1.0f);
    }

    Camera3D::Camera3D(const Vec3f& position)
    {
        this->position = position;
        this->fov = Math::toRadians(45.0f);
        this->nearPlane = 0.1f;
        this->farPlane = 100.0f;

        this->projectionMatrix = glm::mat4(1.0f);
        this->viewMatrix = glm::mat4(1.0f);
        this->viewProjectionMatrix = glm::mat4(1.0f);
    }

    Mat4x4f& Camera3D::getProjectionMatrix()
    {
        float aspectRatio = (float)TankTek::Window::getWidth() / (float)TankTek::Window::getHeight();
        this->projectionMatrix = glm::perspective(this->fov, aspectRatio, this->nearPlane, this->farPlane);

        return this->projectionMatrix;   
    }

    Mat4x4f& Camera3D::getViewMatrix()
    {
        Vec3f cameraFront = Vec3f(0.0f, 0.0f, -1.0f);
        Vec3f cameraUp = Vec3f(0.0f, 1.0f, 0.0f);

        this->viewMatrix = glm::mat4(1.0f);
        this->viewMatrix = glm::lookAt(this->position, this->position + cameraFront, cameraUp);

        return this->viewMatrix;
    }

    void Camera3D::setOrthographic(float left, float right, float bottom, float top, float nearPlane, float farPlane)
    {
        this->nearPlane = nearPlane;
        this->farPlane = farPlane;

        this->projectionMatrix = glm::ortho(left, right, bottom, top, this->nearPlane, this->farPlane);
    }

    void Camera3D::setPerspective(float fov, float aspectRatio, float nearPlane, float farPlane)
    {
        this->fov = fov;
        this->nearPlane = nearPlane;
        this->farPlane = farPlane;

        this->projectionMatrix = glm::perspective(this->fov, aspectRatio, this->nearPlane, this->farPlane);
    }

    void Camera3D::setPosition(const Vec3f& position)
    {
        this->position = position;
    }

    void Camera3D::setFov(float fov)
    {
        this->fov = fov;
    }

    void Camera3D::setNearPlane(float nearPlane)
    {
        this->nearPlane = nearPlane;
    }

    void Camera3D::setFarPlane(float farPlane)
    {
        this->farPlane = farPlane;
    }
}

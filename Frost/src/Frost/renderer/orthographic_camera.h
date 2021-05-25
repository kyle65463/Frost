#pragma once

#include "glm/glm.hpp"

namespace Frost
{
    class FROST_API OrthographicCamera
    {
    public:
        OrthographicCamera(float left, float right, float bottom, float top);

        void setPosition(const glm::vec3 position) { this->position = position; calculateViewMatrix(); }
        void setRotation(float rotation) { this->rotation = rotation; calculateViewMatrix(); }
        
        inline const glm::vec3& getPosition() const { return position; }
        inline float getRotation() const { return rotation; }
        inline const glm::mat4& getProjectionMatrix() const { return projectionMatrix; }
        inline const glm::mat4& getViewMatrix() const { return viewMatrix; }
        inline const glm::mat4& getViewProjectionMatrix() const { return viewProjectionMatrix; }

        void calculateViewMatrix();

    private:
        glm::mat4 projectionMatrix;
        glm::mat4 viewMatrix;
        glm::mat4 viewProjectionMatrix;

        glm::vec3 position = {0.0f, 0.0f, 0.0f};
        float rotation = 0.0f; 
    };
}
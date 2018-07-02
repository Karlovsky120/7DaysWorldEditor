#pragma once

#include "glm\glm.hpp"
#include "glm\gtc\quaternion.hpp"

class Transformation {
public:
    Transformation(const glm::vec3 &position = glm::vec3(0.0f), const glm::quat &rotation = glm::angleAxis(0.0f, glm::vec3(0.0f, 0.0f, 1.0f)), const glm::vec3 &scale = glm::vec3(1.0f));

    glm::vec3 getPosition() const;
    glm::quat getRotation() const;
    glm::vec3 getScale() const;

    void setPosition(const glm::vec3 &position);
    void setRotation(const glm::quat &rotation);
    void setScale(const glm::vec3 &scale);

    void translateObject(const glm::vec3 &translation);

    void rotateObjectFromLeft(const glm::quat &rotation);
    void rotateObjectFromLeft(const float angle, const glm::vec3 &axis);
    void rotateObjectFromRight(const glm::quat &rotation);
    void rotateObjectFromRight(const float angle, const glm::vec3 &axis);

    void scaleObject(const glm::vec3 &factor);

    glm::vec3 getForwardUnitVector() const;
    glm::vec3 getUpUnitVector() const;
    glm::vec3 getLeftUnitVector() const;

private:
    glm::vec3 position;
    glm::quat rotation;
    glm::vec3 scale;
};

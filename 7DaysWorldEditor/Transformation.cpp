#include "Transformation.h"

#include "glm\gtx\quaternion.hpp"

Transformation::Transformation(const glm::vec3 &position, const glm::quat &rotation, const glm::vec3 &scale) :
  position(position),
  rotation(rotation),
  scale(scale) {}

glm::vec3 Transformation::getPosition() const {
  return this->position;
}
glm::quat Transformation::getRotation() const {
  return this->rotation;
}

glm::vec3 Transformation::getScale() const {
  return this->scale;
}

void Transformation::setPosition(const glm::vec3 &position) {
  this->position = position;
}

void Transformation::setRotation(const glm::quat &rotation) {
  this->rotation = rotation;
}
void Transformation::setScale(const glm::vec3 &scale) {
  this->scale = scale;
}

void Transformation::translateObject(const glm::vec3 &translation) {
  this->position += translation;
}

void Transformation::rotateObjectFromLeft(const glm::quat &rotation) {
  this->rotation = rotation * this->rotation;
}

void Transformation::rotateObjectFromLeft(const float angle, const glm::vec3 &axis) {
  rotateObjectFromLeft(glm::angleAxis(glm::radians(angle), axis));
}

void Transformation::rotateObjectFromRight(const glm::quat &rotation) {
  this->rotation = this->rotation * rotation;
}

void Transformation::rotateObjectFromRight(const float angle, const glm::vec3 &axis) {
  rotateObjectFromRight(glm::angleAxis(glm::radians(angle), axis));
}

void Transformation::scaleObject(const glm::vec3 &factor) {
  this->scale *= scale;
}

glm::vec3 Transformation::getForwardUnitVector() const {
  return glm::rotate(this->rotation, glm::vec3(0.0f, 0.0f, 1.0f));
}

glm::vec3 Transformation::getUpUnitVector() const {
  return glm::rotate(this->rotation, glm::vec3(0.0f, 1.0f, 0.0f));
}

glm::vec3 Transformation::getLeftUnitVector() const {
  return glm::rotate(this->rotation, glm::vec3(1.0f, 0.0f, 0.0f));
}
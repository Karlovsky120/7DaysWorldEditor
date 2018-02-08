#include "CameraTransformation.h"

CameraTransformation::CameraTransformation(const glm::vec3 &position, const glm::quat &rotation) :
  position(position),
  rotation(rotation) {}


glm::vec3 CameraTransformation::getPosition() const {
  return this->position;
}
glm::quat CameraTransformation::getRotation() const {
  return this->rotation;
}


void CameraTransformation::setPosition(const glm::vec3 &position) {
  this->position = position;
}

void CameraTransformation::setRotation(const glm::quat &rotation) {
  this->rotation = rotation;
}


void CameraTransformation::translate(const glm::vec3 &translation) {
  this->position -= translation;
}

void CameraTransformation::rotateFromLeft(const glm::quat &rotation) {
  this->rotation = glm::inverse(rotation) * this->rotation;
}

void CameraTransformation::rotateFromLeft(const float angle, const glm::vec3 &axis) {
  rotateFromLeft(glm::angleAxis(glm::radians(angle), axis));
}

void CameraTransformation::rotateFromRight(const glm::quat &rotation) {
  this->rotation = this->rotation * glm::inverse(rotation);
}

void CameraTransformation::rotateFromRight(const float angle, const glm::vec3 &axis) {
  rotateFromRight(glm::angleAxis(glm::radians(angle), axis));
}


glm::vec3 CameraTransformation::getForwardUnitVector() const {
  return glm::rotate(glm::inverse(this->rotation), glm::vec3(0.0f, 0.0f, -1.0f));
}

glm::vec3 CameraTransformation::getUpUnitVector() const {
  return glm::rotate(glm::inverse(this->rotation), glm::vec3(0.0f, -1.0f, 0.0f));
}

glm::vec3 CameraTransformation::getLeftUnitVector() const {
  return glm::rotate(glm::inverse(this->rotation), glm::vec3(-1.0f, 0.0f, 0.0f));
}

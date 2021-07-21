#include <glm/gtc/constants.hpp>
#include <glm/mat4x4.hpp>
#include <glm/vec3.hpp>

#include "camera.hpp"

Camera::Camera(glm::mat4 projection, glm::vec2 rotation) {
	this->projection = projection;
	setRotation(rotation);
}
Camera::~Camera() {
	return;
}
void Camera::setRotation(glm::vec2 rotation) {
	pitch = rotation.x;
	yaw = rotation.y;
	if (yaw > 2 * M_PI) yaw -= 2 * M_PI;
	else if (yaw < 0) yaw += 2 * M_PI;
	pitch = glm::clamp(pitch, -6 * M_PI / 13, 6 * M_PI / 13);
	forward = glm::mat3(glm::rotate(glm::mat4(1.0), yaw, WORLD_UP)) * glm::vec3(0, 0, -1);
	right = glm::cross(forward, Camera::WORLD_UP);
	forward = glm::mat3(glm::rotate(glm::mat4(1.0), pitch, right)) * forward;
	view = glm::lookAt(position, position + forward, WORLD_UP);
	viewProjection = projection * view;
	dirty = true;
}
void Camera::rotate(glm::vec2 mouseDelta) {
	if (mouseDelta == glm::vec2(0, 0)) return;
	yaw -= mouseDelta.x * MOUSE_SENSITIVITY;
	pitch -= mouseDelta.y * MOUSE_SENSITIVITY;
	if (yaw > 2 * M_PI) yaw -= 2 * M_PI;
	else if (yaw < 0) yaw += 2 * M_PI;
	pitch = glm::clamp(pitch, -6 * M_PI / 13, 6 * M_PI / 13);
	forward = glm::mat3(glm::rotate(glm::mat4(1.0), yaw, WORLD_UP)) * glm::vec3(0, 0, -1);
	glm::mat4 rotation = glm::rotate(glm::mat4(1.0), -1 * yaw, WORLD_UP);
	right = glm::cross(forward, Camera::WORLD_UP);
	rotation = rotation * glm::rotate(glm::mat4(1.0), -1 * pitch, right);
	forward = glm::mat3(glm::rotate(glm::mat4(1.0), pitch, right)) * forward;
	view = glm::lookAt(position, position + forward, WORLD_UP);
	dirty = true;
}

void Camera::update(double currentTime) {
	forward = glm::mat3(glm::rotate(glm::mat4(1.0), yaw, WORLD_UP)) * glm::vec3(0, 0, -1);
	right = glm::cross(forward, Camera::WORLD_UP);
	forward = glm::mat3(glm::rotate(glm::mat4(1.0), pitch, right)) * forward;
	view = glm::lookAt(position, position + forward, WORLD_UP);
	viewProjection = projection * view;
	dirty = true;
}

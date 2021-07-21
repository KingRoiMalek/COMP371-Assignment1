#pragma once

#include <GLFW/glfw3.h>

#include "arrow.hpp"
#include "camera.hpp"
#include "cluster.hpp"
#include "cube.hpp"
#include "grid.hpp"
#include "scheduler.hpp"
#include "shader_manager.hpp"
#include "wall.hpp"

class Application {
public:
	double const UPDATE_INTERVAL = 1.0 / 30.0;
	int const WINDOW_SIZE[2] = {1024, 768};
	char const* WINDOW_TITLE = "COMP371	Assignment #1";
public:
	Scheduler scheduler = Scheduler(UPDATE_INTERVAL);
	GLFWwindow* window = nullptr;
	glm::dvec2 lastMousePos = glm::dvec2(0, 0);
public:
	Camera* camera;
	Grid* grid;
	ShaderManager *shaderMan;
	Cube *cube;
	Arrow *xAxis, *yAxis, *zAxis;
public:
	glm::vec2 worldRotation = glm::vec2(0, 0);
	Cluster *clusters;
	int currentCluster = 0;
	Wall* wall;
public:
	Application();
	~Application();
public:
	void handleMouse();
	void render();
	void update();
private:
	void initialiseGLFW();
	void initialiseOpenGL();
	void initialiseOpenGLShaders();
	void initialiseScene();
};
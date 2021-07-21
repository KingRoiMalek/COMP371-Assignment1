#pragma once

#include <GLFW/glfw3.h>

#include "arrow.hpp"
#include "camera.hpp"
#include "cluster.hpp"
#include "cube.hpp"
#include "grid.hpp"
#include "scheduler.hpp"
#include "shader_manager.hpp"

class Application {
public:
	double const UPDATE_INTERVAL = 1.0 / 30.0;
	int const WINDOW_SIZE[2] = {1024, 768};
	char const* WINDOW_TITLE = "COMP371	Assignment #1";
public:
	Scheduler scheduler = Scheduler(UPDATE_INTERVAL);
	GLFWwindow* window = nullptr;
public:
	Camera* camera;
	Grid* grid;
	ShaderManager *shaderMan;
	Cube *cube;
	Arrow *xAxis, *yAxis, *zAxis;
public:
	glm::vec2 worldRotation = glm::vec2(0, 0);
	Cluster clusters[5];
	int currentCluster = 0;
public:
	Application();
	~Application();
public:
	void render();
	void update();
private:
	void initialiseGLFW();
	void initialiseOpenGL();
	void initialiseOpenGLShaders();
	void initialiseScene();
};
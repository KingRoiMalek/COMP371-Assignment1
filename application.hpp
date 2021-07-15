#pragma once

#include <GLFW/glfw3.h>

#include "camera.hpp"
#include "grid.hpp"
#include "render_object.hpp"
#include "scheduler.hpp"
#include "shader_manager.hpp"
#include "arrow.hpp"

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
	RenderObject *triangle;
	Arrow *xAxis, *yAxis, *zAxis;
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
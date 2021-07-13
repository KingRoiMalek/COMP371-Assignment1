#pragma once

#include <GLFW/glfw3.h>

#include "render_object.hpp"
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
	ShaderManager *shaderMan;
	RenderObject *triangle;
public:
	Application();
	~Application();
public:
	void render();
	void update();
	void updateUniforms();
private:
	void initialiseGLFW();
	void initialiseOpenGL();
	void initialiseOpenGLShaders();
	void initialiseScene();
};
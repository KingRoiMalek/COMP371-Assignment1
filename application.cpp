#include <cstdio>

#include <glad.h>
#include <GLFW/glfw3.h>

#include "application.hpp"
#include "shader_manager.hpp"
#include "utility.hpp"

Application::Application() {
	initialiseGLFW();
	initialiseOpenGL();
	initialiseOpenGLShaders();
	initialiseScene();
}
Application::~Application() {
	if(window) glfwDestroyWindow(window);
	glfwTerminate();
}
void Application::initialiseGLFW() {
	printf("Initialising GLFW\n");
	assertFatal(glfwInit(), "Could not initialise GLFW\n");
	glfwWindowHint(GLFW_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_DOUBLEBUFFER, GLFW_TRUE);
	window = glfwCreateWindow(WINDOW_SIZE[0], WINDOW_SIZE[1], WINDOW_TITLE, NULL, NULL);
	assertFatal(window != NULL, "Could not create window\n");
	glfwMakeContextCurrent(window);
}
void Application::initialiseOpenGL() {
	printf("Initialising OpenGL\n");
	assertFatal(gladLoadGLLoader((GLADloadproc)glfwGetProcAddress), "Could not load OpenGL\n");
	glfwSwapInterval(0);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
}
void Application::initialiseOpenGLShaders() {
	printf("Loading OpenGL shaders\n");
	shaderMan = new ShaderManager();
	shaderMan->appendShader("basicVert", GL_VERTEX_SHADER, "resources/shaders/basic.vert");
	shaderMan->appendShader("basicFrag", GL_FRAGMENT_SHADER, "resources/shaders/basic.frag");
	shaderMan->createProgram("basic", { "basicVert", "basicFrag" });
}
void Application::initialiseScene() {
	float const ASPECT_RATIO =
		((float)Application::WINDOW_SIZE[0]) / Application::WINDOW_SIZE[1];
	glm::mat4x4 const projection =
		glm::perspective(45.0f, ASPECT_RATIO, 0.1f, 1000.0f);
	camera = new Camera(projection, glm::vec2(glm::radians(-10.0f), 0));
	triangle = new RenderObject({ OGLVertexAttribute(0, 3, GL_FLOAT, GL_FALSE) });
	std::vector<GLfloat> vertices = 
	{0.5, 0.5, 0, 0.5, -0.5, 0, -0.5, -0.5, 0, -0.5, 0.5, 0 };
	triangle->updateVertices(vertices);
	std::vector<GLuint> indices = { 0, 2, 1, 0, 3, 2 };
	triangle->updateIndices(indices);
	grid = new Grid(100, 100, 0.5f);
	xAxis = new Arrow(2.5f, glm::vec2(glm::radians(90.0f), glm::radians(90.0f)));
	yAxis = new Arrow(2.5f, glm::vec2(0, 0));
	zAxis = new Arrow(2.5f, glm::vec2(0, glm::radians(90.0f)));
}
void Application::render() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	shaderMan->useProgram("basic");
	glEnable(GL_DEPTH_TEST);
	if (camera->dirty) {
		shaderMan->setUniform("viewProjection", "basic", camera->viewProjection);
	}
	shaderMan->setUniform("color", "basic", glm::vec4(1.0f, 1.0f, 0, 1.0f));
	triangle->render();
	shaderMan->setUniform("color", "basic", glm::vec4(1.0f, 1.0f, 1.0f, 0.3f));
	grid->render();
	glDisable(GL_DEPTH_TEST);
	shaderMan->setUniform("color", "basic", glm::vec4(1.0f, 0.0f, 0.0f, 1.0f));
	xAxis->render();
	shaderMan->setUniform("color", "basic", glm::vec4(0.0f, 1.0f, 0.0f, 1.0f));
	yAxis->render();
	shaderMan->setUniform("color", "basic", glm::vec4(0.0f, 0.0f, 1.0f, 1.0f));
	zAxis->render();
	glfwSwapBuffers(window);
	camera->dirty = false;
}
void Application::update() {
	camera->update(scheduler.currentTime);
}
int main(int argc, char const* argv[]) {
	Application* application = new Application();
	while (!glfwWindowShouldClose(application->window)) {
		glfwPollEvents();
		if (application->scheduler.shouldUpdate()) application->update();
		application->render();
		application->scheduler.FPS += 1;
	}
	delete application;
	return 0;
}
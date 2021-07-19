#define GLEW_STATIC 1   // This allows linking with Static Library on Windows, without DLL
#include <glad.h>
#include <GLFW/glfw3.h> // cross-platform interface for creating a graphical context,
// initializing OpenGL and binding inputs

#include <glm/glm.hpp>  // GLM is an optimized math library with syntax to similar to OpenGL Shading Language
#include <glm/gtc/matrix_transform.hpp> // include this to create transformation matrices
#include <glm/common.hpp>

#include "cube.hpp"

using namespace glm;

int Cube::generateCube() {
	
    vec3 color = vec3(0.5f, 0.5f, 0.5f);

    vec3 vertexArray[] = { 
     vec3(-0.5f,-0.5f,-0.5f), color, //left
     vec3(-0.5f,-0.5f, 0.5f), color,
     vec3(-0.5f, 0.5f, 0.5f), color,

     vec3(-0.5f,-0.5f,-0.5f), color,
     vec3(-0.5f, 0.5f, 0.5f), color,
     vec3(-0.5f, 0.5f,-0.5f), color,

     vec3(0.5f, 0.5f,-0.5f), color, //back
     vec3(-0.5f,-0.5f,-0.5f), color,
     vec3(-0.5f, 0.5f,-0.5f), color,

     vec3(0.5f, 0.5f,-0.5f), color, 
     vec3(0.5f,-0.5f,-0.5f), color,
     vec3(-0.5f,-0.5f,-0.5f), color,

     vec3(0.5f,-0.5f, 0.5f), color, //bottom
     vec3(-0.5f,-0.5f,-0.5f), color,
     vec3(0.5f,-0.5f,-0.5f), color,

     vec3(0.5f,-0.5f, 0.5f), color,
     vec3(-0.5f,-0.5f, 0.5f), color,
     vec3(-0.5f,-0.5f,-0.5f), color,

     vec3(-0.5f, 1.0f, 0.5f), color, //face
     vec3(-0.5f,-0.5f, 0.5f), color,
     vec3(0.5f,-0.5f, 0.5f), color,

     vec3(0.5f, 0.5f, 0.5f), color,
     vec3(-0.5f, 0.5f, 0.5f), color,
     vec3(0.5f,-0.5f, 0.5f), color,

     vec3(0.5f, 0.5f, 0.5f), color, //right
     vec3(0.5f,-0.5f,-0.5f), color,
     vec3(0.5f, 0.5f,-0.5f), color,

     vec3(0.5f,-0.5f,-0.5f), color,
     vec3(0.5f, 0.5f, 0.5f), color,
     vec3(0.5f,-0.5f, 0.5f), color,

     vec3(0.5f, 0.5f, 0.5f), color, //top
     vec3(0.5f, 0.5f,-0.5f), color,
     vec3(-0.5f, 0.5f,-0.5f), color,

     vec3(0.5f, 0.5f, 0.5f), color,
     vec3(-0.5f, 0.5f,-0.5f), color,
     vec3(-0.5f, 0.5f, 0.5f), color
    };

    // Create a vertex array
    GLuint vertexArrayObject;
    glGenVertexArrays(1, &vertexArrayObject);
    glBindVertexArray(vertexArrayObject);


    // Upload Vertex Buffer to the GPU, keep a reference to it (vertexBufferObject)
    GLuint vertexBufferObject;
    glGenBuffers(1, &vertexBufferObject);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertexArray), vertexArray, GL_STATIC_DRAW);

    glVertexAttribPointer(0,                   // attribute 0 matches aPos in Vertex Shader
        3,                   // size
        GL_FLOAT,            // type
        GL_FALSE,            // normalized?
        2 * sizeof(vec3), // stride - each vertex contain 2 vec3 (position, color)
        (void*)0             // array buffer offset
    );
    glEnableVertexAttribArray(0);


    glVertexAttribPointer(1,                            // attribute 1 matches aColor in Vertex Shader
        3,
        GL_FLOAT,
        GL_FALSE,
        2 * sizeof(vec3),
        (void*)sizeof(vec3)      // color is offseted a vec3 (comes after position)
    );
    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject);
    glBindVertexArray(0);

    return vertexArrayObject;
};

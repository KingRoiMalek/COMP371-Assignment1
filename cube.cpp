#include <glm/gtc/constants.hpp>
#include <glm/mat4x4.hpp>
#include <glm/vec3.hpp>

#include "cube.hpp"

using namespace glm;

glm::vec3* ::generateCube() {
	
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
};

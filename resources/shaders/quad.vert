#version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec2 texCoord;
out vec2 vertTexCoord;

uniform mat4 projection;
uniform mat4 object;

void main()
{
	vertTexCoord = texCoord;
    gl_Position = projection * object * vec4(position.x, position.y, position.z, 1.0);
}
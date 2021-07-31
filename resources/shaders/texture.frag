#version 330 core
in vec4 vertColor;
in vec2 vertTexCoord;
in vec3 vertNormal;
in vec3 fragPosition;
out vec4 outColor;

uniform sampler2D textureSampler;
uniform vec3 lightPosition;
uniform vec3 cameraPosition;
uniform mat4 world;

const vec3 lightColor = vec3(1.0f, 1.0f, 1.0f);

void main()
{
	float ambientStrength = 0.1f;
	vec3 ambient = ambientStrength * lightColor;
	
	vec3 lightDirection = normalize(fragPosition - lightPosition);
	float diffuseFactor = max(dot(vertNormal, lightDirection), 0.0);
	vec3 diffuse = diffuseFactor * lightColor;
	
	float specularStrength = 0.8;
	vec3 viewDirection = normalize(fragPosition - (inverse(world) * vec4(cameraPosition, 1.0f)).xyz);
	vec3 reflectDirection = reflect(-lightDirection, vertNormal);  
	float specularFactor = pow(max(dot(viewDirection, reflectDirection), 0.0), 16);
	vec3 specular = specularStrength * specularFactor * lightColor;
	
	vec3 final = (ambient + diffuse + specular) * texture(textureSampler, vertTexCoord).xyz;
    outColor = vec4(final, 1.0f);
} 
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <glm/ext/matrix_transform.hpp>

#include "model.hpp"

Model::Model(char const* path, glm::vec4 color, glm::vec3 position, glm::vec2 rotation, float scale) : RenderObject({
	OGLVertexAttribute(0, 3, GL_FLOAT, GL_FALSE), OGLVertexAttribute(1, 4, GL_FLOAT, GL_FALSE), OGLVertexAttribute(2, 2, GL_FLOAT, GL_FALSE), OGLVertexAttribute(3, 3, GL_FLOAT, GL_FALSE) }) {	
	this->position = position;
	this->rotation = rotation;
	this->scale = scale;
	Assimp::Importer importer;
	const aiScene* scene = importer.ReadFile(path, aiProcess_Triangulate | aiProcess_GenSmoothNormals | aiProcess_FixInfacingNormals | aiProcess_JoinIdenticalVertices);
	const aiMesh* mesh = scene->mMeshes[0];
	std::vector<GLfloat> vertices;
	vertices.reserve(mesh->mNumVertices * 12);
	for (unsigned int i = 0; i < mesh->mNumVertices; i += 1) {
		vertices.push_back(mesh->mVertices[i].x);
		vertices.push_back(mesh->mVertices[i].y);
		vertices.push_back(mesh->mVertices[i].z);
		vertices.push_back(color.x);
		vertices.push_back(color.y);
		vertices.push_back(color.z);
		vertices.push_back(color.w);
		vertices.push_back(0.0f);
		vertices.push_back(0.0f);
		vertices.push_back(-1.0f * mesh->mNormals[i].x);
		vertices.push_back(-1.0f * mesh->mNormals[i].y);
		vertices.push_back(-1.0f * mesh->mNormals[i].z);
	}

	std::vector<GLuint> indices;
	indices.reserve(mesh->mNumFaces * 3);
	for (unsigned int i = 0; i < mesh->mNumFaces; i += 1) {
		indices.push_back(mesh->mFaces[i].mIndices[0]);
		indices.push_back(mesh->mFaces[i].mIndices[1]);
		indices.push_back(mesh->mFaces[i].mIndices[2]);
	}

	updateVertices(vertices);
	updateIndices(indices);
	importer.FreeScene();
}
void Model::render(ShaderManager* shaderMan, std::string const& programName) {
	const glm::mat4 i = glm::mat4(1.0f);
	glm::mat4 transform =
	glm::translate(i, position) * // Step 3: Translate cluster
	glm::rotate(i, rotation.x, glm::vec3(1.0f, 0, 0)) * // Step 2: Rotate cluster around x-axis
	glm::rotate(i, rotation.y, glm::vec3(0, 1.0f, 0)) * // Step 2: Rotate cluster around y-axis
	glm::scale(i, glm::vec3(scale)); // Step 1: Scale cluster by a constant
	shaderMan->setUniform("object", programName, transform);
	RenderObject::render();
}
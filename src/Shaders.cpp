// Load Shaders
// Create and compile shaders
// and Shader Programs
// Provide an interface to switch shaders
// and manage shader uniforms

#include <malloc.h>
#include <glad.h>
#include <GLFW/glfw3.h>

#include "Shaders.h"
#include <Utils.h>
#include <stdio.h>

//
// ShaderProgram
// Base class to all other shader programs

ShaderProgram::ShaderProgram(char* vertexShaderFile, char* fragmentShaderFile) {
	vertexShaderID = loadShader(vertexShaderFile, GL_VERTEX_SHADER);
	fragmentShaderID = loadShader(fragmentShaderFile, GL_FRAGMENT_SHADER);

	shaderProgramID = glCreateProgram();
	glAttachShader(shaderProgramID, vertexShaderID);
	glAttachShader(shaderProgramID, fragmentShaderID);
	glLinkProgram(shaderProgramID);
	glValidateProgram(shaderProgramID);
}

unsigned int ShaderProgram::loadShader(char* shaderSourceFile, int shaderType)
{
	char* shaderSource = readFileToString(shaderSourceFile);
	int shaderID = glCreateShader(shaderType);

	glShaderSource(shaderID, 1, &shaderSource, NULL);
	glCompileShader(shaderID);
	free(shaderSource);

	return shaderID;
}

void ShaderProgram::start()
{
	glUseProgram(shaderProgramID);
}

void ShaderProgram::stop()
{
	glUseProgram(0);
}

void ShaderProgram::destroy()
{
	stop();
	glDetachShader(shaderProgramID, vertexShaderID);
	glDetachShader(shaderProgramID, fragmentShaderID);
	glDeleteShader(vertexShaderID);
	glDeleteShader(fragmentShaderID);
	glDeleteProgram(shaderProgramID);
}

//
// Static Shader
// Basic Vertex and Fragment shader program with no uniforms
//

StaticShader::StaticShader()
	: ShaderProgram("shaders/static.vert", "shaders/static.frag")
{
}

class ShaderProgram {
	unsigned int vertexShaderID;
	unsigned int fragmentShaderID;
	unsigned int shaderProgramID;

	unsigned int loadShader(char* shaderSourceFile, int shaderType);
public:
	ShaderProgram(char* vertexShaderFile, char* fragmentShaderFile);

	void start();
	void stop();
	void destroy();
};

class StaticShader : public ShaderProgram {
public:
	StaticShader();
};

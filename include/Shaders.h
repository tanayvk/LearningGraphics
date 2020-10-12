class ShaderProgram {
	unsigned int vertexShaderID;
	unsigned int fragmentShaderID;
	unsigned int shaderProgramID;

	unsigned int loadShader(const char* shaderSourceFile, int shaderType);
public:
	ShaderProgram(const char* vertexShaderFile, const char* fragmentShaderFile);

	void start();
	void stop();
	void destroy();
};

class StaticShader : ShaderProgram {
	const char* VERTEX_SHADER = "../shaders/static.vert";
	const char* FRAGMENT_SHADER = "../shaders/static.frag";
public:
	StaticShader();
};

#include "Shader.h"

namespace Engine {

	Shader::Shader()
	{
	}

	Shader::Shader(string fileName)
	{
		LoadFileData(fileName);
	}

	Shader::~Shader()
	{
		Clean();
	}

	void Shader::LoadFileData(const string& fileName) {
		const GLchar* charArr[1];
		string filePath = fileName;
		string vertexShader = File::LoadFile("res\\Shaders\\" + filePath + ".vert");
		string fragmentShader = File::LoadFile("res\\Shaders\\" + filePath + ".frag");

		m_shaders[VERTEX_SHADER] = glCreateShader(GL_VERTEX_SHADER);
		m_shaders[FRAGMENT_SHADER] = glCreateShader(GL_FRAGMENT_SHADER);
		
		charArr[0] = vertexShader.c_str();
		glShaderSource(m_shaders[VERTEX_SHADER], 1, charArr, 0);
		charArr[0] = fragmentShader.c_str();
		glShaderSource(m_shaders[FRAGMENT_SHADER], 1, charArr, 0);

		glCompileShader(m_shaders[VERTEX_SHADER]);
		glCompileShader(m_shaders[FRAGMENT_SHADER]);

		bool bSuccess = (CheckShaderCompileStatus(m_shaders[VERTEX_SHADER]) && CheckShaderCompileStatus(m_shaders[FRAGMENT_SHADER]));

		if (bSuccess) {
			m_programId = glCreateProgram();
			glAttachShader(m_programId, m_shaders[VERTEX_SHADER]);
			glAttachShader(m_programId, m_shaders[FRAGMENT_SHADER]);
			glLinkProgram(m_programId);

			if (!CheckProgramLinkStatus(m_programId))
				return;

			glDeleteShader(m_shaders[VERTEX_SHADER]);
			glDeleteShader(m_shaders[FRAGMENT_SHADER]);
		}
#if DEBUG
		assert(glGetError() == GL_NO_ERROR);
#endif
	}

	bool Shader::CheckShaderCompileStatus(GLint ShaderId) {
		return CheckStatus(ShaderId, glGetShaderiv, glGetShaderInfoLog, GL_COMPILE_STATUS);
	}

	bool Shader::CheckProgramLinkStatus(GLint ProgramId) {
		return CheckStatus(ProgramId, glGetProgramiv, glGetProgramInfoLog, GL_LINK_STATUS);
	}

	bool Shader::CheckStatus(GLuint objectId,
		PFNGLGETSHADERIVPROC getIvCallback,
		PFNGLGETSHADERINFOLOGPROC getInfoCallback,
		GLenum statusType)
	{
		GLint iStatus;
		getIvCallback(objectId, statusType, &iStatus);
		if (iStatus != GL_TRUE)
		{
			GLint iLength;
			GLsizei iBufferSize;

			getIvCallback(objectId, GL_INFO_LOG_LENGTH, &iLength);
			GLchar* resultBuffer = new GLchar[iLength];

			getInfoCallback(objectId, iLength, &iBufferSize, resultBuffer);
			cout << resultBuffer << endl;
			return false;
		}
		return true;
	}

	void Shader::SetSharderMatrixUniform(const string name, const Matrix4& value)
	{
		glUniformMatrix4fv(GetUniformLocation(name.c_str()), 1, GL_TRUE, &value.m[0][0]);
	}

	void Shader::SetShaderFloatUniform(const string name, const GLfloat value)
	{
		glUniform1f(GetUniformLocation(name.c_str()), value);
	}

	void Shader::SetShaderIntUnifrom(const string name, const GLint value)
	{
		glUniform1i(GetUniformLocation(name.c_str()), value);
	}

	void Shader::SetShaderVec2Uniform(const string name, const Vector2& value)
	{
		glUniform2fv(GetUniformLocation(name.c_str()), 1, &value.x);
	}

	void Shader::SetShaderVec3Uniform(const string name, const Vector3& value)
	{
		glUniform3fv(GetUniformLocation(name.c_str()), 1, &value.x);
	}

	void Shader::Clean()
	{
		glDetachShader(m_programId, m_shaders[VERTEX_SHADER]);
		glDetachShader(m_programId, m_shaders[FRAGMENT_SHADER]);
		glDeleteShader(m_shaders[VERTEX_SHADER]);
		glDeleteShader(m_shaders[FRAGMENT_SHADER]);
		glDeleteProgram(m_programId);
	}

	void Shader::Bind() {
		glUseProgram(m_programId);
	}

	void Shader::UnBind() {
		glUseProgram(0);
	}

	GLint Shader::GetUniformLocation(const char* name)
	{
		GLint uniformLocation = glGetUniformLocation(m_programId, name);
		assert(uniformLocation >= 0);
		return uniformLocation;
	}

}
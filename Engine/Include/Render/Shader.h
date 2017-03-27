#pragma once

#include "..\Util\File.h"
#include "glew.h"
#include "Math\Math.h"
#include "Globals.h"
#include "Shader.h"

using namespace std;

namespace Engine {

	class EXPORT Shader
	{
	public:
		Shader();

		Shader(string fileName);

		bool CheckShaderCompileStatus(GLint ShaderId);

		bool CheckProgramLinkStatus(GLint ProgramId);

		bool CheckStatus(GLuint objectId, PFNGLGETSHADERIVPROC getIvCallback, PFNGLGETSHADERINFOLOGPROC getInfoCallback, GLenum statusType);

		void SetShaderVec2Uniform(const string name, const Vector2 & value);

		void SetSharderMatrixUniform(const string name, const Matrix4 & value);

		void SetShaderVec3Uniform(const string name, const Vector3 & value);

		void SetShaderFloatUniform(const string name, GLfloat value);

		void SetShaderIntUnifrom(const string name, GLint value);

		void Clean();

		void Bind();

		void UnBind();

		virtual ~Shader();

		void LoadFileData(const string & fileName);

	private:
		enum
		{
			VERTEX_SHADER,
			FRAGMENT_SHADER,
			NUM_SHADERS
		};
		GLuint m_programId;
		GLuint m_shaders[NUM_SHADERS];
		GLint GetUniformLocation(const char * name);
		string m_fileName;
	};
}
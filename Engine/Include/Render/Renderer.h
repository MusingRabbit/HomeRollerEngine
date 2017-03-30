#pragma once

#include "Globals.h"
#include "glew.h"
#include "Mesh.h"
#include "Shader.h"
#include <iostream>
#include <string>

namespace Engine {
	class EXPORT Renderer
	{
	public:
		Renderer();
		~Renderer();
		void Initialise();
		void DrawMesh(Mesh & model, Shader & shader);
		void DrawMesh(Mesh & model);
		void SetColour(float r, float g, float b, float a);
		void Clear();
		void Draw();
		char const * GetOpenGLVersion();
	};

}
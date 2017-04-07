#pragma once

#include<glew.h>
#include <vector>
#include <string>
#include "Render\ShapeData.h"

namespace Engine {

	class EXPORT Mesh
	{
	public:
		Mesh();
		Mesh(std::string filename);
		Mesh(const ShapeData data);
		~Mesh();

		void Load(std::string fileName);
		void Load(const ShapeData data);
		void Render();
		void Clear();
		GLuint GetVertexBufferId();
		GLuint GetDrawCount();
		GLushort* GetIndices();

	private:
		void BufferGeometry();

		ShapeData m_shapeData;
		GLuint m_vaoId;
		GLuint m_drawCount;

		enum
		{
			VERTEX_BUFFER,
			INDEX_BUFFER,
			BUFFER_COUNT
		};

		GLuint m_arrayBuffers[BUFFER_COUNT];
	};
}
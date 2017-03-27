#pragma once
#include "Globals.h"
#include "Vertex.h"
#include <glew.h>

namespace Engine {

	struct EXPORT ShapeData
	{
		ShapeData() :
			vertices(0), numVertices(0), indices(0), numIndices(0)
		{

		}

		Vertex* vertices;
		GLuint* indices;
		GLuint numVertices;
		GLuint numIndices;

		GLsizeiptr GetVertexBufferSize() const {
			return numVertices * sizeof(Vertex);
		}

		GLsizeiptr GetIndexBufferSize() const {
			return numIndices * sizeof(GLushort);
		}

		void clear() {
			delete[] indices;
			delete[] vertices;
			numIndices = numVertices = 0;
		}
	};
}
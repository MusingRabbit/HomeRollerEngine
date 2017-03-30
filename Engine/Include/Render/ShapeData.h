#pragma once
#include "Globals.h"
#include "Vertex.h"
#include <glew.h>
#include <vector>

using namespace std;

namespace Engine {

	struct ShapeData
	{
		vector<Vertex> vertices;
		vector<GLuint> indices;

		ShapeData() 
		{

		}

		GLsizeiptr GetVertexBufferSize() const {
			return vertices.size() * sizeof(Vertex);
		}

		GLsizeiptr GetIndexBufferSize() const {
			return indices.size() * sizeof(GLuint);
		}

		void clear() {
			indices.clear();
			vertices.clear();
		}
	};
}
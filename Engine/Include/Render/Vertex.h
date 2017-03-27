#pragma once
#include "Math\Vector3.h"
#include "Math\Vector2.h"
#include <glew.h>

namespace Engine {

	static const float X_DELTA = 0.1f;
	static const GLuint NUM_VERTS_PER_TRI = 3;
	static const GLuint NUM_FLOAT_PER_VERT = 11;
	static const GLuint VERTEX_BYTE_SIZE = NUM_FLOAT_PER_VERT * sizeof(float);
	static const GLuint MAX_TRIANGLE_COUNT = 20;

	struct Vertex
	{
		Vector3 position;
		Vector3 colour;
		Vector3 normal;
		Vector2 uvCoord;
	};
}
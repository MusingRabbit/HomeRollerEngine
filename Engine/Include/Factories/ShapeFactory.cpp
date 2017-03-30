#include "ShapeFactory.h"



namespace Engine {

	ShapeData ShapeFactory::MakeTriangle() {

		ShapeData result;

		Vertex t1Verts[] = {
			Vector3(-1.0f,-1.0f, 0.0f),			//0
			Vector3(1.0f,0.0f,0.0f),			//colour
			Vector3(+0.0f, +0.0f, +1.0f),		//normal
			Vector2(0.0f,0.0f),					//uvCoord
			Vector3(0.0f,1.0f, 0.0f),			//1
			Vector3(0.0f,1.0f,0.0f),			//colour
			Vector3(+0.0f, +0.0f, +1.0f),		//normal
			Vector2(0.0f,0.0f),					//uvCoord
			Vector3(1.0f, -1.0f, 0),			//2
			Vector3(0.0f,0.0f,1.0f),			//colour
			Vector3(+0.0f, +0.0f, +1.0f),		//normal
			Vector2(0.0f,0.0f)					//uvCoord
		};

		GLuint  iArr[]{ 0,1,2 };

		size_t sizeVerts = GET_ARRAY_SIZE(t1Verts);
		size_t sizeIndic = GET_ARRAY_SIZE(iArr);

		result.vertices.reserve(sizeVerts);
		result.indices.reserve(sizeIndic);

		for (int i = 0; i < sizeVerts; i++) {
			result.vertices.push_back(t1Verts[i]);
		}
		for (int i = 0; i < sizeIndic; i++) {
			result.indices.push_back(iArr[i]);
		}

		return result;
	}

	ShapeData ShapeFactory::MakeArrow()
	{
		ShapeData result;
		Vertex t1Verts[] =
		{
			// Top side of arrow head
			Vector3(+0.00f, +0.25f, -0.25f),         // 0
			Vector3(+1.00f, +0.00f, +0.00f),		  // Color
			Vector3(+0.00f, +1.00f, +0.00f),         // Normal
			Vector2(0.0f,0.0f),
			Vector3(+0.50f, +0.25f, -0.25f),         // 1
			Vector3(+1.00f, +0.00f, +0.00f),		  // Color
			Vector3(+0.00f, +1.00f, +0.00f),         // Normal
			Vector2(0.0f,0.0f),
			Vector3(+0.00f, +0.25f, -1.00f),         // 2
			Vector3(+1.00f, +0.00f, +0.00f),		  // Color
			Vector3(+0.00f, +1.00f, +0.00f),         // Normal
			Vector2(0.0f,0.0f),
			Vector3(-0.50f, +0.25f, -0.25f),         // 3
			Vector3(+1.00f, +0.00f, +0.00f),		  // Color
			Vector3(+0.00f, +1.00f, +0.00f),         // Normal
			// Bottom side of arrow head
			Vector2(0.0f,0.0f),
			Vector3(+0.00f, -0.25f, -0.25f),         // 4
			Vector3(+0.00f, +0.00f, +1.00f),		  // Color
			Vector3(+0.00f, -1.00f, +0.00f),         // Normal
			Vector2(0.0f,0.0f),
			Vector3(+0.50f, -0.25f, -0.25f),         // 5
			Vector3(+0.00f, +0.00f, +1.00f),		  // Color
			Vector3(+0.00f, -1.00f, +0.00f),         // Normal
			Vector2(0.0f,0.0f),
			Vector3(+0.00f, -0.25f, -1.00f),         // 6
			Vector3(+0.00f, +0.00f, +1.00f),		  // Color
			Vector3(+0.00f, -1.00f, +0.00f),         // Normal
			Vector2(0.0f,0.0f),
			Vector3(-0.50f, -0.25f, -0.25f),         // 7
			Vector3(+0.00f, +0.00f, +1.00f),		  // Color
			Vector3(+0.00f, -1.00f, +0.00f),         // Normal
			Vector2(0.0f,0.0f),
			// Right side of arrow tip
			Vector3(+0.50f, +0.25f, -0.25f),         // 8
			Vector3(+0.60f, +1.00f, +0.00f),		  // Color
			Vector3(0.83205032f, 0.00f, -0.55470026f), // Normal
			Vector2(0.0f,0.0f),
			Vector3(+0.00f, +0.25f, -1.00f),         // 9
			Vector3(+0.60f, +1.00f, +0.00f),		  // Color
			Vector3(0.83205032f, 0.00f, -0.55470026f), // Normal
			Vector2(0.0f,0.0f),
			Vector3(+0.00f, -0.25f, -1.00f),         // 10
			Vector3(+0.60f, +1.00f, +0.00f),		  // Color
			Vector3(0.83205032f, 0.00f, -0.55470026f), // Normal
			Vector2(0.0f,0.0f),
			Vector3(+0.50f, -0.25f, -0.25f),         // 11
			Vector3(+0.60f, +1.00f, +0.00f),		  // Color
			Vector3(0.83205032f, 0.00f, -0.55470026f), // Normal
			Vector2(0.0f,0.0f),
			// Left side of arrow tip
			Vector3(+0.00f, +0.25f, -1.00f),         // 12
			Vector3(+0.00f, +1.00f, +0.00f),		  // Color
			Vector3(-0.55708605f, 0.00f, -0.37139067f), // Normal
			Vector2(0.0f,0.0f),
			Vector3(-0.50f, +0.25f, -0.25f),         // 13
			Vector3(+0.00f, +1.00f, +0.00f),		  // Color
			Vector3(-0.55708605f, 0.00f, -0.37139067f), // Normal
			Vector2(0.0f,0.0f),
			Vector3(+0.00f, -0.25f, -1.00f),         // 14
			Vector3(+0.00f, +1.00f, +0.00f),		  // Color
			Vector3(-0.55708605f, 0.00f, -0.37139067f), // Normal
			Vector2(0.0f,0.0f),
			Vector3(-0.50f, -0.25f, -0.25f),         // 15
			Vector3(+0.00f, +1.00f, +0.00f),		  // Color
			Vector3(-0.55708605f, 0.00f, -0.37139067f), // Normal
			Vector2(0.0f,0.0f),
			// Back side of arrow tip
			Vector3(-0.50f, +0.25f, -0.25f),         // 16
			Vector3(+0.50f, +0.50f, +0.50f),		  // Color
			Vector3(+0.00f, +0.00f, +1.00f),         // Normal
			Vector2(0.0f,0.0f),
			Vector3(+0.50f, +0.25f, -0.25f),         // 17
			Vector3(+0.50f, +0.50f, +0.50f),		  // Color
			Vector3(+0.00f, +0.00f, +1.00f),         // Normal
			Vector2(0.0f,0.0f),
			Vector3(-0.50f, -0.25f, -0.25f),         // 18
			Vector3(+0.50f, +0.50f, +0.50f),		  // Color
			Vector3(+0.00f, +0.00f, +1.00f),         // Normal
			Vector2(0.0f,0.0f),
			Vector3(+0.50f, -0.25f, -0.25f),         // 19
			Vector3(+0.50f, +0.50f, +0.50f),		  // Color
			Vector3(+0.00f, +0.00f, +1.00f),         // Normal
			Vector2(0.0f,0.0f),
			// Top side of back of arrow
			Vector3(+0.25f, +0.25f, -0.25f),         // 20
			Vector3(+1.00f, +0.00f, +0.00f),		  // Color
			Vector3(+0.00f, +1.00f, +0.00f),         // Normal
			Vector2(0.0f,0.0f),
			Vector3(+0.25f, +0.25f, +1.00f),         // 21
			Vector3(+1.00f, +0.00f, +0.00f),		  // Color
			Vector3(+0.00f, +1.00f, +0.00f),         // Normal
			Vector2(0.0f,0.0f),
			Vector3(-0.25f, +0.25f, +1.00f),         // 22
			Vector3(+1.00f, +0.00f, +0.00f),		  // Color
			Vector3(+0.00f, +1.00f, +0.00f),         // Normal
			Vector2(0.0f,0.0f),
			Vector3(-0.25f, +0.25f, -0.25f),         // 23
			Vector3(+1.00f, +0.00f, +0.00f),		  // Color
			Vector3(+0.00f, +1.00f, +0.00f),         // Normal
			Vector2(0.0f, 0.0f),
			// Bottom side of back of arrow
			Vector3(+0.25f, -0.25f, -0.25f),         // 24
			Vector3(+0.00f, +0.00f, +1.00f),		  // Color
			Vector3(+0.00f, -1.00f, +0.00f),         // Normal
			Vector2(0.0f, 0.0f),
			Vector3(+0.25f, -0.25f, +1.00f),         // 25
			Vector3(+0.00f, +0.00f, +1.00f),		  // Color
			Vector3(+0.00f, -1.00f, +0.00f),         // Normal
			Vector2(0.0f, 0.0f),
			Vector3(-0.25f, -0.25f, +1.00f),         // 26
			Vector3(+0.00f, +0.00f, +1.00f),		  // Color
			Vector3(+0.00f, -1.00f, +0.00f),         // Normal
			Vector2(0.0f, 0.0f),
			Vector3(-0.25f, -0.25f, -0.25f),         // 27
			Vector3(+0.00f, +0.00f, +1.00f),		  // Color
			Vector3(+0.00f, -1.00f, +0.00f),         // Normal
			Vector2(0.0f, 0.0f),
			// Right side of back of arrow
			Vector3(+0.25f, +0.25f, -0.25f),         // 28
			Vector3(+0.60f, +1.00f, +0.00f),		  // Color
			Vector3(+1.00f, +0.00f, +0.00f),         // Normal
			Vector2(0.0f, 0.0f),
			Vector3(+0.25f, -0.25f, -0.25f),         // 29
			Vector3(+0.60f, +1.00f, +0.00f),		  // Color
			Vector3(+1.00f, +0.00f, +0.00f),         // Normal
			Vector2(0.0f, 0.0f),
			Vector3(+0.25f, -0.25f, +1.00f),         // 30
			Vector3(+0.60f, +1.00f, +0.00f),		  // Color
			Vector3(+1.00f, +0.00f, +0.00f),         // Normal
			Vector2(0.0f, 0.0f),
			Vector3(+0.25f, +0.25f, +1.00f),         // 31
			Vector3(+0.60f, +1.00f, +0.00f),		  // Color
			Vector3(+1.00f, +0.00f, +0.00f),         // Normal
			// Left side of back of arrow
			Vector2(0.0f, 0.0f),
			Vector3(-0.25f, +0.25f, -0.25f),         // 32
			Vector3(+0.00f, +1.00f, +0.00f),		  // Color
			Vector3(-1.00f, +0.00f, +0.00f),         // Normal
			Vector2(0.0f, 0.0f),
			Vector3(-0.25f, -0.25f, -0.25f),         // 33
			Vector3(+0.00f, +1.00f, +0.00f),		  // Color
			Vector3(-1.00f, +0.00f, +0.00f),         // Normal
			Vector2(0.0f, 0.0f),
			Vector3(-0.25f, -0.25f, +1.00f),         // 34
			Vector3(+0.00f, +1.00f, +0.00f),		  // Color
			Vector3(-1.00f, +0.00f, +0.00f),         // Normal
			Vector2(0.0f, 0.0f),
			Vector3(-0.25f, +0.25f, +1.00f),         // 35
			Vector3(+0.00f, +1.00f, +0.00f),		  // Color
			Vector3(-1.00f, +0.00f, +0.00f),         // Normal

			// Back side of back of arrow
			Vector2(0.0f, 0.0f),
			Vector3(-0.25f, +0.25f, +1.00f),         // 36
			Vector3(+0.50f, +0.50f, +0.50f),		  // Color
			Vector3(+0.00f, +0.00f, +1.00f),         // Normal
			Vector2(0.0f, 0.0f),
			Vector3(+0.25f, +0.25f, +1.00f),         // 37
			Vector3(+0.50f, +0.50f, +0.50f),		  // Color
			Vector3(+0.00f, +0.00f, +1.00f),         // Normal
			Vector2(0.0f, 0.0f),
			Vector3(-0.25f, -0.25f, +1.00f),         // 38
			Vector3(+0.50f, +0.50f, +0.50f),		  // Color
			Vector3(+0.00f, +0.00f, +1.00f),         // Normal
			Vector2(0.0f, 0.0f),
			Vector3(+0.25f, -0.25f, +1.00f),         // 39
			Vector3(+0.50f, +0.50f, +0.50f),		  // Color
			Vector3(+0.00f, +0.00f, +1.00f)         // Normal
		};

		GLuint iArr[] = {
			0, 1, 2, // Top
			0, 2, 3,
			4, 6, 5, // Bottom
			4, 7, 6,
			8, 10, 9, // Right side of arrow tip
			8, 11, 10,
			12, 15, 13, // Left side of arrow tip
			12, 14, 15,
			16, 19, 17, // Back side of arrow tip
			16, 18, 19,
			20, 22, 21, // Top side of back of arrow
			20, 23, 22,
			24, 25, 26, // Bottom side of back of arrow
			24, 26, 27,
			28, 30, 29, // Right side of back of arrow
			28, 31, 30,
			32, 33, 34, // Left side of back of arrow
			32, 34, 35,
			36, 39, 37, // Back side of back of arrow
			36, 38, 39,
		};


		size_t sizeVerts = GET_ARRAY_SIZE(t1Verts);
		size_t sizeIndic = GET_ARRAY_SIZE(iArr);

		result.vertices.reserve(sizeVerts);
		result.indices.reserve(sizeIndic);

		for (int i = 0; i < sizeVerts; i++) {
			result.vertices.push_back(t1Verts[i]);
		}
		for (int i = 0; i < sizeIndic; i++) {
			result.indices.push_back(iArr[i]);
		}

		return result;
	}

	ShapeData ShapeFactory::MakeCube() {

		ShapeData result;

		Vertex t1Verts[] = {
			//Top
			Vector3(-1.0f, +1.0f, +1.0f), // 0
			Vector3(+1.0f, +0.0f, +0.0f), // Colour
			Vector3(0.0f,	1.0f,	0.0f), // normal
			Vector2(0.0f, 0.0f),
			Vector3(+1.0f, +1.0f, +1.0f), // 1
			Vector3(+0.0f, +1.0f, +0.0f), // Colour
			Vector3(0.0f,	1.0f,	0.0f), // normal
			Vector2(0.0f, 0.0f),
			Vector3(+1.0f, +1.0f, -1.0f), // 2
			Vector3(+0.0f, +0.0f, +1.0f), // Colour
			Vector3(0.0f,	1.0f,	0.0f), // normal
			Vector2(0.0f, 0.0f),
			Vector3(-1.0f, +1.0f, -1.0f), // 3
			Vector3(+1.0f, +1.0f, +1.0f), // Colour
			Vector3(0.0f,	1.0f,	0.0f), // normal
			Vector2(0.0f, 0.0f),
			//Back
			Vector3(-1.0f, +1.0f, -1.0f), // 4
			Vector3(+1.0f, +0.0f, +1.0f), // Colour
			Vector3(0.0f,	1.0f,  -1.0f), // normal
			Vector2(0.0f, 0.0f),
			Vector3(+1.0f, +1.0f, -1.0f), // 5
			Vector3(+0.0f, +0.5f, +0.2f), // Colour
			Vector3(0.0f,	1.0f,  -1.0f), // normal
			Vector2(0.0f, 0.0f),
			Vector3(+1.0f, -1.0f, -1.0f), // 6
			Vector3(+0.8f, +0.6f, +0.4f), // Colour
			Vector3(0.0f,	1.0f,  -1.0f), // normal
			Vector2(0.0f, 0.0f),
			Vector3(-1.0f, -1.0f, -1.0f), // 7
			Vector3(+0.3f, +1.0f, +0.5f), // Colour
			Vector3(0.0f,	1.0f,  -1.0f), // normal
			Vector2(0.0f, 0.0f),
			//Right
			Vector3(+1.0f, +1.0f, -1.0f), // 8
			Vector3(+0.2f, +0.5f, +0.2f), // Colour
			Vector3(+1.0f, +0.0f, +0.0f),  // Normal
			Vector2(0.0f, 0.0f),
			Vector3(+1.0f, +1.0f, +1.0f), // 9
			Vector3(+0.9f, +0.3f, +0.7f), // Colour
			Vector3(+1.0f, +0.0f, +0.0f),  // Normal
			Vector2(0.0f, 0.0f),
			Vector3(+1.0f, -1.0f, +1.0f), // 10
			Vector3(+0.3f, +0.7f, +0.5f), // Colour
			Vector3(+1.0f, +0.0f, +0.0f),  // Normal
			Vector2(0.0f, 0.0f),
			Vector3(+1.0f, -1.0f, -1.0f), // 11
			Vector3(+0.5f, +0.7f, +0.5f), // Colour
			Vector3(+1.0f, +0.0f, +0.0f),  // Normal
			Vector2(0.0f, 0.0f),
			//Left
			Vector3(-1.0f, +1.0f, +1.0f), // 12
			Vector3(+0.7f, +0.8f, +0.2f), // Colour
			Vector3(-1.0f, +0.0f, +0.0f),  // Normal
			Vector2(0.0f, 0.0f),
			Vector3(-1.0f, +1.0f, -1.0f), // 13
			Vector3(+0.5f, +0.7f, +0.3f), // Colour
			Vector3(-1.0f, +0.0f, +0.0f),  // Normal
			Vector2(0.0f, 0.0f),
			Vector3(-1.0f, -1.0f, -1.0f), // 14
			Vector3(+0.4f, +0.7f, +0.7f), // Colour
			Vector3(-1.0f, +0.0f, +0.0f),  // Normal
			Vector2(0.0f, 0.0f),
			Vector3(-1.0f, -1.0f, 1.0f), // 15
			Vector3(+0.2f, +0.5f, +1.0f), // Colour
			Vector3(-1.0f, +0.0f, +0.0f),  // Normal
			Vector2(0.0f, 0.0f),
			//Front
			Vector3(+1.0f, +1.0f, +1.0f), // 16
			Vector3(+0.6f, +1.0f, +0.7f), // Colour
			Vector3(+0.0f, +0.0f, +1.0f),  // Normal
			Vector2(0.0f, 0.0f),
			Vector3(-1.0f, +1.0f, +1.0f), // 17
			Vector3(+0.6f, +0.4f, +0.8f), // Colour
			Vector3(+0.0f, +0.0f, +1.0f),  // Normal
			Vector2(0.0f, 0.0f),
			Vector3(-1.0f, -1.0f, +1.0f), // 18
			Vector3(+0.2f, +0.8f, +0.7f), // Colour
			Vector3(+0.0f, +0.0f, +1.0f),  // Normal
			Vector2(0.0f, 0.0f),
			Vector3(+1.0f, -1.0f, +1.0f), // 19
			Vector3(+0.2f, +0.7f, +1.0f), // Colour
			Vector3(+0.0f, +0.0f, +1.0f),  // Normal
			Vector2(0.0f, 0.0f),
			//Bottom
			Vector3(+1.0f, -1.0f, -1.0f), // 20
			Vector3(+0.8f, +0.3f, +0.7f), // Colour
			Vector3(+0.0f, -1.0f, +0.0f),  // Normal
			Vector2(0.0f, 0.0f),
			Vector3(-1.0f, -1.0f, -1.0f), // 21
			Vector3(+0.8f, +0.9f, +0.5f), // Colour
			Vector3(+0.0f, -1.0f, +0.0f),  // Normal
			Vector2(0.0f, 0.0f),
			Vector3(-1.0f, -1.0f, +1.0f), // 22
			Vector3(+0.5f, +0.8f, +0.5f), // Colour
			Vector3(+0.0f, -1.0f, +0.0f),  // Normal
			Vector2(0.0f, 0.0f),
			Vector3(+1.0f, -1.0f, +1.0f), // 23
			Vector3(+0.9f, +1.0f, +0.2f), // Colour
			Vector3(+0.0f, -1.0f, +0.0f),  // Normal
		};

		GLuint iArr[] = {
			0,1,2,
			0,2,3,		//	Top
			4,5,6,
			4,6,7,		//	Front
			8,9,10,
			8,10,11,		//	Right
			12,13,14,
			12,14,15,	//	Left
			16,17,18,
			16,18,19,	//	Back
			20,22,21,
			20,23,22	//	Bottom
		};

		size_t sizeVerts = GET_ARRAY_SIZE(t1Verts);
		size_t sizeIndic = GET_ARRAY_SIZE(iArr);

		result.vertices.reserve(sizeVerts);
		result.indices.reserve(sizeIndic);

		for (int i = 0; i < sizeVerts; i++) {
			result.vertices.push_back(t1Verts[i]);
		}
		for (int i = 0; i < sizeIndic; i++) {
			result.indices.push_back(iArr[i]);
		}

		return result;
	}

	ShapeData ShapeFactory::MakePlane(uint dimensions)
	{
		ShapeData result;
		int iHalf = dimensions / 2;
		int iCount = 0;
		size_t sizeVerts = dimensions * dimensions;
		size_t sizeIndic = (((dimensions - 1) * (dimensions - 1)) * 2) * 3;

		result.vertices.reserve(sizeVerts);
		result.indices.reserve(sizeIndic);

		for (uint i = 0; i < dimensions; i++)
		{
			for (uint j = 0; j < dimensions; j++)
			{
				Vertex& cVert = result.vertices[i * dimensions + j];
				cVert.position.x = (float)j - iHalf;
				cVert.position.z = (float)i - iHalf;
				cVert.position.y = 0;
				cVert.normal = Vector3(0.0f, 1.0f, 0.0f);
				float fColour = (i % 2 == j % 2) ? 1.0f : 0.1f;
				cVert.colour = Vector3(0.8f, 0.8f, 0.8f);

				if (i < dimensions - 1 && j < dimensions - 1) {
					result.indices[iCount++] = dimensions * i + j;
					result.indices[iCount++] = dimensions * i + j + dimensions;
					result.indices[iCount++] = dimensions * i + j + dimensions + 1;

					result.indices[iCount++] = dimensions * i + j;
					result.indices[iCount++] = dimensions * i + j + dimensions + 1;
					result.indices[iCount++] = dimensions * i + j + 1;
				}
			}
		}

		assert(iCount == result.indices.size());

		return result;
	}

	ShapeData ShapeFactory::GenerateNormalLines(const ShapeData & data)
	{
		ShapeData result;

		result.vertices.reserve(result.vertices.size() * 2);

		for (size_t i = 0; i < result.vertices.size(); i++)
		{
			uint vertIndex = i * 2;
			const Vertex& vSource = data.vertices[i];
			Vertex& v1 = result.vertices[vertIndex];
			Vertex& v2 = result.vertices[vertIndex + 1];
			v1.position = vSource.position;
			v2.position = vSource.position + vSource.normal;
			v1.colour = v2.colour = Vector3(1.0f, 1.0f, 1.0f);
		}

		result.indices.clear();

		for (size_t i = 0; i < result.vertices.size(); i++)
			result.indices.push_back(i);

		return result;
	}

}
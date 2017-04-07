#include "Mesh.h"

namespace Engine {

	Mesh::Mesh()
	{
	}

	Mesh::Mesh(std::string filename)
	{
	}

	Mesh::Mesh(const ShapeData data)
	{
		Load(data);
	}


	Mesh::~Mesh()
	{
		Clear();
	}

	void Mesh::Load(std::string fileName)
	{
	}

	void Mesh::Load(const ShapeData data)
	{
		m_shapeData = data;
		m_drawCount = data.indices.size();
		BufferGeometry();
	}

	void Mesh::Render()
	{
		glBindVertexArray(m_vaoId);
		glDrawElements(GL_TRIANGLES, m_drawCount, GL_UNSIGNED_INT, 0);
		glDrawArrays(GL_TRIANGLES, 0, m_drawCount);
		glBindVertexArray(0);
	}

	void Mesh::Clear()
	{
		m_shapeData.clear();
		glDeleteBuffers(BUFFER_COUNT, m_arrayBuffers);
		glDeleteVertexArrays(1, &m_vaoId);
	}

	GLuint Mesh::GetVertexBufferId()
	{
		return m_vaoId;
	}

	GLuint Mesh::GetDrawCount()
	{
		return m_shapeData.indices.size();
	}

	GLushort* Mesh::GetIndices()
	{
		return &m_shapeData.indices[0];
	}

	void Mesh::BufferGeometry()
	{
		glGenVertexArrays(1, &m_vaoId); // Create a VAO, and assign it's Id
		glBindVertexArray(m_vaoId); //Bind the newly created VAO

		glGenBuffers(BUFFER_COUNT, m_arrayBuffers); //Create Buffers

		//Bind the vertex buffer Id and create buffers within OpenGL
		glBindBuffer(GL_ARRAY_BUFFER, m_arrayBuffers[VERTEX_BUFFER]);
		glBufferData(GL_ARRAY_BUFFER, m_shapeData.GetVertexBufferSize(), &m_shapeData.vertices[0], GL_STATIC_DRAW);

		//Bind the index buffer Id and create buffers within OpenGL
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_arrayBuffers[INDEX_BUFFER]);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_shapeData.GetIndexBufferSize(), &m_shapeData.indices[0], GL_STATIC_DRAW);

		glEnableVertexAttribArray(0);	//Attrib pointer for Vertex Position
		glEnableVertexAttribArray(1);	//Attrib pointer for Vertex Colour
		glEnableVertexAttribArray(2);	//Attrib pointer for Vertex Normal
		glEnableVertexAttribArray(3);	//Attrib pointer for Vertex Texture Coord

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, VERTEX_BYTE_SIZE, 0);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, VERTEX_BYTE_SIZE, (char*)(sizeof(float) * 3));
		glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, VERTEX_BYTE_SIZE, (char*)(sizeof(float) * 6));
		glVertexAttribPointer(3, 2, GL_FLOAT, GL_FALSE, VERTEX_BYTE_SIZE, (char*)(sizeof(float) * 9));

		glBindVertexArray(0); //Unbind VAO once we're done.
	}

}
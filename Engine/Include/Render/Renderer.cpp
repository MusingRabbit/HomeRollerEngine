#include "Renderer.h"

namespace Engine {

	Renderer::Renderer()
	{
	}



	Renderer::~Renderer()
	{
	}

	void Renderer::Initialise() {
		std::cout << "Renderer::" << " OpenGL " << GetOpenGLVersion() << std::endl;

		glEnable(GL_CULL_FACE);
		glEnable(GL_DEPTH_TEST);
		glCullFace(GL_BACK);
		glFrontFace(GL_CW);

		//TODO : Depth Clamp

		glEnable(GL_FRAMEBUFFER_SRGB);

		SetColour(0.0f,0.0f,0.0f,1.0f);
	}

	void Renderer::DrawMesh(Mesh& model, Shader& shader)
	{
		shader.Bind();
		glBindVertexArray(model.GetVertexBufferId());
		glDrawElements(GL_TRIANGLES, model.GetDrawCount(), GL_UNSIGNED_SHORT, 0);
		glBindVertexArray(0);
		shader.UnBind();
		assert(glGetError() == GL_NO_ERROR);
	}

	void Renderer::DrawMesh(Mesh& model)
	{
		glBindVertexArray(model.GetVertexBufferId());
		glDrawElements(GL_TRIANGLES, model.GetDrawCount(), GL_UNSIGNED_SHORT, 0);
		glBindVertexArray(0);
		assert(glGetError() == GL_NO_ERROR);
	}


	void Renderer::SetColour(float r, float g, float b, float a) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(r, g, b, a);
	}

	void Renderer::Clear() {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void Renderer::Draw() {
		Clear();
	}

	std::string Renderer::GetOpenGLVersion()
	{
		return reinterpret_cast<char const *>(glGetString(GL_VERSION));
	}
}
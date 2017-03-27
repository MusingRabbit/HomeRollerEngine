#include "Display.h"

namespace Engine {

	Display::Display()
	{
		m_window = nullptr;
	}

	Display::Display(int width, int height)
	{
		Init(width, height, "Game Window");
		CreateWindow(m_iWidth, m_iHeight, m_sTitle);
	}

	Display::Display(int width, int height, const std::string & title)
	{
		Init(width, height, title);
		CreateWindow(m_iWidth, m_iHeight, m_sTitle);
	}

	Display::~Display()
	{
	}

	void Display::Init(int width, int height, const std::string & title) {
		m_iHeight = height;
		m_iWidth = width;
		m_sTitle = title;
		m_bClosing = false;
	}

	void Display::CreateWindow(int width, int height, const std::string & title) {

		if (m_window != nullptr) {
			throw std::exception("A window already exists for this Display.");
		}

		m_window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);
		m_glContext = SDL_GL_CreateContext(m_window);
	}

	void Display::DestroyWindow() 
	{
		SDL_DestroyWindow(m_window);
		SDL_GL_DeleteContext(m_glContext);
	}

	void Display::SwapBuffer()
	{
		SDL_GL_SwapWindow(m_window);
	}

	bool Display::IsClosing()
	{
		return m_bClosing;
	}

	void Display::Close()
	{
		m_bClosing = true;
		DestroyWindow();
	}

	int Display::GetWidth()
	{
		return m_iWidth;
	}

	int Display::GetHeight()
	{
		return m_iHeight;
	}

	float Display::GetAspectRatio()
	{
		return (float)m_iWidth / (float)m_iHeight;
	}

}
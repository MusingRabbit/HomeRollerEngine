#include "Launcher.h"

namespace Engine 
{
	Launcher::Launcher()
	{
		
	}

	Launcher::~Launcher()
	{

	}

	void Launcher::Initialise(std::string Title, int Width, int Height)
	{
		std::cout << "Launcher::Initialising : " << Title << std::endl;

		SDL_Init(SDL_INIT_EVERYTHING);
		SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
		SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
		SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
		SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
		SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
		SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
		SDL_GL_SetSwapInterval(0);

		std::cout << "Launcher::Creating : SDL Window " << std::endl;
		m_display.CreateWindow(Width, Height, Title);

		std::cout << "Launcher::Initialising : Glew " << std::endl;
		GLenum status = glewInit();

		if (status != GLEW_OK) {
			std::cerr << "GLEW FAILED TO INITIALISE!" << std::endl;
			throw std::exception("GLEW FAILED TO INITIALISE!");
		}

		std::cout << "Launcher::GLEW_OK. Initialisation complete." << std::endl;
	}

	void Launcher::Start()
	{
		m_game.SetDisplay(m_display);
		m_game.Initialise();

		Run();
	}

	void Launcher::Run()
	{
		m_game.Run();
	}

	void Launcher::Stop()
	{
		m_game.Stop();
	}

	void Launcher::Clean()
	{
	}
}

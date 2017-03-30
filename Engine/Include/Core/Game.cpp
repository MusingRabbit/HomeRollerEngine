#include "Game.h"

namespace Engine {

	Game::Game()
	{

	}

	Game::~Game()
	{
	}

	void Game::SetDisplay(Display & value)
	{
		m_display = &value;
	}

	void Game::Initialise()
	{
		std::cout << "Gane::" << "Initialising" << std::endl;
		m_renderer.Initialise();
		m_gameTime.Reset();

		m_input.SetKey("forward", SDLK_w);
		m_input.SetKey("back", SDLK_s);
		m_input.SetKey("left", SDLK_a);
		m_input.SetKey("right", SDLK_d);
		m_input.SetKey("up", SDLK_SPACE);
		m_input.SetKey("down", SDLK_c);

		ShapeData shape = ShapeFactory::MakeCube();
		ShapeData testShape = ObjLoader::LoadFile("starwars\\star_destroyer");

		m_mesh.Load(shape);
		
		m_transform.SetPosition(0, 0, 0);

		m_shader.LoadFileData("testShader");
	}

	void Game::Run()
	{
		std::cout << "Game::Running..." << std::endl;
		m_bRunning = true;
		m_gameTime.Start();
		Update();
	}

	void Game::Pause()
	{
		m_gameTime.Stop();
	}

	void Game::Stop()
	{
		m_bRunning = false;
		m_gameTime.Stop();
	}

	void Game::Update()
	{
		float tmpi = 0.1f;
		while (m_bRunning) {
			m_input.Update();

			float tmpSin = sinf(m_gameTime.GetToalElapsedGameTime());
			
		   m_transform.SetScale(0.5, 0.5, 0.5);
		   m_transform.SetRotation(35.0f, tmpSin * 120, 0.0f);

			if (m_gameTime.Tick()) {
				Draw();

				if (m_input.isButtonHit("forward")) {
					std::cout << "INPUT : 'forward' button hit. " << std::endl;
				}

			}
			PollSDLEvents();
		}
	}

	void Game::Draw()
	{
		m_display->SwapBuffer();
		m_renderer.Draw();
		m_shader.Bind();
		m_shader.SetSharderMatrixUniform("transform", m_transform.GetMatrix());
		m_renderer.DrawMesh(m_mesh);
		m_shader.UnBind();
		assert(glGetError() == GL_NO_ERROR);
	}

	void Game::PollSDLEvents()
	{
		SDL_Event e;

		while (SDL_PollEvent(&e)) {
			switch (e.type)
			{
			case SDL_QUIT:
				Stop();
				m_display->Close();
				return;
			}
			m_input.ProcessSDLEvent(e);
		}
	}

}
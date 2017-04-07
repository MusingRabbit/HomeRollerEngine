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

		ShapeData shape = ShapeFactory::MakeTestCube();
		ShapeData testShape = ObjLoader::LoadFile("box");

		m_mesh.Load(shape);
		
		//m_transform.SetPosition(0, 0, 0);

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
		float tmp = 0;
		while (m_bRunning) {
			std::cout << "Frame Rate : " << m_gameTime.GetFrameRate() << std::endl;
			m_input.Update();

			if (m_gameTime.Tick()) {
				tmp = (m_gameTime.GetToalElapsedGameTime());
				float tmpSin = sinf(tmp);
				m_transform.SetPosition(tmpSin, 0.0f, 5.0f);
				m_transform.SetScale(0.3, 0.3, 0.3);
				m_transform.SetRotation(tmpSin * 35.0f, tmpSin * 180, tmpSin * 180);

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
		Matrix4 mtxModel = m_transform.GetMatrix();
		Matrix4 mtxProjection = Matrix4::CreatePerspectiveMatrix(70.0f, m_display->GetAspectRatio(), 0.1f, 1000);
		Matrix4 mtxModelProjection = mtxProjection * mtxModel;
		m_shader.SetSharderMatrixUniform("transform", mtxModelProjection);
		m_renderer.DrawMesh(m_mesh);
		m_shader.UnBind();
		//assert(glGetError() == GL_NO_ERROR);
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
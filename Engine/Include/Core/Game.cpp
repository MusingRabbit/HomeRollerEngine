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

		m_mouse = m_input.GetMouse();

		m_input.SetKey("forward", SDLK_w);
		m_input.SetKey("back", SDLK_s);
		m_input.SetKey("left", SDLK_a);
		m_input.SetKey("right", SDLK_d);
		m_input.SetKey("up", SDLK_SPACE);
		m_input.SetKey("down", SDLK_c);

		ShapeData importShape = ObjLoader::LoadFile("box");

		m_mesh.Load(importShape);
		
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
		float tmp = 0;
		while (m_bRunning) {
			m_input.Update();

			if (m_gameTime.Tick()) {
				PollSDLEvents();
				Mouse& mouse = m_input.GetMouse();

				tmp = (m_gameTime.GetToalElapsedGameTime());
				float tmpSin = sinf(tmp);
				float tmpCos = cosf(tmp);
				//m_transform.SetPosition(tmpSin, tmpCos * 2, 5.0f);
				m_transform.SetPosition(0, 0, 1.0f);
				m_transform.SetScale(0.3, 0.3, 0.3);

				

				if (mouse.isLeftDown()) {
					m_camera.MouseLook(mouse);
				}

				if (m_input.isButtonDown("forward")) {
					m_camera.MoveForward();
				}
				if (m_input.isButtonDown("back")) {
					m_camera.MoveBackward();
				}
				if (m_input.isButtonDown("left")) {
					m_camera.MoveLeft();
				}
				if (m_input.isButtonDown("right")) {
					m_camera.MoveRight();
				}
				Draw();
			}
			
		}
	}

	void Game::Draw()
	{
		m_display->SwapBuffer();
		m_renderer.Draw();
		m_shader.Bind();
		Matrix4 mtxModel = m_transform.GetMatrix();
		Matrix4 mtxViewToProjection = Matrix4::CreatePerspectiveMatrix(70.0f, m_display->GetAspectRatio(), 0.1f, 1000);
		Matrix4 mtxWorldToView =  m_camera.GetWorldToViewMatrix();
		Matrix4 mtxWorldToProjection = mtxViewToProjection * mtxWorldToView;
		Matrix4 mtxModelProjection = mtxWorldToProjection * mtxModel;
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
#pragma once

#include "GameTIme.h"
#include "Display.h"
#include "Render\Renderer.h"
#include "Input\InputController.h"
#include "Globals.h"
#include <iostream>
#include "Factories\ShapeFactory.h"
#include "Render\ShapeData.h"
#include "Render\Mesh.h"
#include "Render\Shader.h"
#include "Math\Transform.h"

namespace Engine {
	class EXPORT Game {
	public:
		Game();
		~Game();

		void SetDisplay(Display& value);

		void Initialise();
		void Run();
		void Pause();
		void Stop();

	private:
		Renderer m_renderer;
		GameTime m_gameTime;
		InputController m_input;
		Display* m_display;

		bool m_bRunning;

		void Update();
		void Draw();
		void PollSDLEvents();


		Mesh m_mesh;
		Shader m_shader;
		Transform m_transform;
	};
}
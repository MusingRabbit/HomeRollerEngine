#include "GameTIme.h"

Engine::GameTime::GameTime()
{
	Reset();
}

Engine::GameTime::~GameTime()
{
}

float Engine::GameTime::GetToalElapsedGameTime() const
{
	return (float)(SDL_GetPerformanceCounter() / m_dCountsPerSecond);
}

float Engine::GameTime::GetDeltaTime() const
{
	return (float)m_dDeltaTime;
}

float Engine::GameTime::GetFrameRate() const
{
	return 1.0f / m_dDeltaTime;
}

void Engine::GameTime::Reset()
{
	m_ulCurrTime = SDL_GetPerformanceCounter();
	m_dCountsPerSecond = SDL_GetPerformanceFrequency();
	m_dDeltaTime = -1;
	m_ulBaseTime = m_ulCurrTime;
	m_ulPausedTime = 0;
	m_ulPrevTime = 0;
	m_ulFrameCounter = 0;

	m_frameTime = 1.0 / m_dCountsPerSecond;

	m_bStopped = false;
}

void Engine::GameTime::Start()
{
	m_ulCurrTime = SDL_GetPerformanceCounter();

	if (m_bStopped)
	{
		m_ulPausedTime += m_ulCurrTime - m_ulStopTime;
		m_ulPrevTime = m_ulCurrTime;
		m_ulStopTime = 0;
		m_bStopped = false;
	}
}

void Engine::GameTime::Stop()
{
	if (m_bStopped) {
		m_dDeltaTime = 0.0;
		return;
	}

	UpdateTickers();

	m_ulStopTime = m_ulCurrTime;
	m_bStopped = true;
}

bool Engine::GameTime::Tick()
{
	if (m_bStopped)
	{
		m_dDeltaTime = 0;
		return false;
	}

	UpdateTickers();

	bool result = m_dDeltaTime >= 0;

	return result;
}

Uint64 Engine::GameTime::GetTicks()
{
	return m_ulFrameCounter;
}

void Engine::GameTime::UpdateTickers()
{
	m_ulCurrTime = SDL_GetPerformanceCounter();
	m_dDeltaTime = (m_ulCurrTime - m_ulPrevTime);
	m_dDeltaTime = m_bStopped ? m_dDeltaTime * m_dCountsPerSecond : m_dDeltaTime / m_dCountsPerSecond;
	m_dDeltaTime = m_dDeltaTime < 0.0 ? 0.0 : m_dDeltaTime;
	m_ulPrevTime = m_ulCurrTime;
	m_ulFrameCounter++;
}

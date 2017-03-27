#pragma once

#include "SDL.h"
#include "Globals.h"

namespace Engine {
	class EXPORT GameTime {
	public :
		GameTime();
		~GameTime();

		float GetToalElapsedGameTime()const;
		float GetDeltaTime()const;
		float GetFrameRate()const;

		void Reset();
		void Start();
		void Stop();
		bool Tick();
		Uint64 GetTicks();

	private :
		Uint64 m_ulBaseTime;
		Uint64 m_ulPausedTime;
		Uint64 m_ulStopTime;
		Uint64 m_ulPrevTime;
		Uint64 m_ulCurrTime;

		Uint64 m_ulFrameCounter;

		double m_frameTime;
		double m_dCountsPerSecond;
		double m_dDeltaTime;
		bool m_bStopped;

		void UpdateTickers();
	};

}
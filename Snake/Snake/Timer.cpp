#include "Timer.h"

float Timer::Last = 0.0f;
float Timer::DeltaTime = 0.0f;


void Timer::InitDeltaTime()
{
		Last = (float)std::clock() / 1000.0f;
}

void Timer::CalculateDeltaTime()
{
	float timeCycle = (float)std::clock() / 1000.0f;
	DeltaTime = timeCycle - Last;
	Last = timeCycle;

}

float Timer::GetDeltaTime()
{
	return DeltaTime;
}

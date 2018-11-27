#pragma once
#include <ctime>
class Timer
{
public:
	static void InitializeDeltaTime()
	{
		Last = (float)std::clock() / 1000.0f;
	};
	static void CalculateDeltaTime()
	{
		float timeCycle = (float)std::clock() / 1000.0f;
		DeltaTime =timeCycle - Last;
		Last = timeCycle;

	};
	static float GetDeltaTime()
	{
		return DeltaTime;
	};


private:
	static float Last;
	static float DeltaTime;
};

float Timer::Last = 0.0f;
float Timer::DeltaTime = 0.0f;
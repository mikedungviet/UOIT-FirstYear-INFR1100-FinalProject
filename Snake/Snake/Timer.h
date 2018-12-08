#pragma once
#include <ctime>
class Timer
{
public:
	static void InitDeltaTime();

	static void CalculateDeltaTime();

	//return float in SECONDS
	static float GetDeltaTime();


private:
	static float Last;
	static float DeltaTime;
};
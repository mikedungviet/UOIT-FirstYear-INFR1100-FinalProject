#pragma once
#include <Windows.h>

struct Vec2 : public _COORD
{
	Vec2(unsigned newX =0, unsigned newY =0)
	{
		X = newX;
		Y = newY;
	}
};
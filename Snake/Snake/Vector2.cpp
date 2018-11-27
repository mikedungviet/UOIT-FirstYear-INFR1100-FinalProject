#include "Vector2.h"
#include <math.h>


Vec2::Vec2(const float ar_XY): x{ar_XY}, y{ar_XY}
{
	/*Empty*/
}

Vec2::Vec2(const float ar_X, const float ar_Y): x{ar_X}, y{ar_Y}
{
	/*Empty*/
}

Vec2 Vec2::operator+(const Vec2 a) const
{
	Vec2 temp;
	temp.x = x + a.x;
	temp.y = y + a.y;

	return temp;
}

Vec2 Vec2::operator-(const Vec2 a) const
{
	Vec2 temp;
	temp.x = x - a.x;
	temp.y = y - a.y;

	return temp;
}


Vec2 Vec2::operator+=(const Vec2 a)
{
	*this = *this + a;
	return *this;
}

Vec2 Vec2::operator-=(const Vec2 a)
{
	*this = *this - a;
	return *this;
}

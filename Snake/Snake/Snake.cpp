#include "Snake.h"



Snake::Snake()
{
	colliding = false;
	movingDown = false;
	movingUp = false;
	movingRight = false;
	movingLeft = false;

	headPosition.X = 3;
	headPosition.Y = 4;
}


Snake::~Snake()
{
}

PixelSprite Snake::getSprite()
{
	return pm_sprite;
}

Vec2 Snake::getHeadPosition()
{
	return headPosition;
}

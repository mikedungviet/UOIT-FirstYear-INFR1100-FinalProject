#include "Snake.h"



Snake::Snake()
{
	colliding = false;
	movingDown = false;
	movingUp = false;
	movingRight = false;
	movingLeft = false;

	headPosition.x = 3;
	headPosition.y = 4;
}


Snake::~Snake()
{
}

int Snake::getSize()
{
	return pm_size;
}

void Snake::setSize(int p_size)
{
	pm_size = p_size;
}

Sprite Snake::getSprite()
{
	return pm_sprite;
}

Vec2 Snake::getHeadPosition()
{
	return headPosition;
}

#include "Snake.h"



Snake::Snake()
{
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

#include "Snake.h"



Snake::Snake() : PixelSprite(8,8,6)
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
#pragma once
#include "Sprite.h"
#include "Vector2.h"
#include <vector>
class Snake : public PixelSprite
{
public:
	Vec2 headPosition;
	std::vector<Vec2> bodyList;

	bool colliding;
	bool movingLeft;
	bool movingRight;
	bool movingDown;
	bool movingUp;
	int size;

	Snake();
	~Snake();
};


#pragma once
#include "Sprite.h"
#include "Vector2.h"
#include <vector>
class Snake : public Sprite
{
public:

	Vec2 headPosition;
	std::vector<Vec2> bodyList;

	bool colliding;
	bool movingLeft;
	bool movingRight;
	bool movingDown;
	bool movingUp;

	Snake();
	~Snake();

	int getSize();
	void setSize(int p_size);
	Sprite getSprite();
	Vec2 getHeadPosition();

private:
	Sprite pm_sprite;
	int pm_size;
};


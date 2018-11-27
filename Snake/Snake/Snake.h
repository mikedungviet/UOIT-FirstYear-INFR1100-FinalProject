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
	Snake();
	~Snake();

	int getSize();
	void setSize(int p_size);
	Sprite getSprite();

private:
	Sprite pm_sprite;
	int pm_size;
};


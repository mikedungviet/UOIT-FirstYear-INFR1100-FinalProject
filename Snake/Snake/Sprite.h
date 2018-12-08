#pragma once
#include <Windows.h>
#include <vector>
#include "Vec2.h"

//struct Vec2 : public _COORD
//{
//	Vec2(unsigned int newX = 0, unsigned int newY = 0)
//	{
//		X = newX;
//		Y = newY;
//	}
//};

class Sprite
{
public:

	Sprite();
	Sprite(const char *Characters, const unsigned int width, const unsigned int height);
	Sprite(const Sprite &a);
	~Sprite();

	void SetSprite(const char *Characters, const unsigned int width, const unsigned int height, const unsigned int colour);

	COORD GetPosition() const;

	COORD GetSize() const;

	void SetPosition(const unsigned int newX, const unsigned int newY);

	CHAR_INFO *GetBuffer();


protected:
	//The buffer to contain sprite info such as char and colour
	CHAR_INFO *Buffer = nullptr;
	//pos
	Vec2 Position;
	//height width
	Vec2 Size;
};

class PixelSprite : public Sprite
{
public:
	PixelSprite(const unsigned int width, const unsigned int height, const unsigned int colour);

private:


};

class AnimatedPixelSprite
{
public:
	AnimatedPixelSprite();
	//set rate in seconds
	void setRateofAnimation(const float);
	//set rate in milliseconds
	void setRateofAnimation(const unsigned int);

	void AddSprite(PixelSprite *sprite);

	PixelSprite* getAnimation();

private:
	std::vector<PixelSprite*> animationCollection;
	unsigned int CurrentAnimation = 0;
	float RateOfAnimation = 0;
	float last;
	float total;
};

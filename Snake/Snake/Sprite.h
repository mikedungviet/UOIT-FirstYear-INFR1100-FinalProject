#pragma once
#include "Vector2.h"
#include <Windows.h>

class Sprite
{
public:

	Sprite();
	Sprite(const char *Characters, const unsigned int width, const unsigned int height);
	Sprite(const Sprite &a);
	~Sprite();

	void SetSprite(const char *Characters, const unsigned int width, const unsigned int height);

	COORD GetPosition() const;

	COORD GetSize() const;

	void SetPosition(const unsigned int newX, const unsigned int newY);

	CHAR_INFO *GetBuffer();


private:
	//The buffer to contain sprite info such as char and colour
	CHAR_INFO *Buffer;
	//pos
	Vec2 Position;
	//height width
	Vec2 Size;
};

class AnimatedSprite
{
public:
	AnimatedSprite();
	void AddSprite(char *);
private:
	struct LinkedLIst
	{
		Sprite *First;
		Sprite *Next;
		Sprite *Last;
	};

};
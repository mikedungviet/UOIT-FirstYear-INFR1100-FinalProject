#include "Sprite.h"
#include <iostream>

Sprite::Sprite() {}

Sprite::Sprite(const char * Characters, const unsigned int width, const unsigned int height)
{
	Buffer = new CHAR_INFO[height*width];
	for (unsigned int i = 0; i < width * height; i++)
	{
		Buffer[i].Char.AsciiChar = Characters[i];
	}

	Size = Vec2(width, height);
}

Sprite::Sprite(const Sprite & a)
{
	Size = a.Size;
	Position = a.Position;
	Buffer = new CHAR_INFO[a.Size.X * a.Size.Y];
	std::memcpy(Buffer, a.Buffer, (a.Size.X * a.Size.Y));
}

Sprite::~Sprite()
{
	if (Buffer != nullptr)
	{
		delete[] Buffer;
	}
}

void Sprite::SetSprite(const char * Characters, const unsigned int width, const unsigned int height)
{

	Buffer = new CHAR_INFO[height*width];
	for (unsigned int i = 0; i < width * height; i++)
	{
		Buffer[i].Char.AsciiChar = Characters[i];
		//Buffer[i].Attributes
	}

	Size = Vec2(width, height);
}

COORD Sprite::GetPosition() const
{
	return Position;
}

COORD Sprite::GetSize() const
{
	return Size;
}

void Sprite::SetPosition(const unsigned int newX, const unsigned int newY)
{
	Position = Vec2(newX, newY);
}

CHAR_INFO * Sprite::GetBuffer()
{
	return Buffer;
}
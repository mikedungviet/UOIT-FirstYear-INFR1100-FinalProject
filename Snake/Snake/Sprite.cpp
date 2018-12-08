#include "Sprite.h"
#include "Timer.h"
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
	if (Buffer != nullptr)
	{
		delete[] Buffer;
	}

	Size = a.Size;
	Position = a.Position;
	Buffer = new CHAR_INFO[a.Size.X * a.Size.Y];
	std::memcpy(Buffer, a.Buffer, sizeof(CHAR_INFO) * Size.X * Size.Y);
}

Sprite::~Sprite()
{
	if (Buffer != nullptr)
	{
		delete[] Buffer;
	}
}

void Sprite::SetSprite(const char * Characters, const unsigned int width, const unsigned int height, const unsigned int colour)
{
	if (Buffer != nullptr)
	{
		delete[] Buffer;
	}

	Buffer = new CHAR_INFO[height*width];
	for (unsigned int i = 0; i < width * height; i++)
	{
		Buffer[i].Char.AsciiChar = Characters[i];
		Buffer[i].Attributes = colour;
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
	Position.X = newX;
	Position.Y = newY;
}

CHAR_INFO * Sprite::GetBuffer()
{
	return Buffer;
}

PixelSprite::PixelSprite(const unsigned int width, const unsigned int height, const unsigned int colour)
{
	char* temp = new char[width*height];
	for (int i = 0; i < width*height; i++)
	{
		temp[i] = 219;
	}
	SetSprite(temp, width, height, colour);
	delete[] temp;
}

AnimatedPixelSprite::AnimatedPixelSprite()
{
	
}

void AnimatedPixelSprite::setRateofAnimation(const float Rate)
{
	RateOfAnimation = Rate;
}

void AnimatedPixelSprite::setRateofAnimation(const unsigned int Rate)
{
	RateOfAnimation = (float)Rate / 1000.0f;
}

void AnimatedPixelSprite::AddSprite(PixelSprite *sprite)
{
	animationCollection.push_back(sprite);
}

PixelSprite* AnimatedPixelSprite::getAnimation()
{
	//add the recent time to the total
	total += Timer::GetDeltaTime();

	//check to see if total is greater than the last + rate of animaiton
	if (total > last + RateOfAnimation)
	{
		last = total;
		//move to next animation
		CurrentAnimation++;
		//if animation is at the end bring it back to the beginning
		if (CurrentAnimation == animationCollection.size())
		{
			CurrentAnimation = 0;
		}
	}
	return animationCollection[CurrentAnimation];
}

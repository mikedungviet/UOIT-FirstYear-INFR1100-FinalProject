#include "Input.h"
#include "Sprite.h"
#include "Apple.h"
#include "Events.h"
#include "Timer.h"
#include "TextWindow.h"
#include "Vector2.h"
#include "Snake.h"
#include <iostream>


int main()
{

	Snake snake(8, 8, 6);
	while (true)
	{
		if (isEvent(Events::Escape))
		{
			break;
		}
		//Left
		if (isEvent(Events::A))
		{
			snake.movingLeft = true;
		}
		//Right
		else if (isEvent(Events::D))
		{
			snake.movingRight = true;
		}
		//Down
		else if (isEvent(Events::S))
		{
			snake.movingDown = true;
		}
		//Up
		else if (isEvent(Events::W))
		{
			snake.movingUp = true;
		}
	}


	Timer::InitDeltaTime();

	TextWindow tw(600, 800);
	PixelSprite mySprite(4, 4, 6);
	PixelSprite mySprite2(20, 20, 8);
	mySprite.SetPosition(mySprite.GetPosition().X + 5, mySprite.GetPosition().Y);
	AnimatedPixelSprite aps;
	aps.AddSprite(mySprite2);
	aps.setRateofAnimation(0.1f);
	tw.ResizeWindow(800, 600);

	while (true)
	{
		Timer::CalculateDeltaTime();
		aps.AddSprite(mySprite);
		mySprite.SetPosition(mySprite.GetPosition().X + 5, mySprite.GetPosition().Y);
		tw.RenderSprite(aps.getAnimation());
		tw.SwapBackBuffers();
	}
	return 0;
	system("pause");

	return 0;
}
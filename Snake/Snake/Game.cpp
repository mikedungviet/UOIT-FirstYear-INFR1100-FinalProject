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
	Snake snake;


	Timer::InitDeltaTime();

	TextWindow tw(0, 0);
	//PixelSprite mySprite(4, 4, 6);
	//PixelSprite mySprite2(20, 20, 8);

	PixelSprite *mySprite = new PixelSprite(4, 4, 6);
	PixelSprite *mySprite2 = new PixelSprite(20, 20, 8);
	//mySprite.SetPosition(mySprite.GetPosition().X + 5, mySprite.GetPosition().Y);
	
	int tempX = 0;
	int tempY = 0;
	mySprite->SetPosition(tempX + 1, tempY);

	AnimatedPixelSprite aps;
	aps.AddSprite(mySprite2);
	aps.setRateofAnimation(0.01f);
	tw.ResizeWindow(0, 0);

	while (true)
	{
		Timer::CalculateDeltaTime();
		mySprite->SetPosition(mySprite->GetPosition().X + 1, mySprite->GetPosition().Y);
		aps.AddSprite(mySprite);
		tw.RenderSprite(aps.getAnimation());
		tw.SwapBackBuffers();

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
			tempX += 50;
		}
		//Down
		else if (isEvent(Events::S))
		{
			snake.movingDown = true;
			tempY++;
		}
		//Up
		else if (isEvent(Events::W))
		{
			snake.movingUp = true;
		}

		aps.AddSprite(mySprite);
		tw.RenderSprite(aps.getAnimation());
		tw.SwapBackBuffers();
	}
	return 0;
	system("pause");

	return 0;
}
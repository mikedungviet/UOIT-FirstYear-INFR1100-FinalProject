#include "Input.h"
#include "Sprite.h"
#include "Apple.h"
#include "Events.h"
#include "TextWindow.h"
#include "Vector2.h"
#include "Snake.h"
#include <iostream>


int main()
{

	Snake* snake();
	std::cout << snake->headPosition.x;
	while (true)
	{
		if (isEvent(Events::Escape))
		{
			break;
		}
		//Left
		if (isEvent(Events::A))
		{
			snake->movingLeft = true;
		}
		//Right
		else if (isEvent(Events::D))
		{
			snake->movingRight = true;
		}
		//Down
		else if (isEvent(Events::S))
		{
			snake->movingDown = true;
		}
		//Up
		else if (isEvent(Events::W))
		{
			snake->movingUp = true;
		}
	}
	system("pause");

	return 0;
}
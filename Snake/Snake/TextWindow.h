#pragma once
#include <windows.h>
#include "Sprite.h"

class Sprite;

class TextWindow
{
public:
	//constructors
	TextWindow();
	//specified size of buffer for console
	TextWindow(unsigned int width, unsigned int height);

	void ResizeScreenBuffers(unsigned int width, unsigned int height);
	void RenderSprite(Sprite *a);

	void ResizeWindow(const unsigned int width, unsigned int height);
	void SwapBackBuffers();

	


private:
	void ClearBackBufferScreen();
	//windows handle to things
	//used to access api variables
	HANDLE Buffer[2];
	//going to keep track of current buffer
	bool CurrentBuffer = false;
	COORD windowSize;
};
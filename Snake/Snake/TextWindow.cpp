#include "TextWindow.h"
#include "Vec2.h"

//struct Vec2 : public _COORD
//{
//	Vec2(unsigned newX =0, unsigned newY =0)
//	{
//		X = newX;
//		Y = newY;
//	}
//};

TextWindow::TextWindow()
{
	Buffer[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	Buffer[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
}

TextWindow::TextWindow(unsigned int width, unsigned int height) : TextWindow()
{
	ResizeScreenBuffers(width, height);
}

void TextWindow::ResizeScreenBuffers(unsigned int width, unsigned int height)
{
	windowSize = Vec2(width, height);
	SetConsoleScreenBufferSize(Buffer[0], windowSize);
	SetConsoleScreenBufferSize(Buffer[1], windowSize);
}

void TextWindow::RenderSprite(Sprite *a)
{
	SMALL_RECT TempRect;
	TempRect.Bottom = a->GetPosition().Y + a->GetSize().Y;
	TempRect.Left = a->GetPosition().X;
	TempRect.Right = a->GetPosition().X + a->GetSize().X;
	TempRect.Top = a->GetPosition().Y;
	WriteConsoleOutputA(Buffer[(int)!CurrentBuffer], a->GetBuffer(), a->GetSize(), Vec2(0, 0), &TempRect);
}

void TextWindow::ResizeWindow(const unsigned int width, unsigned int height)
{
	//cells 8x8 pixels
	SMALL_RECT temp;
	temp.Top = 0;
	temp.Left = 0;
	temp.Right = width / 8;
	temp.Bottom = height / 8;
	//sets info for window
	SetConsoleWindowInfo(GetConsoleWindow(), true, &temp);
}

void TextWindow::SwapBackBuffers()
{
	CurrentBuffer = !CurrentBuffer;
	SetConsoleActiveScreenBuffer(Buffer[CurrentBuffer]);
}

void TextWindow::ClearBackBufferScreen()
{
	DWORD USELESS;
	FillConsoleOutputCharacterA(Buffer[!CurrentBuffer], ' ', windowSize.X * windowSize.Y, Vec2(0, 0), &USELESS);
	FillConsoleOutputAttribute(Buffer[!CurrentBuffer], 0x0000, windowSize.X * windowSize.Y, Vec2(0, 0), &USELESS);
}

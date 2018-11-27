#include "TextWindow.h"
#include "Vector2.h"

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
	SetConsoleScreenBufferSize(Buffer[0], Vec2(width, height));
	SetConsoleScreenBufferSize(Buffer[1], Vec2(width, height));

}

void TextWindow::RenderSprite(Sprite a)
{
	SMALL_RECT TempRect;
	TempRect.Bottom = a.GetPosition().Y + a.GetSize().Y;
	TempRect.Bottom = a.GetPosition().X;
	TempRect.Right = a.GetPosition().X + a.GetSize().X;
	TempRect.Top = a.GetPosition().Y;
	WriteConsoleOutputA(Buffer[!CurrentBuffer], a.GetBuffer(), a.GetSize(), Vec2(0, 0), &TempRect);
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

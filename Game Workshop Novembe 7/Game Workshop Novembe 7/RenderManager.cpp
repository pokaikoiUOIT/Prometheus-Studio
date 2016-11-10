#include "RenderManager.h" 
#include <iostream>

RenderManager::RenderManager()
{
	FrameBuffers[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, FILE_SHARE_WRITE | FILE_SHARE_READ, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	FrameBuffers[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, FILE_SHARE_WRITE | FILE_SHARE_READ, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	startPoint.X = 0;
	startPoint.Y = 0; 
	currentBuffer = false;

}

RenderManager::~RenderManager() {}

void RenderManager::swapBuffers()
{
	SetConsoleActiveScreenBuffer(FrameBuffers[currentBuffer]);
	currentBuffer = !currentBuffer; 
}


void RenderManager::renderSprite(Sprite s)
{
	SMALL_RECT temp;
	temp.Top = s.Position.Y;
	temp.Left = s.Position.X; 
	temp.Bottom = s.Position.Y + s.SpriteSize.Y;
	temp.Right = s.Position.X + s.SpriteSize.X;

	WriteConsoleOutputA(FrameBuffers[currentBuffer], s.Buffer, s.SpriteSize, s.AnimationPosition, &temp);
}

void RenderManager::clearScreen()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD conSize; 
	DWORD charsWritten; 
	GetConsoleScreenBufferInfo(FrameBuffers[currentBuffer], &csbi);
	conSize = csbi.dwSize.X * csbi.dwSize.Y; 
#ifdef _DEBUG 
	if (!FillConsoleOutputCharacter(FrameBuffers[currentBuffer], (TCHAR) ' ', conSize, startPoint, &charsWritten))
	{
		std::cout << "Error Clearing framebuffer " << currentBuffer << std::endl; //returns true (worked) or false (false)
	}
	if (!FillConsoleOutputAttribute(FrameBuffers[currentBuffer], csbi.wAttributes, conSize, startPoint, &charsWritten))
	{
		std::cout << "Error Clearing Framebuffer Attributes " << currentBuffer << std::endl; 
	}
#else
	FillConsoleOutputCharacter(FrameBuffers[currentBuffer], (TCHAR) ' ', conSize, startPoint, &charsWritten);
	FillConsoleOutputAttribute(FrameBuffers[currentBuffer], csbi.wAttributes, conSize, startPoint, &charsWritten);
#endif
}

void RenderManager::setSize(COORD size)
{

	SetConsoleScreenBufferSize(FrameBuffers[0], size);
	SetConsoleScreenBufferSize(FrameBuffers[1], size);
}
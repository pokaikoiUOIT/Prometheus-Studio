#include "Sprite.h"

Sprite::Sprite()
{
	Position.X = 0;
	Position.Y = 0;
	AnimationPosition.X = 0;
	AnimationPosition.Y = 0;
	SpriteSize.X = 3; 
	SpriteSize.Y = 3;
	Buffer = new CHAR_INFO[9];

	Buffer[0].Char.AsciiChar = 'A';
	Buffer[0].Attributes = FOREGROUND_GREEN | BACKGROUND_BLUE; 
	Buffer[1].Char.AsciiChar = 'B';
	Buffer[1].Attributes = FOREGROUND_RED;
	Buffer[2].Char.AsciiChar = 'B';
	Buffer[2].Attributes = FOREGROUND_GREEN;
	Buffer[3].Char.AsciiChar = 'C';
	Buffer[3].Attributes = FOREGROUND_GREEN;
	Buffer[4].Char.AsciiChar = 'A';
	Buffer[4].Attributes = FOREGROUND_GREEN | BACKGROUND_BLUE;
	Buffer[5].Char.AsciiChar = 'B';
	Buffer[5].Attributes = FOREGROUND_RED; 
	Buffer[6].Char.AsciiChar = 'B';
	Buffer[6].Attributes = FOREGROUND_GREEN;
	Buffer[7].Char.AsciiChar = 'C';
	Buffer[7].Attributes = FOREGROUND_GREEN;
	Buffer[8].Char.AsciiChar = 'C';
	Buffer[8].Attributes = FOREGROUND_GREEN | BACKGROUND_BLUE;
}

Sprite::~Sprite(){}
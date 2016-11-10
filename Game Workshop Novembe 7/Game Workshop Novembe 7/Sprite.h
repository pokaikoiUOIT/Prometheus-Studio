#ifndef __SPRITE_H__
#define __SPRITE_H__
#include "windows.h"

class Sprite
{
public:
	Sprite();
	~Sprite();
	COORD SpriteSize;
	COORD AnimationPosition;
	COORD Position;
	CHAR_INFO *Buffer; 
};

#endif

#ifndef __RENDER_MANAGER___
#define __RENDER_MANAGER_H__
#include "Sprite.h"

class RenderManager
{
public:
	RenderManager();
	~RenderManager();
	void swapBuffers();
	void renderSprite(Sprite s);
	void clearScreen();
	void setSize(COORD size);
private:
	HANDLE FrameBuffers[2]; 
	bool currentBuffer;
	COORD startPoint; 
};
#endif
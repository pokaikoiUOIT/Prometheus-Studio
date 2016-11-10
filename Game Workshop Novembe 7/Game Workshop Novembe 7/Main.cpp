#include "RenderManager.h" 

RenderManager RM;
Sprite s; 
Sprite s2;

int main()
{
	bool check = true; 
	s2.Position.X = 7;
	while (true)
	{
		if (check)
		{
			if (s2.Position.X < 15)
			{
				s2.Position.X++;
			}
			else
			{
				s2.Position.X--;
			}
		}
		RM.clearScreen();
		RM.renderSprite(s);
		RM.renderSprite(s2);
		RM.swapBuffers();
	}
	return 0;
}
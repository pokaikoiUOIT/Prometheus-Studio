#include "spritelib/spritelib.h"

#include <fstream>
#include <streambuf>
#include <vector>
#include <iostream>

using namespace spritelib;
using namespace std;

// Let's create some sprites!
Sprite background1,
background2,
background_grass1,
background_grass2,
background_treehill1,
background_treehill2;
// A vector container to hold all of the sprites we want to draw
std::vector<Sprite*> spritesToDraw;

// Back to front selection sort, to solve the depth issues with transparent sprites
void IterativeSelectionSort(std::vector<Sprite*>& a_sprites);
// Let's move him around the screen
void UpdateHaggar(Sprite &a_sprite);
// A scrolling background function
void HorizontalScroll(Sprite &a_sprite, float speed);

void KeyboardFunc(Window::Key a_key, Window::EventType a_eventType)
{
	switch (a_eventType)
	{
	case Window::EventType::KeyPressed:
	{
		if (a_key == Window::Key::Escape)
		{
			std::cout << "Escape was pressed!" << std::endl;
			exit(1);
		}
	}
		break;
	case Window::EventType::KeyReleased:
	{

	}
		break;
	}
}

void MouseFunc(Window::Button a_button, int a_mouseX, int a_mouseY, Window::EventType a_eventType)
{
	switch (a_eventType)
	{
	case Window::EventType::MouseMoved:
	{
		// When the mouse is moved, the ninja will follow it
		//animatedSprite2.set_position(a_mouseX, a_mouseY);
	}
		break;
	case Window::EventType::MouseButtonReleased:
	{

	}
		break;
	}
}

void Update()
{
	// Let's move hagger to the right, wrap around the screen, and rotate
	//animatedSprite.next_frame();
	//animatedSprite2.next_frame();


	//background(backound, speed); - set speed here
	HorizontalScroll(background1, 0.25f);
	HorizontalScroll(background2, 0.25f);
	HorizontalScroll(background_treehill1, 0.75f);
	HorizontalScroll(background_treehill2, 0.75f);
	HorizontalScroll(background_grass1, 1.0f);
	HorizontalScroll(background_grass2, 1.0f);
}

void DrawSprites()
{
	// IMPORTANT: Sprites NEED to be drawn from back to front! This is one sorting algorithm you could use
	IterativeSelectionSort(spritesToDraw);
	// https://hub.jmonkeyengine.org/t/alpha-transparency-sorting-your-z-buffer-and-you/33709

	/* we could just do the following to draw the four sprites
	but that would be silly since we have a list of sprites to draw
	stored, so all we need to do is go through the list and draw eaach
	sprite in the list */
	/* // silly way
	background.draw();
	donkeyKong.draw();
	ninja.draw();
	hagger.draw();
	*/

	// Let's draw each sprite
	for (auto itr = spritesToDraw.begin(), itrEnd = spritesToDraw.end(); itr != itrEnd; itr++)
		(*itr)->draw();
}

void DrawPrimitives()
{
	/* draw line */
	Shapes::set_line_width(5.0f);
	Shapes::set_color(1.0f, 0.0f, 0.0f);
	Shapes::draw_line(100, 100, 200, 200);
	Shapes::set_line_width(1.0f);

	/* draw rectangle */
	Shapes::set_color(1.0f, 1.0f, 0.0f);
	Shapes::draw_rectangle(true, 200, 200, 50, 50, 45.0f);

	/* draw circle */
	Shapes::set_line_width(5.0f);
	Shapes::set_color(0.0f, 1.0f, 1.0f);
	Shapes::draw_circle(false, 50, 200, 200);
	Shapes::draw_circle(true, 50, 500, 200);
	Shapes::set_line_width(1.0f);

	/* draw triangle */
	Shapes::set_color(0.5f, 0.0f, 0.5f);
	Shapes::draw_triangle(true, 100, 100, 200, 200, 300, 100);

	// Draw Hello World in Times New Roman
	Text::set_color(1.0f, 1.0f, 1.0f);
	Text::draw_string("HELLO WORLD", "TimesNewRoman", 200.0f, 200.0f);
}

int main()
{
	// Let's make a game window. use the static function get_game_window to get a handle to the main game window
	Window& theGame = Window::get_game_window(); // This is a singleton, useful for managing one window https://en.wikipedia.org/wiki/Singleton_pattern
	theGame.init("MY GAME", 1600, 900)
		.set_screen_size(500, 281)
		.set_keyboard_callback(KeyboardFunc)
		.set_mouse_callback(MouseFunc)
		.set_clear_color(0, 255, 0);
	Text::load_font("assets/times.ttf", "TimesNewRoman");

	// Let's load in the sprites
	background1.load_sprite_image("assets/images/background.png")
		.set_scale(500, 281);
	background2.load_sprite_image("assets/images/background.png")
		.set_scale(500, 281)
		.set_position(500.0f,0.0f);
	background_treehill1.load_sprite_image("assets/images/background_treehill.png")
		.set_scale(500, 162);
	background_treehill2.load_sprite_image("assets/images/background_treehill.png")
		.set_scale(500, 162)
		.set_position(500.0f, 0.0f);
	background_grass1.load_sprite_image("assets/images/background_treehill.png")
		.set_scale(500.0f, 41);
	background_grass1.load_sprite_image("assets/images/background_treehill.png")
		.set_scale(500, 41);
	background_grass1.load_sprite_image("assets/images/background_grass.png")
		.set_scale(500.0f, 41);
	background_grass2.load_sprite_image("assets/images/background_grass.png")
		.set_scale(500, 41)
		.set_position(500.0f, 0.0f);
	// Let's add them to our vector container
	spritesToDraw.push_back(&background1);
	spritesToDraw.push_back(&background2);
	spritesToDraw.push_back(&background_treehill1);
	spritesToDraw.push_back(&background_treehill2);
	spritesToDraw.push_back(&background_grass1);
	spritesToDraw.push_back(&background_grass2);
	// IMPORTANT: This is how spritelib 2.0 handles the main game loop
	while (theGame.update(30))
	{
		// You can put movement code inside of this update function, it is called every frame
		Update();
		
		// You can put sprite drawing code inside of this draw function
		DrawSprites();

		// You can put primitives in here. These draw on top of all of the sprites
		/*DrawPrimitives();*/
	}

	return 0;
}

// Back to front selection sort, to solve the depth issues with transparent sprites
// https://en.wikipedia.org/wiki/Selection_sort
void IterativeSelectionSort(std::vector<Sprite*>& a_sprites)
{
	for (unsigned int i = 0; i < a_sprites.size(); i++)
	{
		int minIndex = i;
		for (unsigned int j = i; j < a_sprites.size(); j++)
		{
			if (a_sprites[j]->get_depth() < a_sprites[minIndex]->get_depth())
			{
				minIndex = j;
			}
		}
		std::swap(a_sprites[minIndex], a_sprites[i]);
	}
}

// Code to move our character around the screen, and spin counter-clockwise
//void UpdateHaggar(Sprite &a_sprite)
//{
//	math::Vector3 position = a_sprite.get_position();
//	float rotation = a_sprite.get_rotataion();
//
//	position.x += 5.0f;
//	if (position.x > 800) position.x = 0;
//
//	rotation += 1.0f; // increment orientation 1 degree/frame
//
//	a_sprite.set_position(position.x, position.y);
//	a_sprite.set_rotation(rotation);
//}

void HorizontalScroll(Sprite &a_sprite, float speed)
{
	float scrollingSpeed = speed;

	// update our x position by scrollingSpeed pixels
	a_sprite.set_position(a_sprite.get_position().x - scrollingSpeed, a_sprite.get_position().y);

	// check if we've gone too far
	//if (a_sprite.get_position().x + a_sprite.get_scale().x > Window::get_game_window().get_width(true))
	//{
	//	a_sprite.set_position(Window::get_game_window().get_width(true) + a_sprite.get_scale().x, a_sprite.get_position().y);
	//}
	if(a_sprite.get_position().x + a_sprite.get_scale().x < 0)
	{
		a_sprite.set_position(Window::get_game_window().get_width(true) - 1.0f, a_sprite.get_position().y);
	}
}
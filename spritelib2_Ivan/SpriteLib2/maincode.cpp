//#include "spritelib/spritelib.h"
//
//#include <fstream>
//#include <streambuf>
//#include <vector>
//#include <iostream>
//
//using namespace spritelib;
//using namespace std;
//
//// Let's create some sprites!
//Sprite background, animatedSprite, animatedSprite2, testSprite;
//// A vector container to hold all of the sprites we want to draw
//std::vector<Sprite*> spritesToDraw;
//
//// Back to front selection sort, to solve the depth issues with transparent sprites
//void IterativeSelectionSort(std::vector<Sprite*>& a_sprites);
//// Let's move him around the screen
//void UpdateHaggar(Sprite &a_sprite);
//// A scrolling background function
//void HorizontalScroll(Sprite &a_sprite);
//
//void KeyboardFunc(Window::Key a_key, Window::EventType a_eventType)
//{
//	switch (a_eventType)
//	{
//	case Window::EventType::KeyPressed:
//	{
//		if (a_key == Window::Key::Escape)
//		{
//			std::cout << "Escape was pressed!" << std::endl;
//		}
//	}
//	break;
//	case Window::EventType::KeyReleased:
//	{
//
//	}
//	break;
//	}
//}
//
//void MouseFunc(Window::Button a_button, int a_mouseX, int a_mouseY, Window::EventType a_eventType)
//{
//	switch (a_eventType)
//	{
//	case Window::EventType::MouseMoved:
//	{
//		// When the mouse is moved, the ninja will follow it
//		animatedSprite2.set_position(a_mouseX, a_mouseY);
//	}
//	break;
//	case Window::EventType::MouseButtonReleased:
//	{
//
//	}
//	break;
//	}
//}
//
//void Update()
//{
//	// Let's move hagger to the right, wrap around the screen, and rotate
//	UpdateHaggar(testSprite);
//	animatedSprite.next_frame();
//	animatedSprite2.next_frame();
//	HorizontalScroll(background);
//}
//
//void DrawSprites()
//{
//	// IMPORTANT: Sprites NEED to be drawn from back to front! This is one sorting algorithm you could use
//	IterativeSelectionSort(spritesToDraw);
//	// https://hub.jmonkeyengine.org/t/alpha-transparency-sorting-your-z-buffer-and-you/33709
//
//	/* we could just do the following to draw the four sprites
//	but that would be silly since we have a list of sprites to draw
//	stored, so all we need to do is go through the list and draw eaach
//	sprite in the list */
//	/* // silly way
//	background.draw();
//	donkeyKong.draw();
//	ninja.draw();
//	hagger.draw();
//	*/
//
//	// Let's draw each sprite
//	for (auto itr = spritesToDraw.begin(), itrEnd = spritesToDraw.end(); itr != itrEnd; itr++)
//		(*itr)->draw();
//}
//
//void DrawPrimitives()
//{
//	/* draw line */
//	Shapes::set_line_width(5.0f);
//	Shapes::set_color(1.0f, 0.0f, 0.0f);
//	Shapes::draw_line(100, 100, 200, 200);
//	Shapes::set_line_width(1.0f);
//
//	/* draw rectangle */
//	Shapes::set_color(1.0f, 1.0f, 0.0f);
//	Shapes::draw_rectangle(true, 200, 200, 50, 50, 45.0f);
//
//	/* draw circle */
//	Shapes::set_line_width(5.0f);
//	Shapes::set_color(0.0f, 1.0f, 1.0f);
//	Shapes::draw_circle(false, 50, 200, 200);
//	Shapes::draw_circle(true, 50, 500, 200);
//	Shapes::set_line_width(1.0f);
//
//	/* draw triangle */
//	Shapes::set_color(0.5f, 0.0f, 0.5f);
//	Shapes::draw_triangle(true, 100, 100, 200, 200, 300, 100);
//
//	// Draw Hello World in Times New Roman
//	Text::set_color(1.0f, 1.0f, 1.0f);
//	Text::draw_string("HELLO WORLD", "TimesNewRoman", 200.0f, 200.0f);
//}
//
//int main()
//{
//	// Let's make a game window. use the static function get_game_window to get a handle to the main game window
//	Window& theGame = Window::get_game_window(); // This is a singleton, useful for managing one window https://en.wikipedia.org/wiki/Singleton_pattern
//	theGame.init("MY GAME", 800, 432)
//		.set_screen_size(640, 432)
//		.set_keyboard_callback(KeyboardFunc)
//		.set_mouse_callback(MouseFunc)
//		.set_clear_color(0, 255, 0);
//	Text::load_font("assets/times.ttf", "TimesNewRoman");
//
//	// Let's load in the sprites
//	background.load_sprite_image("assets/images/map2.png")
//		.set_scale(1717, 432);
//
//	animatedSprite.load_sprite_image("assets/images/dkong2.png")
//		.set_scale(40, 80)
//		.set_sprite_frame_size(40, 80)
//		.set_position(300, 200)
//		//.push_frame_row("struggle", 0, 0, 40, 0, 7); <- this is the same as all the push_frame() functions below.
//		.push_frame("struggle", 0, 0)
//		.push_frame("struggle", 40, 0)
//		.push_frame("struggle", 80, 0)
//		.push_frame("struggle", 120, 0)
//		.push_frame("struggle", 160, 0)
//		.push_frame("struggle", 200, 0)
//		.push_frame("struggle", 240, 0)
//		.set_animation("struggle");
//
//	// now let's create a sprite that has multiple rows in the sheet 
//	// here, I'm assuming they are all equally spaced on X, and Y 
//	int numRows = 8;
//	animatedSprite2.load_sprite_image("assets/images/sprite_sheet_full.png")
//		.set_scale(160, 160)
//		.set_sprite_frame_size(160, 160)
//		.set_position(400, 200);
//
//	// set up the pixel x/y locations of each row
//	for (int i = 0; i < numRows; i++)
//	{
//		std::string id = "kung-fu_" + std::to_string(i);
//		unsigned int step = 160 * i;
//		animatedSprite2.push_frame_row(id, 0, step, 160, 0, 8);
//	}
//	animatedSprite2.set_animation("kung-fu_2");
//
//	testSprite.load_sprite_image("assets/images/HaggarSNEStransp.png")
//		.set_scale(63, 99)
//		.set_center(0.5f, 0.5f) // center of the sprites origin for rotation
//		.set_position(400.0f, 216.0f);
//
//	// Let's add them to our vector container
//	spritesToDraw.push_back(&background);
//	spritesToDraw.push_back(&animatedSprite);
//	spritesToDraw.push_back(&animatedSprite2);
//	spritesToDraw.push_back(&testSprite);
//
//	// IMPORTANT: This is how spritelib 2.0 handles the main game loop
//	while (theGame.update(30))
//	{
//		// You can put movement code inside of this update function, it is called every frame
//		Update();
//
//		// You can put sprite drawing code inside of this draw function
//		DrawSprites();
//
//		// You can put primitives in here. These draw on top of all of the sprites
//		DrawPrimitives();
//	}
//
//	return 0;
//}
//
//// Back to front selection sort, to solve the depth issues with transparent sprites
//// https://en.wikipedia.org/wiki/Selection_sort
//void IterativeSelectionSort(std::vector<Sprite*>& a_sprites)
//{
//	for (unsigned int i = 0; i < a_sprites.size(); i++)
//	{
//		int minIndex = i;
//		for (unsigned int j = i; j < a_sprites.size(); j++)
//		{
//			if (a_sprites[j]->get_depth() < a_sprites[minIndex]->get_depth())
//			{
//				minIndex = j;
//			}
//		}
//		std::swap(a_sprites[minIndex], a_sprites[i]);
//	}
//}
//
//// Code to move our character around the screen, and spin counter-clockwise
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
//
//void HorizontalScroll(Sprite &a_sprite)
//{
//	float scrollingSpeed = 10.0f;
//
//	// update our x position by scrollingSpeed pixels
//	a_sprite.set_position(a_sprite.get_position().x - scrollingSpeed, 0.0f);
//
//	// check if we've gone too far
//	if (a_sprite.get_position().x + a_sprite.get_scale().x < Window::get_game_window().get_width(true))
//	{
//		a_sprite.set_position(Window::get_game_window().get_width(true) - a_sprite.get_scale().x, 0.0f);
//	}
//}
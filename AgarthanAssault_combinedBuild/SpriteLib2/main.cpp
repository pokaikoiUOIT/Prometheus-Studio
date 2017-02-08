#include "spritelib/spritelib.h"

#include <fstream>
#include <streambuf>
#include <vector>
#include <iostream>
#include<math.h>
#include<Box2d\Box2D.h>
#include<time.h>
#define PI 3.14159265


using namespace spritelib;
using namespace std;

//time attack
clock_t start;
clock_t end;

// Let's create some sprites!
Sprite player, playerBox, flyingBox,bullet1,mouse, topboundS1, topboundS2, logS, trapS,
background1,
background2,
background_grass1,
background_grass2,
background_treehill1,
background_treehill2;
// A vector container to hold all of the sprites we want to draw
std::vector<Sprite*> spritesToDraw;
// Let's move him around the screen
void UpdatePlayer(Sprite &a_sprite);
void UpdatePlayerBox(Sprite &a_sprite);
void UpdateflyingBox(Sprite &a_sprite);
void Updatebullet(Sprite &a_sprite);
void Updatelog(Sprite &a_sprite);
void Updatetrap(Sprite &a_sprite);

// A scrolling background function
void HorizontalScroll(Sprite &a_sprite, float speed);

// Back to front selection sort, to solve the depth issues with transparent sprites
void IterativeSelectionSort(std::vector<Sprite*>& a_sprites);

float positionbulletx, positionbullety, t_angle(0);
float positionbox1, positionbox2;
float positionbox3, positionbox4;
float playerpositionbox1, playerpositionbox2;
float speedx(0), speedy(0);
float rotation = player.get_rotataion(), acceleration(2.5);
double time2(0);
int counter3;
string speedxString(""), speedyString("");



//math::Vector3 position = player.get_position();

void KeyboardFunc(Window::Key a_key, Window::EventType a_eventType)
{
	math::Vector3 position = player.get_position();
	
	
	//float rotation = player.get_rotataion(), acceleration(0);
	int rotationInt(0);

	//player.set_position(position.x, position.y);

	switch (a_eventType)
	{
	case Window::EventType::KeyPressed:
	{
		if (a_key == Window::Key::Escape)
		{
			std::cout << "Escape was pressed!" << std::endl;
			exit(1);
		}

		if (a_key == Window::Key::W)//up
		{

			position.y +=  acceleration;
			player.set_position(position.x, position.y);
			playerpositionbox1 = position.x;
			playerpositionbox2 = position.y;
		}

		if (a_key == Window::Key::S)//down
		{
			position.y -= acceleration;
			player.set_position(position.x, position.y);
			playerpositionbox1 = position.x;
			playerpositionbox2 = position.y;

		}
		if (a_key == Window::Key::A)//left
		{
			position.x -= acceleration;
			player.set_position(position.x, position.y);
			playerpositionbox1 = position.x;
			playerpositionbox2 = position.y;
		}
		if (a_key == Window::Key::D)//right
		{
			position.x += acceleration;
			player.set_position(position.x, position.y);
			playerpositionbox1 = position.x;
			playerpositionbox2 = position.y;
		}
		if (a_key == Window::Key::P)//up
		{
			bullet1.load_sprite_image("assets/images/bullet.png")
				.set_scale(20, 20)
				.set_center(0.5f, 0.5f)
				.set_sprite_frame_size(20, 20)
				.set_rotation(0)
				.set_position(position.x, position.y);
			// if it hits replace with transparent image
			
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
		//mouse.set_position(a_mouseX, a_mouseY);
	}
		break;
	case Window::EventType::MouseButtonReleased:
	{
		//float dot(0), det(0), A, B;
		////t_angle(0)
		//
		////dot = ((playerpositionbox1*a_mouseX) + (playerpositionbox2*a_mouseY));
		////det = ((playerpositionbox1*a_mouseY) - (playerpositionbox2*a_mouseX));
		////t_angle = atan2(det,dot)*180/PI;
		////t_angle = atan2(det,dot);
		////cout << playerpositionbox1 <<"  "<< a_mouseX << "  "<< dot << det<< angle << endl;
		////cout << playerpositionbox1 << endl;
		////cout << playerpositionbox2 << endl;
		////cout << a_mouseX << endl;
		////cout << a_mouseY << endl;
		//
		//dot = (playerpositionbox1*a_mouseX) + (playerpositionbox2*a_mouseY);
		//A = (playerpositionbox1*playerpositionbox1) + (playerpositionbox2*playerpositionbox2);
		//B = (a_mouseX*a_mouseX) + (a_mouseY*a_mouseY);
		//t_angle = acos(dot/sqrt(A*B));
		//t_angle = (t_angle * 180) / PI;
		//cout << t_angle << endl;
		//
		//bullet.load_sprite_image("assets/images/playerSprite.png")
		//	.set_scale(20, 20)
		//	.set_center(0.5f, 0.5f)
		//	.set_sprite_frame_size(20, 20)
		//	//.set_rotation(90)
		//	.set_position(playerpositionbox1, playerpositionbox2);
		//// if it hits replace with transparent image
	}
		break;
	}
}

void Update()
{
	// Let's move hagger to the right, wrap around the screen, and rotate
	UpdatePlayer(player);
	UpdatePlayerBox(playerBox);
	UpdateflyingBox(flyingBox);
	Updatebullet(bullet1);
	Updatelog(logS);
	Updatetrap(trapS);

	//background(backound, speed); - set speed here
	HorizontalScroll(background1, 0.25f);
	HorizontalScroll(background2, 0.25f);
	HorizontalScroll(background_treehill1, 0.75f);
	HorizontalScroll(background_treehill2, 0.75f);
	HorizontalScroll(background_grass1, 1.0f);
	HorizontalScroll(background_grass2, 1.0f);
	HorizontalScroll(topboundS1, 1.0f);
	HorizontalScroll(topboundS2, 1.0f);
}

void DrawSprites()
{
	IterativeSelectionSort(spritesToDraw);
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
	// Draw Hello World in Times New Roman
	//Text::draw_string(speedxString, "TimesNewRoman", 200.0, 200.0f);
	//Text::draw_string(speedyString, "TimesNewRoman", 150.0, 150.0f);
}


int main()
{
	// Let's make a game window. use the static function get_game_window to get a handle to the main game window
	Window& theGame = Window::get_game_window(); // This is a singleton, useful for managing one window https://en.wikipedia.org/wiki/Singleton_pattern

	clock_t start = clock();//time shiit
	
	theGame.init("MY GAME", 1600, 900)
		.set_screen_size(500, 281)
		.set_keyboard_callback(KeyboardFunc)
		.set_mouse_callback(MouseFunc)
		.set_clear_color(155, 0, 255);
	Text::load_font("assets/times.ttf", "TimesNewRoman");

	////creating gravotyour box2d world
	////defien gravity vector
	//b2Vec2 gravity(0.0f, -9.8f);
	////create the world object
	//b2World world(gravity);
	////setting the gorund
	//b2BodyDef groundBodyDef;
	//groundBodyDef.position.Set(0.0f, -10.0f);
	//b2Body* groundBody = world.CreateBody(&groundBodyDef);
	//
	////
	//b2PolygonShape groundBox;
	//groundBox.SetAsBox(600.0f, 10.0f);
	//groundBody->CreateFixture(&groundBox, 0.0f);

	//groundbody
	b2Vec2 gravity(0.0f, 0.0f);
	b2World world(gravity);
	b2BodyDef groundBodyDef;
	groundBodyDef.position.Set(0.0f, -10.0f);
	b2Body* groundBody = world.CreateBody(&groundBodyDef);
	b2PolygonShape groundBox;
	groundBox.SetAsBox(600.0f, 10.0f);
	groundBody->CreateFixture(&groundBox, 0.0f);
	
	b2BodyDef bd;
	bd.position.Set(40.0f,162.f);
	bd.type = b2_dynamicBody;
	b2Body* solid = world.CreateBody(&bd);
	b2PolygonShape sqaure;
	sqaure.SetAsBox(40.0f,12.5f);
	b2FixtureDef fd;
	fd.shape = &sqaure;
	fd.density = 20.0f;
	solid->CreateFixture(&fd);

	b2BodyDef bdp;
	bdp.position.Set(400.0f, 400.0f);
	bdp.type = b2_dynamicBody;
	b2Body* hollow = world.CreateBody(&bdp);
	b2PolygonShape sqaurep;
	sqaurep.SetAsBox(10.0f, 10.0f);
	b2FixtureDef fdp;
	fdp.shape = &sqaurep;
	fdp.density = 20.0f;
	hollow->CreateFixture(&fdp);

	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(200.0f, 300.0f);
	b2Body* body = world.CreateBody(&bodyDef);
	b2PolygonShape dynamicBox;
	dynamicBox.SetAsBox(10.0f, 10.0f);
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &dynamicBox;
	fixtureDef.density = 1.0f;
	fixtureDef.friction = 1.0f;

	b2BodyDef bdpz;
	bdpz.position.Set(playerpositionbox1, playerpositionbox2);
	bdpz.type = b2_dynamicBody;
	b2Body* hollowz = world.CreateBody(&bdpz);
	b2PolygonShape sqaurepz;
	sqaurepz.SetAsBox(10.0f, 10.0f);
	b2FixtureDef fdpz;
	fdpz.shape = &sqaurepz;
	fdpz.density = 20.0f;
	hollowz->CreateFixture(&fdpz);

	b2BodyDef topboundbox;
	topboundbox.position.Set(0, 270);
	topboundbox.type = b2_dynamicBody;
	b2Body* topb = world.CreateBody(&topboundbox);
	b2PolygonShape topboxs;
	topboxs.SetAsBox(500.0f, 25.0f);
	b2FixtureDef topboxf;
	topboxf.shape = &topboxs;
	topboxf.density = 20.0f;
	topb->CreateFixture(&topboxf);

	b2BodyDef laserHP;
	laserHP.position.Set(trapS.get_position().x, trapS.get_position().y);
	laserHP.type = b2_dynamicBody;
	b2Body* laserc = world.CreateBody(&laserHP);
	b2PolygonShape laserboxs;
	laserboxs.SetAsBox(10, 120.0f);
	b2FixtureDef laserboxf;
	laserboxf.shape = &topboxs;
	laserboxf.density = 20.0f;
	laserc->CreateFixture(&laserboxf);

	body->CreateFixture(&fixtureDef);
	float32 timeStep = 1.0f / 60.0f;

	int32 velocityIterations = 6;
	int32 positionIterations = 2;


	math::Vector3 position2 = player.get_position();

	//for (int32 i = 0; i < 700; ++i){
	//world.Step(timeStep, velocityIterations, positionIterations);
	//b2Vec2 positionbox = body->GetPosition();
	//positionbox1 = positionbox.x;
	//positionbox2 = positionbox.y;
	//float32 anglebox = body->GetAngle();
	//printf("%4.2f %4.2f %4.2f\n", positionbox.x, positionbox.y, anglebox);
	//}


	player.load_sprite_image("assets/images/player.png")
		.set_scale(80, 25)
		.set_center(0.5f, 0.5f)
		.set_sprite_frame_size(80, 25)
		//.set_rotation(90)
		.set_position(40, 162);

	playerBox.load_sprite_image("assets/images/playerSprite.png")
		.set_scale(20, 20)
		.set_center(0.5f, 0.5f)
		.set_sprite_frame_size(20, 20)
		//.set_rotation(90)
		.set_position(200.0f,300.0f);

	flyingBox.load_sprite_image("assets/images/playerSprite.png")
		.set_scale(20, 20)
		.set_center(0.5f, 0.5f)
		.set_sprite_frame_size(20, 20)
		//.set_rotation(90)
		.set_position(400.0f, 400.0f);

	mouse.load_sprite_image("assets/images/blank.png")
		.set_scale(20, 20)
		.set_sprite_frame_size(20, 20)
		.set_center(0.5f, 0.5f)
		.set_position(0, 0);

	topboundS1.load_sprite_image("assets/images/topbound.png")
		.set_scale(500, 41)
		.set_position(0.0f, 240.0f);
	topboundS2.load_sprite_image("assets/images/topbound.png")
		.set_scale(500, 41)
		.set_position(500.0f, 240.0f);

	//log
	
	

	// Let's load in the sprites
	background1.load_sprite_image("assets/images/background.png")
		.set_scale(500, 281);
	background2.load_sprite_image("assets/images/background.png")
		.set_scale(500, 281)
		.set_position(500.0f, 0.0f);
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

	//background
	spritesToDraw.push_back(&background1);
	spritesToDraw.push_back(&background2);
	spritesToDraw.push_back(&background_treehill1);
	spritesToDraw.push_back(&background_treehill2);
	spritesToDraw.push_back(&background_grass1);
	spritesToDraw.push_back(&background_grass2);
	//objects
	spritesToDraw.push_back(&player);
	spritesToDraw.push_back(&playerBox);
	spritesToDraw.push_back(&flyingBox);
	spritesToDraw.push_back(&bullet1);
	spritesToDraw.push_back(&mouse);
	spritesToDraw.push_back(&topboundS1);
	spritesToDraw.push_back(&topboundS2);
	spritesToDraw.push_back(&logS);
	spritesToDraw.push_back(&trapS);

	// IMPORTANT: This is how spritelib 2.0 handles the main game loop
	while (theGame.update(60))
	{
		int seconds;

		//bool overlap = b2TestOverlap(fd.shape, 0, fdp.shape, 0, solid->GetTransform(), hollow->GetTransform());
		bool overlap = b2TestOverlap(fdp.shape, 0, fdpz.shape, 0, hollow->GetTransform(), hollowz->GetTransform());
		//bool overlaptop = b2TestOverlap(topboxf.shape, 0, fd.shape, 0, topb->GetTransform(), solid->GetTransform());
		//bool overlaplasergun = b2TestOverlap(laserboxf.shape, 0, fd.shape, 0, laserc->GetTransform(), solid->GetTransform());
		bool overlaplasergun = b2TestOverlap(laserboxf.shape, 0, fdpz.shape, 0, laserc->GetTransform(), hollowz->GetTransform());


		world.Step(timeStep, velocityIterations, positionIterations);
		b2Vec2 positionbox = body->GetPosition();
		float32 anglebox = body->GetAngle();
		positionbox1 = positionbox.x;
		positionbox2 = positionbox.y;

		solid->SetTransform(b2Vec2 (playerpositionbox1, playerpositionbox2), solid->GetAngle());
		b2Vec2 positionplayer = solid->GetPosition();

		b2Vec2 flypositionbox = hollow->GetPosition();
		float32 flyanglebox = hollow->GetAngle();
		positionbox3 = flypositionbox.x;
		positionbox4 = flypositionbox.y;

		hollowz->SetTransform(b2Vec2(positionbulletx, positionbullety), hollowz->GetAngle());
		b2Vec2 bullet = hollowz->GetPosition();

		laserc->SetTransform(b2Vec2(trapS.get_position().x, trapS.get_position().y), laserc->GetAngle());
		b2Vec2  trapS2 = laserc->GetPosition();

		//b2Vec2 positionplayer = solid->GetPosition;
		//positionplayer = playerpositionbox1;
		//positionplayer = playerpositionbox2;

		//printf("%4.2f %4.2f %4.2f\n", positionbox.x, positionbox.y, anglebox);
		//printf("%4.2f %4.2f %4.2f\n", positionplayer.x, positionplayer.y, anglebox);
		//printf("%s", overlap ? "true" : "false");
		if (overlap) {
			bullet1.load_sprite_image("assets/images/blank.png")
				.set_scale(20, 20)
				.set_center(0.5f, 0.5f)
				.set_sprite_frame_size(20, 20)
				.set_rotation(0);
		}
		//responds to bottom right now
		// up  can not be more more than max bot cannot be less then min
		//printf("%s", overlaptop ? "true" : "false");
		//cout << overlaplasergun << endl;
		if (overlaplasergun) 
		{
			bullet1.load_sprite_image("assets/images/blank.png")
				.set_scale(20, 20)
				.set_center(0.5f, 0.5f)
				.set_sprite_frame_size(20, 20)
				.set_rotation(0);

			trapS.load_sprite_image("assets/images/trapoff.png")
				.set_scale(50, 240)
				.set_sprite_frame_size(50, 240)
				.set_center(0.5f, 0.5f)
				.set_position(trapS.get_position().x, trapS.get_position().y);
		}

			
		
		//if (overlap) {
		//	break;
		//}

		// You can put movement code inside of this update function, it is called every frame
		Update();
		
		// You can put sprite drawing code inside of this draw function
		DrawSprites();

		// You can put primitives in here. These draw on top of all of the sprites
		DrawPrimitives();

		clock_t end = clock();
		time2 = (double)(end - start) / CLOCKS_PER_SEC *100;
		seconds = time2;
		//cout << seconds << endl;

		counter3++;

		if (counter3 == 1000)
		{
			cout << counter3 << endl;
			logS.load_sprite_image("assets/images/log.png")
				.set_scale(500, 220)
				.set_center(0.5f, 0.5f)
				.set_sprite_frame_size(500, 220)
				//.set_rotation(90)
				.set_position(740, 110);
		}
		if (counter3 == 500)
		{
			cout << counter3 << endl;
			trapS.load_sprite_image("assets/images/trapon.png")
				.set_scale(50, 240)
				.set_sprite_frame_size(50, 240)
				.set_center(0.5f, 0.5f)
				.set_position(740, 150);
		}

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
	if (a_sprite.get_position().x + a_sprite.get_scale().x < 0)
	{
		a_sprite.set_position(Window::get_game_window().get_width(true) - 1.0f, a_sprite.get_position().y);
	}
}

// Code to move our character around the screen, and spin counter-clockwise
void UpdatePlayer(Sprite &player)
{

	//math::Vector3 position = player.get_position();
	//float rotation = player.get_rotataion();
	//
	//position.x += 5.0f;
	//if (position.x > 800) position.x = 0;
	//
	//rotation += 1.0f; // increment orientation 1 degree/frame
	//
	//player.set_position(position.x, position.y);
	//player.set_rotation(rotation);
	// update our x position by scrollingSpeed pixels
	player.set_position(player.get_position().x + speedx, player.get_position().y + speedy);
	player.set_rotation(rotation);

	if (player.get_position().y >= 241) {

		player.set_position(player.get_position().x, 241);
	}
	else if (player.get_position().y <= 40) {

		player.set_position(player.get_position().x,40);
	}
	else if (player.get_position().x >= 470) {

		player.set_position(470, player.get_position().y);
	}
	else if (player.get_position().x <= 30) {

		player.set_position(30, player.get_position().y);
	}
}


void UpdatePlayerBox(Sprite &playerBox)
{
	//int gravity(0);

	//math::Vector3 position = player.get_position();
	//float rotation = player.get_rotataion();
	//
	//position.x += 5.0f;
	//if (position.x > 800) position.x = 0;
	//
	//rotation += 1.0f; // increment orientation 1 degree/frame
	//
	//player.set_position(position.x, position.y);
	//player.set_rotation(rotation);
	// update our x position by scrollingSpeed pixels
	//playerBox.set_position(playerBox.get_position().x - positionbox1, playerBox.get_position().y - positionbox2);
	//playerBox.set_rotation(rotation);

	playerBox.set_position(positionbox1, positionbox2);
}
void UpdateflyingBox(Sprite &flyingBox)
{
	//int gravity(0);

	//math::Vector3 position = player.get_position();
	//float rotation = player.get_rotataion();
	//
	//position.x += 5.0f;
	//if (position.x > 800) position.x = 0;
	//
	//rotation += 1.0f; // increment orientation 1 degree/frame
	//
	//player.set_position(position.x, position.y);
	//player.set_rotation(rotation);
	// update our x position by scrollingSpeed pixels
	//playerBox.set_position(playerBox.get_position().x - positionbox1, playerBox.get_position().y - positionbox2);
	//playerBox.set_rotation(rotation);

	flyingBox.set_position(positionbox3, positionbox4);
}
void Updatebullet(Sprite &bullet1)
{
	//int gravity(0);

	//math::Vector3 position = player.get_position();
	//float rotation = player.get_rotataion();
	//
	//position.x += 5.0f;
	//if (position.x > 800) position.x = 0;
	//
	//rotation += 1.0f; // increment orientation 1 degree/frame
	//
	//player.set_position(position.x, position.y);
	//player.set_rotation(rotation);
	// update our x position by scrollingSpeed pixels
	//playerBox.set_position(playerBox.get_position().x - positionbox1, playerBox.get_position().y - positionbox2);
	//playerBox.set_rotation(rotation);
	
	float Xpos, Ypos;
	math::Vector3 positionbullet = bullet1.get_position();

	positionbulletx = positionbullet.x;
	positionbullety = positionbullet.y;
	Xpos = 2.5 * acos(t_angle);
	Ypos = 2.5 * asin(t_angle);
	bullet1.set_position(positionbullet.x +Xpos, positionbullet.y+Ypos);
}
void Updatelog(Sprite &logS)
{
	//float Xpos, Ypos;
	//math::Vector3 positionlog = logS.get_position();

	//positionbulletx = positionlog.x;
	//positionbullety = positionlog.y;
	
	//logS.set_position(positionlog.x - 1, positionlog.y);
	logS.set_position(logS.get_position().x - 1, logS.get_position().y);
}
void Updatetrap(Sprite &trapS)
{
	//float Xpos, Ypos;
	//math::Vector3 positionlog = logS.get_position();

	//positionbulletx = positionlog.x;
	//positionbullety = positionlog.y;

	//logS.set_position(positionlog.x - 1, positionlog.y);
	trapS.set_position(trapS.get_position().x - 1, trapS.get_position().y);
}
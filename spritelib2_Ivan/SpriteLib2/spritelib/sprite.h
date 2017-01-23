#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include <memory>

#include "matrix4x4.h"
#include "vector3.h"

namespace sf
{
	// forward declaring texture, because of circular dependancies
	// https://en.wikipedia.org/wiki/Circular_dependency
	class Texture;
}

namespace spritelib
{
	// forward declaring shaderprogram, because of circular dependancies
	class ShaderProgram;

	class Sprite
	{
	public:
		Sprite();
		~Sprite();
		
		/* load_sprite_image
			- fileLoc is the file location of the image you want to use for your sprite
		*/
		Sprite& load_sprite_image(std::string a_fileLoc, bool a_setScale = true);
		/* set_sprite_frame_size
			- width/height will tell the program how big your sprite is on the spritesheet (in pixels)
		*/
		Sprite& set_sprite_frame_size(unsigned int a_width, unsigned int a_height, bool a_setScale = true);
		/* push_frame_row
			- animationID is a string that you use to set which animation you're using later on
			- startx/starty are the coordinates of the very first frame
			- spacingX/spacingY are the pixel offsets in between each frame
			- numFrames are the number of frames in the row you're adding
		*/
		Sprite& push_frame_row(std::string a_animationID, unsigned int a_startX, unsigned int a_startY,
			int a_spacingX, int a_spacingY, unsigned int a_numFrames);
		/* push_frame
			- animationID is a string that you use to set which animation you're using later on
			- x/y are the coordinates of the frame (bottom left). Be sure to call set_sprite_frame_size() first
		*/
		Sprite& push_frame(std::string a_animationID, unsigned int a_x, unsigned int a_y);
		/* pop_frame
			- will remove an animation from the animation with the ID you set
		*/
		Sprite& pop_frame(std::string a_animationID);
		/* set_animation
			- set the animation that we use with the sprite
		*/
		Sprite& set_animation(std::string a_animationID);
		/* set_frame
			- set the frame our animation is currently on
		*/
		Sprite& set_frame(unsigned int a_frame);
		/* set_center
			- centerX/centerY are the coordinates of the pivot, from 0-1
		*/
		Sprite& set_center(float a_centerX, float a_centerY);
		/* next_frame
			- increment the frame by one
		*/
		Sprite& next_frame();
		/* draw
			- draw your sprite to the screen. This function uses the texture and coordinates for the sprite
		*/
		Sprite& draw();
		/* draw
			- sp is the shader program you can use to draw your sprite. You can set uniforms before calling this function
				- If you use this function, you're responsible for transforming/texturing the sprite
		*/
		Sprite& draw(ShaderProgram& sp);
		/* set_position
			- x/y are the coordinates on the screen where the sprite will be (from the center)
		*/
		Sprite& set_position(float a_x, float a_y);
		/* set_scale
			- width/height will scale your sprite. 
		*/
		Sprite& set_scale(float a_width, float a_height);
		/* set_rotation
			- rotation will set the rotation of the sprite in degrees (clockwise)
		*/
		Sprite& set_rotation(float a_rotation);
		/* set_depth
			- this will set the sprite's depth. Useful for sorting them before drawing them
				- This doesn't affect how the sprite is drawn. It is up to you to SORT the sprites
		*/
		Sprite& set_depth(float a_depth);

		/* get_position
			- this returns a Vector3 with the position of the sprite
		*/
		math::Vector3 get_position();
		/* get_scale
			- this returns a Vector3 with the scale of your sprite
		*/
		math::Vector3 get_scale();
		/* get_rotation
			- this returns the current rotation of your sprite (in degrees, clockwise)
				- usage example: if you want to rotate your sprite 1 degree, you can do this
				mySprite.set_rotation(mySprite.get_rotation() + 1.0f);
		*/
		float get_rotataion();
		/* get_depth
			- this is used for implementing sorting of sprites. You can organize the depth of sprites with this
		*/
		float get_depth();

	private:
		// to prevent people from loading an image 10000000000 times by accident
		static std::unordered_map<std::string, sf::Texture> m_images;

		// a list of animations (we only need to store 2 ints, x/y, because width/height are always the same)
		std::unordered_map<std::string, std::vector<std::pair<int, int>>> m_animations;
		// here are width/height of a frame
		std::pair<int, int> m_frameSize;
		std::string m_currentAnimation;
		unsigned int m_currentFrame;

		// This was the file location of the image we loaded
		std::string m_loc;

		// The transformation values for our transformation matrix
		math::Matrix4x4 m_modelMatrix;
		math::Vector3 m_position;
		math::Vector3 m_center;
		math::Vector3 m_scale;
		float m_rotation;
		bool m_transformationUpdated = true;

		// A private singleton class which wil draw a simple quad. It makes use of smart pointers,
		// to automatically clean-up after itself. https://en.wikipedia.org/wiki/Smart_pointer
		struct Quad
		{
		private:
			Quad();

			static void init_buffers();
			static void cleanup_buffers(Quad *cleanup);

			static unsigned int m_vbo, m_vao, m_ebo;
			static std::shared_ptr<Quad> s_quad;

		public:
			static Quad& get_instance();
			
			void draw();
		};
	};
}
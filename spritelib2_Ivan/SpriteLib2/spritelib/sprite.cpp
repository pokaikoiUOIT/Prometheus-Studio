#include "sprite.h"

#include "spritelib.h"
#include "window.h"

namespace spritelib
{
	std::unordered_map<std::string, sf::Texture> Sprite::m_images = std::unordered_map<std::string, sf::Texture>();
	Sprite::Sprite()
	{
		m_scale = math::Vector3::one;
		m_position = math::Vector3::zero;
		m_rotation = 0.0f;

		m_currentFrame = 0;
	}

	Sprite::~Sprite()
	{
	}

	/* load_sprite_image
		- fileLoc is the file location of the image you want to use for your sprite
	*/
	Sprite & Sprite::load_sprite_image(std::string a_fileLoc, bool a_setScale)
	{
		m_loc = a_fileLoc;
		if (m_images.find(a_fileLoc) == m_images.end())
		{
			sf::Image upsideDownImage;
			upsideDownImage.loadFromFile(a_fileLoc);
			upsideDownImage.flipVertically();

			m_images[a_fileLoc] = sf::Texture();
			m_images[a_fileLoc].loadFromImage(upsideDownImage);
		}
		m_center = math::Vector3::zero;
		if (a_setScale == true)
		{
			auto size = m_images[a_fileLoc].getSize();
			m_transformationUpdated = true;
			m_scale = math::Vector3((float)(size.x), (float)(size.y));
		}
		return *this;
	}

	/* set_sprite_frame_size
		- width/height will tell the program how big your sprite is on the spritesheet (in pixels)
	*/
	Sprite & Sprite::set_sprite_frame_size(unsigned int a_width, unsigned int a_height, bool a_setScale)
	{
		m_frameSize = { a_width, a_height };
		if (a_setScale)
		{
			m_transformationUpdated = true;
			m_scale = math::Vector3((float)(a_width), (float)(a_height));
		}
		return *this;
	}
	
	/* push_frame_row
		- animationID is a string that you use to set which animation you're using later on
		- startx/starty are the coordinates of the very first frame
		- spacingX/spacingY are the pixel offsets in between each frame
		- numFrames are the number of frames in the row you're adding
	*/
	Sprite & Sprite::push_frame_row(std::string a_animationID, unsigned int a_startX, unsigned int a_startY, int a_spacingX, int a_spacingY, unsigned int a_numFrames)
	{
		for (unsigned int i = 0; i < a_numFrames; i++)
		{
			push_frame(a_animationID, a_startX + a_spacingX * i, a_startY + a_spacingY * i);
		}

		return *this;
	}

	/* push_frame
		- animationID is a string that you use to set which animation you're using later on
		- x/y are the coordinates of the frame (bottom left). Be sure to call set_sprite_frame_size() first
	*/
	Sprite & Sprite::push_frame(std::string a_animationID, unsigned int a_x, unsigned int a_y)
	{
		m_animations[a_animationID].push_back({ a_x, a_y });
		return *this;
	}
	
	/* pop_frame
		- will remove an animation from the animation with the ID you set
	*/
	Sprite & Sprite::pop_frame(std::string a_animationID)
	{
		m_animations[a_animationID].pop_back();
		return *this;
	}
	
	/* set_animation
		- set the animation that we use with the sprite
	*/
	Sprite & Sprite::set_animation(std::string a_animationID)
	{
		m_currentAnimation = a_animationID;
		return *this;
	}
	
	/* set_frame
		- set the frame our animation is currently on
	*/
	Sprite & Sprite::set_frame(unsigned int a_frame)
	{
		m_currentFrame = a_frame;
		return *this;
	}

	/* set_center
		- centerX/centerY are the coordinates of the pivot
	*/
	Sprite & Sprite::set_center(float a_centerX, float a_centerY)
	{
		m_transformationUpdated = true;
		m_center = math::Vector3(a_centerX, a_centerY);
		return *this;
	}

	/* next_frame
		- increment the frame by one
	*/
	Sprite & Sprite::next_frame()
	{
		m_currentFrame++;
		return *this;
	}

	/* draw
		- draw your sprite to the screen. This function uses the texture and position to draw the sprite on the screen
	*/
	Sprite & Sprite::draw()
	{
		auto sp = ShaderProgram::PassThrough::get_instance().s_sp;
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, m_images[m_loc].getNativeHandle());
		sp->use_program();

		if (m_transformationUpdated == true)
		{
			m_transformationUpdated = false;

			math::Vector3 center = m_scale.multiply(0.5f);
			center = center.subtract(m_center.multiply(m_scale)); // subtract the size, multiplied from 0 to 1

			m_modelMatrix = math::Matrix4x4(math::Matrix4x4::s_identity);
			m_modelMatrix = m_modelMatrix.multiply(math::Matrix4x4::translate(m_position));
			m_modelMatrix = m_modelMatrix.multiply(math::Matrix4x4::rotate(m_rotation));
			m_modelMatrix = m_modelMatrix.multiply(math::Matrix4x4::translate(center));
			m_modelMatrix = m_modelMatrix.multiply(math::Matrix4x4::scale(m_scale));
		}

		auto imageSize = m_images[m_loc].getSize();

		float uvInfo[4];

		if (m_animations.find(m_currentAnimation) == m_animations.end())
		{
			uvInfo[0] = uvInfo[1] = 0.0f;
			uvInfo[2] = uvInfo[3] = 1.0f;
		}
		else
		{
			m_currentFrame = m_currentFrame % m_animations[m_currentAnimation].size();
			uvInfo[0] = m_animations[m_currentAnimation][m_currentFrame].first / (float)(imageSize.x); // X pos, normalized
			uvInfo[1] = m_animations[m_currentAnimation][m_currentFrame].second / (float)(imageSize.y); // Y pos, normalized
			uvInfo[2] = m_frameSize.first / (float)(imageSize.x); // X pos
			uvInfo[3] = m_frameSize.second / (float)(imageSize.y); // Y pos
		}

		sp->set_vec2("uvPos", &uvInfo[0]); // uses 0,1
		sp->set_vec2("uvScale", &uvInfo[2]); // uses 2,3
		sp->set_mat4("modelView", &m_modelMatrix.m_data[0]);
		sp->set_mat4("projection", &Window::get_game_window().m_proj->m_data[0]);

		Quad::get_instance().draw();
		glUseProgram(GL_NONE);

		return *this;
	}

	/* draw
		- sp is the shader program you can use to draw your sprite. You can set uniforms before calling this function
			- If you use this function, you're responsible for transforming/texturing the sprite
	*/
	Sprite & Sprite::draw(ShaderProgram & sp)
	{
		sp.use_program();
		Quad::get_instance().draw();
		glUseProgram(GL_NONE);

		return *this;
	}

	/* set_position
		- x/y are the coordinates on the screen where the sprite will be (from the center)
	*/
	Sprite & Sprite::set_position(float a_x, float a_y)
	{
		m_transformationUpdated = true;
		m_position.x = a_x;
		m_position.y = a_y;
		return *this;
	}
	
	/* set_scale
		- width/height will scale your sprite. 
	*/
	Sprite & Sprite::set_scale(float a_width, float a_height)
	{
		m_transformationUpdated = true;
		m_scale = math::Vector3(a_width, a_height);
		return *this;
	}

	/* set_rotation
		- rotation will set the rotation of the sprite in degrees (clockwise)
	*/
	Sprite & Sprite::set_rotation(float a_rotation)
	{
		m_transformationUpdated = true;
		m_rotation = a_rotation;
		return *this;
	}

	/* set_depth
		- this will set the sprite's depth. Useful for sorting them before drawing them
			- This doesn't affect how the sprite is drawn. It is up to you to SORT the sprites
	*/
	Sprite & Sprite::set_depth(float a_depth)
	{
		m_transformationUpdated = true;
		m_position.z = a_depth;
		return *this;
	}

	/* get_position
		- this returns a Vector3 with the position of the sprite
	*/
	math::Vector3 Sprite::get_position()
	{
		return m_position;
	}

	/* get_scale
		- this returns a Vector3 with the scale of your sprite
	*/
	math::Vector3 Sprite::get_scale()
	{
		return m_scale;
	}

	/* get_rotation
		- this returns the current rotation of your sprite (in degrees, clockwise)
			- usage example: if you want to rotate your sprite 1 degree, you can do this
			mySprite.set_rotation(mySprite.get_rotation() + 1.0f);
	*/
	float Sprite::get_rotataion()
	{
		return m_rotation;
	}

	/* get_depth
		- this is used for implementing sorting of sprites. You can organize the depth of sprites with this
	*/
	float Sprite::get_depth()
	{
		return m_position.z;
	}
	
	unsigned int Sprite::Quad::m_vbo = 0U;
	unsigned int Sprite::Quad::m_ebo = 0U;
	unsigned int Sprite::Quad::m_vao = 0U;
	std::shared_ptr<Sprite::Quad> Sprite::Quad::s_quad = std::shared_ptr<Sprite::Quad>(nullptr);

	Sprite::Quad::Quad()
	{
	}

	void Sprite::Quad::init_buffers()
	{
		GLfloat vertices[20] = {
			/* Verts */ -0.5f,	-0.5f,	0.0f,	/* UVs */	0.0f, 0.0f,
			/* Verts */ -0.5f,	 0.5f,	0.0f,	/* UVs */	0.0f, 1.0f,
			/* Verts */  0.5f,	 0.5f,	0.0f,	/* UVs */	1.0f, 1.0f,
			/* Verts */  0.5f,	-0.5f,	0.0f,	/* UVs */	1.0f, 0.0f,
		};

		GLuint indices[6] = {
			0, 1, 2,	// Tri 1
			0, 2, 3,	// Tri 2
		};

		// Create a vertex array object
		glGenVertexArrays(1, &m_vao);
		glBindVertexArray(m_vao);

		// Create a vertex buffer object
		glGenBuffers(1, &m_vbo);
		glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
		glBufferData(GL_ARRAY_BUFFER, 20 * sizeof(GLfloat), &vertices[0], GL_STATIC_DRAW);

		// Create an element buffer object
		glGenBuffers(1, &m_ebo);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ebo);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(GLuint), &indices[0], GL_STATIC_DRAW);
	}
	void Sprite::Quad::draw()
	{
		glBindBuffer(GL_ARRAY_BUFFER, m_vao);

		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (void*)0);
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), reinterpret_cast<void*>(3 * sizeof(GLfloat)));

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ebo);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (void*)0);
		glDisableVertexAttribArray(0);
	}
	void Sprite::Quad::cleanup_buffers(Quad *a_object)
	{
		// Cleanup the buffers
		glDeleteBuffers(1, &m_vbo);
		glDeleteBuffers(1, &m_ebo);
		glDeleteVertexArrays(1, &m_vao);

		delete a_object;
	}
	Sprite::Quad & Sprite::Quad::get_instance()
	{
		// Ensure only one instance of the quad is ever created
		if (s_quad == nullptr)
		{
			s_quad = std::shared_ptr<Quad>(new Quad(), Sprite::Quad::cleanup_buffers);
			init_buffers();
		}
		return *s_quad;
	}
}
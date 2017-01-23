#include "text.h"

#include "spritelib.h"

#define FONT_SIZE 32

namespace spritelib
{
	float Text::m_color[3];
	bool Text::m_initialized = false;
	std::unordered_map<std::string, sf::Texture> Text::m_fontImages;
	std::unordered_map<std::string, sf::Font> Text::m_fonts;

	Text::Text()
	{
	}
	
	/* set_color
		- red/green/blue are the normalized color you want text to be drawn with
		- the colors go from 0 to 1, ie: [1,0,0] will be full red
	*/
	void Text::set_color(float a_red, float a_green, float a_blue)
	{
		m_color[0] = a_red;
		m_color[1] = a_green;
		m_color[2] = a_blue;
	}

	/* load_font
		- fileLoc is the location of the .ttf (true type font) file you would like to load
		- fontName is the string that you assign this font. It can be referenced later with this name
	*/
	void Text::load_font(std::string a_fileLoc, std::string a_fontName)
	{
		if (m_fontImages.find(a_fileLoc) == m_fontImages.end())
		{
			sf::Font font;
			font.loadFromFile(a_fileLoc);
			
			for (int i = 0; i < 256; i++)
				font.getGlyph(i, FONT_SIZE, false);

			m_fontImages[a_fontName] = font.getTexture(FONT_SIZE);
			m_fonts[a_fontName] = font;

			if (!m_initialized)
			{
				m_initialized = true;
			}
		}
	}

	/* draw_string
		- stringToDraw is the text you would like to write on screen
		- fontName is the font you would like to use (you need to load a font with this name before you can use it)
		- xPos/yPos are the position on the screen where you would like to draw the font
		- scaleFactor scales the font (ie: 2 is twice as large, 0.5 is half as large). The font is default size 32
	*/
	void Text::draw_string(std::string a_stringToDraw, std::string a_fontName, float a_xPos, float a_yPos, float a_scaleFactor)
	{
		auto sp = TextShader::get_instance().s_sp;
		auto f = m_fonts[a_fontName];
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, m_fontImages[a_fontName].getNativeHandle());
		sp->use_program();
		auto t = m_fontImages[a_fontName].getSize();
		std::pair<float, float> tDim = { (float)t.x, (float)t.y };

		float offsetX = 0.0f;
		float lineHeight = f.getLineSpacing(FONT_SIZE);
		for (unsigned int i = 0; i < a_stringToDraw.length(); i++)
		{
			auto g = f.getGlyph(a_stringToDraw[i], FONT_SIZE, false);
			auto b = g.bounds;
			
			float kerning = 0.0f;
			if (i != a_stringToDraw.length() - 1)
				kerning = f.getKerning(a_stringToDraw[i], a_stringToDraw[i + 1], FONT_SIZE);

			auto texC = g.textureRect;

			float pos[4] = { 
				offsetX + b.left, 
				-(b.height + b.top),
				offsetX + b.left + b.width,
				-(b.height + b.top) + b.height};

			float uvs[4];
			uvs[0] = (float)texC.left / tDim.first;
			uvs[3] = (float)(texC.top) / tDim.second;
			uvs[2] = (float)(texC.left + texC.width) / tDim.first;
			uvs[1] = (float)(texC.top + texC.height) / tDim.second;

			offsetX += g.advance + kerning;

			auto projection = *Window::get_game_window().m_proj;
			auto modelMat = math::Matrix4x4(math::Matrix4x4::s_identity);
			modelMat = modelMat.multiply(math::Matrix4x4::translate(math::Vector3(a_xPos, a_yPos, 0.0f)));
			modelMat = modelMat.multiply(math::Matrix4x4::scale(math::Vector3(a_scaleFactor)));

			sp->set_mat4("modelView", &modelMat.m_data[0]);
			sp->set_mat4("projection", &projection.m_data[0]);
			sp->set_vec4("position", pos);
			sp->set_vec4("uvs", uvs);
			sp->set_vec3("color", &m_color[0]);
			glDrawArrays(GL_POINTS, 0, 1);
		}
		
		glUseProgram(GL_NONE);
	}

	std::shared_ptr<Text::TextShader> Text::TextShader::s_shad = std::shared_ptr<Text::TextShader>(nullptr);
	Text::TextShader::TextShader()
	{

	}
	void Text::TextShader::init_shader()
	{
		s_vert = new Shader();
		s_geom = new Shader();
		s_frag = new Shader();
		s_sp = new ShaderProgram();

		s_vert->load_shader(Shader::VERTEX, "assets/BlankVert.glsl")
			.compile_shader();

		s_geom->load_shader(Shader::GEOMETRY, "assets/TextGeom.glsl")
			.compile_shader();

		s_frag->load_shader(Shader::FRAGMENT, "assets/PassthroughTextureFrag.glsl")
			.compile_shader();

		s_sp->add_shader(*s_vert)
			.add_shader(*s_geom)
			.add_shader(*s_frag)
			.link_program();
	}
	void Text::TextShader::cleanup_shader(TextShader * cleanup)
	{
		cleanup->s_vert->cleanup();
		cleanup->s_geom->cleanup();
		cleanup->s_frag->cleanup();
		cleanup->s_sp->cleanup();
		delete cleanup->s_sp;
		delete cleanup;
	}
	Text::TextShader & Text::TextShader::get_instance()
	{
		// Ensure only one instance of the shader is ever created
		if (s_shad == nullptr)
		{
			s_shad = std::shared_ptr<TextShader>(new TextShader(), cleanup_shader);
			s_shad->init_shader();
		}
		return *s_shad;
	}
}

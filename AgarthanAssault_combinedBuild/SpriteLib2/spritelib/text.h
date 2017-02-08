#pragma once

#include <string>
#include <unordered_map>
#include <memory>

namespace sf
{
	class Texture;
	class Font;
}

namespace spritelib
{
	class Shader;
	class ShaderProgram;

	class Text
	{
	private:
		Text();

		static bool m_initialized;

		struct TextShader
		{
		private:
			TextShader();

			void init_shader();
			static void cleanup_shader(TextShader *cleanup);

			static std::shared_ptr<TextShader> s_shad;

		public:
			static TextShader& get_instance();

			Shader* s_vert;
			Shader* s_geom;
			Shader* s_frag;
			ShaderProgram* s_sp;
		};

	public:

		/* set_color
			- red/green/blue are the normalized color you want text to be drawn with
			- the colors go from 0 to 1, ie: [1,0,0] will be full red
		*/
		static void set_color(float a_red, float a_green, float a_blue);
		/* load_font
			- fileLoc is the location of the .ttf (true type font) file you would like to load
			- fontName is the string that you assign this font. It can be referenced later with this name
		*/
		static void load_font(std::string a_fileLoc, std::string a_fontName);

		/* draw_string
			- stringToDraw is the text you would like to write on screen
			- fontName is the font you would like to use (you need to load a font with this name before you can use it)
			- xPos/yPos are the position on the screen where you would like to draw the font
			- scaleFactor scales the font (ie: 2 is twice as large, 0.5 is half as large). The font is default size 32
		*/
		static void draw_string(std::string a_stringToDraw, std::string a_fontName, float a_xPos, float a_yPos, float a_scaleFactor = 1.0f);

		static float m_color[3];
		static std::unordered_map<std::string, sf::Texture> m_fontImages;
		static std::unordered_map<std::string, sf::Font> m_fonts;
	};
}
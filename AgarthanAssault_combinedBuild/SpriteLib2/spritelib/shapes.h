#pragma once

#include <memory>

namespace spritelib
{
	class Shader;
	class ShaderProgram;

	class Shapes
	{
	public:
		/* set_line_width
			- how wide (in pixels) will lines be drawn.
			- this also affects non-filled shapes (circle, triangle, rectangle)
		*/
		static void set_line_width(float a_width);
		/* set_color
			- red/green/blue are the normalized color you want shapes to be drawn with
			- the colors go from 0 to 1, ie: [1,0,0] will be full red
		*/
		static void set_color(float a_red, float a_green, float a_blue);
		/* draw_line
			- x1/y1 represent the start of a line segment
			- x2/y2 represent the end of a line segment
		*/
		static void draw_line(float a_x1, float a_y1, float a_x2, float a_y2);
		/* draw_rectangle
			- the filled boolean will render a hollow rectangle if set to false, and a filled rectangle if true
			- x/y represent the bottom left corner of the rectangle
			- width/height are the dimensions of the rectangle
			- theta is the rotation (around the pivot x/y) of the rectangle
		*/
		static void draw_rectangle(bool a_filled, float a_x, float a_y, float a_width, float a_height, float a_theta = 0.0f);
		/* draw_circle
			- the filled boolean will render a hollow circle if set to false, and a filled circle if true
			- radius is the radius of the circle in pixels
			- centerX/centerY represent the centroid of the circle
		*/
		static void draw_circle(bool a_filled, float radius, float centerX, float centerY);
		/* draw_triangle
			- the filled boolean will render a hollow triangle if set to false, and a filled triangle if true
			- x1/y1 are a corner of the triangle
			- x2/y2 are a corner of the triangle
			- x3/y3 are a corner of the triangle
		*/
		static void draw_triangle(bool a_filled, float a_x1, float a_y1, float a_x2, float a_y2, float a_x3, float a_y3);

	private:
		struct ShapesShader
		{
		private:
			ShapesShader();

			void init_shader();
			static void cleanup_shader(ShapesShader *cleanup);

			static std::shared_ptr<ShapesShader> s_shad;

		public:
			static ShapesShader& get_instance();

			Shader* s_vert;
			Shader* s_geom;
			Shader* s_geom2;
			Shader* s_geom3;
			Shader* s_frag;
			ShaderProgram* s_sp;
			ShaderProgram* s_sp2;
			ShaderProgram* s_sp3;
		};

	private:
		static float m_color[3];
	};
}
#include "shapes.h"

#include "spritelib.h"

namespace spritelib
{
	float Shapes::m_color[3];

	/* set_line_width
			- how wide (in pixels) will lines be drawn.
			- this also affects non-filled shapes (circle, triangle, rectangle)
	*/
	void Shapes::set_line_width(float a_width)
	{
		glLineWidth(a_width);
	}

	/* set_color
			- red/green/blue are the normalized color you want shapes to be drawn with
			- the colors go from 0 to 1, ie: [1,0,0] will be full red
	*/
	void Shapes::set_color(float a_red, float a_green, float a_blue)
	{
		m_color[0] = a_red;
		m_color[1] = a_green;
		m_color[2] = a_blue;
	}

	/* draw_line
			- x1/y1 represent the start of a line segment
			- x2/y2 represent the end of a line segment
	*/
	void Shapes::draw_line(float a_x1, float a_y1, float a_x2, float a_y2)
	{
		auto sp = ShapesShader::get_instance().s_sp2;

		sp->use_program();

		float posA[3] = { a_x1, a_y1, 0.0f };
		float posB[3] = { a_x2, a_y2, 0.0f };

		sp->set_vec3("posA", posA);
		sp->set_vec3("posB", posB);
		sp->set_mat4("modelView", &math::Matrix4x4::s_identity[0]);
		sp->set_mat4("projection", &Window::get_game_window().m_proj->m_data[0]);
		sp->set_vec3("color", &m_color[0]);

		glDrawArrays(GL_POINTS, 0, 1);
		glUseProgram(GL_NONE);
	}

	/* draw_rectangle
			- the filled boolean will render a hollow rectangle if set to false, and a filled rectangle if true
			- x/y represent the bottom left corner of the rectangle
			- width/height are the dimensions of the rectangle
			- theta is the rotation (around the pivot x/y) of the rectangle
	*/
	void Shapes::draw_rectangle(bool a_filled, float a_x, float a_y, float a_width, float a_height, float a_theta)
	{
		if (!a_filled)
		{
			auto sp = ShapesShader::get_instance().s_sp2;

			sp->use_program();

			float posA0[3] = { 0.0f, 0.0f, 0.0f };
			float posB0[3] = { 1.0f, 0.0f, 0.0f };
			float posA1[3] = { 0.0f, 1.0f, 0.0f };
			float posB1[3] = { 1.0f, 1.0f, 0.0f };
			float posA2[3] = { 0.0f, 0.0f, 0.0f };
			float posB2[3] = { 0.0f, 1.0f, 0.0f };
			float posA3[3] = { 1.0f, 0.0f, 0.0f };
			float posB3[3] = { 1.0f, 1.0f, 0.0f };

			auto modelView = math::Matrix4x4(math::Matrix4x4::s_identity);
			modelView = modelView.multiply(math::Matrix4x4::translate(math::Vector3(a_x, a_y)));
			modelView = modelView.multiply(math::Matrix4x4::rotate(a_theta));
			modelView = modelView.multiply(math::Matrix4x4::scale(math::Vector3(a_width, a_height)));

			sp->set_mat4("modelView", &modelView.m_data[0]);
			sp->set_mat4("projection", &Window::get_game_window().m_proj->m_data[0]);
			sp->set_vec3("color", &m_color[0]);

			sp->set_vec3("posA", posA0);
			sp->set_vec3("posB", posB0);
			glDrawArrays(GL_POINTS, 0, 1);
			sp->set_vec3("posA", posA1);
			sp->set_vec3("posB", posB1);
			glDrawArrays(GL_POINTS, 0, 1);
			sp->set_vec3("posA", posA2);
			sp->set_vec3("posB", posB2);
			glDrawArrays(GL_POINTS, 0, 1);
			sp->set_vec3("posA", posA3);
			sp->set_vec3("posB", posB3);
			glDrawArrays(GL_POINTS, 0, 1);
		}
		else
		{
			auto sp = ShapesShader::get_instance().s_sp3;

			sp->use_program();

			float posA[3] = { 0.0f, 0.0f, 0.0f };
			float posB[3] = { 1.0f, 0.0f, 0.0f };
			float posC[3] = { 0.0f, 1.0f, 0.0f };
			float posD[3] = { 1.0f, 1.0f, 0.0f };

			auto modelView = math::Matrix4x4(math::Matrix4x4::s_identity);
			modelView = modelView.multiply(math::Matrix4x4::translate(math::Vector3(a_x, a_y)));
			modelView = modelView.multiply(math::Matrix4x4::rotate(a_theta));
			modelView = modelView.multiply(math::Matrix4x4::scale(math::Vector3(a_width, a_height)));

			sp->set_mat4("modelView", &modelView.m_data[0]);
			sp->set_mat4("projection", &Window::get_game_window().m_proj->m_data[0]);
			sp->set_vec3("color", &m_color[0]);

			sp->set_vec3("posA", posA);
			sp->set_vec3("posB", posB);
			sp->set_vec3("posC", posC);
			glDrawArrays(GL_POINTS, 0, 1);
			sp->set_vec3("posA", posB);
			sp->set_vec3("posB", posC);
			sp->set_vec3("posC", posD);
			glDrawArrays(GL_POINTS, 0, 1);
		}

		glUseProgram(GL_NONE);
	}

	/* draw_circle
			- the filled boolean will render a hollow circle if set to false, and a filled circle if true
			- radius is the radius of the circle in pixels
			- centerX/centerY represent the centroid of the circle
	*/
	void Shapes::draw_circle(bool a_filled, float a_radius, float a_centerX, float a_centerY)
	{
		if (!a_filled)
		{
			auto sp = ShapesShader::get_instance().s_sp2;

			sp->use_program();

			auto modelMatrix = math::Matrix4x4(math::Matrix4x4::s_identity);
			modelMatrix = modelMatrix.multiply(math::Matrix4x4::translate(math::Vector3(a_centerX, a_centerY, 0.0f)));
			modelMatrix = modelMatrix.multiply(math::Matrix4x4::scale(math::Vector3(a_radius)));

			sp->set_mat4("modelView", &modelMatrix.m_data[0]);
			sp->set_mat4("projection", &Window::get_game_window().m_proj->m_data[0]);
			sp->set_vec3("color", &m_color[0]);

			float x, y;
			float step = 2.0f * 3.14159f / 32.0f;
			
			float posA[3], posB[3];

			posA[0] = 1.0f; posA[1] = 0.0f, posA[2] = 0.0f;
			for (float theta = step; theta < 2.0f * 3.14159f; theta += step)
			{
				x = cos(theta);
				y = sin(theta);
				posB[0] = x; posB[1] = y;
				sp->set_vec3("posA", posA);
				sp->set_vec3("posB", posB);
				glDrawArrays(GL_POINTS, 0, 1);
				posA[0] = posB[0]; posA[1] = posB[1];
			}
			posB[0] = 1.0f; posB[1] = 0.0f;
			sp->set_vec3("posA", posA);
			sp->set_vec3("posB", posB);
			glDrawArrays(GL_POINTS, 0, 1);

		}
		else
		{
			auto sp = ShapesShader::get_instance().s_sp;

			sp->use_program();

			auto modelMatrix = math::Matrix4x4(math::Matrix4x4::s_identity);
			modelMatrix = modelMatrix.multiply(math::Matrix4x4::translate(math::Vector3(a_centerX, a_centerY, 0.0f)));
			modelMatrix = modelMatrix.multiply(math::Matrix4x4::scale(math::Vector3(a_radius)));

			sp->set_mat4("modelView", &modelMatrix.m_data[0]);
			sp->set_mat4("projection", &Window::get_game_window().m_proj->m_data[0]);
			sp->set_vec3("color", &m_color[0]);

			glDrawArrays(GL_POINTS, 0, 1);
		}

		glUseProgram(GL_NONE);
	}

	/* draw_triangle
			- the filled boolean will render a hollow triangle if set to false, and a filled triangle if true
			- x1/y1 are a corner of the triangle
			- x2/y2 are a corner of the triangle
			- x3/y3 are a corner of the triangle
	*/
	void Shapes::draw_triangle(bool a_filled, float a_x1, float a_y1, float a_x2, float a_y2, float a_x3, float a_y3)
	{
		if (!a_filled)
		{
			auto sp = ShapesShader::get_instance().s_sp2;

			sp->use_program();

			float posA0[3] = { a_x1, a_y1, 0.0f };
			float posB0[3] = { a_x2, a_y2, 0.0f };
			float posA1[3] = { a_x2, a_y2, 0.0f };
			float posB1[3] = { a_x3, a_y3, 0.0f };
			float posA2[3] = { a_x3, a_y3, 0.0f };
			float posB2[3] = { a_x1, a_y1, 0.0f };

			sp->set_mat4("modelView", &math::Matrix4x4::s_identity[0]);
			sp->set_mat4("projection", &Window::get_game_window().m_proj->m_data[0]);
			sp->set_vec3("color", &m_color[0]);

			sp->set_vec3("posA", posA0);
			sp->set_vec3("posB", posB0);
			glDrawArrays(GL_POINTS, 0, 1);
			sp->set_vec3("posA", posA1);
			sp->set_vec3("posB", posB1);
			glDrawArrays(GL_POINTS, 0, 1);
			sp->set_vec3("posA", posA2);
			sp->set_vec3("posB", posB2);
			glDrawArrays(GL_POINTS, 0, 1);
		}
		else
		{
			auto sp = ShapesShader::get_instance().s_sp3;

			sp->use_program();

			float posA[3] = { a_x1, a_y1, 0.0f };
			float posB[3] = { a_x2, a_y2, 0.0f };
			float posC[3] = { a_x3, a_y3, 0.0f };

			sp->set_mat4("modelView", &math::Matrix4x4::s_identity[0]);
			sp->set_mat4("projection", &Window::get_game_window().m_proj->m_data[0]);
			sp->set_vec3("color", &m_color[0]);

			sp->set_vec3("posA", posA);
			sp->set_vec3("posB", posB);
			sp->set_vec3("posC", posC);
			glDrawArrays(GL_POINTS, 0, 1);
		}

		glUseProgram(GL_NONE);
	}

	std::shared_ptr<Shapes::ShapesShader> Shapes::ShapesShader::s_shad = std::shared_ptr<Shapes::ShapesShader>(nullptr);
	Shapes::ShapesShader::ShapesShader()
	{

	}

	void Shapes::ShapesShader::init_shader()
	{
		s_vert = new Shader();
		s_geom = new Shader();
		s_geom2 = new Shader();
		s_geom3 = new Shader();
		s_frag = new Shader();
		s_sp = new ShaderProgram();
		s_sp2 = new ShaderProgram();
		s_sp3 = new ShaderProgram();

		s_vert->load_shader(Shader::VERTEX, "assets/BlankVert.glsl")
			.compile_shader();

		s_geom->load_shader(Shader::GEOMETRY, "assets/FilledCircleGeom.glsl")
			.compile_shader();

		s_geom2->load_shader(Shader::GEOMETRY, "assets/LineShaderGeom.glsl")
			.compile_shader();

		s_geom3->load_shader(Shader::GEOMETRY, "assets/FilledTriangleGeom.glsl")
			.compile_shader();

		s_frag->load_shader(Shader::FRAGMENT, "assets/ShapeFrag.glsl")
			.compile_shader();

		s_sp->add_shader(*s_vert)
			.add_shader(*s_geom)
			.add_shader(*s_frag)
			.link_program();

		s_sp2->add_shader(*s_vert)
			.add_shader(*s_geom2)
			.add_shader(*s_frag)
			.link_program();

		s_sp3->add_shader(*s_vert)
			.add_shader(*s_geom3)
			.add_shader(*s_frag)
			.link_program();
	}
	void Shapes::ShapesShader::cleanup_shader(ShapesShader * cleanup)
	{
		cleanup->s_vert->cleanup();
		cleanup->s_geom->cleanup();
		cleanup->s_geom2->cleanup();
		cleanup->s_geom3->cleanup();
		cleanup->s_frag->cleanup();
		cleanup->s_sp->cleanup();
		cleanup->s_sp2->cleanup();
		cleanup->s_sp3->cleanup();
		delete cleanup->s_sp;
		delete cleanup->s_sp2;
		delete cleanup->s_sp3;
		delete cleanup;
	}
	Shapes::ShapesShader & Shapes::ShapesShader::get_instance()
	{
		// Ensure only one instance of the shader is ever created
		if (s_shad == nullptr)
		{
			s_shad = std::shared_ptr<ShapesShader>(new ShapesShader(), cleanup_shader);
			s_shad->init_shader();
		}
		return *s_shad;
	}
}
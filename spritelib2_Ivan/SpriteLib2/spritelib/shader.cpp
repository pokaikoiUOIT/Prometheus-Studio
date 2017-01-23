#include "shader.h"

#include "spritelib.h"

#include <fstream>
#include <string>

namespace spritelib
{
	Shader::Shader()
	{
	}
	Shader & Shader::load_shader(Type a_shaderType, std::string a_shaderLoc)
	{
		m_shader = glCreateShader(a_shaderType);

		// Read the shader
		std::ifstream file(a_shaderLoc);
		std::string shaderContents((std::istreambuf_iterator<char>(file)),
			std::istreambuf_iterator<char>());
		char* buffer = &shaderContents[0];

		// Attach the shader source
		glShaderSource(m_shader, 1, &reinterpret_cast<GLchar*>(buffer), GL_NONE);

		return *this;
	}
	Shader & Shader::shader_from_string(Type a_shaderType, std::string a_shader)
	{
		m_shader = glCreateShader(a_shaderType);
		char* buffer = &a_shader[0];

		// Attach the shader source
		glShaderSource(m_shader, 1, &reinterpret_cast<GLchar*>(buffer), GL_NONE);

		return *this;
	}
	Shader & Shader::compile_shader()
	{
		// Try to compile the shader
		glCompileShader(m_shader);

		// Get the status from opengl, and print out the results from compiling the shader
		GLint isCompiled = 0;
		glGetShaderiv(m_shader, GL_COMPILE_STATUS, &isCompiled);
		if (isCompiled == GL_FALSE)
		{
			GLint maxLength = 0;
			glGetShaderiv(m_shader, GL_INFO_LOG_LENGTH, &maxLength);

			// The maxLength includes the NULL character
			std::vector<GLchar> errorLog(maxLength);
			glGetShaderInfoLog(m_shader, maxLength, &maxLength, &errorLog[0]);

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0C);
			printf("ERR: %s\n", &errorLog[0]);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);

			glDeleteShader(m_shader); // Don't leak the shader.
		}

		return *this;
	}

	void Shader::cleanup()
	{
		glDeleteShader(m_shader);
	}

	ShaderProgram::ShaderProgram()
	{
		m_shaderProg = glCreateProgram();
	}

	ShaderProgram & ShaderProgram::add_shader(Shader a_shader)
	{
		auto shared = std::make_shared<Shader>(a_shader);

		// Attach the shader and add it to the list ofattached shaders
		glAttachShader(m_shaderProg, shared->m_shader);
		m_shaders.push_back(shared);

		return *this;
	}
	ShaderProgram & ShaderProgram::link_program()
	{
		glLinkProgram(m_shaderProg);

		return *this;
	}
	ShaderProgram & ShaderProgram::use_program()
	{
		glUseProgram(m_shaderProg);

		return *this;
	}
	ShaderProgram & ShaderProgram::set_int(std::string a_loc, int a_value)
	{
		glUniform1i(get_loc(a_loc), a_value);
		return *this;
	}
	ShaderProgram & ShaderProgram::set_float(std::string a_loc, float a_value)
	{
		glUniform1f(get_loc(a_loc), a_value);
		return *this;
	}
	ShaderProgram & ShaderProgram::set_vec2(std::string a_loc, float * a_value)
	{
		glUniform2f(get_loc(a_loc), a_value[0], a_value[1]);
		return *this;
	}
	ShaderProgram & ShaderProgram::set_vec3(std::string a_loc, float * a_value)
	{
		glUniform3f(get_loc(a_loc), a_value[0], a_value[1], a_value[2]);
		return *this;
	}
	ShaderProgram & ShaderProgram::set_vec4(std::string a_loc, float * a_value)
	{
		glUniform4f(get_loc(a_loc), a_value[0], a_value[1], a_value[2], a_value[3]);
		return *this;
	}
	ShaderProgram & ShaderProgram::set_mat4(std::string a_loc, float * a_value)
	{
		glUniformMatrix4fv(get_loc(a_loc), 1, GL_FALSE, a_value);
		return *this;
	}

	void ShaderProgram::cleanup()
	{
		glDeleteProgram(m_shaderProg);

		for (auto itr = m_shaders.begin(), itrEnd = m_shaders.end(); itr != itrEnd; itr++)
			(*itr)->cleanup();
	}

	int ShaderProgram::get_loc(std::string a_location)
	{
		if (m_uniformLocations.find(a_location) == m_uniformLocations.end())
		{
			m_uniformLocations[a_location] = glGetUniformLocation(m_shaderProg, &a_location[0]);
		}
		return m_uniformLocations[a_location];
	}

	std::shared_ptr<ShaderProgram::PassThrough> ShaderProgram::PassThrough::s_shad = std::shared_ptr<ShaderProgram::PassThrough>(nullptr);
	ShaderProgram::PassThrough::PassThrough()
	{
	}
	void ShaderProgram::PassThrough::init_shader()
	{
		s_vert = new Shader();
		s_frag = new Shader();
		s_sp = new ShaderProgram();

		s_vert->load_shader(Shader::VERTEX, "assets/PassthroughTextureVert.glsl")
			.compile_shader();

		s_frag->load_shader(Shader::FRAGMENT, "assets/PassthroughTextureFrag.glsl")
			.compile_shader();

		s_sp->add_shader(*s_vert)
			.add_shader(*s_frag)
			.link_program();
	}
	void ShaderProgram::PassThrough::cleanup_shader(ShaderProgram::PassThrough * cleanup)
	{
		cleanup->s_vert->cleanup();
		cleanup->s_frag->cleanup();
		cleanup->s_sp->cleanup();
		delete cleanup->s_sp;
		delete cleanup;
	}
	ShaderProgram::PassThrough & ShaderProgram::PassThrough::get_instance()
	{
		// Ensure only one instance of the shader is ever created
		if (s_shad == nullptr)
		{
			s_shad = std::shared_ptr<PassThrough>(new PassThrough(), cleanup_shader);
			s_shad->init_shader();
		}
		return *s_shad;
	}
}
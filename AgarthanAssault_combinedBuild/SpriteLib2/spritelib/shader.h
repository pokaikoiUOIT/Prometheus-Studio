#pragma once
#include <string>
#include <vector>
#include <memory>
#include <unordered_map>

namespace spritelib
{
	class ShaderProgram;
	class Sprite;

	class Shader
	{
		friend ShaderProgram;
	public:
		Shader();
		
		enum Type {
			VERTEX = 0x8B31,
			GEOMETRY = 0x8DD9,
			FRAGMENT = 0x8B30,
		};

		Shader& load_shader(Type a_shaderType, std::string a_shaderLoc);
		Shader& shader_from_string(Type a_shaderType, std::string a_shader);
		Shader& compile_shader();

		void cleanup();

	private:
		unsigned int m_shader;
	};

	class ShaderProgram
	{
		friend Sprite;
	public:
		ShaderProgram();

		ShaderProgram& add_shader(Shader a_shader);
		ShaderProgram& link_program();
		ShaderProgram& use_program();

		ShaderProgram& set_int(std::string a_loc, int a_value);
		ShaderProgram& set_float(std::string a_loc, float a_value);
		ShaderProgram& set_vec2(std::string a_loc, float* a_value);
		ShaderProgram& set_vec3(std::string a_loc, float* a_value);
		ShaderProgram& set_vec4(std::string a_loc, float* a_value);
		ShaderProgram& set_mat4(std::string a_loc, float* a_value);

		void cleanup();

	private:
		struct PassThrough
		{
		private:
			PassThrough();

			void init_shader();
			static void cleanup_shader(PassThrough *cleanup);

			static std::shared_ptr<PassThrough> s_shad;
			
		public:
			static PassThrough& get_instance();

			Shader* s_vert;
			Shader* s_frag;
			ShaderProgram* s_sp;
		};

		int get_loc(std::string a_location);

		unsigned int m_shaderProg;
		std::vector<std::shared_ptr<Shader>> m_shaders;
		std::unordered_map<std::string, unsigned int> m_uniformLocations;
	};
}
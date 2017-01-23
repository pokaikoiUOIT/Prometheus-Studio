#pragma once

#define PI 3.14159265359

namespace spritelib
{
	namespace math
	{
		class Vector3;
		class Matrix4x4
		{
		public:
			static float s_identity[16];

			float m_data[16];

			Matrix4x4();
			Matrix4x4(float a_data[16]);

			Matrix4x4& make_identity();
			Matrix4x4 multiply(Matrix4x4 a_matrix);
			
			static Matrix4x4 ortho(float a_left, float a_right, float a_bottom, float a_top, float a_near, float a_far);
			static Matrix4x4 translate(Vector3 a_vec);
			static Matrix4x4 scale(Vector3 a_vec);
			static Matrix4x4 rotate(float a_angle);
		};
	}
}
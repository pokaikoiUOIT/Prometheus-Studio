#include "matrix4x4.h"

#include <memory>
#include <math.h>

#include "vector3.h"

namespace spritelib
{
	namespace math
	{
		float Matrix4x4::s_identity[16] = 
		{ 
			1.0f, 0.0f, 0.0f, 0.0f,
			0.0f, 1.0f, 0.0f, 0.0f,
			0.0f, 0.0f, 1.0f, 0.0f,
			0.0f, 0.0f, 0.0f, 1.0f,
		};

		Matrix4x4::Matrix4x4()
		{
			std::fill(std::begin(m_data), std::end(m_data), 0.0f);
		}

		Matrix4x4::Matrix4x4(float a_data[16])
		{
			memcpy(m_data, a_data, 16 * sizeof(float));
		}

		Matrix4x4& Matrix4x4::make_identity()
		{
			memcpy(m_data, s_identity, 16 * sizeof(float));
			return *this;
		}

		Matrix4x4 Matrix4x4::ortho(float a_left, float a_right, float a_bottom, float a_top, float a_near, float a_far)
		{
			Matrix4x4 ret = Matrix4x4(s_identity);

			ret.m_data[0 + 0 * 4] = 2.0f / (a_right - a_left);
			ret.m_data[1 + 1 * 4] = 2.0f / (a_top - a_bottom);
			ret.m_data[2 + 2 * 4] = 2.0f / (a_near - a_far);
			ret.m_data[0 + 3 * 4] = (a_left + a_right) / (a_left - a_right);
			ret.m_data[1 + 3 * 4] = (a_bottom + a_top) / (a_bottom - a_top);
			ret.m_data[2 + 3 * 4] = (a_far + a_near) / (a_far - a_near);

			return ret;
		}

		Matrix4x4 Matrix4x4::translate(Vector3 a_vec)
		{
			Matrix4x4 ret = Matrix4x4(s_identity);

			ret.m_data[0 + 3 * 4] = a_vec.x;
			ret.m_data[1 + 3 * 4] = a_vec.y;
			ret.m_data[2 + 3 * 4] = a_vec.z;

			return ret;
		}

		Matrix4x4 Matrix4x4::scale(Vector3 a_vec)
		{
			Matrix4x4 ret = Matrix4x4(s_identity);

			ret.m_data[0 + 0 * 4] *= a_vec.x;
			ret.m_data[1 + 1 * 4] *= a_vec.y;
			ret.m_data[2 + 2 * 4] *= a_vec.z;

			return ret;
		}

		Matrix4x4 Matrix4x4::rotate(float a_angle)
		{
			Matrix4x4 ret = Matrix4x4(s_identity);

			float r = (float)((PI / 180.0f) * a_angle);
			float c = (float)cos(r);
			float s = (float)sin(r);

			ret.m_data[0 + 0 * 4] = c;
			ret.m_data[1 + 0 * 4] = s;
			ret.m_data[0 + 1 * 4] = -s;
			ret.m_data[1 + 1 * 4] = c;

			return ret;
		}

		Matrix4x4 Matrix4x4::multiply(Matrix4x4 a_matrix)
		{
			Matrix4x4 ret = Matrix4x4();

			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					float sum = 0.0f;
					for (int k = 0; k < 4; k++)
					{
						sum += m_data[j + k * 4] * a_matrix.m_data[k + i * 4];
					}
					ret.m_data[j + i * 4] = sum;
				}
			}
			return ret;
		}
	}
}
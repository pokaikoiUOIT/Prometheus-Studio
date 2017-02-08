#pragma once

namespace spritelib
{
	namespace math
	{
		class Vector3
		{
		public:
			float x, y, z;

			static Vector3 one;
			static Vector3 zero;

			static Vector3 right;
			static Vector3 left;
			static Vector3 up;
			static Vector3 down;
			static Vector3 forward;
			static Vector3 backward;

			Vector3::Vector3();
			Vector3::Vector3(float a_value);
			Vector3::Vector3(float a_x, float a_y);
			Vector3::Vector3(float a_x, float a_y, float a_z);

			Vector3 Vector3::multiply(Vector3 a_other);
			Vector3 Vector3::multiply(float a_other);

			Vector3 Vector3::divide(Vector3 a_other);
			Vector3 Vector3::divide(float a_other);

			Vector3 Vector3::add(Vector3 a_other);
			Vector3 Vector3::add(float a_other);

			Vector3 Vector3::subtract(Vector3 a_other);
			Vector3 Vector3::subtract(float a_other);

			Vector3 Vector3::cross(Vector3 a_other);
			Vector3 Vector3::normalize();
			
			float Vector3::dot(Vector3 a_other);
			float Vector3::magnitude();

		};
	}
}
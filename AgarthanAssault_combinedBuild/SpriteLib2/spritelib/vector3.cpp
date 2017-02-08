#include "vector3.h"

#include <math.h>

namespace spritelib
{
	namespace math
	{
		Vector3 Vector3::one = Vector3(1.0f, 1.0f, 1.0f);
		Vector3 Vector3::zero = Vector3(0.0f, 0.0f, 0.0f);

		Vector3 Vector3::left		= Vector3(-1.0f, 0.0f, 0.0f);
		Vector3 Vector3::right		= Vector3(1.0f, 0.0f, 0.0f);
		Vector3 Vector3::down		= Vector3(0.0f, -1.0f, 0.0f);
		Vector3 Vector3::up			= Vector3(0.0f, 1.0f, 0.0f);
		Vector3 Vector3::backward	= Vector3(0.0f, 0.0f, -1.0f);
		Vector3 Vector3::forward	= Vector3(0.0f, 0.0f, 1.0f);

		Vector3::Vector3()
		{
			x = 0.0f;
			y = 0.0f;
			z = 0.0f;
		}

		Vector3::Vector3(float a_value) : Vector3(a_value, a_value, a_value)
		{

		}

		Vector3::Vector3(float a_x, float a_y) : Vector3(a_x, a_y, 0.0f)
		{

		}

		Vector3::Vector3(float a_x, float a_y, float a_z)
		{
			x = a_x;
			y = a_y;
			z = a_z;
		}

		Vector3 Vector3::multiply(Vector3 a_other)
		{
			return Vector3(x * a_other.x, y * a_other.y, z * a_other.z);
		}

		Vector3 Vector3::multiply(float a_other)
		{
			return Vector3(x * a_other, y * a_other, z * a_other);
		}

		Vector3 Vector3::divide(Vector3 a_other)
		{
			return Vector3(x / a_other.x, y / a_other.y, z / a_other.z);
		}

		Vector3 Vector3::divide(float a_other)
		{
			return Vector3(x / a_other, y / a_other, z / a_other);
		}

		Vector3 Vector3::add(Vector3 a_other)
		{
			return Vector3(x + a_other.x, y + a_other.y, z + a_other.z);
		}

		Vector3 Vector3::add(float a_other)
		{
			return Vector3(x + a_other, y + a_other, z + a_other);
		}

		Vector3 Vector3::subtract(Vector3 a_other)
		{
			return Vector3(x - a_other.x, y - a_other.y, z - a_other.z);
		}

		Vector3 Vector3::subtract(float a_other)
		{
			return Vector3(x - a_other, y - a_other, z - a_other);
		}

		Vector3 Vector3::cross(Vector3 a_other)
		{
			float newX = y * a_other.z - z * a_other.y;
			float newY = z * a_other.x - x * a_other.z;
			float newZ = x * a_other.y - y * a_other.x;

			return Vector3(newX, newY, newZ);
		}

		float Vector3::magnitude()
		{
			return (float)sqrt(x * x + y * y + z * z);
		}

		Vector3 Vector3::normalize()
		{
			return divide(Vector3(magnitude()));
		}

		float Vector3::dot(Vector3 a_other)
		{
			return (x * a_other.x + y * a_other.y + z * a_other.z);
		}
	}
}
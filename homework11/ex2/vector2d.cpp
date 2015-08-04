#include <cmath>
#include "vector2d.h"

namespace math
{
	Vector2d Vector2d::operator+(const Vector2d& other) const
	{
		return Vector2d(x + other.x, y + other.y);
	}

	Vector2d Vector2d::operator-(const Vector2d& other) const
	{
		return Vector2d(x - other.x, y - other.y);
	}

	double Vector2d::operator*(const Vector2d& other) const
	{
		return x * other.x + y * other.y;
	}

	double Vector2d::vector_product(const Vector2d& other) const
	{
		return x * other.y - y * other.x;
	}

	Vector2d Vector2d::rotate(double theta) const
	{
		return Vector2d(x * std::cos(theta) - y * std::sin(theta),
			            x * std::sin(theta) + y * std::cos(theta));
	}
}
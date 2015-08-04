#ifndef VECTOR2D_H
#define VECTOR2D_H

//A library for 2 dimensional vector

namespace math
{
	const double PI = 3.1415926;

	struct Vector2d
	{
		//data
		double x;
		double y;

		Vector2d(double xx, double yy) :x(xx), y(yy){}//constructor
		Vector2d operator+(const Vector2d& other) const;
		Vector2d operator-(const Vector2d& other) const;
		double operator*(const Vector2d& other) const;//dot product
		double vector_product(const Vector2d& other) const;//return the norm of vector product
		Vector2d rotate(double theta) const;//return the vector rotated theta(rad)
	};
}

#endif //VECTOR2D_H
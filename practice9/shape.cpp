#include "shape.h"
#include <string>
#include <iostream>
#include <stdexcept>

const double Pi = 3.1415926;

//Shape
void Shape::print() const
{
	std::cout << "Error: Shape::print called." << std::endl;
}

//Circle
Circle::Circle(double r) :radius(r) //constructor
{
	if (radius <= 0){//check
		throw std::runtime_error("Circle: invalid radius");
	}
}

double Circle::getArea() const
{
	return Pi * radius * radius;
}

void Circle::setRadius(double r)
{
	if (r > 0){//check
		radius = r;
	}
	else{
		throw std::runtime_error("Circle: invalid radius");
	}
}

//Square
Square::Square(double a) :sideLength(a)//constructor
{
	if (sideLength <= 0){
		throw std::runtime_error("Square: invalid side length");
	}
}

void Square::setSideLength(double a)
{
	if (a > 0){//check
		sideLength = a;
	}
	else{
		throw std::runtime_error("Square: invalid side length");
	}
}

//Cylinder
Cylinder::Cylinder(double r, double h) :radius(r), height(h)//constructor
{
	if ((radius <= 0) || (height <= 0)){
		throw std::runtime_error("Cylinder: invalid data");
	}
}

void Cylinder::setRadius(double r)
{
	if (r > 0){//check
		radius = r;
	}
	else{
		throw std::runtime_error("Cylinder: invalid radius");
	}
}

void Cylinder::setHeight(double h)
{
	if (h > 0){//check
		height = h;
	}
	else{
		throw std::runtime_error("Cylinder: invalid height");
	}
}

double Cylinder::getArea() const
{
	return 2 * Pi * radius * radius + 2 * Pi * radius * height;
}

double Cylinder::getVolume() const
{
	return Pi * radius * radius * height;
}

//Cube
Cube::Cube(double a) :sideLength(a)//constructor
{
	if (sideLength <= 0){
		throw std::runtime_error("Cube: invalid side length");
	}
}

void Cube::setSideLength(double a)
{
	if (a > 0){//check
		sideLength = a;
	}
	else{
		throw std::runtime_error("Cube: invalid side length");
	}
}

double Cube::getArea() const
{
	return 6 * sideLength * sideLength;
}

double Cube::getVolume() const
{
	return sideLength * sideLength * sideLength;
}
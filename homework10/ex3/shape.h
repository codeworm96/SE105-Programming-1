#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include <stdexcept>
#include <iostream>

class Shape
{
public:
	virtual void print() const = 0;
};

class TwoDimensionalShape :public Shape
{
public:
	virtual double getArea() const = 0;//area
	void print() const//print for 2D shape
	{
		std::cout << "two dimensional shape" << std::endl;
		std::cout << "Area: " << getArea() << std::endl;
	}
};

class ThreeDimensionalShape :public Shape
{
public:
	virtual double getArea() const = 0;//surface area
	virtual double getVolume() const = 0;//volume
	void print() const//print for 3D shape
	{
		std::cout << "three dimensional shape" << std::endl;
		std::cout << "Area: " << getArea() << std::endl;
		std::cout << "Volume: " << getVolume() << std::endl;
	}
};

class Circle :public TwoDimensionalShape
{
public:
	Circle(double r);//constructor
	double getArea() const;
	//accessor
	double getRadius() const
	{
		return radius;
	}
	void setRadius(double r);
private:
	double radius;
};

class Square :public TwoDimensionalShape
{
public:
	Square(double a);//constructor
	double getArea() const
	{
		return sideLength * sideLength;
	}
	//accessor
	double getSideLength() const
	{
		return sideLength;
	}
	void setSideLength(double a);
private:
	double sideLength;
};

class Cylinder :public ThreeDimensionalShape
{
public:
	Cylinder(double r, double h);//constructor
	//accessors
	double getRadius() const
	{
		return radius;
	}
	void setRadius(double r);
	double getHeight() const
	{
		return height;
	}
	void setHeight(double h);

	double getArea() const;
	double getVolume() const;
private:
	double radius;
	double height;
};

class Cube :public ThreeDimensionalShape
{
public:
	Cube(double a);//constructor
	//accessors
	double getSideLength() const
	{
		return sideLength;
	}
	void setSideLength(double a);

	double getArea() const;
	double getVolume() const;
private:
	double sideLength;
};
#endif //SHAPE_H
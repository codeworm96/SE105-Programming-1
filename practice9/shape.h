#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include <stdexcept>
#include <iostream>

class Shape
{
public:
	virtual void print() const;
};

class TwoDimensionalShape :public Shape
{
public:
	virtual double getArea() const//area
	{
		throw std::runtime_error("getArea in TwoDimensionalShape called");
	}
	void print() const//print for 2D shape
	{
		std::cout << "two dimensional shape" << std::endl;
		std::cout << "Area: " << getArea() << std::endl;
	}
};

class ThreeDimensionalShape :public Shape
{
public:
	virtual double getArea() const//surface area
	{
		throw std::runtime_error("getArea in ThreeDimensionalShape called");
	}
	virtual double getVolume() const//volume
	{
		throw std::runtime_error("getVolume in ThreeDimensionalShape called");
	}
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
/*本道题目的题号是：1
*要求是:
Rectangle：Create a class Rectangle with attributes length and width , each of which defaults to 1;
a)Provide member functions that calculate the perimeter and the area of the rectangle.
b)Also provide set and get functions for the length and width attributes. The
set functions should verify that length and width are each integer numbers larger than 0 and less than 20.
c) Write draw function to display the Rectangle.
（注意：在我们学习图形化输出之前，你可以采用文本方式打印一个矩形。）
d)Write a driver program to test class Rectangle
*/
#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle
{
public:
	class Invalid{};//exception
	//default constructor
	Rectangle() :length(1), width(1){}

	int get_perimeter() const { return 2 * (length + width); }
	int get_area() const { return width * length; }
	//getters
	int get_length() const { return length; }
	int get_width() const { return width; }
	//setters
	void set_length(int l);
	void set_width(int w);

	void draw();
private:
	int length;
	int width;
};

#endif //RECTANGLE_H
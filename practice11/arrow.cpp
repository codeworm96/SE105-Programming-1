#include "arrow.h"
#include "Graph.h"
#include "Point.h"
#include <stdexcept>
#include <cmath>

namespace Graph_lib
{
	Arrow::Arrow(const Point& begin, const Point& end, int width, int head_length)//constructor
	{
		//the line
		Shape::add(begin);
		Shape::add(end);

		if (width <= 0||head_length <= 0){//check
			throw std::runtime_error("invalid arrow");
		}

		//the head
		//linear algebra
		//vector of the line
		int xx = begin.x - end.x;
		int yy = begin.y - end.y;
		double len = sqrt(xx*xx + yy*yy);//length of the line;
		//(xx,yy) is perpendicular to (-yy,xx)
		Point mid(end.x + int(xx / len * head_length), end.y + int(yy / len * head_length));
		head.add(end);
		Point p1(mid.x - int(yy / len*width), mid.y + int(xx / len*width));
		head.add(p1);
		Point p2(mid.x + int(yy / len*width), mid.y - int(xx / len*width));
		head.add(p2);
		head.set_fill_color(head.color());
	}

	void Arrow::draw_lines() const
	{
		Shape::draw_lines();//draw the line
		head.draw_lines();//draw the head
	}

	void Arrow::move(int dx, int dy)
	{
		Shape::move(dx, dy);//move the line
		head.move(dx, dy);//move the head;
	}
}
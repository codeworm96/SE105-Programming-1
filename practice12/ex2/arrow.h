#include "Graph.h"
#include "Point.h"

//draw arrow

namespace Graph_lib
{
	class Arrow :public Shape
	{
	public:
		Arrow(const Point& begin, const Point& end, int width = 4, int head_length = 10);//constructor
		void draw_lines() const;
		void move(int dx, int dy); // move the shape +=dx and +=dy
		void set_color(Color c);  //set the color of the arrow
	private:
		Polygon head;
	};
}
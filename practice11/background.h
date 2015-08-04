#include "Graph.h"
#include "Point.h"

//The background behind text

namespace Graph_lib
{
	class Background :public Shape
	{
	public:
		Background(const Point& p, int width, int height, unsigned int num = 0,int deco_len = 30);//constructor
		void draw_lines() const;
		void move(int dx, int dy); // move the shape +=dx and +=dy
		void set_fill_color(Color col);
		virtual ~Background();//destructor
	private:
		Background(const Background&);               // prevent copying
		Background& operator=(const Background&);

		vector < Rectangle* > rects;//restore rectangles
	};
}
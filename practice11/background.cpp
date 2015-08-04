#include "Graph.h"
#include "Point.h"
#include "background.h"
#include <stdexcept>

namespace Graph_lib{
	Background::Background(const Point& p, int width, int height, unsigned int num, int deco_len)
	{
		if (deco_len <= 0){//check
			throw std::runtime_error("invalid length");
		}
		rects.push_back(new Rectangle(p, width, height));//The bigest one
		Point pp = p;
		for (unsigned int i = 0; i < num; ++i){
			//offest
			pp.x -= deco_len / 2;
			pp.y -= deco_len / 2;
			rects.push_back(new Rectangle(pp, deco_len, height));//decorations
		}
	}

	void Background::draw_lines() const
	{
		//draws rectangles in correct order
		for (int i = rects.size() - 1; i >= 0; --i){
			rects[i]->draw_lines();
		}
	}

	void Background::move(int dx, int dy)
	{
		//move all rectangles
		for (int i = 0; i < rects.size(); ++i){
			rects[i]->move(dx, dy);
		}
	}
	Background::~Background()
	{
		//dispose rectangles
		for (int i = 0; i < rects.size(); ++i){
			delete rects[i];
		}
	}

	void Background::set_fill_color(Color col)
	{
		//change each rectangle
		for (int i = 0; i < rects.size(); ++i){
			rects[i]->set_fill_color(col);
		}
	}
}
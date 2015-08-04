#include "Graph.h"
#include "ski_area.h"
#include "strategy.h"
#include <string>
#include <vector>
#include <sstream>
#include "ski_area_gui.h"

void Ski_area_gui::draw_lines() const
{
	int r = sa->get_r();
	int c = sa->get_c();
	for (int i = 0; i < r; ++i){
		for (int j = 0; j < c; ++j){
			Graph_lib::Rectangle rt(Point(pos.x + j*width, pos.y + i*height), width, height);
			ostringstream oss;
			oss << sa->get_height(i + 1, j + 1);
			if (comment[i][j] != ""){
				oss << '(' << comment[i][j] << ')';
			}
			Graph_lib::Text t(Point(pos.x + j*width + width / 2, pos.y + i*height + height), oss.str());
			if (hl[i][j]){
				t.set_color(Graph_lib::Color::white);
				rt.set_fill_color(Graph_lib::Color::black);
			}
			rt.draw();
			t.draw();
		}
	}
}

Ski_area_gui::Ski_area_gui(Point p, const Ski_area& ski_area, int w, int h) :pos(p), sa(&ski_area), width(w), height(h)
{
	int r = sa->get_r();
	int c = sa->get_c();
	comment.resize(r);
	hl.resize(r);
	for (int i = 0; i < r; ++i){
		comment[i].resize(c);
		hl[i].resize(c);
		for (int j = 0; j < c; ++j){
			comment[i][j] = "";
			hl[i][j] = false;
		}
	}
}
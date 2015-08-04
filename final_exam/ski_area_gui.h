#ifndef SKI_AREA_GUI_H
#define SKI_AREA_GUI_H

#include "Graph.h"
#include "ski_area.h"
#include "strategy.h"
#include <string>
#include <vector>

class Ski_area_gui :public Graph_lib::Shape
{
public:
	Ski_area_gui(Point p, const Ski_area& ski_area, int w, int h);
	void draw_lines() const;
	void set_comment(Pos p, const std::string& com){ comment[p.x - 1][p.y - 1] = com; }
	void set_hl(Pos p, bool h){ hl[p.x - 1][p.y - 1] = h; }
private:
	const Ski_area* sa;
	Point pos;
	int width;
	int height;
	std::vector<std::vector<std::string> > comment;
	std::vector<std::vector<bool> > hl;
};

#endif //SKI_AREA_GUI_H
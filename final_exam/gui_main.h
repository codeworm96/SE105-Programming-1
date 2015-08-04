#ifndef GUI_MAIN_H
#define GUI_MAIN_H

#include "Window.h"
#include "GUI.h"
#include "ski_area.h"
#include "ski_area_gui.h"
#include <string>

//size
const int WIDTH = 100;
const int HEIGHT = 40;

//Window size
const int MAXX = 800;
const int MAXY = 600;

class MainGUI :public Graph_lib::Window
{
public:
	MainGUI(Point tl);//constructor
private:
	Graph_lib::In_box inx;
	Graph_lib::In_box iny;
	Graph_lib::Out_box outd;
	Graph_lib::Text l1;
	Graph_lib::Text l2;
	Graph_lib::Text l3;
	Graph_lib::Button next1;
	Graph_lib::Button next2;
	Ski_area ski_area;
	Ski_area_gui sa_gui;
	int sx, sy;
	int cx, cy;
	int d;
	Strategy* strategy1;
	Strategy* strategy2;
	//call backs
	static void cb_next1(Graph_lib::Address, Graph_lib::Address pw)
	{
		Graph_lib::reference_to<MainGUI>(pw).next(Graph_lib::reference_to<MainGUI>(pw).strategy1);
	};
	static void cb_next2(Graph_lib::Address, Graph_lib::Address pw)
	{
		Graph_lib::reference_to<MainGUI>(pw).next(Graph_lib::reference_to<MainGUI>(pw).strategy2);
	};
	void next(Strategy* s);
};

#endif //GUIMAIN
/*本道题目的题号是：1
*要求是：绘制 12.8节中的文件结构图。该图如下
*/
#include "Graph.h"
#include "Simple_window.h"
#include <stdexcept>
#include <iostream>
//extend Graph_lib (see background.h/cpp arrow.h/cpp)
#include "background.h"
#include "arrow.h"

using namespace std;
using namespace Graph_lib;

const int color_red = Color::red;
const int color_orange = Color::dark_yellow;
const int color_yellow = Color::yellow;
const int color_cyan = Color::cyan;


int main()
try{
	//create window
	Point tl(100, 30);    // top-left corner of our window
	Simple_window win(tl, 600, 600, "Canvas");

	//block FLTK headers
	Background fltk_h_bg(Point(250, 50), 110, 50, 2);
	fltk_h_bg.set_fill_color(color_red);
	Text fltk_h_t(Point(255, 80), "FLTK headers");
	fltk_h_t.set_font(Font::times);
	win.attach(fltk_h_bg);
	win.attach(fltk_h_t);

	//block FLTK code
	Background fltk_code_bg(Point(480, 100), 90, 50, 2);
	fltk_code_bg.set_fill_color(color_red);
	Text fltk_code_t(Point(485, 130), "FLTK code");
	fltk_code_t.set_font(Font::times);
	win.attach(fltk_code_bg);
	win.attach(fltk_code_t);
	Arrow a1(Point(450, 95), Point(360, 75));
	win.attach(a1);

	//block point
	Background point_bg(Point(20, 100), 130, 50);
	point_bg.set_fill_color(color_orange);
	Text point_t(Point(25, 130), "struct Point { ... };");
	point_t.set_font(Font::times_bold);
	win.attach(point_bg);
	win.attach(point_t);

	//block Graph_h
	Background Graph_h_bg(Point(20, 200), 150, 50);
	Graph_h_bg.set_fill_color(color_orange);
	Text Graph_h_t1(Point(25, 215), "// Graphing interface:");
	Graph_h_t1.set_font(Font::times);
	Text Graph_h_t2(Point(25, 230), "struct Point { ... };");
	Graph_h_t2.set_font(Font::times_bold);
	Text Graph_h_t3(Point(25, 245), "...");
	Graph_h_t3.set_font(Font::times_bold);
	Text Graph_h_lab(Point(20, 195), "Graph.h:");
	Graph_h_lab.set_font(Font::times);
	win.attach(Graph_h_bg);
	win.attach(Graph_h_t1);
	win.attach(Graph_h_t2);
	win.attach(Graph_h_t3);
	win.attach(Graph_h_lab);
	Arrow a2(Point(95, 200), Point(85, 150));
	Arrow a3(Point(95, 200), Point(315, 100));
	win.attach(a2);
	win.attach(a3);

	//block window.h
	Background Window_h_bg(Point(220, 200), 150, 50);
	Window_h_bg.set_fill_color(color_orange);
	Text Window_h_t1(Point(225, 215), "// window interface:");
	Window_h_t1.set_font(Font::times);
	Text Window_h_t2(Point(225, 230), "class Window {...};");
	Window_h_t2.set_font(Font::times_bold);
	Text Window_h_t3(Point(225, 245), "...");
	Window_h_t3.set_font(Font::times_bold);
	Text Window_h_lab(Point(215, 195), "Window.h:");
	Window_h_lab.set_font(Font::times);
	win.attach(Window_h_bg);
	win.attach(Window_h_t1);
	win.attach(Window_h_t2);
	win.attach(Window_h_t3);
	win.attach(Window_h_lab);
	Arrow a4(Point(310, 200), Point(85, 150));
	Arrow a5(Point(310, 200), Point(315, 100));
	win.attach(a4);
	win.attach(a5);

	//block gui.h
	Background gui_h_bg(Point(430, 200), 150, 50);
	gui_h_bg.set_fill_color(color_orange);
	Text gui_h_t1(Point(435, 215), "// GUI interface:");
	gui_h_t1.set_font(Font::times);
	Text gui_h_t2(Point(435, 230), "struct In_box  {...};");
	gui_h_t2.set_font(Font::times_bold);
	Text gui_h_t3(Point(435, 245), "...");
	gui_h_t3.set_font(Font::times_bold);
	win.attach(gui_h_bg);
	win.attach(gui_h_t1);
	win.attach(gui_h_t2);
	win.attach(gui_h_t3);
	Arrow a6(Point(505, 200), Point(85, 150));
	Arrow a7(Point(505, 200), Point(315, 100));
	win.attach(a6);
	win.attach(a7);

	//Graph_cpp
	Background Graph_cpp_bg(Point(20, 300), 150, 50);
	Graph_cpp_bg.set_fill_color(color_yellow);
	Text Graph_cpp_t(Point(25, 330), "Graph code");
	Graph_cpp_t.set_font(Font::times_bold);
	Text Graph_cpp_lab(Point(20, 295), "Graph.cpp:");
	Graph_cpp_lab.set_font(Font::times);
	win.attach(Graph_cpp_bg);
	win.attach(Graph_cpp_t);
	win.attach(Graph_cpp_lab);
	Arrow a8(Point(95, 300), Point(95, 250));
	win.attach(a8);

	//Window_cpp
	Background window_cpp_bg(Point(350, 300), 150, 50);
	window_cpp_bg.set_fill_color(color_yellow);
	Text window_cpp_t(Point(355, 330), "Window code");
	window_cpp_t.set_font(Font::times_bold);
	Text window_cpp_lab(Point(320, 295), "Window.cpp:");
	window_cpp_lab.set_font(Font::times);
	win.attach(window_cpp_bg);
	win.attach(window_cpp_t);
	win.attach(window_cpp_lab);
	Arrow a9(Point(425, 300), Point(295, 250));
	Arrow a10(Point(425, 300), Point(505, 250));
	win.attach(a9);
	win.attach(a10);

	//gui_cpp
	Background gui_cpp_bg(Point(440, 400), 150, 50);
	gui_cpp_bg.set_fill_color(color_yellow);
	Text gui_cpp_t(Point(445, 430), "GUI code");
	gui_cpp_t.set_font(Font::times_bold);
	Text gui_cpp_lab(Point(440, 395), "GUI.cpp:");
	gui_cpp_lab.set_font(Font::times);
	win.attach(gui_cpp_bg);
	win.attach(gui_cpp_t);
	win.attach(gui_cpp_lab);
	Arrow a11(Point(515, 400), Point(505, 250));
	win.attach(a11);

	//our code
	Background our_bg(Point(200, 350), 150, 80);
	our_bg.set_fill_color(color_cyan);
	Text our_t1(Point(205, 365), "#include \"Graph.h\"");
	our_t1.set_font(Font::times_bold);
	Text our_t2(Point(205, 380), "#include \"Window.h\"");
	our_t2.set_font(Font::times_bold);
	Text our_t3(Point(205, 395), "int main{...}");
	our_t3.set_font(Font::times_bold);
	Text our_lab(Point(190, 345), "chapter12.cpp:");
	our_lab.set_font(Font::times);
	win.attach(our_bg);
	win.attach(our_t1);
	win.attach(our_t2);
	win.attach(our_t3);
	win.attach(our_lab);
	Arrow a12(Point(275, 350), Point(295, 250));
	Arrow a13(Point(275, 350), Point(95, 250));
	win.attach(a12);
	win.attach(a13);

	win.wait_for_button();
	return 0;
}
catch (exception& e){
	cerr << "Error: " << e.what() << endl;
	return 1;
}
catch (...){
	cerr << "Unknown error" << endl;
	return 2;
}
/*本道题目的题号是：1
*要求是：
修改Binary_tree，使用虚函数来绘制它的节点。然后，从Binary_tree
派生一个新类，对节点使用一个不同的表示（比如一个三角形）来覆盖此虚函数。
修改Binary_tree，使其接受一个或者多个参数来指出用什么类型的线来连接这些节点
为Binary_tree增加一个操作，将文本添加到节点上。
*/
#include "Graph.h"
#include "Point.h"
#include "Simple_window.h"
#include "bin_tree.h"
#include <stdexcept>
#include <iostream>

using namespace std;
using namespace Graph_lib;

//Window size
const int MAXX = 1000;
const int MAXY = 600;

int main()
try{
	//create window
	Point tl(100, 100);    // top-left corner of our window
	Simple_window win(tl, MAXX, MAXY, "Canvas");

	//bulid trees
	Tri_binary_tree tbt1(Point(10,10), 4, 480, 280, 10, &Normal_line());
	tbt1.set_fill_color(Color::red);
	tbt1.set_label("", "triangle tree with normal line");
	win.attach(tbt1);

	Tri_binary_tree tbt2(Point(510, 10), 3, 480, 280, 10, &Red_arrow_line());
	tbt2.set_label("", "triangle tree with red arrow");
	win.attach(tbt2);
	
	Binary_tree bt1(Point(10, 310), 4, 480, 280, 10, &Arrow_line());
	bt1.set_label("", "circle tree with arrow");
	win.attach(bt1);

	Binary_tree bt2(Point(510, 310), 3, 450, 280, 10, &Normal_line());
	bt2.set_label("", "root");
	bt2.set_label("l", "l");
	bt2.set_label("r", "r");
	bt2.set_label("ll", "ll");
	bt2.set_label("lr", "lr"); 
	bt2.set_label("rl", "rl"); 
	bt2.set_label("rr", "rr");
	win.attach(bt2);

	win.wait_for_button();

	return 0;
}
catch (exception& e){
	cerr << "Error: " << e.what() << endl;
	cin.get();
	cin.get();
	return 1;
}
catch (...){
	cerr << "Unknown error" << endl;
	cin.get();
	cin.get();
	return 2;
}
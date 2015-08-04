/*本道题目的题号是：1
*要求是：
定义Hexagon类（Hexagon为正六边形），构造函数的参数为中心和从中心到每个角的距离。用
Hexagon铺贴窗口的一部分区域（至少使用8个六边形）。
*/
#include "Graph.h"
#include "Simple_window.h"
#include "vector2d.h"
#include <stdexcept>
#include <iostream>
#include <cmath>

using namespace std;
using namespace Graph_lib;

//Window size
const int MAXX = 400;
const int MAXY = 400;
//distance of center and the vertices
const int dist = 20;
 
int main()
try{
	//create window
	Point tl(100, 100);    // top-left corner of our window
	Simple_window win(tl, MAXX, MAXY, "Canvas");

	//generate hexagons to cover the area
	vector<Hexagon*> hexagons;
	Point p(50, 50);//the center of the top-left hexagon
	for (int i = 0; i < 10; ++i){//10 rows
		//calculate the position of the first hexagon in the row
		Point pp(p.x, p.y + dist * cos(math::PI / 6) * i);
		if (i % 2){
			pp.x += 1.5 * dist;
		}

		while (pp.x < 300)//cover the width of the area
		{
			hexagons.push_back(new Hexagon(pp, dist));
			pp.x += 3 * dist;//next position
		}
	}

	//set fill color & attach
	for (vector<Hexagon*>::iterator iter = hexagons.begin(); iter != hexagons.end(); ++iter)
	{
		(*iter)->set_fill_color(Color::cyan);
		win.attach(**iter);
	}

	//show!
	win.wait_for_button();

	//dispose resources
	for (vector<Hexagon*>::iterator iter = hexagons.begin(); iter != hexagons.end(); ++iter)
	{
		delete *iter;
	}

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
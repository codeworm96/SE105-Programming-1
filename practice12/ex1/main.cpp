/*������Ŀ������ǣ�1
*Ҫ���ǣ�
����һ�� Binary_tree �࣬�������� Shape �ࣨ�� 14.2����������Ϊһ��������ʹ��СԲȦ��ʾһ���ڵ㣬������������Щ�ڵ�
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

	//input level
	int levels = 0;
	cout << "input the level:";
	cin >> levels;

	//bulid tree
	Binary_tree bt(Point(50,50), levels, 900, 500);
	win.attach(bt);

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
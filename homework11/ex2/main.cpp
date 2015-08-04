/*������Ŀ������ǣ�2
*Ҫ���ǣ�
����Poly���ʾ����Σ����ڹ��캯�����жϸ������Ƿ���Ĺ���һ������Ρ���ʾ����Ҫ��������Ϊ���캯���Ĳ�����
*/
#include "Graph.h"
#include "Point.h"
#include "Simple_window.h"
#include <stdexcept>
#include <iostream>

using namespace std;
using namespace Graph_lib;

//Window size
const int MAXX = 400;
const int MAXY = 400;

int main()
try{
	//create window
	Point tl(100, 100);    // top-left corner of our window
	Simple_window win(tl, MAXX, MAXY, "Canvas");

	//input the poly
	cout << "number of points: ";
	int n = 0;
	cin >> n;

	cout << "Point(x,y): " << endl;
	vector<Point> vp;
	for (int i = 0; i < n; ++i){
		int x = 0;
		int y = 0;
		cin >> x >> y;
		vp.push_back(Point(x, y));
	}

	//create poly
	Poly poly(vp);
	win.attach(poly);

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
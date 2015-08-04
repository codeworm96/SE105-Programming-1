/*本道题目的题号是：3
*要求是：
对上次上机作业(Practice9)中的TwoDimensionalShape和ThreeDimensionalShape类进行重构，使它们的
getArea和getVolume成为纯虚方法，由它们的子类提供这些方法的实现，但是print方法仍旧在这两个基类中实现，其功
能也和上次作业要求相同，即分别打印出图形，并显示面积或体积。用你上次上机作业中使用这些Shape
的程序来验证你的重构版本的正确性。
*/

#include "shape.h"
#include <vector>
#include <iostream>
using namespace std;

int main()
try{
	vector<Shape*> shapes;

	//create shapes
	Circle circle(2.0);
	shapes.push_back(&circle);

	Square square(2.0);
	shapes.push_back(&square);

	Cylinder cylinder(2.0, 3.0);
	shapes.push_back(&cylinder);

	Cube cube(2.0);
	shapes.push_back(&cube);

	//print
	vector<Shape*>::iterator iter = shapes.begin();
	vector<Shape*>::iterator end = shapes.end();
	for (; iter != end; ++iter){
		cout << "=====================" << endl;
		(*iter)->print();
	}
	return 0;
}
catch (runtime_error& e){
	cerr << "Error: " << e.what() << endl;
	return 1;
}
catch (...){
	cerr << "Unknown error" << endl;
	return 2;
}
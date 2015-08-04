/*本道题目的题号是：1
*要求是：
develop the hierarchy
The program should print the objects determine whether each shape is a TwoDimensionalShape or a ThreeDimensionalShape.
If a shape is 2D display its area.If it is a 3D display its area and volume.
*/
#include "shape.h"
#include <vector>
#include <iostream>
using namespace std;

int main()
try{
	vector<Shape*> shapes;

	//create shapes
	Circle circle(3.0);
	shapes.push_back(&circle);

	Square square(3.0);
	shapes.push_back(&square);

	Cylinder cylinder(3.0, 3.0);
	shapes.push_back(&cylinder);

	Cube cube(3.0);
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
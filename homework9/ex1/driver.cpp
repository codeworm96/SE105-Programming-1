#include <iostream>
#include "rectangle.h"
using namespace std;

int main()
try{
	Rectangle r;
	//default test
	cout << "default length: " << r.get_length() << endl;
	cout << "default width: " << r.get_width() << endl;
	//setter test
	int l;
	int w;
	cout << "new length: ";
	cin >> l;
	cout << "new width: ";
	cin >> w;
	r.set_length(l);
	r.set_width(w);

	cout << "length: " << r.get_length() << endl;
	cout << "width: " << r.get_width() << endl;

	cout << "perimeter: " << r.get_perimeter()<<endl;
	cout << "area: " << r.get_area() << endl;
	r.draw();

	return 0;
}
catch (Rectangle::Invalid){
	cerr << "Invalid rectangle" << endl;
	return 1;
}
catch (...){
	cerr << "Unknown error" << endl;
	return 2;
}
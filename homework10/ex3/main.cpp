/*������Ŀ������ǣ�3
*Ҫ���ǣ�
���ϴ��ϻ���ҵ(Practice9)�е�TwoDimensionalShape��ThreeDimensionalShape������ع���ʹ���ǵ�
getArea��getVolume��Ϊ���鷽���������ǵ������ṩ��Щ������ʵ�֣�����print�����Ծ���������������ʵ�֣��书
��Ҳ���ϴ���ҵҪ����ͬ�����ֱ��ӡ��ͼ�Σ�����ʾ���������������ϴ��ϻ���ҵ��ʹ����ЩShape
�ĳ�������֤����ع��汾����ȷ�ԡ�
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
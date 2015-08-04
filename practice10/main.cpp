/*������Ŀ������ǣ�1
*Ҫ���ǣ��������C�����޸�ΪC++���򣬲��������еĴ���ʹ�������Ա������ȷ������ 
*/
#include "List.h"
#include "person.h"
#include "date.h"
#include "String.h"
#include <iostream>
#include <fstream>

using namespace std;

int main()
try{
	//open file
	ifstream fin("input.dat");
	if (!fin){
		throw runtime_error("file open failed");
	}
	//input
	List list;
	String name, first;
	Date d;
	while ((fin >> name >> first) && (d.input(fin))){//not end
		Person* p = new Person(name, first, d);
		list.insert(p);
	}

	list.output(cout);

	return 0;
}catch(Date::Invalid){
	cerr << "date invalid" << endl;
	return 1;
}
catch (runtime_error& e){
	cerr << "Error: " << e.what() << endl;
	return 2;
}
catch (...){
	cerr << "Unknown error" << endl;
	return 3;
}
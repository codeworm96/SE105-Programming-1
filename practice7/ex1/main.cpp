/*本道题目的题号是：1
*要求是：设计并实现一个保存(name,  age)对的Name_pairs类，其中name是一个string，age是一个double。
*/

#include "name_pairs.h"
#include <iostream>

//for testing,see name_pairs.cpp/h
int main()
try{
	Name_pairs np;
	np.read_names();
	np.read_ages();
	np.print();
	np.sort();
	np.print();
	return 0;
}
catch (std::runtime_error& e){
	std::cerr << "Error: " << e.what() << std::endl;
	return 1;
}
catch (...){
	std::cerr << "Unknown error." << std::endl;
	return 2;
}
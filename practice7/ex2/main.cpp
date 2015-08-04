/*本道题目的题号是：2
*要求是：将Name_pairs::print()函数替换为（全局）运算符<<，并定义Name_pairs的==和!=操作符。
*/

#include "name_pairs.h"
#include <iostream>

//for testing
int main()
try{
	Name_pairs np1,np2;
	np1.read_names();
	np1.read_ages();
	np2.read_names();
	np2.read_ages();
    //test <<
	std::cout << np1;
	std::cout << np2;
	//testing ==
	if (np1 == np2){
		std::cout << "==: np1==np2" << std::endl;
	}
	else{
        std::cout << "==: np1!=np2" << std::endl;
	}
	//testing !=
	if (np1 != np2){
		std::cout << "!=: np1!=np2" << std::endl;
	}
	else{
		std::cout << "!=: np1==np2" << std::endl;
	}
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
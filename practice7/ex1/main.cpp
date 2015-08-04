/*������Ŀ������ǣ�1
*Ҫ���ǣ���Ʋ�ʵ��һ������(name,  age)�Ե�Name_pairs�࣬����name��һ��string��age��һ��double��
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
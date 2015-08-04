#ifndef INPUT_H
#define INPUT_H
#include <stdexcept>
#include <iostream>

void skip_a_line();

template <class T> void checked_input(T& x)
{
	T res;
	while (true){
		if (std::cin >> res){
			x = res;
			return;//read successfully. return it
		}
		cout << "Try again." << endl;
		skip_a_line();
	}
}

#endif //INPUT_H
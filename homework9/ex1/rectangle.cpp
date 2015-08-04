#include "rectangle.h"
#include <iostream>

void Rectangle::set_length(int l)
{
	if ((l <= 0) || (l >= 20)){//verify
		throw Invalid();
	}
	length = l;
}

void Rectangle::set_width(int w)
{
	if ((w <= 0) || (w >= 20)){//verify
		throw Invalid();
	}
	width = w;
}

void Rectangle::draw()
{
	for (int i = 0; i < width; ++i){
		for (int j = 0; j < length; ++j){
			std::cout << '*';
		}
		std::cout << std::endl;
	}
}
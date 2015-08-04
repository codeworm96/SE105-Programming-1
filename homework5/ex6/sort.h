#ifndef SORT_H
#define SORT_H
#include <string>
#include <vector>

namespace sort
{
	void swap(int&, int&);
	void swap(double&, double&);
	void swap(bool&, bool&);
	void swap(std::string&, std::string&);

	void sort(std::vector<int>::iterator, std::vector<int>::iterator);
	void sort(std::vector<double>::iterator, std::vector<double>::iterator);
	void sort(std::vector<bool>::iterator, std::vector<bool>::iterator);
	void sort(std::vector<std::string>::iterator, std::vector<std::string>::iterator);
	//these functions are very similar
	//don't repeat yourself!
	/*
	template <class T> void swap(T& a, T& b)
	{
		T tmp;
		tmp = a;
		a = b;
		b = tmp;
	}
	template <class T> void sort(T begin, T end)
	{
		if (begin == end){
			return;
		}
		T j = begin;
		for (T iter = begin + 1; iter != end; ++iter){
			if (*iter < *begin){
				++j;
				swap(*j, *iter);
			}
		}
		swap(*begin, *j);
		sort(begin, j);
		sort(j + 1, end);
	}
	*/
}

#endif //SORT_H
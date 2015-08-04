#include "sort.h"
#include <string>
#include <vector>

namespace sort
{
	//4 swap ,only type is different
	void swap(int& a, int& b)
	{
		int tmp;
		tmp = a;
		a = b;
		b = tmp;
	}
	void swap(double& a, double& b)
	{
		double tmp;
		tmp = a;
		a = b;
		b = tmp;
	}
	void swap(bool& a, bool& b)
	{
		bool tmp;
		tmp = a;
		a = b;
		b = tmp;
	}
	void swap(std::string& a, std::string& b)
	{
		std::string tmp;
		tmp = a;
		a = b;
		b = tmp;
	}

	//4 sort, only type is different
	void sort(std::vector<int>::iterator begin, std::vector<int>::iterator end)
	{
		//basic case
		if (begin == end){
			return;
		}
		//partition
		std::vector<int>::iterator j = begin;
		for (std::vector<int>::iterator iter = begin + 1; iter != end; ++iter){
			if (*iter < *begin){
				++j;
				swap(*j, *iter);
			}
		}
		swap(*begin, *j);

		sort(begin, j);
		sort(j + 1, end);
	}
	void sort(std::vector<double>::iterator begin, std::vector<double>::iterator end)
	{
		//basic case
		if (begin == end){
			return;
		}
		//partition
		std::vector<double>::iterator j = begin;
		for (std::vector<double>::iterator iter = begin + 1; iter != end; ++iter){
			if (*iter < *begin){
				++j;
				swap(*j, *iter);
			}
		}
		swap(*begin, *j);

		sort(begin, j);
		sort(j + 1, end);
	}
	void sort(std::vector<bool>::iterator begin, std::vector<bool>::iterator end)
	{
		//basic case
		if (begin == end){
			return;
		}
		//partition
		std::vector<bool>::iterator j = begin;
		for (std::vector<bool>::iterator iter = begin + 1; iter != end; ++iter){
			if (*iter < *begin){
				++j;
				swap(*j, *iter);
			}
		}
		swap(*begin, *j);

		sort(begin, j);
		sort(j + 1, end);
	}
	void sort(std::vector<std::string>::iterator begin, std::vector<std::string>::iterator end)
	{
		//basic case
		if (begin == end){
			return;
		}
		//partition
		std::vector<std::string>::iterator j = begin;
		for (std::vector<std::string>::iterator iter = begin + 1; iter != end; ++iter){
			if (*iter < *begin){
				++j;
				swap(*j, *iter);
			}
		}
		swap(*begin, *j);

		sort(begin, j);
		sort(j + 1, end);
	}
}
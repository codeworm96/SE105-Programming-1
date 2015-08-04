#ifndef MATRIX
#define MATRIX

#include <iostream>
#include <vector>
using namespace std;
namespace math{
	class Matrix
	{
	public:
		//constructors
		Matrix();
		//Matrix(const Matrix&); //for vector the default is ok

		Matrix operator* (const Matrix&);//multiply
		friend ostream& operator<<(ostream&, const Matrix&);//output
		friend istream& operator>>(istream&, Matrix&);//input
	private:
		int row;
		int column;
		vector<vector<double> > data;//'> >' is for old compilers
	};
}
#endif
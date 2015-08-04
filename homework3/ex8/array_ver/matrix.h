#ifndef MATRIX
#define MATRIX

#include <iostream>
using namespace std;
namespace math{
	const int max_size = 50;

	class Matrix
	{
	public:
		//constructors
		Matrix();
		Matrix(const Matrix&);

		Matrix operator* (const Matrix&);//multiply
		friend ostream& operator<<(ostream&, const Matrix&);//output
		friend istream& operator>>(istream&, Matrix&);//input
	private:
		int row;
		int column;
		double data[max_size][max_size];
	};
}
#endif
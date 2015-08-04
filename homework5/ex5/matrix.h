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
		Matrix(int, int);//row,column
		//Matrix(const Matrix&); //for vector the default is ok

		Matrix operator* (const Matrix&);//multiply
		Matrix operator+ (const Matrix&);//addition
		Matrix operator- (const Matrix&);//subtraction
		Matrix sub_mat(int, int, int, int) const;//get sub-matrix parameter:begin_i,begin_j,row,column
		void resize(int, int);//resize a matrix parameter:row,column
		friend ostream& operator<<(ostream&, const Matrix&);//output
		friend istream& operator>>(istream&, Matrix&);//input
		//combine two matrix
		friend Matrix combineV(const Matrix&, const Matrix&);//vertical
		friend Matrix combine(const Matrix&, const Matrix&);

	private:
		int row;
		int column;
		vector<vector<double> > data;//'> >' is for old compilers
		Matrix strassen(const Matrix&);//strassen algrithm
	};
}
#endif
#include "matrix.h"
#include <iostream>
#include <stdexcept>
using namespace std;
namespace math{
	Matrix::Matrix() //default constructor
	{
		row = 0;
		column = 0;
	}

	Matrix::Matrix(const Matrix& mat) //constructor
	{
		row = mat.row;
		column = mat.column;
		//copy array;
		for (int i = 0; i < row; ++i){
			for (int j = 0; j < column; ++j){
				data[i][j] = mat.data[i][j];
			}
		}
	}

	Matrix Matrix::operator* (const Matrix& mat)
	{
		//check
		if (column != mat.row){
			throw runtime_error("Can't multiply!");
		}
		//multiply
		Matrix res;
		res.column = mat.column;
		res.row = row;
		for (int i = 0; i < res.row; ++i){
			for (int j = 0; j < res.column; ++j){
				res.data[i][j] = 0;
				for (int k = 0; k < column; ++k){
					res.data[i][j] += (data[i][k] * mat.data[k][j]);
				}
			}
		}
		return res;
	}

	ostream& operator<<(ostream& os, const Matrix& mat)//output
	{
		cout << mat.row << '*' << mat.column << " matrix:" << endl;
		for (int i = 0; i < mat.row; ++i){
			for (int j = 0; j < mat.column; ++j){
				cout << mat.data[i][j] << ' ';
			}
			cout << endl;
		}
		return os;
	}
	istream& operator>>(istream& is, Matrix& mat)//input
	{
		is >> mat.row >> mat.column;
		if ((mat.row < 1) || (mat.column<1)){
			throw runtime_error("invalid row or column");
		}
		if ((mat.row>max_size) || (mat.column > max_size)){
			throw runtime_error("the matrix is too big.");
		}
		for (int i = 0; i < mat.row; ++i){
			for (int j = 0; j < mat.column; ++j){
				is >> mat.data[i][j];
			}
		}
		if (!is){
			throw runtime_error("input fails.");
		}
		return is;
	}
}
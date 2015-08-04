#include "matrix.h"
#include <iostream>
#include <stdexcept>
using namespace std;
namespace math{
	Matrix::Matrix() //defualt constructor
	{
		row = 0;
		column = 0;
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
		//change vector size to fit
		res.data.resize(res.row);
		for (int i = 0; i < res.row; ++i){
			res.data.at(i).resize(res.column);
		}

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
		if ((mat.row < 1) || (mat.column < 1)){
			throw runtime_error("invalid row or column");
		}
		//change vector size to fit
		mat.data.resize(mat.row);
		for (int i = 0; i < mat.row; ++i){
			mat.data.at(i).resize(mat.column);
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
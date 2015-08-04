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
	Matrix::Matrix(int r, int c)
	{
		this->resize(r, c);
	}

	Matrix Matrix::operator+(const Matrix& mat)
	{
		if ((row != mat.row) || (column != mat.column)){
			throw runtime_error("Can't add");
		}
		Matrix res(row, column);
		for (int i = 0; i < row; ++i){
			for (int j = 0; j < column; ++j){
				res.data.at(i).at(j) = data.at(i).at(j) + mat.data.at(i).at(j);
			}
		}
		return res;
	}
	Matrix Matrix::operator-(const Matrix& mat)
	{
		if ((row != mat.row) || (column != mat.column)){
			throw runtime_error("Can't subtract");
		}
		Matrix res(row, column);
		for (int i = 0; i < row; ++i){
			for (int j = 0; j < column; ++j){
				res.data.at(i).at(j) = data.at(i).at(j) - mat.data.at(i).at(j);
			}
		}
		return res;
	}
	/*
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
	*/
	//here I use strassen algrithm to solve the problem
	//through it is not necessary
	//it has better time complexity
	Matrix Matrix::operator* (const Matrix& mat)
	{
		//check
		if (column != mat.row){
			throw runtime_error("Can't multiply!");
		}
		int n = 1;
		while (n < row || n < column || n < mat.row || n < mat.column){
			n *= 2;
		}
		Matrix a(*this);
		Matrix b(mat);
		a.resize(n, n);
		b.resize(n, n);//strassen require 2^k
		Matrix c(a.strassen(b));
		c.resize(row,mat.column);
		return c;
	}
	void Matrix::resize(int new_row, int new_column)//resize a matrix parameter:row,column
	{
		if (new_row < 0 || new_column < 0){
			throw runtime_error("resize failed. bad arguments.");
		}
		row = new_row;
		column = new_column;
	    data.resize(new_row);
		for (int i = 0; i < new_row; ++i){
			data.at(i).resize(new_column);
		}
	}
	Matrix Matrix::sub_mat(int x, int y, int r, int c) const
	{
		if (x<0 || y<0 || x + r>row || y + c>column){
			throw runtime_error("sub-matrix failed. bad arguments.");
		}
		Matrix res(r,c);
		for (int i = 0; i < r; ++i){
			for (int j = 0; j < c; ++j){
				res.data.at(i).at(j) = data.at(x + i).at(y + j);
			}
		}
		return res;
	}

	//a
	//b
	Matrix combineV(const Matrix& a, const Matrix& b)
	{
		if (a.column != b.column){
			throw runtime_error("Can't combine");
		}
		Matrix res(a.row + b.row, a.column);
		for (int i = 0; i < a.row; ++i){
			for (int j = 0; j < a.column; ++j){
				res.data.at(i).at(j) = a.data.at(i).at(j);
			}
		}
		for (int i = 0; i < b.row; ++i){
			for (int j = 0; j < a.column; ++j){
				res.data.at(i+a.row).at(j) = b.data.at(i).at(j);
			}
		}
		return res;
	}

	//ab
	Matrix combine(const Matrix& a, const Matrix& b)
	{
		if (a.row != b.row){
			throw runtime_error("Can't combine");
		}
		Matrix res(a.row, a.column + b.column);
		for (int i = 0; i < a.row; ++i){
			for (int j = 0; j < a.column; ++j){
				res.data.at(i).at(j) = a.data.at(i).at(j);
			}
		}
		for (int i = 0; i < a.row; ++i){
			for (int j = 0; j < b.column; ++j){
				res.data.at(i).at(j + a.column) = b.data.at(i).at(j);
			}
		}
		return res;
	}
    //strassen algrithm
	// a b * e f = r s
	// c d   g h   t u
	/*
	p1 = a * ( f - h )
	p2 = ( a + b ) *  h
	p3 = ( c +d ) * e
	p4 = d *  ( g - e )
	p5 = ( a + d ) * ( e + h )
	p6 =  ( b - d ) * ( g + h )
	p7 = ( a - c ) * ( e + f )

	r  = p5 + p4 + p6 - p2
	s = p1 + p2
	t = p3 + p4
	u = p5 + p1 - p3 - p7
	*/
	Matrix Matrix::strassen(const Matrix& mat)
	{
		int n = row;
		if (n == 1){
			Matrix res(1, 1);
			res.data.at(0).at(0) = data.at(0).at(0) * mat.data.at(0).at(0);
			return res;
 		}
		Matrix a = this->sub_mat(0, 0, n / 2, n / 2);
		Matrix b = this->sub_mat(0, n / 2, n / 2, n / 2);
		Matrix c = this->sub_mat(n / 2, 0, n / 2, n / 2);
		Matrix d = this->sub_mat(n / 2, n / 2, n / 2, n / 2);

		Matrix e = mat.sub_mat(0, 0, n / 2, n / 2);
		Matrix f = mat.sub_mat(0, n / 2, n / 2, n / 2);
		Matrix g = mat.sub_mat(n / 2, 0, n / 2, n / 2);
		Matrix h = mat.sub_mat(n / 2, n / 2, n / 2, n / 2);

		//7 mul
		Matrix p1 = a.strassen(f - h);
		Matrix p2 = (a + b).strassen(h);
		Matrix p3 = (c + d).strassen(e);
		Matrix p4 = d.strassen(g - e);
		Matrix p5 = (a + d).strassen(e + h);
		Matrix p6 = (b - d).strassen(g + h);
		Matrix p7 = (a - c).strassen(e + f);

		return combineV(combine(p5 + p4 + p6 - p2, p1 + p2), combine(p3 + p4, p5 + p1 - p3 - p7));
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
		mat.resize(mat.row, mat.column);
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
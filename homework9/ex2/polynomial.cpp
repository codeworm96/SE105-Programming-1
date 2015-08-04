#include "polynomial.h"
#include <iostream>
#include <cmath>
#include <algorithm>

//default constructor
Polynomial::Polynomial() :degree(0)
{
	coefficients = new double[1];
	coefficients[0] = 1;
}

//copy constructor
Polynomial::Polynomial(const Polynomial& other) :degree(other.degree)
{
	coefficients = new double[degree + 1];
	for (unsigned int i = 0; i <= degree; ++i){
		coefficients[i] = other.coefficients[i];
	}
}

//parameterized constructor
Polynomial::Polynomial(unsigned int d, double* pc) :degree(d)
{
	if (pc){//check for pointer
		coefficients = new double[degree + 1];
		for (unsigned int i = 0; i <= degree; ++i){
			coefficients[i] = pc[i];
		}
	}
	else{
		throw Error();
	}

}

Polynomial Polynomial::operator=(const Polynomial& other)
{
	double* p = new double[other.degree + 1];
	for (unsigned int i = 0; i <= other.degree; ++i){
		p[i] = other.coefficients[i];
	}
	degree = other.degree;
	delete [] coefficients;
	coefficients = p;
	return other;
}

void Polynomial::output_term(unsigned int id) const
{
	if (id<0 || id>degree){//range check
		throw Error();
	}

	if ((id == 0) || (std::abs(coefficients[id] - 1) >= eps && std::abs(coefficients[id] + 1) >= eps)){
		std::cout << coefficients[id];
	}
	else{
		if (std::abs(coefficients[id] + 1) < eps){
			std::cout << '-';
		}
	}
	
	if (id > 0){
		std::cout << 'x';
		if (id > 1){
			std::cout << '^' << id;
		}
	}
}

void Polynomial::output() const
{
	bool is_first = true;
	for (int i = degree; i >= 0; --i){
		if (coefficients[i] > eps){
			if (!is_first){
				std::cout << '+';
			}
			output_term(i);
			is_first = false;
		}
		if (coefficients[i] < -eps){
			output_term(i);
			is_first = false;
		}
	}
	if (is_first){
		std::cout << 0;
	}
}

void Polynomial::input()
{
	std::cout << "degree of the polynomial: ";
	std::cin >> degree;//unsigned int
	std::cout << "coeffcients: ";
	double* p = new double[degree + 1];
	for (int i = degree; i >= 0; --i){
		std::cin >> p[i];
	}
	delete[] coefficients;
	coefficients = p;
}

Polynomial Polynomial::add(const Polynomial& other) const
{
	int d = std::max(degree, other.degree);
	double* p = new double[d + 1];
	unsigned int i = 0;
	unsigned int j = 0;
	while ((i <= degree) && (j <= other.degree)){
		p[i] = coefficients[i] + other.coefficients[j];
		++i;
		++j;
	}
	//left terms
	while (i <= degree){
		p[i] = coefficients[i];
		++i;
	}
	while (j <= other.degree){
		p[j] = other.coefficients[j];
		++j;
	}

	Polynomial res(d, p);

	delete[] p;//dispose

	return res;
}

Polynomial Polynomial::subtract(const Polynomial& other) const
{
	int d = std::max(degree, other.degree);
	double* p = new double[d + 1];
	unsigned int i = 0;
	unsigned int j = 0;
	while ((i <= degree) && (j <= other.degree)){
		p[i] = coefficients[i] - other.coefficients[j];
		++i;
		++j;
	}
	//left terms
	while (i <= degree){
		p[i] = coefficients[i];
		++i;
	}
	while (j <= other.degree){
		p[j] = -other.coefficients[j];
		++j;
	}

	Polynomial res(d, p);

	delete[] p;//dispose
	return res;
}

Polynomial Polynomial::multiply(const Polynomial& other) const
{
	unsigned int d = degree + other.degree;
	double* p = new double[d + 1];
	for (unsigned int i = 0; i <= d; ++i){
		p[i] = 0;
	}
	for (unsigned int i = 0; i <= degree; ++i){
		for (unsigned int j = 0; j <= other.degree; ++j){
			p[i + j] += coefficients[i] * other.coefficients[j];
		}
	}

	Polynomial res(d, p);

	delete[] p;//dispose

	return res;
}
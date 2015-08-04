/*本道题目的题号是：2
*要求是:
a.Provide a default constructor and a parameterized constructor that enables an arbitrary
Polynomial to be constructed by providing the degree of the polynomial and the array of
coefficients. The default constructor will generate the polynomial 1.
b.Provide an overloaded operator = and a destructor.
c.Provide member function input(first input the degree of the Polynomial, then an array of coefficients),
output(you can use “x^n” to denote xn), and add, subtract, and multiply.
d.Write a driver program to test your class Polynomial.
*/
#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

const double eps = 1e-8;//accuracy

class Polynomial
{
public:
	class Error{};//exception
	//default constructor
	Polynomial();
	//copy constructor
	Polynomial(const Polynomial& other);
	//parameterized constructor
	Polynomial(unsigned int d, double* pc);
	//destructor
	~Polynomial()
	{
		delete[] coefficients;
	}

	Polynomial operator=(const Polynomial& other);

	Polynomial add(const Polynomial& other) const;
	Polynomial subtract(const Polynomial& other) const;
	Polynomial multiply(const Polynomial& other) const;
	void output() const;
	void input();//order:...x^2,x,1
private:
	unsigned int degree;
	double* coefficients;

	void output_term(unsigned int id) const;
};

#endif //POLYNOMIAL_H
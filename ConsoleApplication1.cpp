// ConsoleApplication1.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
using std::cin; using std::cout; using std::endl;

#include <cmath>
											// approximation of the exponent function can be obtained from the
											// taylor series expansion:
											// exp(a) = 1 + a + (a^2)/2! + (a^3)/3! + (a^3)/4! + ...

double my_exp(double x)						// function for calculating the exponent of 'a'
{
	double f;								// declares and difines the variable for the taylor expansion

	if (x < 0)								// if the value of 'a' is negative, the exponent is calculated from
	{										// the inverse of the exponent function of the corresponding 
		f = 1.0 / my_exp(-x);				// positive value of 'a', which is '-a'
	}
	else									
	{										
		double d;
		f = 1.0 + x;						// the first and second term of the taylor series expansion
		int n = 2;							// n is initialized at 2, because the first (n=0) and second (n=1)
											// are already included in the taylor series expansion (f)
		do
		{
			d = x;

			for (int i = 2; i <= n; i++)
			{								// term i of the taylor serie expansion is calculted by multiplying
				d *= x / i;					// the the previous term (i - 1) by a/i
			}
			f += d;							// term i is added to the taylor series expansion
			n++;
		} 
		while (d > 1.0E-10);				// when term i is larger than 1.0E-10, the term is added to the
	}										// taylor series expansion, otherwise the current value of the taylor
	return (f);								// series expansion (f) is returned
}

int main()
{
	double a = 0.0;							// initialization of a

	cout << "a = ";						
	cin >> a;							
	
	double j = my_exp(a);					// calculates the exponent of 'a' from the function exp(a)

	double k = std::exp(a);					// calculates the exponent of 'a' from cmath

	cout << "my_exp(a) = " << j << endl;
	cout << "exp(a)    = " << k << endl;
}
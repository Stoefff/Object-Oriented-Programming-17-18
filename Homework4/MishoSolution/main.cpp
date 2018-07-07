#include <iostream>
#include "Polynom.hpp"


int main()
{
	//when creating a polynomial, the user has to give power of the polynomial
	//and then he has to give the coefficients in front of the powers of x in a descending order
	//when there is no x of that power, the user can simply write 0

	int coefficients1[3] = { 6, 2, -8 }; //6x^2 + 2x - 8x
	int coefficients2[2] = { 3, -2 }; 
	double coefficients4[4] = { 3.14, 2.4, 1.3, 5.7 }; 
	int coefficients5[5] = { 1, 2, 3, 4, 5 };

	try
	{
		Polynom<int> pol1(2, coefficients1);

		Polynom<int> pol2(1, coefficients2);

		Polynom<int> pol3 = pol1 + pol2;
		std::cout << "The sum of pol1 and pol2 is: " << pol3;
		pol1--;
		std::cout << "The derivative of pol1 is " << pol1;
		std::cout << "The integral of pol2 is " << ++pol2;

		std::cout << "For x = 3, the value of pol2 is "<< pol2(3) << std::endl;
		std::cout << "Integral from 1 to 2 of pol2 is "<< pol2(1, 2) << std::endl;
		std::cout << "The second coefficient of pol1 is "<< pol1[1] << std::endl;
		std::cout << "The power of pol1 is "<< pol1(3.12) << std::endl;
		if (!pol1)
			std::cout << "This polynom is 0.\n";
		
		Polynom<double> pol4(3, coefficients4);
		std::cout << "The derivative of pol3 is "<< --pol3 << std::endl;
		pol1 %= pol2;
		std::cout << pol1;
		pol2 *= 3;

		Polynom<int> pol5(4, coefficients5);
		std::cout << "The coefficients of pol5 are: ";
		for (Polynom<int>::Iterator i(pol5.begin()); i != pol5.end(); ++i)
			//cant be used if the polynom is resized.
		{
			std::cout << *i << " ";
		}
	}
	catch (std::bad_alloc & e)
	{
		std::cerr << "Program is quitting.\n";
	}
	catch (std::invalid_argument & e)
	{
		std::cerr << "Program is qutting.\n";
	}

	return 0;
}
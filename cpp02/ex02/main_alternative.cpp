#include "Fixed.hpp"

#include <iostream>

int main(void)
{
	Fixed a(6.5f);
	Fixed b(2.5f);
	Fixed sameAsA(6.5f);
	Fixed const constA(6.5f);
	Fixed const constB(2.5f);

	std::cout << "Values: a = " << a << ", b = " << b << std::endl;
	std::cout << "Comparisons:" << std::endl;
	std::cout << "a > b: " << (a > b) << std::endl;
	std::cout << "a < b: " << (a < b) << std::endl;
	std::cout << "a >= sameAsA: " << (a >= sameAsA) << std::endl;
	std::cout << "b <= a: " << (b <= a) << std::endl;
	std::cout << "a == sameAsA: " << (a == sameAsA) << std::endl;
	std::cout << "a != b: " << (a != b) << std::endl;

	std::cout << "Arithmetic:" << std::endl;
	std::cout << "a + b = " << (a + b) << std::endl;
	std::cout << "a - b = " << (a - b) << std::endl;
	std::cout << "a * b = " << (a * b) << std::endl;
	std::cout << "a / b = " << (a / b) << std::endl;

	Fixed counter;
	std::cout << "Prefix increment: " << ++counter
		<< " (counter = " << counter << ")" << std::endl;
	std::cout << "Postfix increment: " << counter++
		<< " (counter = " << counter << ")" << std::endl;
	std::cout << "Prefix decrement: " << --counter
		<< " (counter = " << counter << ")" << std::endl;
	std::cout << "Postfix decrement: " << counter--
		<< " (counter = " << counter << ")" << std::endl;

	std::cout << "min(a, b) = " << Fixed::min(a, b) << std::endl;
	std::cout << "max(a, b) = " << Fixed::max(a, b) << std::endl;
	std::cout << "min(constA, constB) = "
		<< Fixed::min(constA, constB) << std::endl;
	std::cout << "max(constA, constB) = "
		<< Fixed::max(constA, constB) << std::endl;

	return (0);
}

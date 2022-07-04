#include <iostream>

const unsigned n = 10;

unsigned long factoriel(unsigned n)
{
	unsigned long r = 1;
	for (size_t i = 2; i <= n; i++)
	{
		r *= i;
	}

	return r;
}

int main() {
	std::cout << n << "! = " << factoriel(n) << std::endl;
	return 0;
}
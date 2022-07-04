#include <iostream>

const unsigned n = 6;
unsigned i = 0;

unsigned long fact()
{
	if (i == 1)
	{
		return 1;
	}
	unsigned tempValue = --i;
	return (tempValue * fact());
}

int main()
{
	i = n + 1;
	std::cout << n << "! = " << fact() << std::endl;
	return 0;
}

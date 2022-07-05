#include <iostream>

const unsigned n = 5;
unsigned long result = 1;
unsigned k = 0;

void printRed()
{
	++k;

	result *= 10;
	std::cout << result << " ";

	if (k < n)
	{
		printRed();
	}

	std::cout << result << " ";
	result /= 10;
}

int main() 
{
	printRed();
	return 0;
}

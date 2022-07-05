#include <iostream>

const unsigned n = 5;

void printRed(unsigned k, unsigned long result)
{
	std::cout << result << " ";
	
	if (k < n)
	{
		printRed(k + 1, result * 10);
	}

	std::cout << result << " ";
}

int main() 
{
	printRed(1, 10);

	return 0;
}
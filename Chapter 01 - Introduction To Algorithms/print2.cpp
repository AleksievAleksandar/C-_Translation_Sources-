#include <iostream>

const unsigned n = 5;
unsigned k = 0;

void printRed(unsigned long result)
{
	++k;

	std::cout << result << " ";
	if (k < n)
	{
		printRed(result * 10);
	}		
	std::cout << result << " ";
}

int main() 
{
	printRed(10);
	return 0;
}

#include <iostream>

unsigned n = 7892;

void printN(unsigned n)
{
	if (n >= 10)
	{
		printN(n / 10);
	}
	std::cout << n % 10 << " ";
}

int main() 
{
	printN(n); 
	return 0;
}

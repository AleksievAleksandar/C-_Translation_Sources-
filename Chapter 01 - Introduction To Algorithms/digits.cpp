#include <iostream>

unsigned n = 4242;

int main() 
{
	unsigned digits = 0;
	for (int i = n; i > 0; i /= 10)
	{
		++digits;
	}

	std::cout << "Броят на цифрите на " << n << " e " << digits << std::endl;
	return 0;
}

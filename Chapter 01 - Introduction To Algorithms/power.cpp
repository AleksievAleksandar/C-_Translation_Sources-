#include <iostream>

float power(const float x, const unsigned y)
{
	float res = x;

	for (size_t i = 1; i < y; i++)
	{
		res *= x;
	}
	return res;
}

int main()
{
	std::cout << power(3, 2) << std::endl;
	return 0;
}
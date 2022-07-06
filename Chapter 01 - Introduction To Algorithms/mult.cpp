#include <iostream>

constexpr size_t n = 5;
int a[n] = { 1, 2, 3, 4, 5 };

int mult()
{
	int s = 1;
	for (size_t i = 0; i < n; i++)
	{
		s *= a[i];
	}
	return s;
}

int main()
{
	std::cout << mult() << std::endl;

	return 0;
}
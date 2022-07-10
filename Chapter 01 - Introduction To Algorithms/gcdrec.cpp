#include <iostream>

constexpr unsigned a = 28;
constexpr unsigned b = 49;

unsigned gcd(const unsigned a, const unsigned b)
{
	return (b == 0) ? a : gcd(b, a % b);
}

int main()
{
	std::cout << "NOD(" << a << "," << b << ") = " << gcd(a, b) << std::endl;

	return 0;
}

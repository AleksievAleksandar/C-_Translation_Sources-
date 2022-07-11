#include <iostream>

constexpr unsigned a = 28;
constexpr unsigned b = 49;

unsigned gcd(unsigned a, unsigned b)
{
    unsigned swap;
    while (b > 0)
    {
        swap = b;
        b = a % b;
        a = swap;
    }
    return a;
}

int main()
{
    std::cout << "NOD(" << a << "," << b << ") = " << gcd(a, b) << std::endl;
    return 0;
}

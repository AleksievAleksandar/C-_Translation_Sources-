#include <stdio.h>
#include <math.h>
#include <iostream>

const unsigned n = 23;

/* Функцията връща 1 ако n е просто и 0 ако n е съставно */
char isPrime(unsigned n)
{
    unsigned i = 2;
    if (n == 2)
    {
        return 1;
    }

    while (i <= sqrt(n))
    {
        if (n % i == 0)
        {
            return 0;
        }
        ++i;
    }
    return 1;
}

int main()
{
    if (isPrime(n))
    {
        std::cout << "Числото " << n << " е просто." << std::endl;
    }
    else
    {
        std::cout << "Числото " << n << " е съставно." << std::endl;
    }
    return 0;
}

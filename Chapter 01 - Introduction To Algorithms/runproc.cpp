#include <iostream>
#include <iomanip>

#define MAXN 10000
const unsigned n = 500;

unsigned primes[MAXN], pN = 0;

char isPrime(const unsigned n)
{
    unsigned i = 0;
    while (i < pN && ((primes[i] * primes[i]) <= n))
    {
        if (n % primes[i] == 0)
        {
            return 0;
        }
        ++i;
    }
    return 1;
}

void findPrimes(const unsigned n)
{
    unsigned i = 2;
    while (i < n)
    {
        if (isPrime(i))
        {
            primes[pN] = i;
            pN++;
            std::cout << std::setw(5) << i;
        }
        ++i;
    }
}

int main()
{
    findPrimes(n);
    std::cout << std::endl;
    return 0;
}


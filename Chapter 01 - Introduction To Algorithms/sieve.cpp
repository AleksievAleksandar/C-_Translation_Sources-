#include <iostream>

#define MAXN 30000

const unsigned n = 200;

char sieve[MAXN];

void eratosten(unsigned n)
{
    unsigned j, i = 2;
    while (i <= n)
    {
        if (sieve[i] == 0)
        {
            std::cout << i << " ";
            j = i;
            while (j <= n)
            {
                sieve[j] = 1;
                j += i;
            }
        }
        ++i;
    }
}

int main()
{
    for (size_t i = 0; i < n; i++)
    {
        sieve[i] = 0;
    }
    eratosten(n);

    return 0;
}

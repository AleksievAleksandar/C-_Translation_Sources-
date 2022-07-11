#include <iostream>

#define MAXN 100

const unsigned long n = 10;

unsigned long M[MAXN + 1];

void stirling(const unsigned n)
{
    if (n == 0)
    {
        M[0] = 1;
    }
    else
    {
        M[0] = 0;
    }

    for (size_t i = 1; i <= n; i++)
    {
        M[i] = 1;
        for (size_t j = i - 1; j >= 1; j--)
        {
            M[j] = j * M[j] + M[j - 1];
        }
    }
}

unsigned long bell(const unsigned n)
{
    unsigned long result = 0;
    for (size_t i = 0; i <= n; i++)
    {
        result += M[i];
    }
    return result;
}

int main()
{
    stirling(n);

    std::cout << "bell(" << n << ")= " << bell(n) << std::endl;

    return 0;
}

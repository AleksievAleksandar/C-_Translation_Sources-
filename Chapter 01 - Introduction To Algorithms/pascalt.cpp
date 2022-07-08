#include <stdio.h>
#include <iostream>

/* Максимален размер на триъгълника */
#define MAXN 1000

constexpr unsigned n = 7;
constexpr unsigned k = 3;

unsigned long lastLine[MAXN + 1];

int main()
{
    lastLine[0] = 1;
    for (size_t i = 1; i <= n; i++)
    {
        lastLine[i] = 1;
        for (size_t j = i - 1; j >= 1; j--)
        {
            lastLine[j] += lastLine[j - 1];
        }
    }

    std::cout << "C(" << n << "," << k << ") = " << lastLine[k] << std::endl;

    return 0;
}

#include <iostream>

/* comment */
#define MAXN 20

/* Намира всички комбинации на n елемента от k-ти клас */
const unsigned n = 5;
const unsigned k = 3;

unsigned mp[MAXN];

void print(const unsigned length)
{
    for (size_t i = 0; i < length; i++)
    {
        std::cout << mp[i] << " ";
    }
    std::cout << std::endl;
}

void komb(const unsigned i, const unsigned after)
{
    if (i > k)
    {
        return;
    }

    for (size_t j = after + 1; j <= n; j++)
    {
        mp[i - 1] = j;
        if (i == k)
        {
            print(i);
        }
        komb(i + 1, j);
    }
}

int main()
{
    std::cout << "C(" << n << "," << k << "):" << std::endl;
    komb(1, 0);
    return 0;
}


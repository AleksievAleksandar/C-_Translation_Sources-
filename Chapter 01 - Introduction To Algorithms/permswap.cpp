#include <iostream>

#define MAXN 100

constexpr unsigned n = 3;

unsigned a[MAXN];

void print()
{
    for (size_t i = 0; i < n; i++)
    {
        std::cout << a[i] + 1 << " ";
    }
    std::cout << std::endl;
}

void permut(unsigned k)
{
    unsigned swap;
    if (k == 0)
    {
        print();
    }
    else
    {
        permut(k - 1);
        for (size_t i = 0; i < k - 1; i++)
        {
            swap = a[i];
            a[i] = a[k - 1];
            a[k - 1] = swap;

            permut(k - 1);

            swap = a[i];
            a[i] = a[k - 1];
            a[k - 1] = swap;
        }
    }
}

int main()
{
    for (size_t i = 0; i < n; i++)
    {
        a[i] = i;
    }
    permut(n);

    return 0;
}

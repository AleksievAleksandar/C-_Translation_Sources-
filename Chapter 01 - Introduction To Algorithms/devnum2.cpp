#include <iostream>

/* Максимален брой на множителите, най-много log2n (минималният е 2). */
#define MAXLN 20

/* Число, което ще разбиваме */
const unsigned n = 50;

unsigned mp[MAXLN];

void print(const unsigned length)
{
    for (size_t i = 1; i < length; i++)
    {
        std::cout << mp[i] << " * ";
    }
    std::cout << mp[length] << std::endl;
}

void devNum(unsigned n, unsigned pos)
{
    for (size_t k = n; k > 1; k--)
    {
        if (n != k)
        {
            mp[pos] = k;
            if (mp[pos] <= mp[pos - 1])
            {
                if (n % k == 0)
                {
                    devNum(n / k, pos + 1);
                }
            }
        }
        else
        {
            mp[pos] = k;
            if (mp[pos] <= mp[pos - 1])
            {
                print(pos);
            }
        }
    }
}

int main()
{
    mp[0] = n + 1;
    devNum(n, 1);
    return 0;
}

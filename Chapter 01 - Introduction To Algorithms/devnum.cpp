#include <iostream>

#define MAXN 100

const unsigned n = 7;

unsigned mp[MAXN + 1];

void print(const unsigned length)
{
    for (size_t i = 1; i < length; i++)
    {
        std::cout << mp[i] << "+";
    }
    std::cout << mp[length] << std::endl;
}

void devNum(const unsigned n, const unsigned pos)
{
    for (size_t k = n; k >= 1; k--)
    {
        if (n != k)
        {
            mp[pos] = k;
            if (mp[pos] <= mp[pos - 1])
            {
                devNum(n - k, pos + 1);
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

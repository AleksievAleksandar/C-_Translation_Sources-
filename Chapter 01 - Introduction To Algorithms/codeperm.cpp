#include <iostream>

constexpr unsigned MAXN = 100;

constexpr unsigned n = 6;
unsigned perm[MAXN] = { 5, 3, 6, 4, 2, 1 };
constexpr unsigned long code = 551;

unsigned long codePerm(const unsigned n, unsigned perm[])
{
    unsigned p[MAXN];
    unsigned long r;
    unsigned long result = 0;

    for (size_t i = 0; i < n; i++)
    {
        p[i] = i + 1;
    }

    for (size_t pos = 0; pos < n; pos++)
    {
        r = 0;
        while (perm[pos] != p[r])
        {
            r++;
        }
        result = result * (n - pos) + r;
        for (size_t i = r + 1; i < n; i++)
        {
            p[i - 1] = p[i];
        }
    }
    return result;
}

void decodePerm(unsigned long num, const unsigned n, unsigned perm[])
{
    unsigned long m, k;
    unsigned p[MAXN];
    for (size_t i = 0; i < n; i++)
    {
        p[i] = i + 1;
    }

    k = n;
    do
    {
        m = n - k + 1;
        perm[k - 1] = num % m;
        if (k > 1)
        {
            num /= m;
        }
    } while (--k > 0);

    k = 0;
    do
    {
        m = perm[k];
        perm[k] = p[m];
        if (k < n)
        {
            for (size_t i = m + 1; i < n; i++)
            {
                p[i - 1] = p[i];
            }
        }
    } while (++k < n);
}

int main()
{
    std::cout << "???????? ?????????? ?? ?????? ???? " << codePerm(n, perm) << std::endl;
    std::cout << "?????????? ???????????? ?????????? ?? ??????? " << code << ": ";

    decodePerm(code, n, perm);
    for (size_t i = 0; i < n; i++)
    {
        printf("%u ", perm[i]);
    }
    std::cout << std::endl;

    return 0;
}

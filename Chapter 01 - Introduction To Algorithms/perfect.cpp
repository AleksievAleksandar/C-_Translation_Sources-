#include <iostream>

#define MN 10

unsigned mPrimes[MN] = { 2, 3, 5, 7, 13, 17, 19, 31, 61, 89 };
unsigned k, number[200];

void doubleN()
{
    unsigned carry = 0;
    unsigned temp;

    for (size_t i = 0; i < k; i++)
    {
        temp = number[i] * 2 + carry;
        number[i] = temp % 10;
        carry = temp / 10;
    }
    if (carry > 0)
    {
        number[k++] = carry;
    }
}

void print()
{
    for (size_t i = k; i > 0; i--)
    {
        std::cout << number[i - 1];
    }
    std::cout << std::endl;
}

void perfect(const unsigned s, const unsigned m)
{
    k = 1;
    number[0] = 1;

    for (size_t i = 0; i < m; i++)
    {
        doubleN();  /* това са делители от вида 2^i */
    }

    number[0]--;  /* последната цифра със сигурност е измежду {2,4,8,6} */

    for (size_t i = 0; i < m - 1; i++)
    {
        doubleN();
    }

    std::cout << s << "-то съвършено число е = ";
    print();      /* отпечатва поредното число */
}

int main()
{
    for (size_t i = 1; i <= MN; i++)
    {
        perfect(i, mPrimes[i - 1]);
    }
    return 0;
}


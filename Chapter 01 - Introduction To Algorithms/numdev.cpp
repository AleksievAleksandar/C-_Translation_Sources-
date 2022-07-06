#include <iostream>

/* Число, което ще се разлага */
unsigned n = 435;

int main()
{
    unsigned how, i;

    std::cout << n << " = ";
    i = 1;
    while (n != 1)
    {
        i++;
        how = 0;
        while ((n % i) == 0)
        {
            how++;
            n = n / i;
        }
        for (size_t j = 0; j < how; j++)
        {
            std::cout << i << " ";
        }
    }

    return 0;
}
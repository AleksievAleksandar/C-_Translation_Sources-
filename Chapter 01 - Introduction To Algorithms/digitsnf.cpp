#include <math.h>
#include <iostream>

const unsigned long n = 123;

int main()
{
    float digits = 0;
    for (unsigned i = 1; i <= n; i++)
    {
        digits += log10(i);
    }

    /* операцията [x] ще реализираме, като използваме превръщане до тип unsigned long */
    std::cout << "Броят на цифрите на " << n << "! е " << (unsigned long)digits + 1 << std::endl;
    return 0;
}

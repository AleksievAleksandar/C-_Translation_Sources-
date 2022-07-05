#include <iostream>

unsigned n = 7892;

int main()
{
    unsigned dig[10];
    size_t k = 0;

    while (n > 0) {
        dig[k] = n % 10;
        n = n / 10;
        ++k;
    }

    for (size_t i = k; i > 0; i--)
    {
        std::cout << dig[i - 1] << " ";
    }

    std::cout << std::endl;
    return 0;
}

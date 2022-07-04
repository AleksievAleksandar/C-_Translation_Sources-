#include <iostream>

const unsigned n = 10;

int main() 
{
    unsigned zeroes = 0;
    unsigned p = 5;

    while (n >= p) 
    {
        zeroes += (n / p);
        p *= 5;
    }
    std::cout << "Броят на нулите в края на " << n << "! е " << zeroes << std::endl;

    return 0;
}
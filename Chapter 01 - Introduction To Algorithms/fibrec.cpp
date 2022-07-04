#include <iostream>

const unsigned n = 7;

unsigned long fib(unsigned n)
{
    if (n <= 2)
    {
        return 1;
    }       
    else
    {
        return fib(n - 1) + fib(n - 2);
    }
}

int main() 
{
    std::cout << "fib(" << n << ") = " << fib(n)<< std::endl;
    return 0;
}

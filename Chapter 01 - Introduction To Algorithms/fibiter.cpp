//n->const, FibIter -> fibIter
#include <iostream>

const unsigned n = 7;

unsigned long fibIter(unsigned n) //using 3 vars
{
    unsigned long fn = 1;
    unsigned long fn_1 = 0;
    unsigned long fn_2 = 0;

    while (n--)
    {
        fn_2 = fn_1;
        fn_1 = fn;
        fn = fn_1 + fn_2;
    }

    return fn_1;
}

unsigned long fibIter2(unsigned n) //using 2 vars
{

    unsigned long f1 = 0;
    unsigned long f2 = 1;

    while (n--)
    {
        f2 = f1 + f2;
        f1 = f2 - f1;
    }

    return f1;
}

int main()
{
    std::cout << "fib(" << n << ") = " << fibIter(n) << std::endl;
    std::cout << "fib(" << n << ") = " << fibIter2(n) << std::endl;

    return 0;
}

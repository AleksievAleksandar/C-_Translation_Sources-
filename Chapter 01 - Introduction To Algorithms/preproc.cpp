#include <iostream>

constexpr unsigned n = 23;

/* брой прости числа, с които разполагаме – изчислени предварително */
#define K 25
constexpr unsigned prime[K] = {
  2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43,
  47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };

/* проверяваме дали число е просто, като проверяваме дали има делители сред
 * числата от масива prime[]
 */
char checkprime(unsigned n)
{
    unsigned i = 0;
    while (i < K && (prime[i] * prime[i]) <= n)
    {
        if (n % prime[i] == 0)
        {
            return 0;
        }
        ++i;
    }
    return 1;
}

int main()
{
    if (checkprime(n))
    {
        std::cout << "Числото " << n << " е просто." << std::endl;
    }
    else
    {
        std::cout << "Числото " << n << " е съставно." << std::endl;
    }
    return 0;
}

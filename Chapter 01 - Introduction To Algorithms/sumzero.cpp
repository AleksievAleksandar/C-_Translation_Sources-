#include <iostream>
#include <math.h>

/* Брой числа в редицата */
constexpr size_t n = 8;
/* Редица */
int a[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
/* Търсена сума */
int sum = 0;

void checkSol(void)
{
    int tempSum = 0;
    for (size_t i = 0; i < n; i++)
    {
        tempSum += a[i];
    }

    if (tempSum == sum)
    { /* намерено е решение => отпечатваме го */
        for (size_t i = 0; i < n; i++)
        {
            if (a[i] > 0)
            {
                std::cout << "+" << a[i] << " ";
            }
            else
            {
                std::cout << a[i] << " ";
            }
        }

        std::cout << "= " << tempSum << std::endl;
    }
}

void variate(unsigned i)
{
    if (i >= n)
    {
        checkSol();
        return;
    }
    a[i] = abs(a[i]);
    variate(i + 1);

    a[i] = -abs(a[i]);
    variate(i + 1);
}

int main()
{
    variate(0);
    return 0;
}

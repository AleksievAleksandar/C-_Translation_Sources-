#include <iostream>

#define MAXN 100

/* Вариации на n елемента от клас k */
const unsigned n = 4;
const unsigned k = 2;

int taken[MAXN];

void print(const unsigned i)
{
	std::cout << "( ";
	for (size_t k = 0; k <= i - 1; k++)
	{
		std::cout << taken[k] + 1 << " ";
	}
	std::cout << ")" << std::endl;
}

/* рекурсия */
void variate(const unsigned i)
{
	/* без if (i>=k) и return; тук (а само print(i); ако искаме всички
	 * генерирания с дължина 1,2, …, k, а не само вариациите с дължина k */
	if (i >= k)
	{
		print(i);
		return;
	}
	for (size_t j = 0; j < n; j++)
	{
		/* if (allowed(k)) { */
		taken[i] = j;
		variate(i + 1);
	}
}

int main()
{
	variate(0);
	return 0;
}

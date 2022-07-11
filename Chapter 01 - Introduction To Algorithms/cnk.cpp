#include <iostream>

#define MAXN 500

constexpr unsigned long n = 7;
unsigned long k = 3;

unsigned long pN, primes[MAXN], counts[MAXN];

void modify(const long int x, const int how)
{
	for (size_t i = 0; i < pN; i++)
	{
		if (x == primes[i])
		{
			counts[i] += how;
			return;
		}
	}
	counts[pN] = how;
	primes[pN++] = x;
}

void solve(const unsigned long start, const unsigned long end, const unsigned long inc)
{
	unsigned long prime, mul, how;
	for (size_t i = start; i <= end; i++)
	{
		mul = i;
		prime = 2;
		while (mul != 1)
		{
			for (how = 0; mul % prime == 0; how++)
			{
				mul /= prime;
			}
			if (how > 0)
			{
				modify(prime, inc * how);
			}
			prime++;
		}
	}
}

long int calc()
{
	long int result = 1;
	for (size_t i = 0; i < pN; i++)
	{
		for (size_t j = 0; j < counts[i]; j++)
		{
			result *= primes[i];
		}
	}
	return result;
}

int main()
{
	std::cout << "C(" << n << "," << k << ")= ";
	pN = 0;
	if (n - k < k) k = n - k;
	solve(n - k + 1, n, 1); /* Факторизира числителя (n–k+1),...,n */
	solve(1, k, -1);        /* Факторизира знаменателя 1,...,k */
	std::cout << calc() << std::endl;
	return 0;
}


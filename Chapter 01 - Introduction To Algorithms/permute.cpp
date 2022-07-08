#include <iostream>

#define MAXN 100

constexpr unsigned n = 3;

bool used[MAXN];
unsigned mp[MAXN];

void print()
{
	for (size_t i = 0; i < n; i++)
	{
		std::cout << mp[i] + 1 << " ";
	}
	std::cout << std::endl;
}

void permute(unsigned i)
{
	if (i >= n)
	{
		print();
		return;
	}

	for (size_t k = 0; k < n; k++)
	{
		if (!used[k])
		{
			used[k] = true;
			mp[i] = k;
			permute(i + 1); /* if (ако има смисъл да продължава генерирането) {permute(i+1);} */
			used[k] = false;
		}
	}
}

int main()
{
	for (size_t i = 0; i < n; i++)
	{
		used[i] = 0;
	}

	permute(0);

	return 0;
}

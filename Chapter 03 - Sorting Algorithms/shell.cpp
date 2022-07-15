#include <assert.h>
#include <iostream>
#include <time.h>

#define MAX 100
#define TEST_LOOP_CNT 100

#define STEPS_CNT 4
#define steps0 40
const unsigned steps[STEPS_CNT] = { steps0, 13, 4, 1 };

struct  CElem
{
	int key;
	/* .............
	   Някакви данни
	   ............. */
};

void init(CElem m[], const unsigned n) /* Запълва масива със случайни цели числа */
{
	srand(time(nullptr));
	for (size_t i = 1; i <= n; i++)
	{
		m[i].key = rand() % n;
	}
}

void shellSort(CElem m[], const unsigned n)
{
	int j, k, s;
	struct CElem x;

	for (size_t stepInd = 0; stepInd < STEPS_CNT; stepInd++)
	{
		s = -(k = steps[stepInd]); /* Ограничител */
		for (size_t i = k + 1; i <= (int)n; i++)
		{
			x = m[i];
			j = i - k;
			if (0 == s)
			{
				s = -k;
			}
			m[++s] = x;

			while (x.key < m[j].key)
			{
				m[j + k] = m[j];
				j -= k;
			}

			m[j + k] = x;
		}
	}
}

void print(CElem m[], const unsigned n) /* Извежда ключовете на масива на екрана */
{
	for (size_t i = 1; i <= n; i++)
	{
		std::cout << m[i].key << " ";
	}
	std::cout << std::endl;
}

void check(const CElem m[], const CElem saveM[], const unsigned n)
{
	unsigned j;
	char* found = nullptr; /* третира се като масив от булев тип */

	/* 1. Проверка за наредба във възходящ ред */
	for (size_t i = 1; i < n; i++)
	{
		assert(m[i].key <= m[i + 1].key);
	}

	/* 2. Проверка за пермутация на изходните елементи */
	found = new char[n + 1]{};

	for (size_t i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (!found[j] && m[i].key == saveM[j].key)
			{
				found[j] = 1;
				break;
			}
		}
		assert(j <= n); /* Пропада, ако не е намерен съответен */
	}
	delete[] found;
}

int main()
{
	CElem pm[MAX + steps0 + 2], saveM[MAX + 1], * m;

	m = pm + steps0 + 1;

	std::cout << "start -- " << std::endl;

	for (size_t loopInd = 1; loopInd <= TEST_LOOP_CNT; loopInd++)
	{
		init(m, MAX);
		memcpy(saveM, m, (MAX + 1) * sizeof(*m)); /* Запазва се копие на масива */

		std::cout << "Масивът преди сортирането: ";
		print(m, MAX);

		std::cout << "Масивът след сортирането: ";
		shellSort(m, MAX);
		print(m, MAX);

		check(m, saveM, MAX);
	}
	return 0;
}
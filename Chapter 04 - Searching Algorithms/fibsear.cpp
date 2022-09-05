#include <iostream>

#define MAX 100
#define NOT_FOUND -1

#define DataType int
struct CElem
{
	int key;
	DataType data;
	/* ... */
} m[MAX + 1];        /* Масив от записи */
unsigned n;        /* Брой елементи в масива */
unsigned fib[MAX]; /* Числата на Фибоначи, ненадвишаващи n */

void fibInit(void) /* Инициализация */
{
	n = 0;
}

void sort()                                  /* Сортиране */
{
	for (size_t i = 1; i < n; i++)
	{
		for (size_t j = i + 1; j <= n; j++)
		{
			if (m[i].key > m[j].key)
			{
				CElem tmp = m[i];
				m[i] = m[j];
				m[j] = tmp;
			}
		}
	}
}

unsigned findFib(const unsigned n)                    /* Намира числата на Фибоначи */
{
	fib[0] = 0;
	fib[1] = 1;
	for (size_t k = 2; ; k++)
	{
		if ((fib[k] = fib[k - 1] + fib[k - 2]) > n)
		{
			return k - 1;
		}
	}
	return 0;
}

unsigned fibSearch(const int key)                      /* Извършва Фибоначиево търсене */
{
	int p, q, r, k;
	k = findFib(n);
	p = fib[k - 1];
	q = fib[k - 2];
	r = fib[k - 3];
	if (key > m[p].key)
	{
		p += n - fib[k] + 1;
	}
	while (p > 0)
		if (key == m[p].key)
		{
			return p;
		}
		else
		{
			if (key < m[p].key)
			{
				if (0 == r)
				{
					p = 0;
				}
				else
				{
					int t;
					p -= r;
					t = q;
					q = r;
					r = t - r;
				}
			}
			else
			{
				if (1 == q)
				{
					p = 0;
				}
				else
				{
					p += r;
					q -= r;
					r -= q;
				}
			}
		}
	return NOT_FOUND;
}

void fibInsert(const int key, const int data)               /* Добавяне на нов елемент */
{
	m[++n].key = key;
	m[n].data = data;
}

void fibPrint()                             /* Извежда списъка на екрана */
{
	for (size_t i = 1; i <= n; i++)
	{
		std::cout << m[i].key << "|" << m[i].data << " ";
	}
	std::cout << std::endl;
}

void performSearchTest()
{
	unsigned ind;
	for (size_t elem2Search = 0; elem2Search < 2 * MAX; elem2Search++)
	{
		std::cout << "Търсим елемент с ключ " << elem2Search << std::endl;

		if (NOT_FOUND == (ind = fibSearch(elem2Search)))
		{
			std::cout << "Елемент с такъв ключ не съществува!" << std::endl;
		}
		else
		{
			std::cout << "Елементът е намерен!Стойност на инф.част: " << m[ind].data << std::endl;
		}
	}
}

int main()
{
	fibInit();
	for (size_t ind = 0; ind < MAX; ind++)
	{
		fibInsert(rand() % (MAX * 2), ind);
	}
	sort();
	std::cout << "Списъкът съдържа следните елементи: " << std::endl;
	fibPrint();

	std::cout << "Тестване:" << std::endl;
	performSearchTest();

	return 0;
}
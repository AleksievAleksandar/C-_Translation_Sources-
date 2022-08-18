#include <iostream>

#define MAX 100
#define NOT_FOUND -1

#define DataType int
struct CElem
{
	int key;
	DataType data;
	/* ... */
} m[MAX];   /* Масив от записи */
unsigned n; /* Брой елементи в масива */

const unsigned step = 10;

void jmpInit() /* Инициализация */
{
	n = 0;
}

void sort()                                  /* Сортиране */
{
	for (size_t i = 0; i < n - 1; i++)
	{
		for (size_t j = i + 1; j < n; j++)
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

unsigned seqSearch(unsigned l, unsigned r, const int key)  /* Последователно търсене */
{
	while (l <= r)
	{
		if (m[l++].key == key)
		{
			return l - 1;
		}
	}
	return NOT_FOUND;
}

unsigned jmpSearch(const int key, unsigned step)                /* Търсене със скокове */
{
	unsigned ind;
	for (ind = 0; ind < n && m[ind].key < key; ind += step);

	return seqSearch(ind + 1 < step ? 0 : ind + 1 - step, n < ind ? n : ind, key);
}

void jmpInsert(const int key, const int data)               /* Добавяне на нов елемент */
{
	m[n].key = key;
	m[n++].data = data;
}

void jmpPrint()                             /* Извежда списъка на екрана */
{
	for (size_t i = 0; i < n; i++)
	{
		std::cout << m[i].key << " " << m[i].data << std::endl;
	}
	std::cout << std::endl;
}

void performSearchTest()
{
	unsigned ind;
	for (size_t elem2Search = 0; elem2Search < 2 * MAX; elem2Search++)
	{
		std::cout << "Търсим елемент с ключ " << elem2Search << std::endl;
		if (NOT_FOUND == (ind = jmpSearch(elem2Search, step)))
		{
			std::cout << "Елемент с такъв ключ не съществува!" << std::endl;
		}
		else
		{
			std::cout << "Елементът е намерен! Стойност на инф. част: " << m[ind].data << std::endl;
		}
	}
}

int main()
{
	jmpInit();
	for (size_t ind = 0; ind < MAX; ind++)
	{
		jmpInsert(rand() % (MAX * 2), ind);
	}
	sort();
	std::cout << "Списъкът съдържа следните елементи:" << std::endl;
	jmpPrint();

	std::cout << "Тестване:" << std::endl;
	performSearchTest();
	return 0;
}
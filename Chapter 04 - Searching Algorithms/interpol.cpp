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

void interpolInit() /* Инициализация */
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

unsigned interpolSearch(const int key)                 /* Извършва интерполационно търсене */
{
	unsigned l, r, mid;
	float k;
	l = 0; r = n - 1;
	while (l <= r)
	{
		if (m[r].key == m[l].key)
		{
			if (m[l].key == key)
			{
				return l;
			}
			else
			{
				return NOT_FOUND;
			}
		}
		k = (float)(key - m[l].key) / (m[r].key - m[l].key);
		if (k < 0 || k > 1)
		{
			return NOT_FOUND;
		}
		mid = (unsigned)(l + k * (r - l) + 0.5);
		if (key < m[mid].key)
		{
			r = mid - 1;
		}
		else if (key > m[mid].key)
		{
			l = mid + 1;
		}
		else
		{
			return mid;
		}
	}
	return NOT_FOUND;
}

void interpolInsert(const int key, const int data)          /* Добавяне на нов елемент */
{
	m[n].key = key;
	m[n++].data = data;
}

void interpolPrint()                        /* Извежда списъка на екрана */
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
		if (NOT_FOUND == (ind = interpolSearch(elem2Search)))
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
	interpolInit();
	for (size_t ind = 0; ind < MAX; ind++)
	{
		interpolInsert(rand() % (MAX * 2), ind);
	}
	sort();
	std::cout << "Списъкът съдържа следните елементи:" << std::endl;
	interpolPrint();

	std::cout << "Тестване:" << std::endl;
	performSearchTest();
	return 0;
}
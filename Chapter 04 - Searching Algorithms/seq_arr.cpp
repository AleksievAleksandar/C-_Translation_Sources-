#include <iostream>

#define MAX 100

#define DataType int

struct CElem
{
	int key;
	DataType data;
	/* ... */
} m[MAX + 1]; /* Масив от записи */

unsigned n;   /* Брой елементи в масива */

void seqInit() /* Инициализация */
{
	n = 0;
}

unsigned seqSearch(int key)            /* Последователно търсене */
{
	unsigned x;
	m[0].key = key; /* Ограничител */
	for (x = n + 1; key != m[--x].key; );
	return x;
}

void seqInsert(int key, DataType data) /* Добавя нов елемент */
{
	m[++n].key = key;
	m[n].data = data;
}

void seqPrint()                    /* Извежда списъка на екрана */
{
	for (size_t i = 1; i <= n; i++)
	{
		std::cout << m[i].key << " " << m[i].data << std::endl;
	}
}

void performSearchTest()
{
	unsigned ind;

	for (size_t elem2Search = 0; elem2Search < 2 * MAX; elem2Search++)
	{
		std::cout << "Търсим елемент с ключ " << elem2Search << ": ";
		if (0 == (ind = seqSearch(elem2Search)))
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
	seqInit();
	for (size_t ind = 0; ind < MAX; ind++)
	{
		seqInsert(rand() % (MAX * 2), ind);
	}
	std::cout << "Списъкът съдържа следните елементи: " << std::endl;
	seqPrint();

	std::cout << "Тестване: " << std::endl;
	performSearchTest();
	return 0;
}

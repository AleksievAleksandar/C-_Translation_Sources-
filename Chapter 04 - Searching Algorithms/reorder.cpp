#include <iostream>

#define MAX 10

#define DataType int

struct CElem
{

	int key;
	DataType data;
	CElem* next;
	/* ... */
} *head;

void listInit(void) /* Инициализация */
{
	head = nullptr;
}

void listInsert(int key, DataType data) /* Добавя нов елемент */
{
	CElem* q = new CElem;
	q->key = key;
	q->data = data;
	q->next = head;
	head = q;
}

CElem* listSearch(int key) /* Последователно търсене с преподреждане */
{
	CElem* q;
	CElem* p = head;

	if (nullptr == head)
	{
		return nullptr;
	}
	if (head->key == key)
	{
		return head;
	}

	for (q = head->next; q != nullptr; )
	{
		if (q->key != key)
		{
			p = q;
			q = q->next;
		}
		else
		{
			p->next = q->next;
			q->next = head;
			return (head = q);
		}
	}
	return nullptr;
}

void listPrint() /* Извежда списъка на екрана */
{
	CElem* q = nullptr;

	for (q = head; q != nullptr; q = q->next)
	{
		std::cout << q->key << " " << q->data << std::endl;
	}
}

void performSearchTest()
{
	CElem* p = nullptr;

	for (size_t elem2Search = 0; elem2Search < 2 * MAX; elem2Search++)
	{
		std::cout << "Търсим елемент с ключ " << elem2Search << std::endl;
		if (nullptr == (p = listSearch(elem2Search)))
		{
			std::cout << "Елемент с такъв ключ не съществува!" << std::endl;
		}
		else
		{
			std::cout << "Елементът е намерен!Стойност на инф.част: " << p->data << std::endl;
		}
	}
}

int main()
{
	listInit();
	for (size_t ind = 0; ind < MAX; ind++)
	{
		listInsert(rand() % (MAX * 2), ind);
	}
	std::cout << "Списъкът съдържа следните елементи:" << std::endl;
	listPrint();

	std::cout << "Тестване:" << std::endl;
	performSearchTest();

	std::cout << "Списъкът след търсенето:" << std::endl;
	listPrint();

	return 0;
}
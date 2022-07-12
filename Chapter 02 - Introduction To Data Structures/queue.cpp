#include <iostream>

#define MAX 10

typedef int data;
data queue[MAX];
int front, rear, empty;

void init()
{
	front = 0;
	rear = 0;
	empty = 1;
}

void put(data i)
{
	if (front == rear && !empty)
	{/* Проверка за препълване */
	 /* препълване - индексите са равни, а опашката не е празна */
		std::cerr << "Препълване!" << std::endl;
		return;
	}
	queue[rear++] = i;
	if (rear >= MAX)
	{
		rear = 0;
	}
	empty = 0;
}

data get()
{
	data x;
	if (empty)
	{ /* Проверка за празна опашка */
		std::cerr << "Опашката е празна!" << std::endl;
		return 0;
	}
	x = queue[front++];
	if (front >= MAX)
	{
		front = 0;
	}
	if (front == rear)
	{
		empty = 1;
	}
	return x;
}

int main()
{
	data p;
	init();
	for (size_t i = 0; i < 2 * MAX; i++)
	{
		put(i);
		p = get();
		std::cout << p << " ";
	}

	std::cout << std::endl;

	/* Това ще причини препълване при последното включване */
	for (size_t i = 0; i < MAX + 1; i++)
	{
		put(i);
	}

	/* Това ще причини грешка при последното изключване, тъй като опашката е празна */
	for (size_t i = 0; i < MAX + 1; i++)
	{
		get();
	}

	return 0;
}

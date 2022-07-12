#include <iostream>

#define MAX 10

typedef int data;
data stack[MAX];
int top;

void init()
{
	top = 0;
}

void push(data i)
{
	if (MAX == top)
	{
		std::cerr << "Препълване на стека!" << std::endl;
	}
	else
	{
		stack[top++] = i;
	}
}

data pop()
{
	if (0 == top) {
		std::cerr << "Стекът е празен!" << std::endl;
		return 0;
	}
	else
	{
		return stack[--top];
	}
}

int empty()
{
	return (0 == top);
}

int main()
{
	data p;
	init();

	/* Четат се цели числа от клавиатурата до прочитане на 0 и се включват в стека */
	std::cin >> p;
	while (0 != p)
	{
		push(p);
		std::cin >> p;
	};

	/* Изключват се последователно всички елементи от стека и се печатат. Това ще
	 * доведе до отпечатване на първоначално въведената последователност в обратен ред
	 */
	while (!empty())
	{
		std::cout << pop() << " ";
	}
	std::cout << std::endl;
	return 0;
}

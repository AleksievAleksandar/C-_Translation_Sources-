#include <iostream>

typedef int data;
data stack[10];
int top;

void init()
{
	top = 0;
}

void push(data i)
{
	stack[top++] = i;
}

data pop()
{
	return stack[--top];
}

int empty()
{
	return(top == 0);
}

int main()
{
	/* ... */
	return 0;
}

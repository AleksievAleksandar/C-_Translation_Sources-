#include <iostream>
#include <stdlib.h>

typedef int data;
typedef int keyType;

struct list
{
    keyType key;
    data info;
    list* next;
};

/* включва елемент в началото на свързан списък */
void insertBegin(list** L, keyType key, data x)
{
    list* temp;
    temp = new list();
    if (nullptr == temp)
    {
        std::cerr << "Няма достатъчно памет за създаване на нов елемент!" << std::endl;
        return;
    }

    temp->next = *L;
    (*L) = temp;
    (*L)->key = key;
    (*L)->info = x;
}

/* включва след даден елемент */
void insertAfter(list** L, keyType key, data x)
{
    list* temp;

    if (nullptr == *L)
    {   /* ако списъкът е празен => специален случай */
        insertBegin(L, key, x);
        return;
    }

    temp = new list();
    /* създаване на новия елемент */
    if (nullptr == temp)
    {
        std::cerr << "Няма достатъчно памет за новия елемент!" << std::endl;
        return;
    }

    temp->key = key;
    temp->info = x;
    temp->next = (*L)->next;
    (*L)->next = temp;
}

/* включва преди даден елемент */
void insertBefore(list** L, keyType key, data x)
{
    list* temp;

    if (nullptr == *L)
    {   /* елементът трябва да се вмъкне преди първия */
        insertBegin(L, key, x);
        return;
    }

    temp = new list();
    /* създаване на новия елемент */
    if (nullptr == temp)
    {
        std::cerr << "Няма достатъчно памет за новия елемент!" << std::endl;
        return;
    }

    *temp = **L;
    (*L)->next = temp;
    (*L)->key = key;
    (*L)->info = x;
}

/* изтрива елемент от списъка */
void deleteNode(list** L, keyType key)
{
    list* current = *L;
    list* save;
    if ((*L)->key == key)
    {  /* трябва да се изтрие първият елемент */
        current = (*L)->next;
        delete(*L);
        (*L) = current;
        return;
    }

    /* намира елемента, който ще се трие */
    while (current->next != nullptr && current->next->key != key)
    {
        current = current->next;
    }

    if (nullptr == current->next)
    {
        std::cerr << "Грешка: Елементът за изтриване не е намерен!" << std::endl;
        return;
    }
    else
    {
        save = current->next;
        current->next = current->next->next;
        delete save;
    }
}

/* отпечатва елементите на свързан списък */
void print(list* L)
{
    while (nullptr != L)
    {
        std::cout << L->key << "(" << L->info << ") ";
        L = L->next;
    }
    std::cout << std::endl;
}

/* търси по ключ елемент в свързан списък */
struct list* search(list* L, keyType key)
{
    while (L != nullptr)
    {
        if (L->key == key)
        {
            return L;
        }
        L = L->next;
    }
    return nullptr;
}

int main()
{
    list* L = nullptr;
    int edata = 0;
    insertBegin(&L, 0, 42);

    for (size_t i = 1; i < 6; i++)
    {
        edata = rand() % 100;
        std::cout << "Вмъкване преди: " << i << "(" << edata << ")" << std::endl;
        insertBefore(&L, i, edata);
    }

    for (size_t i = 6; i < 10; i++)
    {
        edata = rand() % 100;
        std::cout << "Вмъкване след: " << i << "(" << edata << ")" << std::endl;
        insertAfter(&L, i, edata);
    }

    print(L);
    deleteNode(&L, 9);
    print(L);
    deleteNode(&L, 0);
    print(L);
    deleteNode(&L, 3);
    print(L);
    deleteNode(&L, 5);
    print(L);
    deleteNode(&L, 5);
    return 0;
}

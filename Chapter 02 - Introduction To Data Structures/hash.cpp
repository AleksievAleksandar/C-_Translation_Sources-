#include <iostream>

#define N 211

typedef int data;
typedef long int keyType;
/* стойност, връщана от функцията get, когато елементът не се намира в хеш-таблицата*/
#define NOT_EXIST -1

struct List
{
    keyType key;
    data info;
    List* next;
};

List* hashTable[N];

/* включва елемент в началото на свързан списък */
void insertBegin(List** L, keyType key, data x)
{
    List* temp;
    temp = new List();
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

/* изтрива елемент от списъка */
void deleteNode(List** L, keyType key)
{
    List* current = *L;
    List* save = nullptr;
    if ((*L)->key == key) /* трябва да се изтрие първият елемент */
    {
        current = (*L)->next;
        delete (*L);
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

/* търси по ключ елемент в свързан списък */
List* search(List* L, keyType key)
{
    while (L != nullptr)
    {
        if (L->key == key)
        {
            return L;
        }
        L = L->next;
    }
    return NULL;
}

int hashFunction(keyType key)
{
    return(key % N);
}

void initHashTable()
{
    for (size_t i = 0; i < N; i++)
    {
        hashTable[i] = nullptr;
    }
}

void put(keyType key, data x)
{
    int place = hashFunction(key);
    insertBegin(&hashTable[place], key, x);
}

data get(keyType key)
{
    int place = hashFunction(key);
    List* l = search(hashTable[place], key);

    return (nullptr != l) ? l->info : NOT_EXIST;
}

int main()
{
    initHashTable();

    put(1234, 100);       /* -> в слот 179 */
    put(1774, 120);       /* -> в слот 86 */
    put(86, 180);         /* -> в слот 86 -> колизия */

    std::cout << "Отпечатва данните на елемента с ключ   86: " << get(86) << std::endl;
    std::cout << "Отпечатва данните на елемента с ключ 1234: " << get(1234) << std::endl;
    std::cout << "Отпечатва данните на елемента с ключ 1774: " << get(1774) << std::endl;
    std::cout << "Отпечатва данните на елемента с ключ 1773: " << get(1773) << std::endl;

    return 0;
}

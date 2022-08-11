#include <assert.h>
#include <iostream>
#include <time.h>

#define MAX 100

struct CElem
{
    int key;
    /* .............
       Някакви данни
       ............. */
};

struct CList
{
    CElem data;
    CList* next;
};

CList* init(const unsigned n) /* Запълва масива със случайни цели числа */
{
    CList* head = nullptr;
    CList* p = nullptr;

    srand(time(nullptr));

    for (size_t i = 0; i < n; i++)
    {
        p = new CList;
        p->data.key = rand();

        assert(p->data.key);

        p->next = head;
        head = p;
    }
    return head;
}

CList* bitSort(CList* head)
{
    CList* zeroEnd, * oneEnd, * zero, * one;
    unsigned maxBit, bitPow2;

    /* 0. Определяне на максималната битова маска */
    maxBit = 1 << (8 * sizeof(head->data.key) - 1);

    /* 1. Фиктивен елемент в началото на списъците */
    zero = new CList;
    one = new CList;

    /* 2. Сортиране */
    for (bitPow2 = 1; bitPow2 < maxBit; bitPow2 <<= 1)
    {
        /* 2.1. Разпределяне по списъци */
        for (zeroEnd = zero, oneEnd = one; nullptr != head; head = head->next)
        {
            if (!(head->data.key & bitPow2))
            {
                zeroEnd->next = head;
                zeroEnd = zeroEnd->next;
            }
            else
            {
                oneEnd->next = head;
                oneEnd = oneEnd->next;
            }
        }
        /* 2.2. Обединение на списъците */
        oneEnd->next = nullptr;
        zeroEnd->next = one->next;
        head = zero->next;
    }

    /* 3. Освобождаване на паметта */
    delete zero;
    delete one;

    return head;
}

void print(CList* head)
{
    for (; nullptr != head; head = head->next)
    {
        std::cout << head->data.key << " ";
    }
    std::cout << std::endl;
}

void check(CList* head)
{
    if (nullptr == head)
    {
        return;
    }
    for (; nullptr != head->next; head = head->next)
    {
        assert(head->data.key <= head->next->data.key);
    }
}

void clear(CList* head)
{
    CList* p = head;
    while (nullptr != head)
    {
        head = (p = head)->next;
        delete p;
    }
}

int main()
{
    CList* head;
    head = init(MAX);
    std::cout << "Масивът преди сортирането: ";
    print(head);

    head = bitSort(head);
    std::cout << "Масивът след сортирането: ";
    print(head);

    check(head);

    clear(head);

    return 0;
}
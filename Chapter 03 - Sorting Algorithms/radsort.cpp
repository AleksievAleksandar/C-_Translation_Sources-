#include <assert.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>

#define MAX     100
#define BASE   16 /* Основа на бройната система */
#define POW2    4 /* 16 = 1 << 4 */
#define DIG_CNT 8 /* Брой цифри */

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
        p = new CList();
        p->data.key = rand();

        assert(p->data.key);

        p->next = head;
        head = p;
    }
    return head;
}

CList* radixSort(CList* head)
{
    struct { CList* st, * en; } mod[BASE]; /* Класове на еквивалентност */
    unsigned mask, shrM;

    /* 1. Инициализация */
    for (size_t i = 0; i < BASE; i++)
    {
        mod[i].st = new CList();
    }

    /* 2. Сортиране */
    mask = BASE - 1;
    shrM = 0;
    for (size_t dig = 1; dig <= DIG_CNT; dig++)
    {

        /* 2.1. Инициализация */
        size_t i;
        for (i = 0; i < BASE; i++)
        {
            mod[i].en = mod[i].st;
        }

        /* 2.2. Разпределяне елементите по списъци */
        while (nullptr != head)
        {
            /* 2.2.1. Намиране i-тата цифра в BASE-ичното представяне на числото */
            i = (head->data.key & mask) >> shrM;
            /* 2.2.2. Включване числото в съответния списък */
            mod[i].en->next = head;
            mod[i].en = mod[i].en->next;

            head = head->next;
        }

        /* 2.3. Обединение на списъците */
        mod[BASE - 1].en->next = NULL;
        for (i = BASE - 1; i > 0; i--)
        {
            mod[i - 1].en->next = mod[i].st->next;
        }
        head = mod[0].st->next;

        /* 2.4. Изчисляваме новите маски */
        shrM += POW2;
        mask <<= POW2;
    }

    /* 3. Освобождаване на паметта */
    for (size_t i = 0; i < BASE; i++)
    {
        delete mod[i].st;
    }

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

    head = radixSort(head);
    std::cout << "Масивът след сортирането: ";
    print(head);

    check(head);
    clear(head);

    return 0;
}
#include <assert.h>
#include <iostream>
#include <time.h>

#define MAX 100
#define FACTOR 5
#define MAX_VALUE (MAX*FACTOR)
#define TEST_LOOP_CNT 100

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

void init(CElem m[], const unsigned n) /* Запълва масива със случайни цели числа */
{
    srand(time(nullptr));
    for (size_t i = 0; i < n; i++)
    {
        m[i].key = rand() % MAX_VALUE;
    }
}

void countSort(CElem m[], const unsigned n)
{ /* Сортира масив по метода на броенето. Внимание - неустойчив метод! */

    CList* lst[MAX_VALUE];
    CList* p;

    /* 0. Начална инициализация */
    for (size_t i = 0; i < MAX_VALUE; i++)
    {
        lst[i] = nullptr;
    }

    /* 1. Разпределяне на елементите по списъци */
    for (size_t j = 0; j < n; j++)
    {
        /* 1.1. Проверка за ключа */
        assert(m[j].key >= 0 && m[j].key < MAX_VALUE);
        /* 1.2. Добавяне на елемента в началото на списъка */
        p = new CList();
        p->data = m[j];
        p->next = lst[m[j].key];
        lst[m[j].key] = p;
    }

    /* 2. Извеждане на ключовете на сортираната последователност */
    size_t j = 0;
    for (size_t i = j = 0; i < MAX_VALUE; i++)
    {
        while (nullptr != (p = lst[i]))
        {
            m[j++] = lst[i]->data;
            lst[i] = lst[i]->next;
            delete p;
        }
    }
}

void print(CElem m[], const unsigned n) /* Извежда ключовете на масива на екрана */
{
    for (size_t i = 0; i < n; i++)
    {
        std::cout << m[i].key << " ";
    }
    std::cout << std::endl;
}

void check(const CElem m[], const CElem saveM[], const unsigned n)
{
    unsigned j;
    char* found = nullptr; /* третира се като масив от булев тип */

    /* 1. Проверка за наредба във възходящ ред */
    for (size_t i = 0; i < n - 1; i++)
    {
        assert(m[i].key <= m[i + 1].key);
    }

    /* 2. Проверка за пермутация на изходните елементи */
    found = new char[n] {};
    for (size_t i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (!found[j] && m[i].key == saveM[j].key)
            {
                found[j] = 1;
                break;
            }
        }
        assert(j < n); /* Пропада, ако не е намерен съответен */
    }

    delete[] found;
}

int main()
{
    CElem m[MAX];
    CElem saveM[MAX];

    for (size_t loopInd = 1; loopInd <= TEST_LOOP_CNT; loopInd++)
    {
        std::cout << "<<<<< Тест " << loopInd << " >>>>>" << std::endl;
        init(m, MAX);
        memcpy(saveM, m, sizeof(m)); /* Запазва се копие на масива */

        std::cout << "Масивът преди сортирането: ";
        print(m, MAX);

        countSort(m, MAX);
        std::cout << "Масивът след сортирането: ";
        print(m, MAX);

        check(m, saveM, MAX);
    }
    return 0;
}
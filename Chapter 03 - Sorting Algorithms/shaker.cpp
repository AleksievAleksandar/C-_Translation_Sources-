#include <assert.h>
#include <iostream>
#include <time.h>

#define MAX           100
#define TEST_LOOP_CNT 100

struct  CElem
{
    int key;
    /* .............
       Някакви данни
       ............. */
};

void swap(CElem* x1, CElem* x2)
{
    CElem tmp = *x1;
    *x1 = *x2;
    *x2 = tmp;
}

void init(CElem m[], const unsigned n) /* Запълва масива със случайни цели числа */
{
    srand(time(nullptr));

    for (size_t i = 0; i < n; i++)
    {
        m[i].key = rand() % n;
    }
}

void shakerSort(CElem m[], const unsigned n)
{
    unsigned k = n;
    unsigned r = n - 1;
    unsigned l = 1;

    do {
        for (size_t j = r; j >= l; j--)
        {
            if (m[j - 1].key > m[j].key)
            {
                swap(m + j - 1, m + j);
                k = j;
            }
        }

        l = k + 1;
        for (size_t j = l; j <= r; j++)
        {
            if (m[j - 1].key > m[j].key)
            {
                swap(m + j - 1, m + j);
                k = j;
            }
        }
        r = k - 1;
    } while (l <= r);
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
    found = new char[n + 1]{};

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

    std::cout << "start -- " << std::endl;

    for (size_t loopInd = 1; loopInd <= TEST_LOOP_CNT; loopInd++)
    {
        init(m, MAX);
        memcpy(saveM, m, sizeof(m)); /* Запазва се копие на масива */

        std::cout << "Масивът преди сортирането: ";
        print(m, MAX);

        std::cout << "Масивът след сортирането: ";
        shakerSort(m, MAX);
        print(m, MAX);

        check(m, saveM, MAX);
    }
    return 0;
}
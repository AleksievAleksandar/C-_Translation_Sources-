#include <assert.h>
#include <iostream>
#include <time.h>

#define MAX           100
#define TEST_LOOP_CNT 100

struct CElem
{
    int key;
    /* .............
      Някакви данни
    ............. */
} m[MAX];

void swap(CElem* x1, CElem* x2)
{
    CElem tmp = *x1;
    *x1 = *x2;
    *x2 = tmp;
}

void init(CElem m[], const unsigned n)             /* Запълва масива със случайни цели числа */
{
    srand(time(nullptr));
    for (size_t i = 0; i < n; i++)
    {
        m[i].key = rand() % n;
    }
}

void quickSort(int l, int r)
{
    int i, j, x;
    i = l;
    j = r;
    x = m[(i + j) / 2].key;
    do
    {
        while (x > m[i].key)
        {
            i++;
        }
        while (x < m[j].key)
        {
            j--;
        }
        if (i <= j)
        {
            swap(m + i, m + j);
            i++;
            j--;
        }
    } while (j >= i);

    if (j > l)
    {
        quickSort(l, j);
    }
    if (i < r)
    {
        quickSort(i, r);
    }
}

void print(CElem m[], const unsigned n)            /* Извежда ключовете на масива на екрана */
{
    for (size_t i = 0; i < n; i++)
    {
        std::cout << m[i].key << " ";
    }
    std::cout << std::endl;
}

void check(const CElem m[], const CElem saveM[], const unsigned n)
{
    size_t j = 0;
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
        assert(j < n);               /* Пропада, ако не е намерен съответен */
    }

    delete[] found;
}

int main()
{
    CElem saveM[MAX];

    for (size_t loopInd = 1; loopInd <= TEST_LOOP_CNT; loopInd++)
    {
        std::cout << "<<<<< Тест " << loopInd << " >>>>>" << std::endl;
        init(m, MAX);
        memcpy(saveM, m, sizeof(m));  /* Запазва се копие на масива */

        std::cout << "Масивът преди сортирането: ";
        print(m, MAX);

        quickSort(0, MAX - 1);
        std::cout << "Масивът след сортирането: ";
        print(m, MAX);

        check(m, saveM, MAX);
    }
    return 0;
}
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
    for (size_t i = 1; i <= n; i++)
    {
        m[i].key = rand() % n;
    }
}

/* Отсяване на елемента от върха на пирамидата */
void sift(CElem m[], const unsigned l, const unsigned r)
{
    unsigned i = l;
    unsigned j = i + i;
    CElem x = m[i];

    while (j <= r)
    {
        if (j < r)
        {
            if (m[j].key < m[j + 1].key)
            {
                j++;
            }
        }
        if (x.key >= m[j].key)
        {
            break;
        }
        m[i] = m[j];
        i = j;
        j <<= 1;
    }
    m[i] = x;
}

void heapSort(CElem m[], const unsigned n) /* Пирамидално сортиране */
{
    /* 1. Построяване на пирамидата */
    for (int k = n / 2 + 1; k > 1; k--)
    {
        sift(m, k - 1, n);
    }

    /* 2. Построяване на сортирана последователност */
    for (int k = n; k > 1; k--)
    {
        swap(m + 1, m + k);
        sift(m, 1, k - 1);
    }
}

void print(CElem m[], const unsigned n) /* Извежда ключовете на масива на екрана */
{
    for (size_t i = 1; i <= n; i++)
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
    for (size_t i = 1; i < n; i++)
    {
        assert(m[i].key <= m[i + 1].key);
    }

    /* 2. Проверка за пермутация на изходните елементи */
    found = new char[n + 1]{};
    for (size_t i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (!found[j] && m[i].key == saveM[j].key)
            {
                found[j] = 1;
                break;
            }
        }
        assert(j <= n); /* Пропада, ако не е намерен съответен */
    }
    delete[] found;
}

int main()
{
    CElem m[MAX + 1];
    CElem saveM[MAX + 1];

    std::cout << "start -- " << std::endl;
    for (size_t loopInd = 1; loopInd <= TEST_LOOP_CNT; loopInd++)
    {
        init(m, MAX);
        memcpy(saveM, m, sizeof(m)); /* Запазва се копие на масива */

        std::cout << "Масивът преди сортирането: ";
        print(m, MAX);

        heapSort(m, MAX);
        std::cout << "Масивът след сортирането: ";
        print(m, MAX);

        check(m, saveM, MAX);
    }
    return 0;
}

#include <assert.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <time.h>

#define MAX 100
#define TEST_LOOP_CNT 100

struct  CElem
{
    int key;
    /* .............
       Някакви данни
       ............. */
};

void init(CElem m[], unsigned n) /* Запълва масива със случайни цели числа */
{
    srand(time(nullptr));
    for (size_t i = 1; i <= n; i++)
    {
        m[i].key = rand() % n;
    }
}

void shellSort(CElem m[], unsigned l, unsigned r)
{
    static unsigned incs[16] =
    { 1391376, 463792, 198768, 86961, 33936, 13776, 4592, 1968, 861, 336, 112, 48, 21, 7, 3, 1 };

    CElem v;

    for (size_t k = 0; k < 16; k++)
    {
        size_t h = incs[k];
        for (size_t i = l + h; i <= r; i++)
        {
            v = m[i];
            size_t j = i;

            while (j > h && m[j - h].key > v.key)
            {
                m[j] = m[j - h];
                j -= h;
            }
            m[j] = v;
        }
    }
}

void print(CElem m[], unsigned n) /* Извежда ключовете на масива на екрана */
{
    for (size_t i = 1; i <= n; i++)
    {
        std::cout << m[i].key << " ";
    }
    std::cout << std::endl;
}

void check(const CElem m[], const CElem saveM[], unsigned n)
{
    unsigned i, j;
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
        memcpy(saveM, m, (MAX + 1) * sizeof(*m)); /* Запазва се копие на масива */

        std::cout << "Масивът преди сортирането: ";
        print(m, MAX);

        std::cout << "Масивът след сортирането: ";
        shellSort(m, 1, MAX);
        print(m, MAX);

        check(m, saveM, MAX);
    }
    return 0;
}
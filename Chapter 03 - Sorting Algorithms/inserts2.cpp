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

void init(CElem m[], const unsigned n) /* Запълва масива със случайни цели числа */
{
    srand(time(nullptr));
    for (size_t i = 1; i <= n; i++)
    {
        m[i].key = rand() % n;
    }
}

void straightInsertion(CElem m[], const unsigned n)
{
    unsigned j;
    struct CElem x;
    for (size_t i = 1; i <= n; i++)
    {
        x = m[i]; m[0].key = x.key;
        for (j = i - 1; x.key < m[j].key; j--)
        {
            m[j + 1] = m[j];
        }
        m[j + 1] = x;
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

    std::cout << "start --" << std::endl;
    for (size_t loopInd = 1; loopInd <= TEST_LOOP_CNT; loopInd++)
    {
        init(m, MAX);
        memcpy(saveM, m, sizeof(m)); /* Запазва се копие на масива */
        std::cout << "Масивът преди сортирането: ";
        print(m, MAX);

        straightInsertion(m, MAX);
        std::cout << "Масивът след сортирането: ";
        print(m, MAX);

        check(m, saveM, MAX);
    }
    return 0;
}
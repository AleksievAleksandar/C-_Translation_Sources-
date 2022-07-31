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
};

void init(CElem m[], const unsigned n)             /* Запълва масива със случайни цели числа */
{
    srand(time(nullptr));
    for (size_t i = 0; i < n; i++)
    {
        m[i].key = rand() % n;
    }
}

void binaryInsertion(CElem m[], const unsigned n)  /* Сортиране с двоично вмъкване */
{
    CElem x;

    for (size_t i = 1; i < n; i++)
    {
        x = m[i];
        int l = 0;
        size_t r = i - 1;
        /* Двоично търсене */
        while (l <= (int)r)
        {
            size_t med = (l + r) / 2;
            if (x.key < m[med].key)
            {
                r = med - 1;
            }
            else
            {
                l = med + 1;
            }
        }
        /* Мястото е намерено. Следва вмъкване чрез изместване надясно */
        for (int j = i - 1; j >= l; j--)
        {
            m[j + 1] = m[j];
        }
        m[l] = x;
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
        assert(j < n);               /* Пропада, ако не е намерен съответен */
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
        memcpy(saveM, m, sizeof(m));  /* Запазва се копие на масива */
        std::cout << "Масивът преди сортирането: ";
        print(m, MAX);

        binaryInsertion(m, MAX);
        std::cout << "Масивът след сортирането: ";
        print(m, MAX);

        check(m, saveM, MAX);
    }
    return 0;
}
#include <assert.h>
#include <iostream>
#include <time.h>

#define MAX           100
#define FACTOR        5
#define MAX_VALUE     (MAX*FACTOR)
#define TEST_LOOP_CNT 100

void init(unsigned m[], const unsigned n) /* Запълва масива със случайни цели числа */
{
    srand(time(nullptr));
    for (size_t i = 0; i < n; i++)
    {
        m[i] = rand() % n;
    }
}

void countSort(unsigned m[], const unsigned n) /* Сортира чрез броене */
{
    unsigned char cnt[MAX_VALUE];
    unsigned j;

    /* 0. Инициализиране на множеството */
    for (size_t i = 0; i < MAX_VALUE; i++)
    {
        cnt[i] = 0;
    }

    /* 1. Формиране на множеството */
    for (j = 0; j < n; j++)
    {
        assert(m[j] >= 0 && m[j] < MAX_VALUE);
        cnt[m[j]]++;
    }

    /* 2. Генериране на сортирана последователност */
    for (size_t i = j = 0; i < MAX_VALUE; i++)
    {
        while (cnt[i]--)
        {
            m[j++] = i;
        }
    }
    assert(j == n);
}

void print(unsigned m[], const unsigned n) /* Извежда ключовете на масива на екрана */
{
    for (size_t i = 0; i < n; i++)
    {
        std::cout << m[i] << " ";
    }
    std::cout << std::endl;
}

void check(const unsigned m[], const unsigned saveM[], const unsigned n)
{
    unsigned j;
    char* found = nullptr; /* третира се като масив от булев тип */

    /* 1. Проверка за наредба във възходящ ред */
    for (size_t i = 0; i < n - 1; i++)
    {
        assert(m[i] <= m[i + 1]);
    }

    /* 2. Проверка за пермутация на изходните елементи */
    found = new char[n + 1]{};
    for (size_t i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (!found[j] && m[i] == saveM[j])
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
    unsigned m[MAX];
    unsigned saveM[MAX];

    std::cout << "start --" << std::endl;
    for (size_t loopInd = 1; loopInd <= TEST_LOOP_CNT; loopInd++)
    {
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
#include <assert.h>
#include <iostream>
#include <time.h>

#define MAX           100
#define TEST_LOOP_CNT 100
#define FACTOR 5
#define MAX_VALUE (MAX*FACTOR)

void init(unsigned m[], const unsigned n) /* Запълва масива със случайни цели числа */
{
    /* 1. Запълвване със случайни стойности в нарастващ ред */
    srand(time(NULL));
    m[0] = rand() % FACTOR;
    for (size_t i = 1; i < n; i++)
    {
        m[i] = 1 + m[i - 1] + rand() % FACTOR;
    }

    /* 2. Разменяме многократно произволни двойки елементи */
    for (size_t i = 1; i < n; i++)
    {
        unsigned ind1, ind2;
        unsigned tmp;

        /* 2.1. Избиране на два случайни индекса */
        ind1 = rand() % n;
        ind2 = rand() % n;

        /* 2.2. Разменяме ги */
        tmp = m[ind1];
        m[ind1] = m[ind2];
        m[ind2] = tmp;
    }
}

void setSort(unsigned m[], const unsigned n) /* Сортира масив с използване на множество */
{
    char set[MAX_VALUE];
    unsigned j;

    /* 0. Инициализиране на множеството */
    for (size_t i = 0; i < MAX_VALUE; i++)
    {
        set[i] = 0;
    }

    /* 1. Формиране на множеството */
    for (j = 0; j < n; j++)
    {
        assert(m[j] >= 0 && m[j] < MAX_VALUE);
        assert(0 == set[m[j]]);
        set[m[j]] = 1;
    }

    /* 2. Генериране на сортирана последователност */
    for (size_t i = j = 0; i < MAX_VALUE; i++)
    {
        if (set[i])
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
    char* found; /* третира се като масив от булев тип */

    /* 1. Проверка за наредба във възходящ ред */
    for (size_t i = 0; i < n - 1; i++)
    {
        assert(m[i] <= m[i + 1]);
    }

    /* 2. Проверка за пермутация на изходните елементи */
    size_t j = 0;
    found = new char[n] {};
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
    unsigned m[MAX], saveM[MAX];

    for (size_t loopInd = 1; loopInd <= TEST_LOOP_CNT; loopInd++)
    {
        std::cout << "<<<<< Тест " << loopInd << " >>>>>" << std::endl;
        init(m, MAX);
        memcpy(saveM, m, sizeof(m)); /* Запазва се копие на масива */

        std::cout << "Масивът преди сортирането: ";
        print(m, MAX);

        setSort(m, MAX);
        std::cout << "Масивът след сортирането: ";
        print(m, MAX);

        check(m, saveM, MAX);
    }
    return 0;
}
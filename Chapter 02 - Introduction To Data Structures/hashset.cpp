#include <iostream>
#include <string>

#define S 107           /* стъпка на увеличаване при колизия */
unsigned long n = 32;   /* начален размер на хеш-таблицата */

struct SingleWord
{
    std::string word = "";     /* ключ - символен низ */
    unsigned long freq = 0;   /* честота на срещане на думата */
};
SingleWord* ht = nullptr;

unsigned long count;

/* Хеш-функция за символен низ */
unsigned long hashFunction(const std::string& key)
{
    unsigned long result = 0;
    for (size_t i = 0; i < key.size(); i++)
    {
        result += result + (unsigned char)key[i];
    }

    return result & (n - 1);
}

/* Инициализиране на хеш-таблицата */
void initHashtable()
{
    count = 0;
    ht = new SingleWord[n];
}

/* Търсене в хеш-таблицата: връща 1 при успех, и 0 – иначе */
/* При успех: *ind съдържа индекса на намерения елемент */
/* При неуспех: свободна позиция, където може да бъде вмъкнат */
int get(const std::string& key, unsigned long& ind)
{
    unsigned long k = 0;
    ind = hashFunction(key);
    k = ind;

    do {
        if ("" == ht[ind].word)
        {
            return 0;
        }

        if (key == ht[ind].word)
        {
            return 1;
        }

        ind = (ind + S) & (n - 1);
    } while (ind != k);

    return 0;
}

/* Разширяване на хеш-таблицата */
void resize()
{
    unsigned long hashInd = 0;
    SingleWord* oldHashTable = nullptr;

    /* 1. Запазване на указател към хеш-таблицата */
    oldHashTable = ht;

    /* 2. Двойно разширяване */
    n <<= 1;

    /* 3. Заделяне на памет за новата хеш-таблица */
    ht = new SingleWord[n];

    /* 4. Преместване на записите в новата хеш-таблица */
    for (size_t ind = 0; ind < (n >> 1); ind++)
    {
        if (oldHashTable[ind].word == "")
        {
            /* Премества записа на новото място */
            if (!get(oldHashTable[ind].word, hashInd))
            {
                ht[hashInd] = oldHashTable[ind];
            }
            else
            {
                std::cout << "Грешка при разширяване на хеш-таблицата!" << std::endl;
            }
        }
    }

    /* 5. Освобождаване на старата памет */
    delete[] oldHashTable;
}

/* Добавяне на елемент в хеш-таблицата */
void put(const std::string& key)
{
    unsigned long ind = 0;

    if (!get(key, ind)) /* Думата не е в хеш-таблицата */
    {
        ht[ind].word = key;
        ht[ind].freq = 1;
        if (++count > ((unsigned long)n * 0.9))
        {
            resize();
        }
    }
    else
    {
        ht[ind].freq++;
    }
}

/* Отпечатване на хеш-таблица */
void printAll()
{
    for (size_t ind = 0; ind < n; ind++)
    {
        if (ht[ind].word != "")
        {
            std::cout << ht[ind].word << " " << ht[ind].freq << std::endl;
        }
    }
}

/* Унищожаване на хеш-таблица */
void destroy()
{
    delete[] ht;
}

int main()
{
    unsigned long find = 0;
    initHashtable();

    put("reload");
    put("crush tour");
    put("room service");
    put("load");
    put("reload");
    put("reload");

    printAll();

    if (get("reload", find))
    {
        std::cout << "Честота на думата 'reload': " << ht[find].freq << std::endl;
    }
    else
    {
        std::cout << "Думата 'reload' липсва!" << std::endl;
    }

    if (get("download", find))
    {
        std::cout << "Честота на думата 'download': " << ht[find].freq << std::endl;
    }
    else
    {
        std::cout << "Думата 'download' липсва!" << std::endl;
    }

    destroy();
    return 0;
}

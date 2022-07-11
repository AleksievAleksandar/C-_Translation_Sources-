#define EPS 0.0001
#define MAX_LEN 100

#include <assert.h>
#include <math.h>
#include <iostream>
#include <iomanip>
#include <string>

char getChar(const char n) /* Връща символа, съответстващ на n */
{
	return (n < 10) ? n + '0' : n + 'A' - 10;
}

char getValue(const char c) /* Връща стойността на символа c */
{
	return (c >= '0' && c <= '9') ? c - '0' : c - 'A' + 10;
}

void reverse(std::string& pch)
{
	if (pch.empty())
	{
		return;
	}

	size_t left = 0;
	size_t right = pch.size() - 1;

	while (left < right)
	{
		char ch = pch[left];
		pch[left] = pch[right];
		pch[right] = ch;

		++left;
		--right;
	}
}

void convert(std::string& rslt, unsigned long n, unsigned char base)
/* Преобразува цялото десетично число n (n >= 0) в бройна система с основа base */
{
	while (n > 0)
	{
		rslt += getChar((char)(n % base));
		n /= base;
	}
	reverse(rslt);
}

void convertLessThan1(std::string& rslt, double n, unsigned char base, unsigned char cnt)
/* Преобразува десетичното число 0 <= n < 1 в бройна система с основа base
   с не повече от cnt на брой цифри след десетичната запетая */
{
	size_t idx = 0;
	while (cnt--)
	{
		/* Дали не сме получили 0? */
		if (fabs(n) < EPS)
		{
			break;
		}
		/* Получаване на следващата цифра */
		n *= base;
		rslt += getChar((char)(int)floor(n));
		n -= floor(n);
	}

}

void convertReal(std::string& rslt, double n, unsigned char base, unsigned char cnt)
/* Преобразува десетичното реално число n в бройна система с основа base */
{
	double integer, fraction;

	/* Намиране на знака */
	if (n < 0) {
		rslt += '-';
		n = -n;
	}

	/* Разбиване на цяла и дробна част */
	fraction = modf(n, &integer);

	/* Конвертиране на цялата част */
	convert(rslt, (unsigned long)integer, base);

	/* Поставяне на десетична точка */
	rslt += '.';

	/* Конвертиране на дробната част */
	convertLessThan1(rslt, fraction, base, cnt);
}

unsigned long calculate(std::string& numb, unsigned char base)
/* Намира десетичната стойност на числото numb, зададено в бройна система
	с основа base, numb >= 0 */
{
	unsigned long result = 0;
	for (size_t i = 0; i < numb.size(); i++)
	{
		result = result * base + getValue(numb[i]);
	}
	return result;
}

double calculateLessThan1(std::string& numb, unsigned char base)
/* Намира десетичната стойност на числото numb (0 < numb < 1),
   зададено в бройна система с основа base */
{
	double result = 0.0;
	for (int i = numb.size() - 1; i >= 0; --i)
	{
		result = (result + getValue(numb[i])) / base;
	}
	return result;
}

double calculateReal(std::string& numb, unsigned char base)
/* Намира десетичната стойност на реалното число numb, зададено
   в бройна система с основа base */
{
	int minus;
	/* Проверка за минус */
	if ('-' == numb[0])
	{
		minus = -1;
		numb = numb.substr(1);
	}
	else
	{
		minus = 1;
	}

	if (std::string::npos == numb.find("."))
	{
		return calculate(numb, base); /* Няма дробна част */
	}

	/* Пресмятане на цялата част */
	std::string temp = numb.substr(0, numb.find("."));
	double result = calculate(temp, base);

	/* Прибавяне на дробната част */
	temp.clear();
	temp = numb.substr(numb.find(".") + 1);
	result += calculateLessThan1(temp, base);

	return minus * result;

}

int main()
{
	std::cout << "!!! Демонстрация на преобразуването между бройни системи !!!" << std::endl;

	std::string numb;
	convertReal(numb, 777.777, 7, 10);
	std::cout << "Седмичният запис на 777.777 (10) е " << numb << std::endl;

	numb = "11.D873";
	std::cout << "Десетичният запис на 11.D873 (16) е: " << std::fixed << std::setprecision(10) << calculateReal(numb, 16) << std::endl;

	return 0;
}
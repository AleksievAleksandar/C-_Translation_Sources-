#define MAX_ROMAN_LEN 20

#include <iostream>
#include <string>

std::string roman1_9[] = { "", "A", "AA", "AAA", "AB", "B", "BA", "BAA", "BAAA", "AC" };
std::string romanDigits[] = { "IVX", "XLC", "CDM", "M" };

std::string roman2test = "MCMLXXXIX";

void getRomanDigit(std::string& outRslt, char x, unsigned char power)
{
    outRslt.clear();
    for (char ab : roman1_9[x])
    {
        outRslt += romanDigits[power][ab - 'A'];
    }
}

void decimal2Roman(std::string& outRslt, unsigned x)
{
    int power = 0;
    while (x > 0)
    {
        std::string digit;
        getRomanDigit(digit, (char)(x % 10), power);
        outRslt = digit + outRslt;
        power += 1;
        x /= 10;
    }
}

unsigned roman2Decimal(std::string& roman, unsigned& error)
{
    int old = 1000;
    int result = 0;
    error = 0;
    for (char ch : roman)
    {
        int value = 0;
        switch (ch)
        {
        case 'I':
            value = 1; break;
        case 'V':
            value = 5; break;
        case 'X':
            value = 10; break;
        case 'L':
            value = 50; break;
        case 'C':
            value = 100; break;
        case 'D':
            value = 500; break;
        case 'M':
            value = 1000; break;

        default:
            error = 1;
            result = -1;

            return result;
        }

        result += value;

        if (value > old)
        {
            result -= 2 * old;
        }

        old = value;
    }

    return result;
}

int main()
{
    unsigned decimal;
    unsigned error;
    decimal = roman2Decimal(roman2test, error);
    if (error)
    {
        std::cout << "Некоректнo римско число!";
    }
    else
    {
        std::cout << "Числото в десетична бройна система е " << decimal;
    }
    return 0;
}

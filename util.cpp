#include "util.h"

bool Util::is_add_safe(int x, int y)
{
    bool is_safe = true;
    if ((x > 0) && (y > INT_MAX - x)) //overflow
    {
        is_safe = false;
    }
    else if ((x < 0) && (y < INT_MIN - x)) //underflow
    {

        is_safe = false;
    }
    return is_safe;
}


bool Util::is_mul_safe(int x, int y)
{

    bool is_safe = true;

    if (x > INT_MAX / y) //overflow
    {
        is_safe = false;
    }
    else if ((x < INT_MIN / y)) //underflow
    {
        is_safe = false;
    }

    if ((x == -1) && (y == INT_MIN)) // special case -1 with 2's complement
    {
        is_safe = false;
    }
    else if ((y == -1) && (x == INT_MIN)) //overflow
    {
        is_safe = false;
    }

    return is_safe;

}

int Util::gcd(int a, int b)
{
    int x = abs(a);
    int y = abs(b);
    int temp;
    while (y != 0) {
        temp = y;
        y = x%y;
        x = temp;
    }
    return x;
}
int Util::lcm(int a, int b)
{
    int x = abs(a);
    int y = abs(b);
    int gc = gcd(x, y);
    return gc ? (x/gc * y) : 0;

}

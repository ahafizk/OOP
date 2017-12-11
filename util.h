#ifndef UTIL_H
#define UTIL_H
#include <limits.h>
#include <cmath>
using namespace std;
class  Util
{
public:
    bool is_add_safe(int x, int y);
    bool is_mul_safe(int x, int y);
    int gcd(int x, int y);
    int lcm(int x, int y);

};

#endif // UTIL_H

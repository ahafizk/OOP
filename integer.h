#ifndef INTEGER_H
#define INTEGER_H
#include <typeinfo>
#include <iostream>
#include "number.h"
#include "fraction.h"
#include "util.h"

using namespace std;


class Fraction;
class Integer :public Number
{
    int value;
    Util uobj;


public:

    Integer();
    Integer(int val);
    virtual void display();
    virtual bool operator==(const Number & );
    virtual Number* operator+ ( const Number & num);
    int get_value();
    void set_value(int);
    virtual ~ Integer();

};

#endif // INTEGER_H

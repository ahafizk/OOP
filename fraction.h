#ifndef FRACTION_H
#define FRACTION_H
#include<iostream>
#include <stdexcept>
#include "integer.h"
#include "util.h"
class Integer;


class Fraction : public Number
{
    int numerator;
    int denominator;
    int _num;
    int _denom;
    Util uobj;

public:
    Fraction();
    Fraction(int numerator, int denominator);
    bool is_valid(int num, int denom);
    virtual void display();
    virtual Number* operator+ (const Number &);
    virtual bool operator==(const Number & );
//    friend Fraction operator+(Integer &, Fraction &); //integer + fraction
//    friend Fraction operator+(Fraction &, Integer &); //fraction + integer
    int get_num();
    int get_denom();
    int get_reduced_num();
    int get_reduced_denom();
    void set_numerator();
    void set_denominator();
    void set_fraction_number(int numerator, int denominator);
    ~Fraction(){}
};

#endif // FRACTION_H

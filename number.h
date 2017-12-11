#ifndef NUMBER_H
#define NUMBER_H
#include <memory>
//class Integer;
//class Fraction;
using namespace std;
class Number
{
public:
    Number();
    virtual void display()=0;
    virtual bool operator==(const Number & ) = 0;
    virtual Number* operator+(const Number &)=0;

    virtual ~Number();
};

#endif // NUMBER_H

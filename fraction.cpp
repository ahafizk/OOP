#include "fraction.h"

Fraction::Fraction()
{

}

Fraction::Fraction(int num, int denom)
{

    set_fraction_number(num,denom);

}

bool Fraction::is_valid(int num, int denom)
{

}

void Fraction::display()
{
    cout << get_num() <<"/"<< get_denom();
}



//Fraction operator+(Integer & a, Fraction & b) //integer + fraction
//{
//    friend function
//    Fraction c;
//    return c;
//}

//Fraction operator+(Fraction & a, Integer & b) //fraction + integer
//{
//    friend function
//    Fraction d;
//    return d;
//}


Number*  Fraction::operator +(const Number & num)
{
    Number * ret_value;
    Fraction *res;
    int numer = 0;
    int denom = 1;

    if (typeid(*this)==typeid(num))
    {
        try
        {
            //Fraction + Fraction
            Fraction* a =  (Fraction*) (&num);

            res = new Fraction(numer,denom);
            ret_value  = (Number*)res;

            denom = uobj.lcm(this->get_denom(),a->get_denom());
            bool is_safe1 = uobj.is_mul_safe(this->get_num(),(denom/this->get_denom()));
            bool is_safe2 = uobj.is_mul_safe(a->get_num(),(denom/a->get_denom()));
            if (!is_safe1||!is_safe2){
                throw "Unsafe multiplication (Overflow/Underflow) in fraction addition! result set to (0/1)";
            }
            else
            {


                int part1 = this->get_num()*(denom/this->get_denom());
                int part2 = a->get_num()*(denom/a->get_denom());
                if (!uobj.is_add_safe(part1,part2))
                {

                    throw "Unsafe fraction addition (Overflow/Underflow)! result set to (0/1).";
                }
                else{
                    numer = part1 + part2 ;
                }

            }

        }
        catch (const char* msg)
        {
            cerr << msg << endl;
        }
        catch(...)
        {
            cerr<<"Exception!"<<endl;
        }

    }
    else {
        //Fraction + Integer
        Integer* a =  (Integer*) (&num);
        res = new Fraction(numer,denom);
        ret_value  = (Number*)res;
        try{
            if (uobj.is_add_safe(a->get_value(),(this->get_denom()))&&uobj.is_mul_safe(a->get_value(),(this->get_denom() )))
            {
                numer = (a->get_value()*(this->get_denom() )) + this->get_num();
                denom = this->get_denom();
            }
            else
            {

                throw "Unsafe addition (Overflow/Underflow) of Fraction and Integer! result set to (0/1)";
            }

        }
        catch(const char* msg)
        {
            cerr << msg << endl;
        }
        catch(...)
        {
            cerr<<"Exception!"<<endl;
        }

    }

    res->set_fraction_number(numer,denom); //update the fraction numerator and denominator

    return ret_value;
}

bool Fraction::operator==(const Number & num )
{
    bool ret_val = false;
    if (typeid(*this)==typeid(num))
    {
        //Fraction == Fraction
        int num1 = this->get_reduced_num();
        int denom1 = this->get_reduced_denom();
        int q1 = num1/denom1; //quotient
        int r1 = num1%denom1;
        Fraction * fract = (Fraction*)(&num);
        int num2 = fract->get_reduced_num();
        int denom2 = fract->get_reduced_denom();
        int q2 = num2/denom2;
        int r2 = num2%denom2;

        if ((q1==q2)&&(r1==r2)){
            ret_val = true;
        }

    }
    else
    {
        //Fraction == Integer

        Integer *int_part = (Integer*)(&num);
        int value = int_part->get_value();
        int numer = this->get_reduced_num();
        int denom = this->get_reduced_denom();
        int q = numer/denom; //quotient
        int r = numer%denom; //reminder
        if ((value==q) && (r==0))
        {
            ret_val = true;
        }

    }
    return ret_val;
}


int Fraction::get_denom()
{
    return denominator;
}
int Fraction::get_num()
{
    return numerator;
}

int Fraction::get_reduced_num()
{
    return _num;
}
int Fraction::get_reduced_denom()
{
    return _denom;
}

void Fraction::set_fraction_number(int num, int denom)
{
    if (denom==0){
        cerr << "Divison by zero error! fraction set to (0/1)." << endl;
        this->numerator = 0;
        this->denominator = 1;
    }
    else {

        if ((num>0 && denom<0)||(num<0&&denom<0))
        {
            int sign = -1;
            _num = sign*num;
            _denom = denom*sign;
        }
        else
        {
            _num = num;
            _denom = denom;
        }

        this->numerator = _num;
        this->denominator = _denom;
        int divisor = uobj.gcd(_num, _denom);
        _num /= divisor; //reduced numerator
        _denom /= divisor; // reduced denominator


    }
}

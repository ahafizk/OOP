#include "integer.h"

Integer::Integer()
{

}
Integer::Integer(int val)
{
    value = val;

}
Integer::~Integer()
{

}

bool Integer::operator==(const Number & num)
{
    bool ret_val = false;
    if (typeid(*this)==typeid(num))
    {
        Integer* a =  (Integer*) (&num);
        if (this->get_value()==a->get_value())
        {
            ret_val = true;
        }
    }
    else
    {
        //Integer == Fraction
        Fraction *fract = (Fraction*)(&num);
        int numer = fract->get_reduced_num();
        int denom = fract->get_reduced_denom();
        int d = numer/denom;
        int r = numer%denom;

        if ((this->get_value()==d) && (r==0))
        {

            ret_val = true;

        }

    }

    return ret_val;
}

Number*  Integer::operator +( const Number & num)
{
    Number * ret_value;

    if (typeid(*this)==typeid(num))
    {
        //Integer + Integer
        Integer *b = new Integer();
        Integer* a =  (Integer*) (&num);
        try
        {

            if (uobj.is_add_safe(this->get_value(),a->get_value()))
            {
                b->set_value(this->get_value()+a->get_value());
            }
            else
            {
                b->set_value(0);
                throw "Unsafe addition (Overflow/Underflow) of two integer! Addition result sets to zero (0).";
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

        ret_value  = (Number*)b;
    }
    else
    {

        //Integer + Fraction
        int numer = 0;
        int denom = 1;
        try{

            Fraction* a =  (Fraction*) (&num);
            Fraction *b = new Fraction(numer, denom);
            ret_value  = (Number*)b;
            if (uobj.is_mul_safe(this->get_value(),a->get_denom()))
            {
                int temp = (this->get_value()*(a->get_denom() ));
                if (uobj.is_add_safe(temp,a->get_num()))
                {
                    numer = temp +   a->get_num();
                    denom = a->get_denom();
                }
                else
                {
                    throw "Unsafe Integer and Fraction addition (Overflow/Underflow)! Results set to zero (0/1).";
                }
            }
            else
            {
                throw "Unsafe Integer and Fraction addition (Overflow/Underflow)! Results set to zero (0/1).";
            }


            b->set_fraction_number(numer,denom);

        }
        catch(const char* msg)
        {
            cerr << msg << endl;
        }
        catch(...)
        {
            cerr<<"Exception!";
        }
    }


    return ret_value;

}


void Integer::display()
{
    cout << value;
}

int Integer::get_value()
{
    return value;
}

void Integer::set_value(int val)
{
    value = val;
}

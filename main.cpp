#include <iostream>
#include "number.h"
#include "integer.h"
#include "fraction.h"

using namespace std;
void integer_fraction_equal_test();
void two_integer_equal_test();
void fraction_fraction_equal_test();
void print_result(bool stat,Number &a, Number &b)
{
    if (stat){
        a.display();
        cout<<"==";
        b.display();
        cout <<endl;
    }
    else
    {
        a.display();
        cout<<"!=";
        b.display();
        cout <<endl;
    }
}
void equal_test()
{
    int c;
    cout <<"Integer == Integer: 1"<<endl;
    cout <<"Integer == Fraction: 2"<<endl;
    cout << "Fraction == Integer: 3"<<endl;
    cout << "Fraction == Fraction: 4"<<endl;
    cout << "To Terminate: (Ctrl+C)"<<endl;
    cout << "Enter your choice:"<<endl;
    while(cin>>c){

        if (c==1)
        {
            int num1, num2;
            cout << "Enter First Integer"<<endl;
            cin >> num1;
            cout << "Enter Second Integer:"<<endl;
            cin>>num2;
            Integer a(num1), b(num2);
            print_result(a==b,a,b);


        }
        else if (c==2)
        {
            int num1, num,denom;
            cout << "Enter Integer"<<endl;
            cin >> num1;
            cout << "Enter Fraction:"<<endl;
            cout << "Numerator: ";
            cin>>num;
            cout << "Denominator: ";
            cin>>denom;
            Integer a(num1);
            Fraction b(num,denom);

            print_result(a==b,a,b);
        }
        else if (c==3)
        {
            int num1, num,denom;

            cout << "Enter Fraction:"<<endl;
            cout << "Numerator: ";
            cin>>num;
            cout << "Denominator: ";
            cin>>denom;
            cout << "Enter Integer"<<endl;
            cin >> num1;
            Integer a(num1);
            Fraction b(num,denom);
            print_result(a==b,a,b);

        }
        else if (c==4)
        {
            int num1,denom1, num2,denom2;

            cout << "Enter First Fraction:"<<endl;
            cout << "Numerator: ";
            cin>>num1;
            cout << "Denominator: ";
            cin>>denom1;
            cout << "Enter Second Fraction"<<endl;
            cout << "Numerator: ";
            cin>>num2;
            cout << "Denominator: ";
            cin>>denom2;

            Fraction a(num1,denom1);
            Fraction b(num2,denom2);
            print_result(a==b,a,b);

        }
        cout <<"Enter your choice [1-4]:";

    }
}

void addition_test()
{
    int c;

    cout <<"Integer+Integer: 1"<<endl;
    cout <<"Integer+Fraction: 2"<<endl;
    cout << "Fraction + Integer: 3"<<endl;
    cout << "Fraction + Fraction: 4"<<endl;
    cout << "To Terminate: (Ctrl+C)"<<endl;
    cout << "Enter your choice:"<<endl;
    while(cin>>c){

        if (c==1)
        {
            int num1, num2;
            cout << "Enter First Integer"<<endl;
            cin >> num1;
            cout << "Enter Second Integer:"<<endl;
            cin>>num2;
            Integer a(num1), b(num2);
            Number * res = a+b;
            res->display();
            cout <<endl;
            delete res;
        }
        else if (c==2)
        {
            int num1, num,denom;
            cout << "Enter Integer"<<endl;
            cin >> num1;
            cout << "Enter Fraction:"<<endl;
            cout << "Numerator: ";
            cin>>num;
            cout << "Denominator: ";
            cin>>denom;
            Integer a(num1);
            Fraction b(num,denom);
            Number *  res = a+b;
            res->display();
            cout <<endl;
            delete res;//delete the object
        }
        else if (c==3)
        {
            int num1, num,denom;

            cout << "Enter Fraction:"<<endl;
            cout << "Numerator: ";
            cin>>num;
            cout << "Denominator: ";
            cin>>denom;
            cout << "Enter Integer"<<endl;
            cin >> num1;
            Integer a(num1);
            Fraction b(num,denom);
            Number * res = b+a;
            res->display();
            cout <<endl;
            delete res;//delete the object

        }
        else if (c==4)
        {
            int num1,denom1, num2,denom2;

            cout << "Enter First Fraction:"<<endl;
            cout << "Numerator: ";
            cin>>num1;
            cout << "Denominator: ";
            cin>>denom1;
            cout << "Enter Second Fraction"<<endl;
            cout << "Numerator: ";
            cin>>num2;
            cout << "Denominator: ";
            cin>>denom2;
            Fraction a(num1,denom1);
            Fraction b(num2,denom2);
            Number * res = a+b;
            res->display();
            cout <<endl;
            delete res;//delete the object
        }
        cout <<"Enter your choice [1-4]:";

    }
}

int main()
{

    addition_test();
    equal_test();
    return 0;
}




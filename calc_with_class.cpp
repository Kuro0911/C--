/*
#include <iostream>
#include <math.h>
using namespace std;
//create 2 classes - 1 simple calculator and adv calculator
//simple calculator takes input of 2 nos using a utility func and performs + _ * /
//adv takes input of 2 nos using a utility func and performs + _ * / and any other 2 more
//create another class hybrid calc and inherit it using these classes
//create an obj of hybrid class and use it for calc


class simple_calc
{
public:
    int a, b;
    simple_calc(){};
    void set_Simplenum(int x, int y)
    {
        a = x;
        b = y;
    }
    void get_Simplenum(void);
};
void simple_calc ::get_Simplenum()
{
    cout << "the numbers are " << a << " and " << b << endl;
}
class adv_calc
{
public:
    adv_calc(){};
    int a1, b2;
    void set_Advnum(int X, int Y)
    {
        a1 = X;
        b2 = Y;
    }
    void get_Advnum(void);
};
void adv_calc ::get_Advnum()
{
    cout << "the numbers are " << a1 << " and " << b2 << endl;
}

class Simplefuncs : public simple_calc
{
    int sum, multi, div, sub;

public:
    void display_all_simple();
    void display_sum_simple();
    void display_multi_simple();
    void display_divide_simple();
    void display_sub_simple();
};
void Simplefuncs ::display_all_simple()
{
    get_Simplenum();
    cout << "the sum is " << a + b << endl;
    cout << "the multi is " << a * b << endl;
    cout << "the division is " << a / b << endl;
    cout << "the sub is " << a - b << endl;
};

void Simplefuncs ::display_sum_simple()
{
    get_Simplenum();
    cout << "the sum is " << a + b << endl;
};
void Simplefuncs ::display_multi_simple()
{
    get_Simplenum();
    cout << "the multi is " << a * b << endl;
};
void Simplefuncs ::display_divide_simple()
{
    get_Simplenum();
    cout << "the division is " << a / b << endl;
};
void Simplefuncs ::display_sub_simple()
{
    get_Simplenum();
    cout << "the sub is " << a - b << endl;
};

class Advfuncs : public adv_calc
{
    int sumAdv, multiAdv, divAdv, subAdv;

public:
    void display_all_Adv();
    void display_sum_Adv();
    void display_multi_Adv();
    void display_divide_Adv();
    void display_sub_Adv();
    void display_sqrt_Adv();
    void display_fact_Adv();
};
void Advfuncs ::display_all_Adv()
{
    int fact1 = 1, fact2 = 1;
    get_Advnum();
    cout << "the sum is " << a1 + b2 << endl;
    cout << "the multi is " << a1 * b2 << endl;
    cout << "the division is " << a1 / b2 << endl;
    cout << "the sub is " << a1 - b2 << endl;
    for (int i1 = 1; i1 <= a1; ++i1)
    {
        fact1 *= i1;
    }

    for (int i2 = 1; i2 <= b2; ++i2)
    {
        fact2 *= i2;
    }

    cout << "the fact of " << a1 << " is " << fact1 << " and " << b2 << " is " << fact2 << endl;
};
void Advfuncs ::display_sum_Adv()
{
    get_Advnum();
    cout << "the sum is " << a1 + b2 << endl;
};
void Advfuncs ::display_multi_Adv()
{
    get_Advnum();
    cout << "the multi is " << a1 * b2 << endl;
};
void Advfuncs ::display_divide_Adv()
{
    get_Advnum();
    cout << "the division is " << a1 / b2 << endl;
};
void Advfuncs ::display_sub_Adv()
{
    get_Advnum();
    cout << "the sub is " << a1 - b2 << endl;
};
void Advfuncs ::display_sqrt_Adv()
{
    get_Advnum();
    cout << "the sum is " << sqrt(a1 * b2) << endl;
};
void Advfuncs ::display_fact_Adv()
{
    int fact1 = 1, fact2 = 1;
    get_Advnum();

    for (int i1 = 1; i1 <= a1; ++i1)
    {
        fact1 *= i1;
    }

    for (int i2 = 1; i2 <= b2; ++i2)
    {
        fact2 *= i2;
    }

    cout << "the fact of " << a1 << " is " << fact1 << " and " << b2 << " is " << fact2 << endl;
};

class Epic_calc : public Simplefuncs , public Advfuncs{
    public:
        void display_chad(void){
            display_all_Adv();
            cout<<endl;
            display_all_simple();
        }
};
int main()
{
    Epic_calc kuro;
    kuro.set_Advnum(5 , 4);
    kuro.set_Simplenum(2 , 6);

    kuro.display_chad();
    return 0;
}
*/

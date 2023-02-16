#include <iostream>
using namespace std;

class Complex
{
    int real, img;

public:
    void set_num(int r, int i)
    {
        real = r;
        img = i;
    }
    // for firend class
    friend class Sum;
    // for friend func
    friend Complex sum(Complex n1, Complex n2);
    void print()
    {
        cout << real << " + " << img << "i" << endl;
    }
};

// friend class
class Sum
{
public:
    void sum(Complex n1, Complex n2)
    {
        Complex n3;
        n3.set_num(n1.real + n2.real, n1.img + n2.img);
        n3.print();
    }
};
// function
Complex sum(Complex n1, Complex n2)
{
    Complex n3;
    n3.set_num(n1.real + n2.real, n1.img + n2.img);
    return n3;
}

int main()
{
    Complex n1, n2;
    n1.set_num(12, 2);
    n2.set_num(2, 4);
    // using func
    Complex n3 = sum(n1, n2);
    n3.print();

    // using class
    Sum x;
    x.sum(n1, n2);
    return 0;
}
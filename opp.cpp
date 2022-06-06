/*
//classes

#include <iostream>

using namespace std;

class employee
{
    private:
        int a, b ,c;
    public:
        int d , e;
        void setData(int a, int b ,int c);
        void getData(){
            cout<<"the value of a is :"<<a<<endl;
            cout<<"the value of b is :"<<b<<endl;
            cout<<"the value of c is :"<<c<<endl;
            cout<<"the value of d is :"<<d<<endl;
        }
};

void employee :: setData(int a1 , int b1 ,int c1 ){
    a = a1;
    b = b1;
    c = c1;
}
int main(){
    employee kuro;
    kuro.d = 45;
    kuro.e = 84;
    kuro.setData(1,2,4);
    kuro.getData();
    return 0;
}
//nesting of member functions:
#include <iostream>
#include <string.h>

using namespace std;

class binary
{
    string s;

public:
    void read(void);
    void chk_bin(void);
};
void binary ::read(void)
{
    cout << "enter a binary number : " << endl;
    cin >> s;
}
void binary ::chk_bin(void)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s.at(i) != '0' && s.at(i) != '1')
        {
            cout << "inncorrect binary format" << endl;
            exit(0);
        }
    }
}

int main()
{
    binary b;
    b.read();
    b.chk_bin();
    return 0;
}
//memory allocation;
#include <iostream>

using namespace std;
class shop
{
    int itemid[100];
    int itemPrice[100];
    int counter;

public:
    void initCounter(void) { counter = 0; }
    void getPrice(void);
    void setpPrice(void);
    void displayPrice(void);
};
void shop ::setpPrice(void)
{
    cout << "enter the id of your item no. "<<counter+1<< endl;
    cin >> itemid[counter];
    cout << "enter the price of your item" << endl;
    cin >> itemPrice[counter];
    counter++;
}
void shop ::displayPrice(void)
{
    for (int i = 0; i < counter; i++)
    {
        cout<<"the price of the item is "<<itemPrice[i]<<" and the id is "<<itemid[i]<<endl;
    }

}
int main()
{
    shop dukaan;
    dukaan.initCounter();
    dukaan.setpPrice();
    dukaan.setpPrice();
    dukaan.setpPrice();
    dukaan.setpPrice();
    dukaan.displayPrice();
    return 0;
}
//static data members
#include <iostream>

using namespace std;
class employee
{
    int id;
    static int count;

public:
    void setdata(void)
    {
        cin >> id;
        count++;
    }
    void getdata(void)
    {
        cout << "the id of the employee is " << id << " and the count is " << count << endl;
    }
};
int employee ::count;
int main()
{
    employee kuro, raptor, phenom;
    kuro.setdata();
    kuro.getdata();
    raptor.setdata();
    raptor.getdata();
    phenom.setdata();
    phenom.getdata();
    return 0;
}


#include <iostream>

using namespace std;
class complex
{
    int a;
    int b;

public:
    void setData(int v1, int v2)
    {
        a = v1;
        b = v2;
    }

    void setDataBySum(complex o1, complex o2)
    {
        a = o1.a + o2.a;
        b = o1.b + o2.b;
    }
    void printNumber()
    {
        cout << "the number is " << a << " + " << b <<"i"<< endl;
    }
};
int main()
{
    complex c1, c2, c3;
    c1.setData(1, 2);
    c1.printNumber();

    c2.setData(3, 4);
    c1.printNumber();

    c3.setDataBySum(c1, c2);
    c1.printNumber();
    return 0;
}
//friend functions:
#include <iostream>

using namespace std;

class complex{
    int a,b;
    public:
        void setNumber(int n1,int n2){
            a = n1;
            b = n2;
        }
        friend complex sumComplex(complex o1 , complex o2);
        void printNumber(){
            cout<<"your number is "<<a<<" +"<<b<<"i"<<endl;
        }
};
complex sumComplex(complex o1,complex o2 ){
    complex o3;
    o3.setNumber((o1.a + o2.a), (o1.b+ o2.b));
    return o3;
};
int main(){
    complex c1,c2,sum;

    c1.setNumber(1 , 2);
    c1.printNumber();

    c2.setNumber(3 , 4);
    c2.printNumber();

    sum = sumComplex(c1 , c2);
    sum.printNumber();
    return 0;
}
//properties:
1) not in the scope of class
2)since it is not in the scope it can not be called with the componrt of the cclass
3)can be invoked without the help of any object
4)ussually contains the objects as arguments
5) is can not use the object name
#include <iostream>

using namespace std;
class complex;
class Calculator
{
public:
    int add(int a, int b)
    {
        cout << "your number is  " << a << " + " << b << "i" << endl;
    }
    int sumRealComplex(complex o1, complex o2);
    int sumCompComplex(complex o1, complex o2);
};

class complex
{
    int a, b;
    friend int Calculator ::sumRealComplex(complex o1, complex o2);
    friend int Calculator ::sumCompComplex(complex o1, complex o2);
    friend class Calculator;

public:
    void setNumber(int n1, int n2)
    {
        a = n1;
        b = n2;
    }

    void printNumber()
    {
        cout << "your number is " << a << " +" << b << "i" << endl;
    }
};
int Calculator ::sumRealComplex(complex o1, complex o2)
{
    return (o1.a + o2.a);
};
int main()
{
    complex o1, o2;
    o1.setNumber(1, 4);
    o2.setNumber(3, 5);
    Calculator calc;
    int res = calc.sumRealComplex(o1, o2);
    cout << "the sum fo real part of o1 and o2 is " << res << endl;

    return 0;
}
#include <iostream>

using namespace std;
class Y;
class X{
    int data;
    public:
        void setValue(int value){
            data = value;
        };
    friend void add(X,Y);
};
class Y{
    int num;
    public:
        void setValue(int value){
            num = value;
        };
    friend void add(X,Y);
};
void add(X o1 , Y o2){
    cout<<"sum data of x and y gives "<<o1.data + o2.num;
}

int main(){
    X a1;
    a1.setValue(2);
    Y b1;
    b1.setValue(3);

    add(a1 , b1);
    return 0;
}
#include <iostream>

using namespace std;
class c2;
class c1{
    int val1;
    public:
        void indata(int a){
            val1 = a;
        }
        void printdata(void){
            cout<<val1<<endl;
        }
    friend void exchange(c1 & , c2 & );
};
class c2{
    int val2;
    public:
        void indata(int a){
            val2 = a;
        }
        void printdata(void){
            cout<<val2<<endl;
        }
    friend void exchange(c1 &  , c2 & );
};
void exchange(c1 & x , c2 & y){
    int temp = x.val1;
    x.val1 = y.val2;
    y.val2 = temp;
}
int main(){
    c1 oc1;
    c2 oc2;
    oc1.indata(23);
    oc2.indata(53);
    exchange(oc1 , oc2);
    cout<<"A = ";
    oc1.printdata();
    cout<<"B = ";
    oc2.printdata();


    return 0;
}
//constructors : is a special member function with same name as of the class it is used to initialize the obj of the class

#include <iostream>

using namespace std;
class complex
{
    int a, b;
    public :
    void printdata(void){
            cout<<"the number is "<<a<<" +"<<b<<"i "<<endl;
        }

    complex(void);
};
complex :: complex(void){ //default constructor which takes no value;
    a = 10;
    b = 2;
};

int main()
{
    complex c;
    c.printdata();

    return 0;
}
properties :
1:it should be declared in public class;
2:they are automaticaly invoked whenever the obj is cereated
3:it can not have a return type;
4:we can not reffer to their address and it can have default argumrets
//parameterized and default constructor

#include <iostream>

using namespace std;
class complex
{
    int a, b;

public:
    void printdata(void)
    {
        cout << "the number is " << a << " +" << b << "i " << endl;
    }

    complex(int x, int y);
};
complex ::complex(int x, int y)
{ //default constructor which takes no value;
    a = 10;
    b = 2;
};

int main()
{
    //implicit call
    complex a(4, 6);
    //explicit call
    complex b = complex(5, 7);
    a.printdata();
    b.printdata();
    return 0;
}


#include <iostream>
#include <math.h>

using namespace std;

class Point
{
    int x, y;
    friend void  distance(Point o1, Point o2 );
    public:
    Point(int a, int b)
    {
        x = a;
        y = b;
    }

    void displayPoint()
    {
        cout << "the point is (" << x << " , " << y << ")" << endl;
    }


};
void  distance(Point o1, Point o2 )
{
    double d1 , d2;

    d1 = (o1.x - o2.x) * (o1.x - o2.x);
    d2 = (o2.y - o1.y) * (o2.y - o1.y);

    cout<<"the distance bw the points is  = "<<sqrt(d1 + d2)<<endl;
}
int main()
{
    Point p(2 , 4);
    Point q(5 , 3);
    p.displayPoint();
    q.displayPoint();
    distance(p , q);
    return 0;
}

#include <iostream>

using namespace std;
class complex
{
    int a, b;

public:
    complex(int x, int y)
    {
        a = x;
        b = y;
    }
    complex(int x){
        a = x;
        b = 0;
    }
    void displaynumber()
    {
        cout << "the number is " << a << " + " << b << "i" << endl;
    }
};
int main()
{
    complex c1(1 , 6);
    c1.displaynumber();

    complex c2(6);
    c2.displaynumber();
    return 0;
}

//Constructors With Default Arguments
#include <iostream>

using namespace std;
class Simple{
    int data1;
    int data2;
    public:
        Simple(int a , int b = 9){
            data1 = a;
            data2 = b;
        }
        void printdata();
};
void Simple :: printdata(){
    cout<<"data = "<<data1<<" and data2 = "<<data2<<endl;
}
int main(){
    Simple s(3);
    s.printdata();
    return 0;
}


//Dynamic Initialization of Objects Using Constructors

#include <iostream>

using namespace std;
class BankDeposit
{
    int principal;
    int years;
    float Ir;
    float Rv;

public:
    BankDeposit() {}
    BankDeposit(int p, int y, float r);
    BankDeposit(int p, int y, int r);
    void show();
};

BankDeposit ::BankDeposit(int p, int y, float r)
{
    principal = p;
    years = y;
    Ir = r;
    Rv = principal;
    for (int i = 0; i < y; i++)
    {
        Rv = Rv * (1 + r);
    }
}
BankDeposit ::BankDeposit(int p, int y, int r)
{
    principal = p;
    years = y;
    Ir = float(r);
    Rv = principal;
    for (int i = 0; i < y; i++)
    {
        Rv = Rv * (1 + Ir);
    }
}
void BankDeposit ::show()
{
    cout << "principlal amt = " << principal << endl
         << "return value after " << years
         << " is " << Rv << endl;
};
int main()
{
    BankDeposit bd1, bd2, bd3;
    int p, y;
    float r;
    int R;
    cout << "Enter the value of p y and r" << endl;
    cin >> p >> y >> r;
    bd1 = BankDeposit(p, y, r);
    bd1.show();

    cout << "Enter the value of p y and r" << endl;
    cin >> p >> y >> R;
    bd2 = BankDeposit(p, y, R);
    bd2.show();
    return 0;
}

//copy constructor

#include <iostream>

using namespace std;
class Number
{
    int a;

public:
    Number() {}
    Number(int num)
    {
        a = num;
    }
    Number(Number &obj)//copy constructor
    {
        a = obj.a;
    }
    void display()
    {
        cout << "the number fir this obj is " << a << endl;
    }
};

int main()
{
    Number x, y, z(45);
    x.display();
    y.display();
    z.display();

    Number z1(x);
    z1.display();
    return 0;
}

//destructor: never takes an argument nor does it take any value

#include <iostream>

using namespace std;
int count = 0;
class num{
    public:
        num(){
            count++;
            cout<<"this is the time when constructor is called for obj number "<<count<<endl;

        }
        ~num(){
            cout<<"this is the time when distructor is called for obj number "<<count<<endl;
            count--;
        }

};

int main(){
    cout<<"in the main function"<<endl;
    cout<<"Creating first obj for n1"<<endl;
    num n1;
    {
        cout<<"entering this block"<<endl;
        cout<<"Creating 2 more obj"<<endl;
        num n2 , n3;
        cout<<"exiting this block"<<endl;
    }
    cout<<"back to main"<<endl;
    return 0;
}

//Inheritance
#include <iostream>
using namespace std;
//base class
class Employee{
    public:
    int id;
    float salary;
    Employee(int inpId){
        id = inpId;
        salary = 3;
    }
    Employee(){};

};

//derived class : syntax
//class {{derived-class-name}} : {{visibility-mode}} {{base-class-name}}
//{
//    class members/methods,etc..
//1.default visibility mode is private
//private visibility mode : public members of base class will become private
//private visibility mode : public members of base class will become public

//}

class Programmer : Employee{
    public:
    Programmer(int inpId){
        id = inpId;
    };
    int languagecode = 9;
};

//creating a derived class

int main(){
      Employee kuro(1) , raptor(2);
      cout<<kuro.salary<<endl;
      cout<<raptor.salary<<endl;
      Programmer skillf(1);
      cout<<skillf.languagecode<<endl;
    return 0;
}

#include <iostream>

using namespace std;

class Base
{

    int data1;

public:
    int data2;
    void setData();
    int getData1();
    int getData2();
};
void Base ::setData(void)
{
    data1 = 12;
    data2 = 22;
}

int Base ::getData1()
{
    return data1;
}
int Base ::getData2()
{
    return data2;
}

class Derived : public Base
{
    int data3;

public:
    void process();
    void display();
};

void Derived ::process()
{
    data3 = data2 * getData1();
};
void Derived ::display()
{
    cout << "the value of data 1 is " << getData1() << endl;
    cout << "the value of data 2 is " << data2 << endl;
    cout << "the value of data 3 is " << data3 << endl;
};
int main()
{
    Derived der;
    der.setData();
    der.process();
    der.display();

    return 0;
}
//Protected Access Modifier

for a protected members
                        private members    public members    protected members
1 private members       not inherited      not inherited      not inherited

2 public members        public              private           protected

3 protected members     private           protected           protected


#include <iostream>

using namespace std;
class Base{
    protected:
        int a;
    private:
        int b;
};

class Derived : protected Base{

};
int main(){

    return 0;
}
// multi level inheritance:
#include <iostream>

using namespace std;
class Student
{
protected:
    int roll_number;

public:
    void set_roll_number(int);
    void get_roll_number(void);
};

void Student ::set_roll_number(int r)
{
    roll_number = r;
};
void Student ::get_roll_number()
{
    cout << "the roll number is " << roll_number << endl;
};
class Exam : public Student
{
protected:
    float maths;
    float physics;

public:
    void set_marks(float, float);
    void get_marks(void);
};

void Exam ::set_marks(float m1, float m2)
{
    maths = m1;
    physics = m2;
};
void Exam ::get_marks(void)
{
    cout << "marks obtained in maths are " << maths << endl;
    cout << "marks obtained in physics are " << physics << endl;
};

class Result : public Exam
{
    float percentage;

public:
    void display()
    {
        get_roll_number();
        get_marks();
        cout << "your percentage is " << (maths + physics) / 2 << endl;
    };

};
int main()
{
    Result kuro;
    kuro.set_roll_number(432);
    kuro.set_marks(90.0 , 95.0);
    kuro.display();
    return 0;
}

// multiple inheritance:

class derived : visibility mode base1, visibility mode base2{
    class body of class derived
}
#include <iostream>
using namespace std;

class Base1
{
protected:
    int base1int;

public:
    void set_base1int(int a)
    {
        base1int = a;
    }
};
class Base2
{
protected:
    int base2int;

public:
    void set_base2int(int a)
    {
        base2int = a;
    }
};
class Base3
{
protected:
    int base3int;

public:
    void set_base3int(int a)
    {
        base3int = a;
    }
};
class Derived : public Base1, public Base2, public Base3
{
public:
    void show()
    {
        cout << "the value of base1 is " << base1int << endl;
        cout << "the value of base2 is " << base2int << endl;
        cout << "the value of base3 is " << base3int << endl;
        cout << "the sum of base1 , base2 ans base3 is " << base1int + base2int + base3int << endl;
    }
};
int main()
{
    Derived kuro;
    kuro.set_base1int(32);
    kuro.set_base2int(3);
    kuro.set_base3int(43);

    kuro.show();
    return 0;
}

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


//Ambiguity Resolution

#include <iostream>

using namespace std;

class Base1{
    public:
        void greet(){
            cout<<"how are you ?? "<<endl;
        }
};
class Base2{
    void greet(){
            cout<<"kesa hai vai ?? "<<endl;
        }
};

class Derived : public Base1 ,public Base2{
    int a;
    public :
        void greet()
        {
            Base1::greet();//specify the greet
        }
};
int main(){

    return 0;
}


//Virtual Base Class

#include <iostream>

using namespace std;
class Student{
    protected :
        int roll_number;
    public:
        void set_number(int a){
            roll_number = a;
        }

        void print_number(void){
            cout<<"roll number is "<<roll_number<<endl;
        }
};

class Marks : virtual public Student{
    protected:
        float maths,physics;
    public:
        void set_marks(float m1,float m2){
            maths = m1;
            physics = m2;
        }
        void print_Marks(void){
            cout<<"your marks are : "<<endl
                <<"Maths : "<<maths<<endl
                <<"Physics : "<<physics<<endl;
        }
};

class Sports : virtual public Student{
    protected:
        float score;
    public:
        void set_score(float sc){
            score = sc;
        }
        void print_score(void){
            cout<<"your score is : "<<endl
                <<"Sports : "<<score<<endl;
        }
};

class Result : public Marks ,public Sports{
    private:
        float total;
    public:
        void display(void){
            total = maths + physics + score;
            print_number();
            print_Marks();
            print_score();

            cout<<"your total result is "<<total<<endl;
        }
};
int main(){
    Result kuro;
    kuro.set_number(990221);
    kuro.set_marks(99.0 , 92.1);
    kuro.set_score(10);
    kuro.display();
    return 0;
}
//Constructors in Derived Class

//case 1:
class A : public B{
    order of exicution of constructor : B() ,A()
}
//case 2:
class A : public B , public C
{
    order of exicution of constructor : B() , C() ,A()
}//case 3:
class A : public B ,virtual public C
{
    order of exicution of constructor : C() , B() ,A()
}

#include <iostream>

using namespace std;
class Base1
{
    int data1;

public:
    Base1(int i)
    {
        data1 = i;
        cout << "Base class constructor called " << endl;
    }
    void print_Data1(void)
    {
        cout << "value of data is " << data1 << endl;
    }
};
class Base2
{
    int data2;

public:
    Base2(int i)
    {
        data2 = i;
        cout << "Base class constructor called " << endl;
    }
    void print_Data2(void)
    {
        cout << "value of data is " << data2 << endl;
    }
};

class Derived : public Base1 , public Base2 {
    int derived1 , derived2;
    public:
        Derived(int a,int b,int c,int d) : Base1(a) , Base2(b)
        {
            cout << "Derived class constructor called " << endl;
        };
        void print_derived(void)
    {
        cout << "value of dirived1 is " << derived1 << endl;
        cout << "value of dirived2 is " << derived2 << endl;

    }
};

int main()
{
    Derived kuro(1 ,2, 3 ,4);
    kuro.print_Data1();
    kuro.print_Data2();
    kuro.print_derived();

    return 0;
}


//Initialization list in Constructors
constructor (argument_list) : initillization-section
{
    assignment + other code;
}

class test {
    int a;
    int b;
    public:
        test(int i , int j ) : a(i) , b(j){ constructor body }
};

// Pointers


#include <iostream>

using namespace std;

int main(){
    //basic eg
    int a = 4;
    int* ptr = &a;

    cout<<"the val of ptr is"<<*(ptr)<<endl;

    //new keyword
    //int *p = new int(40);
    //float *p = float int(40);
    //int arr*  = new int[3];

    //delete operator
    //delete arr;
    //delete[] arr;


    return 0;
}



#include <iostream>

using namespace std;
class Complex{
    int real, imaginary;
    public:
        void getData(){
            cout<<"the real part is "<<real<<endl;
            cout<<"the imaginary part is "<<imaginary<<endl;
        }

        void setData(int a , int b){
            real = a;
            imaginary = b;
        }
};


int main(){
    Complex c1;
    Complex *ptr = &c1;

    //or
    //Complex *ptr = new Complex;


    ptr->setData(2 , 43);
    //or (*ptr).setData(2,37);
    (*ptr).getData();



    return 0;
}


#include <iostream>

using namespace std;

class Shop
{
    int id;
    float price;

public:
    void setData(int a, float b)
    {
        id = a;
        price = b;
    }
    void getData(void)
    {
        cout << "Code of this item  is " << id << endl;
        cout << "price of this item  is " << price << endl;
    }
};
int main()
{
    int size = 3;
    int p, i;
    float q;
    Shop *ptr = new Shop[size];
    Shop *ptrTemp = ptr;
    for (i = 0; i < size; i++)
    {
        cout << "Enter Id and price of item " << i + 1 << endl;
        cin >> p >> q;
        ptr->setData(p, q);
        ptr++;
    }

    for (i = 0; i < size; i++)
    {
        cout << "Item number : " << i + 1 << endl;
        ptrTemp->getData();
        ptrTemp++;
    }

    return 0;
}


#include <iostream>

using namespace std;
class A
{
    int a;

public:
    void setData(int a)
    {
        this->a = a;
    }
    void getData(void)
    {
        cout << "Value of a is :  " << a << endl;
    }
};
int main()
{
    //this is a keyword which is a pointer which point s to the object which invokes the memeber function
    A a;
    a.setData(4);
    a.getData();

    return 0;
}

//Polymorphism
- one name multiple forms;
- function overloading;
- virtual function;
TYPES -
1 compile time polymorphism :
    1.1 function overloading
    1.2 oprator overloading
2 run time polymorphism
    2.1 virtual function


//POINTERS TO DERIVED CLASS;

#include <iostream>

using namespace std;

class Baseclass{
    public :
        int var_base;
        void display(){
            cout<<"displaying base class variable "<<var_base<<endl;
        }
};
class Derived : public Baseclass{
    public :
        int var_derived;
        void display(){
            cout<<"displaying derived class variable "<<var_derived<<endl;
        }
};
int main(){
    Baseclass * base_class_ptr;
    Baseclass obj_base;
    Derived  obj_derived;
    base_class_ptr = &obj_derived;

    base_class_ptr->var_base = 21;
    base_class_ptr->display();

    Derived * derived_class_ptr;
    derived_class_ptr = &obj_derived;


    return 0;
}


//virtual functions

#include <iostream>

using namespace std;

class Baseclass{
    public :
        int var_base;
        virtual void display(){
            cout<<"displaying base class variable "<<var_base<<endl;
        }
};
class Derived : public Baseclass{
    public :
        int var_derived;
        void display(){
            cout<<"displaying derived class variable "<<var_derived<<endl;
        }
};
int main(){
    Baseclass * base_class_ptr;
    Baseclass obj_base;
    Derived  obj_derived;
    base_class_ptr = &obj_derived;

    base_class_ptr->var_base = 21;
    base_class_ptr->display();

    return 0;
}



#include <iostream>
#include <cstring>
using namespace std;
class Kt{
    protected:
        string title;
        float rating;
    public :
        Kt(string s , float r){
            title =  s;
            rating = r;
        }

        virtual void display(){}
};

class Ktvideo : public Kt{
    float video_length;
    public:
        Ktvideo( string s , float r , float vl) : Kt(s , r){
            video_length = vl;
        };
        void display(){
            cout<<"this is amazing video with title "<<title<<endl
                <<"it has rating of "<<rating<<" / 10"<<endl
                <<"it has runtime of "<<video_length<<" minutes "<<endl;
        }

};

class KtText : public Kt{
    int words;
    public:
        KtText( string s , float r , int wc) : Kt(s , r){
            words = wc;
        }
        void display(){
            cout<<"this is amazing blog with title "<<title<<endl
                <<"it has rating of "<<rating<<" / 10"<<endl
                <<"it has "<<words<<" words "<<endl;
        }

};
int main(){

    string title;
    float rating, vlen;
    int words;

    //video
    title =  "how to get mad pussy in gta";
    vlen = 5.34;
    rating = 8.5;
    Ktvideo gtavideo(title , rating , vlen );
    //gtavideo.display();


    //word
    title =  "how to get mad pussy in gta";
    words = 534;
    rating = 9.5;
    KtText gtaBlog(title , rating , words );
    //gtaBlog.display();

    Kt * vid[2];

    vid[0] = &gtavideo;
    vid[1] = &gtaBlog;

    vid[0]->display();
    vid[1]->display();

    return 0;
}

RULES for virtual funcs{
    -- they can not be static
    --They are accesed by object pointers
    --virtual funcs can be friend of another class
    --virtual func in base class might no tbe used
    -- virtual func defined in a base class their is no need to redo it in the base class
}



//Abstract Base Class & Pure Virtual Functions
//Abstract Base Class is made for the pure virtual func

#include <iostream>
#include <cstring>
using namespace std;
class Kt{
    protected:
        string title;
        float rating;
    public :
        Kt(string s , float r){
            title =  s;
            rating = r;
        }

        virtual void display() = 0;//PURE VIRTUAL FUNC
};

class Ktvideo : public Kt{
    float video_length;
    public:
        Ktvideo( string s , float r , float vl) : Kt(s , r){
            video_length = vl;
        };
        void display(){
            cout<<"this is amazing video with title "<<title<<endl
                <<"it has rating of "<<rating<<" / 10"<<endl
                <<"it has runtime of "<<video_length<<" minutes "<<endl;
        }

};

class KtText : public Kt{
    int words;
    public:
        KtText( string s , float r , int wc) : Kt(s , r){
            words = wc;
        }
        void display(){
            cout<<"this is amazing blog with title "<<title<<endl
                <<"it has rating of "<<rating<<" / 10"<<endl
                <<"it has "<<words<<" words "<<endl;
        }

};
int main(){

    string title;
    float rating, vlen;
    int words;

    //video
    title =  "how to get mad pussy in gta";
    vlen = 5.34;
    rating = 8.5;
    Ktvideo gtavideo(title , rating , vlen );
    //gtavideo.display();


    //word
    title =  "how to get mad pussy in gta";
    words = 534;
    rating = 9.5;
    KtText gtaBlog(title , rating , words );
    //gtaBlog.display();

    Kt * vid[2];

    vid[0] = &gtavideo;
    vid[1] = &gtaBlog;

    vid[0]->display();
    vid[1]->display();

    return 0;
}

//File I/O

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//the classes used to work with files in c++
//fstreambase
//ifstream - > derived from fstreambase
//ofstream - > derived from fstreambase

//in oder to work with files in c u have to open them
//ways are
//1 . opeing using constructor
//2 . using memberfunction open() of the class

int main(){
    string st;
    //write opration
    //string st = "dont be like 6ix9ine that mother fucking snitch";
    //opening a file with constructor
    //ofstream out("sample.txt");
    //out<<st;

    //reading the file;

    ifstream in("sample.txt");
    //in>>st; will give only one word
    getline(in , st);//it will give one line
    cout<<st;

    return 0;
}


#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    string name;
    ofstream kout("sample.txt");
    cout<<"enter your name : "<<endl;
    cin>>name;
    kout<<"boku no namaewa " + name;
    kout.close();

    ifstream kin("sample.txt");
    string content;
    getline(kin , content);

    cout<<"the content of this file is  : "<<content<<endl;
    kin.close();
    return 0;
}


#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ofstream out;
    out.open("sample.txt");
    out << "ha vai kiski ? ";
    out.close();

    ifstream in;
    string st1, st2;
    in.open("sample.txt");

    while (in.eof() == 0)
    {
        getline(in, st1);
        cout << st1 << endl;
    }
    in.close();

    return 0;
}



//templates / parameterized classes : usable for generic programming
//syntax
// template <class T>
//class vector{
//T * arr
//public :
//vector(T*ar){
//code
//}
//}

#include <iostream>

using namespace std;
template <class T>
class vector
{
public:
    T *arr;
    int size;
    vector(int m)
    {
        size = m;
        arr = new T[size];
    }
    T dotProduct(vector &v)
    {
        T d = 0;
        for (int i = 0; i < size; i++)
        {
            d += this->arr[i] * arr[i];
        }
        return d;
    }
};
int main()
{
    vector <float>v(3);
    v.arr[0] = 4.5;
    v.arr[1] = 2.2;
    v.arr[2] = 1.7;

    vector <float>v1(3);
    v.arr[0] = 2.7;
    v.arr[1] = 5.9;
    v.arr[2] = 8.2;

    float a = v.dotProduct(v1);
    cout << a << endl;

    return 0;
}

//template with multiple parameters
template <class T1 , class T2>
class NameofClass{
    //body
};



#include <iostream>

using namespace std;
template <class T1, class T2>
class data
{
public:
    T1 data1;
    T2 data2;

    data(T1 a ,T2 b){
        data1 = a;
        data2 = b;
    }
    void display()
    {
        cout << this->data1 << this->data2;
    }
};
int main()
{
    data<int , char> obj(1 , 'c');
    obj.display();
    return 0;
}


#include <iostream>

using namespace std;
template <class T1, class T2>
class simple_clc
{
protected:
    T1 num1;
    T2 num2;

public:
    simple_clc(T1 a, T2 b)
    {
        num1 = a;
        num2 = b;
    }
        void display(){
        cout << "the sum is " << num1 + num2 << endl;
        cout << "the multi is " << num1 * num2 << endl;
        cout << "the division is " << num1 / num2 << endl;
        cout << "the sub is " << num1 - num2 << endl;
    };
};

int main()
{
    simple_clc < float , int >x(1.5 , 5);
    x.display();
    return 0;
}

//default parameters
#include <iostream>

using namespace std;
template <class T1 = int, class T2 = float>
class simple_clc
{
protected:
    T1 num1;
    T2 num2;

public:
    simple_clc(T1 a, T2 b)
    {
        num1 = a;
        num2 = b;
    }
    void display()
    {
        cout << "the sum is " << num1 + num2 << endl;
        cout << "the multi is " << num1 * num2 << endl;
        cout << "the division is " << num1 / num2 << endl;
        cout << "the sub is " << num1 - num2 << endl;
    };
};

int main()
{
    simple_clc<> x(3, 7.8);
    x.display();

//or
    simple_clc<float , int> y(3.65, 7);
    y.display();

    return 0;
}


//function templates

#include <iostream>

using namespace std;

template<class T>
void swap__NUM(T &a , T &b){
    T temp = a;
    a = b;
    b = temp;
};

template <class T1  ,class T2>
float funcavg(T1 a ,T2 b){
    float avg = (a+b)/2;
    return avg;
};
int main(){
    float a;
    a = funcavg(3 , 8.4);
    cout<<"Avg =  "<<a<<endl;

    int x = 1 , y = 4;
    swap__NUM(x , y);

    cout<<"X : "<<x<<"  Y : "<<y<<endl;

    return 0;
}



#include <iostream>

using namespace std;
template <class T>
class Base
{
public:
    T data;
    Base(T a)
    {
        data = a;
    }
    void display();
};

template <class T>
void Base<T>::display()
{
    cout << data << endl;
}

void func(int a)
{
    cout << "i am 1 func" <<a<< endl;
};
template <class T>
void func(T a)
{
    cout << "i am temp func " <<a<< endl;
};
int main()
{
    Base<float> k(4.3);
    cout << k.data << endl;
    k.display();

    func('a');
    return 0;
}

//******STL********

//stl = standard template library of generic classes and funcs;

//componets = 1 . container : stores data | 2 . algorithms : procedure to process data | 3. iterators : object which points to a element of a container

//1 . CONTAINTER;
//types :
// 1 .sequence container : linear fashion eg {vector , list , dequeue}  |

vector :
            random access -> fast
            middle insertion del -> slow
            insertion at end -> fast

list :
            random access -> slow
            middle insertion del -> fast
            insertion at end -> fast


// 2 .associative container : direct access tree like data structure eg {set, muliset, multimap}
associative containers:
            random access -> slow
            middle insertion del -> fast
            insertion at end -> fast


// 3  .derived container : real world modleing eg {stack , queue , priority queue}

depends on data structues



//vectors

#include <iostream>
#include <vector>
using namespace std;
template <class T>
void display(vector<T> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
};
int main()
{
    //ways to make vector
    vector<float> vec1; //zero length func

    vector<int> vec2(4); //int vector with 4 elements

    vector<char> vec3(4);     //char vector with 4 elements
    vector<char> vec3a(vec3); //char vector with 4 elements from vec3

    vector<double> vec4(4); //double vector with 4 elements

    vector<char> vec5(6, 3); // 6 element vector fo 3's

    float ele;
    int size;

    cout << "enter the sIze of vector : " << endl;
    cin >> size;

    for (int i = 0; i < size; i++)
    {
        cout << "enter an element to add to this vector : ";
        cin >> ele;
        vec1.push_back(ele);
    }
    //vec1.pop_back(); //last member delete

    display(vec1);
    vector<float>::iterator iter = vec1.begin();
    vec1.insert(iter + 1, 3, 566); //inserts stuff where the iter pointer id the pointer

    display(vec1);

    return 0;
}


//LISTS

#include <iostream>
#include <list>
using namespace std;

void display(list<int> &lst)
{
    list<int>::iterator it;
    for (it = lst.begin(); it != lst.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
    //how to make list
    list<int> list1; //empty list of 0  length

    //list<int> list2(7); //emptly list of 7 length

    list1.push_back(5);
    list1.push_back(7);
    list1.push_back(5);
    list1.push_back(9);
    list1.push_back(3);
    list1.push_back(1);

    display(list1);
    //removing elements from list
    list1.pop_back();
    list1.pop_front();
    list1.remove(9);

    //sorting
    list1.sort();
    display(list1);

    list<int> list2(3);
    list<int>::iterator iter = list2.begin();
    *iter = 54;
    iter++;
    *iter = 42;
    iter++;
    *iter = 78;
    iter++;
    display(list2);

    //MERging lists
    list1.merge(list2);
    list1.sort();
    list1.reverse();
    display(list1);


    return 0;
}


//map associative array

#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    map<string, int> marksMap;
    marksMap["kuro"] = 90;
    marksMap["raptor"] = 23;
    marksMap["phenom"] = 65;
    map<string, int>::iterator iter;
    for (iter = marksMap.begin(); iter != marksMap.end(); iter++)
    {
        cout<<(*iter).first<<" "<<(*iter).second<<"\n";
    }

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n , mx = 0;
    string a;
    map<string , int> mpp;
    map<string , int>::iterator iter;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>a;
        mpp[a]++;
    }
    for (iter = mpp.begin(); iter != mpp.end(); iter++)
    {
        if (iter->second>mx)
        {
            mx = iter->second;
            a = iter->first;
        }
    }
    cout<<a;
    return 0;
}

//function obj (functor) : func wrapped in a class so that it is available like an obj

#include <iostream>
#include <functional>
#include <algorithm>
using namespace std;

int main()
{
    int arr[] = {16, 32, 73, 94, 25, 36};
    sort(arr, arr + 5 , greater<int>());
    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}

#include <bits/stdc++.h>

   using namespace std;
   void display(int arr[] , int n){
       for (int i = 0; i < n; i++)
       {
           cout<<arr[i]<<" ";
       }
       cout<<endl;
   }
   int index_insertion(int arr[] , int size , int ele , int capacity , int index){
       if (size>=capacity)
       {
           return -1;
       }
       for (int i = size - 1; i >= index; i--)
       {
           arr[i+1] = arr[i];
       }
       arr[index] = ele;
       return 1;

   };
   int main(){
       int arr[100] = {7 , 8 , 12 , 27 , 88};
       int size = 5 , ele = 45 , index = 3;
       display(arr , size);
       index_insertion(arr , size , ele , 100 , index);
       return 0;
   }
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve(){
    int a = 6;
    int b = 2;
    int c = a^b;
    cout<<c;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    //cin>>t;
    while (t--)
    {
        solve();
    }
    cout<<endl;
    #ifndef ONLINE_JUDGE
    cerr <<"Time :"<<1000*((double)clock()) / (double)CLOCKS_PER_SEC<<"ms";
    #endif
        return 0;
}
// operator overloading

// overloading - to sub 2 fractions using friend func
#include <iostream>
#include <algorithm>
using namespace std;
class Fraction
{
    int n, d;

public:
    Fraction(int num, int deno)
    {
        n = num;
        d = deno;
    }
    friend Fraction operator-(const Fraction &f1, const Fraction &f2);
};
Fraction operator-(const Fraction &f1, const Fraction &f2)
{
    if (f1.d == 0 || f2.d == 0)
    {
        cout << "Error: Attempting to Divide by Zero";
        exit(0);
    }
    int nnum, l, s;
    l = (f1.d * f2.d) / __gcd(f1.d, f2.d);
    s = ((f1.n * l) / f1.d) - ((f2.n * l) / f2.d);
    nnum = s / __gcd(s, l);
    l = l / __gcd(s, l);
    if (l == 1)
        cout << nnum;
    else if (l < 0)
        cout << "-" << nnum << "/" << abs(l);
    else
        cout << nnum << "/" << l;
    return f1;
}
int main()
{
    int n1, n2, d1, d2;
    cin >> n1 >> d1;
    cin >> n2 >> d2;
    Fraction ob1(n1, d1), ob2(n2, d2);
    Fraction fracSum{ob1 - ob2};
    return 0;
}


#include <iostream>
using namespace std;
int r, c;
class matrix
{
public:
    int M[101][101];
    void create()
    {
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                cin >> M[i][j];
    }
    friend matrix operator+(matrix &, matrix &);
};
matrix operator+(matrix &a, matrix &b)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << a.M[i][j] + b.M[i][j] << " ";
        }
        cout << "\n";
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << a.M[i][j] - b.M[i][j] << " ";
        }
        cout << "\n";
    }
    return a;
}
int main()
{
    cin>>r>>c;
    matrix a, b;
    a.create();
    b.create();
    matrix Summ{a + b};
    return 0;
}
*/
#include <bits/stdc++.h>
using namespace std;

class yt
{
public:
    string name;
    int num;
    yt(string n, int no)
    {
        name = n;
        num = no;
    }
};
void operator<<(ostream &cout, yt &yt1)
{
    cout << "Name: " << yt1.name << "\nSubs:" << yt1.num;
}
int main()
{
    yt yt1("name", 9), yt2("na", 10);
    cout << yt1;
    cout << yt2;
    return 0;
}
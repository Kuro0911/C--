    /*
#include <iostream>
#include <string>
using namespace std;
class Employee
{
public:
    string name;
    int salary;
    Employee(string name, int salary , int sp)
    {
        this->name = name;
        this->salary = salary;
        secretPassword->sp;
    }

    void printDetails()
    {
        cout << "the name of the employee is " << this->name << " and his sallary is " << this->salary;
    }

    private:
    int secretPassword;
};
int main()
{
    //cout<<"hello world"<<endl;
    //cout<<"next line";

    //datatypes

    //int a,b,c;

    //short a=9;

    //long b;

    //long long c;

    //float score = 80.09;

    //double score2;

    //long double score score3;

    //cout<<ea;

    int a, b;

    cout << "Enter first number" << endl;

    cin >> a;

    cout << "Enter second number" << endl;

    cin >> b;

    cout << "a + b is " << a + b<<endl;
    cout << "a - b is " << a - b<<endl;
    cout << "a * b is " << a * b<<endl;
    cout << "a / b is " << a / b<<endl;

    int age;
    cout << "enter your age :" << endl;
    cin >> age;
    switch (age)
    {
    case 12:
        cout << "you are 12 years old";
        break;

    case 20:
        cout << "you are 20 years old";
        break;
    default:
        cout << "you are nither 12 nor 20";
        break;
    }

    if (age >> 18)
    {
        cout << "you can vote";
    }
    else
    {
        cout << "you cant vote";
    }

   
   int index = 0;
   while (index<10)
   {
       cout<<"we are at index number : " <<index<<endl;
       index=index + 1;
   }

   ALL THE LOOPS ARE SAME AS C

    int i, j, rows;
    cout << "enter the number of rows :";
    cin >> rows;
    for (i = 0; i <= rows; i++)
    {
        for (j = 0; j <= i; j++)
        {
            cout << "* ";
        }
        cout << "" << endl;
    }
    int a = 323;
    cout << (float)a / 34 << endl;

   string name = "dhananjai";

    cout<<"my name is "<<name<<endl;
    cout<<"my names lenght is "<<name.length()<<endl;
    cout<<"my name is "<<name.substr(0 , 3)<<endl;
    cout<<"my name is "<<name<<endl;
   
   
   int a =65;
   int* ptra;
   ptra = &a;

   cout<<"the value of a is "<<a<<endl;
   cout<<"the value of a is "<<*ptra<<endl;
   cout<<"the address of a is "<<ptra<<endl;
   cout<<"the address of a is "<<&a<<endl;   

    Employee dha("dhananjai sharma", 100 , 5151545);
    //dha.name = "dhananjai";
    //dha.salary = 100;
    dha.printDetails();


    return 0;
}
recursions

#include <iostream>

using namespace std;
int factorial(int n){
    if (n<=1)
    {
        return 1;
    }
    
    return n * factorial(n-1);
}
int main(){
    //facorial of a number
    int a;
    cin>>a;
    cout<<"facotial of a is = "<<factorial(a);
    return 0;
}
*/


#include <bits/stdc++.h>

using namespace std;
typedef long long                                        ll;
typedef long double                                      ld;
typedef pair <int, int>                                  pii;
typedef pair <pii, int>                                  ppi;
typedef pair <int, pii>                                  pip;
typedef pair <pii, pii>                                  ppp;
typedef pair <ll, ll>                                    pll;

void solve(){
    ll n,k;cin>>n>>k;
    map<ll , ll> mp;
    for (ll i = 1; i <= n; i++){
        mp.insert({i,i});
    }
    while (k--){
        vector<ll> Evec,Ovec;
        for (auto x : mp)
        {
            if(x.first%2==1){
                Ovec.push_back(x.second);
            }else{
                Evec.push_back(x.second);
            }
        }
        mp.clear();
        ll ind = 1;
        for (auto x : Ovec){
           mp.insert({ind,x});
           ind++; 
        }
        for (auto x : Evec){
           mp.insert({ind,x});
           ind++; 
        }
        for (auto x : mp)
        {
            cout<<x.second <<" ";
        }
        cout<<endl;
    }
    for (auto x : mp)
    {
        cout<<x.second <<" ";
    }
    cout<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;cin>>t;
    while (t--)
    {
        solve();
    }
    #ifndef ONLINE_JUDGE
    cerr <<"Time :"<<1000*((double)clock()) / (double)CLOCKS_PER_SEC<<"ms";
    #endif
        return 0;
}


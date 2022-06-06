/*
#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    char zoostr[30];
    int n,count_z=0,count_o=0;
    cin>>zoostr;

    n = strlen(zoostr);
    for (int i = 0; i < n; i++)
    {
        if (zoostr[i]=='z'||zoostr[i]=='Z')
        {
            count_z++;
        }
        else{
            count_o++;
        }
    }
    if (2*count_z==count_o)
    {
        cout<<"yes";
    }
    else{
        cout<<"no";
    }


    return 0;
}
#include <iostream>

using namespace std;
void OTaxi()
{
    int D, oc, of, od, otc;
    oc + (D - of) * od == otc;
}
void Ctaxi()
{
    int D, Cb, Cs, Cm, Cd, ctc;
    Cb + (D / Cs) * Cm + D *Cd == ctc;
}
int main()
{
    int D, oc, of, od, Cb, Cs, Cm, Cd, otc, ctc;
    cin >> D;
    cin >> oc;cin >> of;cin >> od;
    cin >> Cs;cin >> Cb;cin >> Cm;cin >> Cd;
    OTaxi();
    Ctaxi();
    if (otc < ctc)
    {
        cout << "Online Taxi" << endl;
    }
    else if (ctc < otc)
    {
        cout << "Classic Taxi" << endl;
    }
    else
    {
        cout << "Online Taxi" << endl;
    }

    return 0;
}
#include <iostream>

using namespace std;

int main()
{
    int T, N, M;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        cin >> N >> M;
        if (M % N == 0)
        {
            cout << "Yes"<<endl;;
        }
        else
        {
            cout << "no"<<endl;;
        }
    }
    return 0;
}
#include <iostream>
#include <cstring>

using namespace std;

int main(){
    char str[100];
    cin>>str;
    int len = strlen(str);
    for (int i = len; i >= 0; i--)
    {
        cout<<str[i];
    }

    return 0;
}
#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    int T, i;
    int flag = 0;
    char s[10001];
    char val[] = "AEIOUaeiou";
    cin >> T;
    for (i = 0; i < T; i++)
    {
        cin >> s;
        int len = strlen(s);
        int a = 0, b = 0;
        for (int y = 0; y < 5; y++)
        {
            for (int i = 0; i < len; i++)
            {
                if (val[y] == s[i])
                {
                    a++;
                    break;
                }
            }
        }
        for (int y = 5; y < 10; y++)
        {
            for (int i = 0; i < len; i++)
            {
                if (val[y] == s[i])
                {
                    b++;
                    break;
                }
            }
        }
        if (a == 5 || b == 5)
        {
            cout << "lovely string"<<endl;;
        }
        else
        {
            cout << "lovely string"<<endl;;
        }
    }

    return 0;
}
#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    char Vstr[30];
    int n,count_a=0;
    cin>>n;
    cin>>Vstr;

    n = strlen(Vstr);
    for (int i = 0; i < n; i++)
    {
        if (Vstr[i]=='a'||Vstr[i]=='A')
        {
            count_a++;
        }
        else if (Vstr[i]=='e'||Vstr[i]=='E')
        {
            count_a++;
        }
        else if (Vstr[i]=='i'||Vstr[i]=='I')
        {
            count_a++;
        }
        else if (Vstr[i]=='o'||Vstr[i]=='O')
        {
            count_a++;
        }
        else if (Vstr[i]=='u'||Vstr[i]=='U')
        {
            count_a++;
        }

        else{
            count_a--;
        }
    }
    if (count_a == 5)
    {
        cout<<"lovely string";
    }
    else{
        cout<<"ugly string";
    }
    return 0;
}
#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int x;
    double Ib,Ob;
    cin>>x;cin>>Ib;
    if (x%5==0)
    {
        if (x <= (Ib-0.50))
        {
            Ob = Ib- x - 0.5;
            cout<<fixed<<setprecision(2)<<Ob;
        }
        else{
            cout<<Ib;
        }

    }
    else{
        cout<<Ib;
    }
    return 0;
}
#include <iostream>

using namespace std;

int main(){
    int k,n,count=0;
    cin>>n>>k;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin>>t;
        if (t % k == 0)
        {
            count++;
        }
    }
    cout<<count;

    return 0;
}
#include <iostream>

using namespace std;

int main(){
    int a,b,t,sum;
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        sum = a + b;
        cout<<sum<<endl;
    }

    return 0;
}
#include <iostream>

using namespace std;

int main(){
    int T,num,count_4 = 0 , a,f;
    cin>>T;
    for (int k = 0; k < T; k++)
    {
        cin>>a;
        while (a != 0)
        {
            f = num % 10;
            if (f == 4)
            {
                count_4++;
            }
            num = num/10;
        }
        cout<<count_4<<endl;
    }

    return 0;
}
#include <iostream>
using namespace std;

int main() {

    int T,i,k,n,c,e;
    cin>>T;
    for(k=0;k<T;k++){
        cin>>n;
        c=0;
        while(n!=0){
            e=n%10;
            if(e==4){
                c++;
            }
            n=n/10;
        }
        cout<<c<<endl;
    }
    return 0;
}
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
    int a,t;
    cin>>t;
    while (t--)
    {
        cin>>a;
        cout<<factorial(a)<<endl;
    }
    return 0;
}
#include <iostream>

using namespace std;

int main()
{
    long long t, a, sum, remainder, n;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        sum = 0;
        cin >> a;
        n = a;
        while (n != 0)
        {
            remainder = n % 10;
            sum = sum + remainder;
            n = n / 10;
        }
        cout << sum << endl;
    }

    return 0;
}
#include <iostream>

using namespace std;

int main(){
    long long t,a,b,remainder;
    cin>>t;
    while (t--)
    {
        remainder = 0;
        cin>>a>>b;
        remainder = a % b;
        cout<<remainder<<endl;
    }

    return 0;
}
#include <iostream>
#include <math.h>
using namespace std;

int main(){
    int t,a,sum,fd,ld,nod;
    cin>>t;
    while (t--)
    {
        sum = 0;
        cin>>a;
        fd = a % 10;
        nod = log10(a) + 1;
        ld = a / pow(10 , nod -1);
        sum = fd + ld;
        cout<<sum<<endl;
    }

    return 0;
}
#include <iostream>
#include<algorithm>
using namespace std;

int main(){
    int t;
    int arr[t];
    cin>>t;
    for (int i = 0; i < t; i++)
    {
        cin>>arr[i];
    }
    //sort(arr , arr + t);
    for (int i = 0; i < t; i++)
    {
        cout<<arr[i]<<endl;
    }

    return 0;
}
#include <iostream>

using namespace std;

int main(){
    int t,a,reverse,remainder;
    cin>>t;
    while (t--)
    {
        reverse = 0;
        cin>>a;
        while (a != 0)
        {
            remainder = a % 10;
            reverse = reverse * 10 + remainder;
            a /= 10;
        }
        cout<<reverse<<endl;
    }

    return 0;
}
#include <iostream>
#include <math.h>
using namespace std;

int main(){
    int t,a;
    cin>>t;
    while (t--)
    {
        cin>>a;
        a = sqrt(a);
        cout<<round(a)<<endl;
    }

    return 0;
}
#include <iostream>

using namespace std;

int main(){
    int n,score_1,score_2,l,w,count_l1 = 0,count_l2 = 0;
    cin>>n;
    while (n--)
    {
        cin>>score_1>>score_2;
        if (score_1 > score_2 )
        {
            l = score_1 - score_2;
            l = abs(l);
            count_l1++;
        }
        else if (score_2 > score_1)
        {
            l = score_2 - score_1;
            l = abs(l);
            count_l2++;
        }
        else{
            cout<<"tie";
        }
    }
    if (count_l1 >> count_l2)
    {
        cout<<"1";
    }
    else{
        cout<<"2";
    }
    return 0;
}
#include <iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n],b[n],c[n],d[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i]>>b[i];
    }
    int score_1 = 0 ,score_2 = 0;
    for (int i = 0; i < n; i++)
    {
        score_1 = score_1 + a[i];
        score_2 = score_2 + b[i];
        c[i] = abs(score_1 - score_2);
        if (score_1 > score_2)
        {
            d[i] = 1;
        }
        else{
            d[i] = 2;
        }
    }
    int x = max_element(c ,c+n) - c;
    cout<<d[x]<<"\t"<<c[x];
    return 0;
}
#include <iostream>

using namespace std;

int main(){
    int t,a,b,c;
    cin>>t;
    for (int i = 0; i < t; i++)
    {
        cin>>a>>b>>c;
        if (a > b && a < c )
        {
            cout<<a<<endl;
        }
        else if (b > a && b < c )
        {
            cout<<b<<endl;
        }
        else if (c > b && c < a )
        {
            cout<<c<<endl;
        }
        else{
            cout<<"too big"<<endl;
        }
    }

    return 0;
}
#include <iostream>

using namespace std;

int main(){
    int t;
    int x = 3 , a[x];
    cin>>t;

    while (t--)
    {
        for (int i = 0; i < 3; i++)
        {
            cin>>a[i];
        }
        sort(a,a+j);
        cout<<a[1]<<endl;
    }

    return 0;
}
#include <iostream>

using namespace std;

int main(){
    int t,n;
    cin>>t;
    while (t--)
    {
        cin>>n;
        cout<<(n/2)+1<<endl;
    }

    return 0;
};



#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    bool chk_Lv, chk_Uv;
    int n = 0;
    string s;
    cin >> s;
    n = s.length();

    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'a')
        {
            chk_Lv == true;
        }
        else if (s[i] == 'A' )
        {
            chk_Uv == true;
        }
        else
        {
            chk_Uv == false;
            chk_Lv == false;
        }
    }
    if (chk_Lv == true)
    {
        cout << "lovely string";
    }
    else if (chk_Uv == true)
    {
        cout << "lovely string";
    }


    else
    {
        cout << "ugly string";
    }

    return 0;
}

#include <iostream>

using namespace std;

int main()
{
    int t;
    int size, arr[100000], n;
    cin >> t;
    while (t--)
    {
        cin >> size;
        n = 0;
        for (int i = 0; i < size; i++)
        {

            cin >> arr[i];
            n = n + arr[i];
        }
        if (n % 2 == 0)
        {
            cout << "1" << endl;
        }
        else
        {
            cout << "2" << endl;
        }
    }

    return 0;
}


#include <iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        long long a, b;
        int count = 0;

        cin >> a >> b;
        for (long long i = a; i <= b; i++)
        {
            if (i%10 == 2 || i%10 == 3 || i%10 == 9)
            {
                count++;
            }
        }
        cout << count << endl;
    }

    return 0;
}
#include <iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int count;
        int n;
        cin>>n;

        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin>>arr[i];
        }
        sort(arr , arr + n);
        count = 0;
        for (int i = 0; i < n; i++)
        {
            if (count >= arr[i])
            {
                count++;
            }
        }
        cout<<count<<endl;
    }

    return 0;
}

#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int sum = 0;
        for (int i = 0; i < s.strlen(); i++)
        {
            if (s[i] <= '0' && s[i] <= '9')
            {
                sum = sum + (s[i] - '0');
            }
        }
        cout << sum << endl;
    }

    return 0;
}

#include <iostream>

using namespace std;

int main(){
    long long a , b, c ;
    cin>>a>>b>>c;
    if (a > b && a > c  )
    {
        cout<<a<<endl;
    }
    else if (b > c && b > a )
    {
        cout<<b<<endl;
    }
    else if (c > b && c > a )
    {
        cout<<c<<endl;
    }


    return 0;
}

#include <iostream>

using namespace std;

int main(){
    int a,multi;
    cin>>a;
    for (int i = 1; i <= 10; i++)
    {
        multi = a * i;
        cout<<multi<<endl;
    }

    return 0;
}
#include <iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    if (n%3==0)
    {
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    return 0;
}
#include <iostream>

using namespace std;

int main(){
    int n,a;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>a;
        cout<<a<<" ";
    }

    return 0;
}

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int  a[n], b[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    int min = *min_element(a, a + n);
    int f = 0, c = 0;
    for (int i = 0; i < n; i++)
    {
        while (a[i] > min && b[i] != 0)
        {
            a[i] -= b[i];
            c++;
        }
        if (a[i]<min)
        {
            i = -1;
        }
        if (a[i] <0)
        {
            f = 1;break;
        }
    }
    if (f == 0)
    {
        cout<<c<<endl;
    }
    else{
        cout<<"-1"<<endl;
    }
    return 0;
}

#include <iostream>

using namespace std;

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int A,B,C,d,D;
        cin>>D>>d>>A>>B>>C;
        int Td = d*D;
        if ( Td >= 10  && Td < 21  )
        {
            cout<<A<<endl;
        }
        else if ( Td >= 21  && Td < 42  )
        {
            cout<<B<<endl;
        }
        else if ( Td >= 42 )
        {
            cout<<C<<endl;
        }
        else{
            cout<<"0"<<endl;
        }

    }

    return 0;
}
*******check how to do********
#include <iostream>

using namespace std;

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int P,G,X[10];
        cin>>G>>P;
        for (int i = 0; i < 10; i++)
        {
            cin>>X[i];
        }
        int mindays = 0;
        int maxdays = 0;
        for (int i = 0; i <= G; i++)
        {
            if (P == X[i] )
            {
                mindays++;
                maxdays++;
            }
            else if (P < X[i])
            {
                X[i + 1] += P - X[i];
                maxdays++;
            }
            else if (P > X[i] )
            {
                P += P - X[i];
                X[i + 1] -= P - X[i];
                mindays++;
            }

        }
        cout<<mindays<<" "<<maxdays;
    }

    return 0;
}
#include <iostream>

using namespace std;
int permute(int A[], int P[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int next = 1;
        while (P[next] >= 0)
        {
            swap(A[i], A[P[next]]);
            int temp = P[next];
            P[next] -= size;
            next = temp;
        }
    }
};
void swap(int digits[], int index1, int index2)
{
    int temp = 0;
    temp = digits[index1];
    digits[index1] = digits[index2];
    digits[index2] = temp;
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n,Q, x,x1, y ,q;
        int A[100000], P[100000];
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> A[i] >> P[i];
        }
            cin>>Q;
            if (Q == 1)
            {
                int size = sizeof(A) / sizeof(int);
                permute(A, P, size);
            }
            if (Q = 2)
            {
                int size = sizeof(A) / sizeof(int);
                permute(A, P, size);
                cin >> x >> y;
                swap(A, x, y);
            }
            if (Q == 3)
            {
                int size = sizeof(A) / sizeof(int);
                permute(A, P, size);
                cin >>q>> x >> y;
                swap(A, x, y);
                cin >>q>> x1;
                cout << A[x1] << endl;
            }
    }

    return 0;
}
#include <iostream>

using namespace std;
void reverseArr(int arr[] ,int start ,int end){
    while (start<end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] =temp;
        start++;
        end--;
    }

};
void displayarr(int arr[] , int size){
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i];
    }

};
int main(){
    int size,n;
    cin>>size;

    int *arr = new int[size];

    for (int i = 0; i < size; i++)
    {
        cin>>arr[i];
    }
    reverseArr(arr, 0 , size - 1);
    displayarr(arr , size);
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main(){
    int N,K;
    cin>>N>>K;
    vector<int> vec1(N);
    vector<int> :: iterator it;
    for (int i = 0; i < N; i++)
    {
        int ele;
        cin>>ele;
        vec1.push_back(ele);
    }
    sort(vec1.begin() , vec1.end());
    it = find(vec1.begin() , vec1.end() , K);
    if (it != vec1.end())
    {
        cout<<"1"<<endl;
    }
    else{
        cout<<"-1"<<endl;
    }
}
#include <bits/stdc++.h>

using namespace std;

int main(){
    int N;
    cin>>N;
    vector<int> vec1(N);
    for (int i = 0; i < N; i++)
    {
        int ele;
        cin>>ele;
        vec1.push_back(ele);
    }
    reverse(vec1.begin() , vec1.end());
    for (int i = 0; i < N; i++)
    {
        cout<<vec1[i]<<" ";
    }
    return 0;
}

#include <bits/stdc++.h>

using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S;
        cin>>S;
        int len;
        len = S.length();
        string ::iterator iter1 = begin(S);
        string ::iterator iter2 = end(S);
        if (len % 2 == 0)
        {
            int count_yes = 0;
            int count_no = 0;
            for (iter1 = begin(S); iter1 != end(S) - (len / 2); iter1++)
            {
                for (iter2 = begin(S) + (len / 2); iter2 != end(S); iter2++)
                {
                    if (S[*iter1] == S[*iter2])
                    {
                        count_yes++;
                    }
                    else
                    {
                        count_no++;
                    }
                }
            }
            if (count_yes == count_no)
            {
                cout << "YES"<<endl;
            }
            else
            {
                cout << "NO"<<endl;
            }
        }
        else
        {
            int count_yes = 0;
            int count_no = 0;
            for (iter1 = begin(S); iter1 != end(S) - ((len / 2) + 1); iter1++)
            {
                for (iter2 = begin(S) + ((len / 2) + 1); iter2 != end(S); iter2++)
                {
                    if (S[*iter1] == S[*iter2])
                    {
                        count_yes++;
                    }
                    else
                    {
                        count_no++;
                    }
                }
            }
            if (count_yes == count_no)
            {
                cout << "YES"<<endl;
            }
            else
            {
                cout << "NO"<<endl;
            }
        }
    }
    return 0;
}

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
void display(vector<ll> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
};
int main(){
    ll C;
    cin>>C;
    vector<ll> budget;
    for (int i = 0; i < C; i++)
    {
        int ele;
        cin>>ele;
        budget.push_back(ele);
    }
    display(budget);
    return 0;
}

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll N,remainderNum,reveseNum=0;
        cin>>N;
        while (N!=0)
        {
            remainderNum = N%10;
            reveseNum = reveseNum*10 + remainderNum;
            N /= 10;
        }
        cout<<reveseNum<<endl;
    }
    return 0;
}

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {

        int N;
        cin >> N;
        int arr[N];
         for (int i = 0; i > N; i++)
        {
            cin>>arr[i];
        }
        int count_max = 0;
        int speed_prev_Car = arr[0];
        for (int i = 0; i < N; i++)
        {
            if (speed_prev_Car >= arr[i])
            {
                count_max++;
                speed_prev_Car = arr[i];
            }
            else{
            }
        }
        cout << count_max << endl;
    }

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    for(int tc ; tc < t ; tc++){
        int n;
        string origin;
        int laddos = 0;
        cin>>n>>origin;

        for (int i = 0; i < n; i++)
        {
            string S;
            cin>>S;
            if (S == "CONTEST_WON")
            {
                int rank;
                cin>>rank;
                if (rank<=20)
                {
                    laddos += 300 + (20 - rank);
                }
                else{
                    laddos += 300;
                }

            }
            else if (S == "TOP_CONTRIBUTOR")
            {
                laddos += 300;
            }
            else if (S == "BUG_FOUND")
            {
                int severity;
                cin>>severity;
                if (severity >= 50)
                {
                    laddos += severity;
                }
            }
            else if (S == "CONTEST_HOSTED")
            {
                laddos += 50;
            }
            else{assert(false);}
        }
        int months=0;
        if (origin == "INDIAN")
        {
            months = laddos/200;
        }
        else
        {
            months = laddos/400;
        }
        cout<<months<<endl;
    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main(){
    int a[1000];
    for (int i = 0; i < 10000; i++)
    {
        cin>>a[i];
        if (a[i] == 42)
        {
            break;
        }
        cout<<a[i]<<endl;
    }
    return 0;
}

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll k, d0, d1;
        cin >> k >> d0 >> d1;

        ll lastDigit = (d0 + d1) % 10;
        ll sum = d0 + d1 + lastDigit;
        if (k==2)
        {
            if ((d0*10 + d1)%3 == 0)
            {
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
            continue;
        }


        ll remDigits = k - 3;
        while (remDigits > 0)
        {
            if (lastDigit == 6)
            {
                ll sets = remDigits/4;
                sum+=20*(sets);
                remDigits -= sets*4;
                if (remDigits == 0)
                {

                }else if (remDigits == 1)
                {
                    sum+=2;
                }else if (remDigits == 2)
                {
                    sum += 6;
                }else if (remDigits == 3)
                {
                    sum+=14;
                }
                break;
            }
            else if (lastDigit==0)
            {
                break;
            }
            else
            {
                lastDigit = (lastDigit*2) % 10;
                sum += lastDigit;
                remDigits--;
            }
        }
        if (sum % 3 == 0)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(false);
    cin.tie();
    int t;
    cin>>t;
    while (t--)
    {
        int g;
        cin>>g;
        for (int gt = 0; gt < g; gt++)
        {
            int i,n,q;
            cin>>i>>n>>q;

            int ans = n/2;

            if (i == 1 && q ==1 )
            {
                ans=ans;
            }
            else if (i == 1 && q == 2)
            {
                ans = n - ans;
            }
            else if (i == 2 && q == 1)
            {
                ans = n - ans;
            }
            else if (i == 2 && q == 2)
            {
                ans = ans;
            }
            else{
                assert(false);
            }
            cout<<ans<<endl;
        }

    }

    return 0;
}


#include <bits/stdc++.h>

using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, Si[10000], Pi[10000], Vi[10000], int max_profit = 0;
        ;
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            cin >> Si[i] >> Pi[i] >> Vi[i];
        }
        int profit;
        for (int i = 0; i < n; i++)
        {
            profit = Vi[i] * Pi[i] / (Si[i] + 1);
            max_profit = max(max_profit, profit);
        }

        cout << max_profit << endl;
    }

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    for (int tc = 0; tc < t; tc++)
    {
        int n;
        cin>>n;
        string ts;
        cin>>ts;
        int curr_score[] = {0 , 0};
        int rem[] = {n , n};
        int shots = 2+n;
        for (int i = 0; i < ts.length(); i++)
        {
            int curr_team= i%2;
            if (ts[i] == '0')
            {
                curr_score[curr_team++];
                int diff = curr_score[curr_team] - curr_score[curr_team^1];
                int remaining_shots = rem[curr_team^1];
                if (diff > remaining_shots  )
                {
                    shots = min(shots,i+1);
                    break;
                }
                rem[curr_team]--;
            }
            cout<<shots<<endl;
        }
    }

    return 0;
}
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll s[n];
        for (ll i = 0; i < n; i++)
        {
            cin >> s[i];
        }
        int max_tokens = 0,min = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (s[i] < min) min = s[i];
            max_tokens = max_tokens + min;
        }
        cout<<max_tokens<<endl;
    }
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main(){
    int t , v , max;
    cin>>t;
    for (int tc = 0; tc < t; tc++)
    {
        string s;
        cin>>s;
        int len = s.length();
        v = 0;max = 0;
        for (int i = 0; i < len; i++)
        {
            if (s[i] == '<')
            {
                v++;
            }
            else if (s[i] == '>')
            {
                if (v == 1)
                {
                    max = i + 1;
                    v--;
                }
                else if(v == 0){
                    break;
                }
                else{
                    v--;
                }
            }
        }
        cout<<max<<endl;

    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int tc = 0; tc < t; tc++)
    {
        int n, k=0;
        cin >> n >> k;
        vector<int> s(n);
        for (int i = 0; i < n; i++)
        {
            cin >> s[i];
        }
        vector<int>count(k+1);
        int u = 1;
        int l = 0 , r = 0;
        int Rmax = 1;
        count[s[0]]++;
        while (true)
        {
            while (r<n-1 && u < k)
            {
                r++;
                if(count[s[r]] == 0) u++;
                count[s[r]]++;
                if(u<k) Rmax = max(Rmax , r-l+1);
            }
            if(r == n-l) break;

            while (l<=r && u==k)
            {
                if(count[s[l]] == 1 ) u--;
                count[s[l]]--;
                l++;
            }
        }
        cout<<Rmax<<endl;
    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n, z,power,count;
        cin>>n>>z;
        vector<int>a(n);
        for (int i = 0; i < n; i++)
        {
            cin>>i;
            a.push_back(i);
        }
        power = a[0]/2;
        count = 0;
        for (int i = 0; i < n; i++)
        {
            if (power != 0)
            {
                power += a[i]/2;
                count++;
            }
        }
        if (power == z)
        {
            cout<<count<<endl;
        }
        else{
            cout<<"Evacuate"<<endl;
        }

    }


    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int m,x,d;
        cin>>x>>m>>d;
        cout<<min(m*x , x+d);
    }

    return 0;
}
#include <bits/stdc++.h>

using namespace std;
void solve(){
    int k;
    cin>>k;
    string s;
    bool ans=1;
    for (int i = 0; i < k; i++)
    {
        cin>>s;
        if(islower(s[0])){
            for (int j = 0; j < s.size(); j++)
            {
                if (s[j]>='a' && s[j] <= 'm'){}
                else{ans=0;break;}
            }

        }
        else{
            for (int j = 0; j < s.size(); j++)
            {
                if (s[j]>='N' && s[j] <= 'Z'){}
                else{ans=0;break;}
            }
        }
    }
    if (ans)cout<<"YES";
    else cout<<"NO";
    cout<<endl;
};
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        solve();
    }

    return 0;
}

#include <bits/stdc++.h>

using namespace std;
void Csum(vector<int> s)
{
    int add = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] = s[i + 1])
        {
            add = add + 2;
        }
        else
        {
            add = add + 1;
        }
    }
    cout<<add<<endl;
}
void solve()
{
    int n, k, q;
    vector<int> S(n);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> i;
        S.push_back(i);
    }

    while (k--)
    {
        cin >> q;
        for (int i = 0; i < n; i++)
        {
            if (S[i] = 1)
            {
                S[i] = 0;
            }
            else
            {
                S[i] = 1;
            }
        }
        for (int i = 0; i < n; i++)
        {
            cout << S[i];
        }
        Csum(S);
    }
};
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
#include <bits/stdc++.h>

using namespace std;
void solve(){

};
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c, d, k;
        cin >> a >> b >> c >> d >> k;
        int dist = abs(a - c) + abs(b - d);
        if (k >= dist && k % 2 == d % 2)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;
void solve(){
    int D,d,P,Q,money;
    cin>>D>>d>>P>>Q;
    int n = P;
    int arr[1000];
    for (int i = 0; i < D; i++)
    {
        arr[i] = P;
    }
    if (d > 1)
    {
        for (int x = d; x < D; d*x++)
        {
            for (int j = 1; j < D; j++)
            {
                arr[x] = P + (Q*j);
            }
        }
    }
    else{
        exit(0);
    }

    for (int i = 0; i < D; i++)
    {
        cout<<arr[i]<<" ";
    }
};
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
*/

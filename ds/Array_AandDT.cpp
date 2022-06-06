/*
#include <bits/stdc++.h>

using namespace std;
class myArray
{
protected:
    int total_size;
    int used_size;
    int *ptr;

public:
    void create_Arr(myArray *a, int tsize, int usize)
    {
        a->total_size = tsize;
        a->used_size = usize;
        (*a).ptr = (int *)malloc(tsize * sizeof(int));
    }
    void setarr(myArray *a)
    {
        int n;
        for (int i = 0; i < a->used_size; i++)
        {
            cout << "enter element" << i << " : ";
            cin >> n;
            (a->ptr)[i] = n;
            cout << endl;
        }
    }
    void showarr(myArray *a)
    {
        for (int i = 0; i < a->used_size; i++)
        {
            cout << (a->ptr)[i] << endl;
        }
    };
    int main()
    {
        myArray marks;
        myArray *marks_Ptr = new myArray(marks); 
        marks.create_Arr(marks_Ptr, 10, 2);
        marks.setarr(marks_Ptr);
        marks.showarr(marks_Ptr);
        return 0;
    }
   //insertion
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
       size += 1;
       display(arr , size);
       return 0;
   }

//deletion :
#include <bits/stdc++.h>
   
   using namespace std;
   void display(int arr[] , int n){
       for (int i = 0; i < n; i++)
       {
           cout<<arr[i]<<" ";
       }
       cout<<endl;
   }
   void index_deletion(int arr[] , int size, int index){
       for (int i = index; i < size - 1; i++)
       {
           arr[i] = arr[i+1];
       }   
    };
   int main(){
       int arr[100] = {7 , 8 , 12 , 27 , 88};
       int size = 5 , index = 1;
       display(arr , size);
       index_deletion(arr , size , index);
       size -= 1;
       display(arr , size);
       return 0;
   }

//linear and binary search
#include <bits/stdc++.h>

using namespace std;
void display(int arr[] , int n){
       for (int i = 0; i < n; i++)
       {
           cout<<arr[i]<<" ";
       }
       cout<<endl;
   }
int linear_Search(int arr[], int size, int ele)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == ele)
        {
            return 1;
        }
    }
    return -1;
};
int binary_Search(int arr[], int size, int ele)
{
    int low, mid, high;
    low = 0;
    high = size-1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == ele)
        {
            return mid;
        }
        if (arr[mid] < ele)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
};
int main()
{
    int arr[] = {1, 3, 4, 45, 54, 76, 23, 453, 231, 234, 2, 34, 43};
    int size = sizeof(arr) / sizeof(int);
    sort(arr , arr + size);
    display(arr , size);
    int ele = 54;
    cout << "the element is found ar index : " << binary_Search(arr, size, ele);
    return 0;
}


//questions:
#include <bits/stdc++.h>

using namespace std;
void solve()
{
    int n;
    cin >> n;
    int a[100], b[100], player[100];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    for (int i = 0; i < n; i++)
    {
        player[i] = a[i] * 20 - b[i] * 10;
        if (player[i] < 0)
            player[i] = 0;
    }
    cout << *max_element(player, player + n) << endl;
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
    int n;
    cin>>n;
    int s[100],p[100];
    int a[9] = {};
    for (int i = 0; i < n; i++)
    {
        cin>>p[i]>>s[i];
        if (p[i]<9 && a[p] < s)
        {
            a[p] = s;
        }
    }
    int max_score = 0;
    for (int i = 0; i < 9; i++)
    {
        max_score = max_score + a[i];1
    }
    cout<<max_score<<endl;
    
    
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
void solve(){
    int n;
    cin>>n;
    int a[n],minval= INT_MAX ;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    for (int i = 0; i < n; i++)
    {
        minval = min(minval , a[i] ^ a[i+1]);
    }
    cout<<minval<<endl;
    
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
*/

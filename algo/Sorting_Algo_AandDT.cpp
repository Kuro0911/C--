/*
//bubble sort = CHECK 2 ALTERNATIVE ELE AND SWAPS THE BIGGER TO THE RIGHT SIDE ;
#include <bits/stdc++.h>

using namespace std;
void printarr(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
};
void bubble_Sort(int *a, int n)
{
    int temp;
    int isSorted = 0;
    for (int i = 0; i < n - 1; i++)
    {
        isSorted=1;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1]){
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                isSorted = 0;
            }
        }
    }
    if (isSorted)
        return;
};
int main()
{
    int a[] = {10, 45, 21, 8, 50,78};
    int n = 6;
    printarr(a, n);
    bubble_Sort(a, n);
    printarr(a, n);
    return 0;
}

//insersion sort = INSERTS NEXT ELE TO A ALREDY SORTED ARR ;
#include <bits/stdc++.h>

using namespace std;
void printarr(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
};
void insersion_sort(int * a , int n){
        int key , j;
    for (int i = 1; i <= n-1; i++)
    {
        //loop for each pass;
        key = a[i];
        j = i -1;
        while (j>=0 && a[j] > key)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
};
int main(){
    int a[] = {10, 45, 21, 8, 50,78};
    int n = 6;
    printarr(a , n);
    insersion_sort(a , n);
    printarr(a , n);
    return 0;
}


//selection sort : CHECKS ALL THE VALUES FOR THE MINIMUM ONE AND INSERT SIT IT IN LEFTMOST SIDE;
#include <bits/stdc++.h>

using namespace std;
void printarr(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
};
void selection_sort(int * a , int n){
    cout<<"running select sort...."<<endl;
    int index_of_min,temp;
    for (int i = 0; i < n-1; i++)
    {
        index_of_min = i;
        for (int j = i+1; j < n; j++)
        {
            if(a[j] < a[index_of_min] )
                index_of_min = j;
        }
        temp = a[i];
        a[i] = a[index_of_min];
        a[index_of_min] = temp;
    }

};
int main(){
    int a[] = {10, 45, 21, 8, 50,78};
    int n = 6;
    printarr(a , n);
    selection_sort(a , n);
    printarr(a , n);
    return 0;
}



//  quick sort  : SELECTS A SINGLE ELE CALLED PIVIOT AND PUTS IT IN A POS
//WHERE ALL THE ELE LESS THAN IT ARE TO ITS LEFT AND BIGGER
// TO THE RIGHT;

#include <bits/stdc++.h>

using namespace std;
void printarr(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
};
int partition(int *a, int low, int high)
{
    int pivot = a[low];
    int i = low + 1;
    int j = high;
    int temp;
    do
    {
        while (a[i] <= pivot)
        {
            i++;
        }
        while (a[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            temp = a[i];
            a[i] = a[j];
            temp = a[i];
        }
    } while (i < j);
    temp = a[low];
    a[low] = a[j];
    temp = a[i];
    return j;
}
void Quick_sort(int *a, int low, int high)
{
    cout << "running quick sort...." << endl;
    int partionIndex;
    if (low < high)
    {
        partionIndex = partition(a, low, high);
        Quick_sort(a, low, partionIndex - 1);
        Quick_sort(a, partionIndex - 1, high);
    }
};
int main()
{
    int a[] = {10, 45, 21, 8, 50, 78};
    int n = 6;
    printarr(a, n);
    Quick_sort(a , 0 , n-1);
    printarr(a, n);
    return 0;
}


//Merge sort 2 sorted arrays are made into one ;
#include <bits/stdc++.h>

using namespace std;
void printarr(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
};
void merge_Sort_part1(int *a, int low, int mid, int high)
{
    int i, j, k, b[100];
    j = mid + 1;
    i = k = low;
    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            b[k] = a[i];
            i++;k++;
        }
        else
        {
            b[k] = a[j];
            j++;k++;
        }
    }
    while (i <= mid)
    {
        b[k] = a[i];
        i++;k++;
    }
    while (j <= high)
    {
        b[k] = a[j];
        j++;k++;
    }
    for (int i = low; i <= high; i++)
    {
        a[i] = b[i];
    }

};
void merge_Sort_part2( int * a , int low , int high ){
    int mid;
    if (low < high)
    {
        mid = (low + high)/2;
        merge_Sort_part2(a , low , mid);
        merge_Sort_part2(a , mid+1 , high);
        merge_Sort_part1(a , low ,mid , high);
    }

};
int main()
{
    int a[] = {54, 87, 10, 84, 32, 69};
    int n = 6;
    printarr(a, n);
    merge_Sort_part2(a , 0 ,5);
    printarr(a, n);
    return 0;
}

//count arr : it incerments the value form zero to ++ on the
//value of the element fg : if num is i a[i] = 0+1;
#include <bits/stdc++.h>

using namespace std;
void printarr(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
};
int max_ele(int *a, int n)
{
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (max <= a[i])
            max = a[i];
    }
    return max;
}
void count_Sort(int *a, int n)
{
    int i, j;
    int max = max_ele(a, n);
    int *count = (int *)malloc((max + 1) * sizeof(int));
    for (i = 0; i < max+1; i++)
    {
        count[i] = 0;
    }
    //increment a new index in count arr;
    for (i = 0; i < n; i++)
    {
        count[a[i]] = count[a[i]] + 1;
    }
    i = 0;
    j = 0;
    while (i <= max)
    {
        if (count[i] > 0)
        {
            a[j] = i;
            count[i] = count[i] - 1;
            j++;
        }
        else
        {
            i++;
        }
    }
};
int main()
{
    int a[] = {54, 87, 10, 84, 32, 69};
    int n = 6;
    printarr(a, n);
    count_Sort(a, n);
    printarr(a, n);
    return 0;
}
*/
// All Sorting algo
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define tb ' '
#define all(a) (a).begin(), (a).end()
#define sz(x) ((int)x.size())
#define MOD (int)(1e9 + 7)
typedef pair<int, int> pii;
typedef pair<pii, int> ppi;
typedef pair<int, pii> pip;
typedef pair<pii, pii> ppp;
void print(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
// SelectSort
void SelectSort(int a[], int n)
{
    for (int i = 0; i < n - 2; i++)
    {
        int Imin = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[Imin] > a[j])
            {
                Imin = j;
            }
        }
        int temp = a[i];
        a[i] = a[Imin];
        a[Imin] = temp;
    }
    print(a, n);
}
// BubbleSort
void BubbleSort(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        bool flag = false;
        for (int j = 0; j < n - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                flag = true;
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
        if (!flag)
            break;
    }
    print(a, n);
}
// InsertSort
void insertSort(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int hole = i;
        int val = a[i];
        while (hole > 0 && a[hole - 1] > val)
        {
            a[hole] = a[hole - 1];
            hole = hole - 1;
        }
        a[hole] = val;
    }
    print(a, n);
}
// MergeSort
void merge(int *a, int low, int mid, int high)
{
    int temp[101];
    int i, k, j;
    i = k = low;
    j = mid + 1;
    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            temp[k] = a[i];
            k++;
            i++;
        }
        else
        {
            temp[k] = a[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        temp[k] = a[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        temp[k] = a[j];
        j++;
        k++;
    }
    for (int x = low; x <= high; x++)
    {
        a[x] = temp[x];
    }
}
void mergeSort(int *a, int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}
// QuickSort
int partition(int *a, int st, int ed)
{
    int pivot = a[ed];
    int pIndex = st;
    for (int i = st; i < ed; i++)
    {
        if (a[i] <= pivot)
        {
            int temp = a[i];
            a[i] = a[pIndex];
            a[pIndex] = temp;
            pIndex++;
        }
    }
    int temp = a[pIndex];
    a[pIndex] = a[ed];
    a[ed] = temp;
    return pIndex;
}
void QuickSort(int *a, int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int index = partition(a, start, end);
    QuickSort(a, start, index - 1);
    QuickSort(a, index + 1, end);
}
// HeapSort
void heapify(int a[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && a[l] > a[largest])
    {
        largest = l;
    }
    if (r < n && a[r] > a[largest])
    {
        largest = r;
    }
    if (largest != i)
    {
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}
void HeapSort(int a[], int n)
{
    for (int i = n - 1 / 2; i >= 0; i--)
    {
        heapify(a, n, i);
    }
    for (int i = n - 1; i > 0; i--)
    {
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}
int partitionR(int arr[], int low, int hi)
{
    int pvt = arr[hi];
    int i = low - 1;
    for (int j = low; j < hi; j++)
    {
        if (arr[j] <= pvt)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[hi], arr[i + 1]);
    return (i + 1);
};
int r_partition(int arr[], int low, int hi)
{
    srand(time(NULL));
    int r = low + rand() % (hi - low);
    swap(arr[r], arr[hi]);
    return partitionR(arr, low, hi);
};
void randomQuick(int arr[], int low, int hi)
{
    if (low < hi)
    {
        int p = r_partition(arr, low, hi);
        randomQuick(arr, low, p - 1);
        randomQuick(arr, p + 1, hi);
    }
}
void solve()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    // SelectSort(a, n);
    // BubbleSort(a, n);
    // insertSort(a, n)z`;
    // mergeSort(a, 0, n - 1);
    // QuickSort(a, 0, n - 1);
    // HeapSort(a, n);
    randomQuick(a, 0, n - 1);
    print(a, n);
}

signed main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    // cin>>t;
    while (t--)
    {
        solve();
    }
#ifndef ONLINE_JUDGE
    cerr << "Time :" << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms";
#endif
    return 0;
}
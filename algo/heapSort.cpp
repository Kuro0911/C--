/*
// Array representaion of BT
=> if a node is at index = i
    its left child is at = 2 * i
    its right child is at = 2 * i + 1
    parent is at = i / 2

//Full Binary Tree : the tree which has maximum number of nodes ie 2^h+1 - 1
    al full BT is a complete BT

//Complete Binary Tree : when we do a array representation of the tree no blank spaces are left
    it is a full BT upto height h - 1 and at the last lvl elements are filled from left to right
    height = log n

//Heap :
1) Max Heap : a complete Binary tree where all nodes have the value more than its decendents
Insert:
    an element is inserted where there is the first place empty in the array representaion of the heap
    then we compare it with its parents and put it to its position
    time : best = O(1) , worst = O(log n)
2) Min Heap : a complete Binary tree where all nodes have the value less than its decendents


*/

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
void heapSort(int a[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(a, n, i);
    }
    for (int i = n - 1; i > 0; i--)
    {
        swap(a[0], a[i]);
        heapify(a, i, 0);
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
    heapSort(a, n);
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
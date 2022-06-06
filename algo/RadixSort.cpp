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
void print(vector<int> &arr)
{
    for (auto &x : arr)
    {
        cout << x << " ";
    }
}
struct node
{
    int data;
    node *next;
};
node *create(int x)
{
    node *temp = new node();
    temp->data = x;
    temp->next = NULL;
    return temp;
}
void insert(node *&head, int data)
{
    if (head == NULL)
    {
        head = create(data);
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = create(data);
}
int del(node *&head)
{
    if (head == NULL)
    {
        return 0;
    }
    node *temp = head;
    int val = head->data;
    head = head->next;
    delete temp;
    return val;
}
int digits(int n)
{
    int i = 1;
    if (n < 10)
    {
        return 1;
    }
    while (n > (int)pow(10, i))
    {
        i++;
    }
    return i;
}
void RadixSort(vector<int> &arr)
{
    int sz = arr.size();
    int max = *max_element(all(arr));
    int d = digits(max);
    node **bins;
    bins = new node *[10];
    for (int i = 0; i < 10; i++)
    {
        bins[i] = NULL;
    }
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < sz; j++)
        {
            insert(bins[(arr[j] / (int)pow(10, i)) % 10], arr[j]);
        }
        int x = 0, y = 0;
        while (x < 10)
        {
            while (bins[x] != NULL)
            {
                arr[y++] = del(bins[x]);
            }
            x++;
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &x : arr)
    {
        cin >> x;
    }
    RadixSort(arr);
    print(arr);
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
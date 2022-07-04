// insert sort
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

void print(int n, vector<int> &vec)
{
    for (int i = 0; i < n; i++)
    {
        cout << vec[i] << " ";
    }
}
void insertSort(int n, vector<int> &vec)
{
    for (int i = 0; i < n; i++)
    {
        int hole = i;
        int val = vec[hole];
        while (hole > 0 && vec[hole - 1] > val)
        {
            vec[hole] = vec[hole - 1];
            hole--;
        }
        vec[hole] = val;
    }
}
void BubbleSort(int n, vector<int> &vec)
{
    for (int i = 0; i < n; i++)
    {
        int j = i + 1;
        while (vec[i] > vec[j] && j != n)
        {
            swap(vec[i], vec[j]);
            j++;
        }
    }
}
void merge(int low, int hi, int mid, vector<int> &vec)
{
    int i = low, k = low, j = mid + 1;
    int temp[101];
    while (i <= mid && j <= hi)
    {
        if (vec[i] < vec[j])
        {
            temp[k] = vec[i];
            k++;
            i++;
        }
        else
        {
            temp[k] = vec[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        temp[k] = vec[i];
        k++;
        i++;
    }
    while (j <= hi)
    {
        temp[k] = vec[j];
        k++;
        j++;
    }
    for (int x = low; x <= hi; x++)
    {
        vec[x] = temp[x];
    }
}
void mergeSort(int low, int hi, vector<int> &vec)
{
    if (low < hi)
    {
        int mid = (low + hi) / 2;
        mergeSort(low, mid, vec);
        mergeSort(mid + 1, hi, vec);
        merge(low, hi, mid, vec);
    }
}
int partition(int low, int hi, vector<int> &vec)
{
    int pvt = vec[hi];
    int Pindex = low;
    for (int i = low; i < hi; i++)
    {
        if (vec[i] <= pvt)
        {
            swap(vec[i], vec[Pindex]);
            Pindex++;
        }
    }
    swap(vec[Pindex], vec[hi]);
    return Pindex;
}
void QuickSort(int low, int hi, vector<int> &vec)
{
    if (low >= hi)
    {
        return;
    }
    int p = partition(low, hi, vec);
    QuickSort(low, p - 1, vec);
    QuickSort(p, hi, vec);
}
void binSearch(int low, int hi, int tar, vector<int> &vec)
{
    int md = (low + hi) / 2;
    if (md == 0 && vec[md] != tar || md == hi && vec[md] != tar)
    {
        cout << "NF";
        return;
    }
    if (tar < vec[md])
    {
        binSearch(low, md, tar, vec);
    }
    else if (tar > vec[md])
    {
        binSearch(md + 1, hi, tar, vec);
    }
    else
    {
        cout << "found on " << md + 1 << endl;
    }
}
pair<int, int> MaxMin(int low, int hi, vector<int> &vec, pair<int, int> CurrMaxMin)
{
    if (low == hi)
    {
        CurrMaxMin = {vec[low],
                      vec[low]};
        return CurrMaxMin;
    }
    if (low == hi - 1)
    {
        CurrMaxMin = {max(vec[low], vec[hi]),
                      min(vec[low], vec[hi])};
        return CurrMaxMin;
    }
    int mid = (low + hi) / 2;
    pair<int, int> temp1, temp2;
    temp1 = MaxMin(low, mid - 1, vec, CurrMaxMin);
    temp2 = MaxMin(mid, hi, vec, CurrMaxMin);
    CurrMaxMin.first = max(temp1.first, temp2.first);
    CurrMaxMin.second = min(temp1.second, temp2.second);
    return CurrMaxMin;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> vec(n);
    for (auto &x : vec)
    {
        cin >> x;
    }
    pair<int, int> temp = {INT_MIN, INT_MAX};
    pair<int, int> ans = MaxMin(0, n - 1, vec, temp);
    cout << "max : " << ans.first << "\nmin : " << ans.second;
    // QuickSort(0, n - 1, vec);
    // print(n, vec);
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
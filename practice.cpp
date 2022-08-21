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

//#####################################################

template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v)
{
    for (auto &x : v)
        os << x << " ";
    os << endl;
    return os;
}
template <typename T>
ostream &operator<<(ostream &os, const set<T> &v)
{
    for (auto it : v)
        os << it << " ";
    return os;
}
template <typename T, typename S>
ostream &operator<<(ostream &os, const map<T, S> &v)
{
    for (auto it : v)
        os << it.first << " : " << it.second << endl;
    return os;
}
template <typename T, typename S>
ostream &operator<<(ostream &os, const pair<T, S> &v)
{
    os << v.first << " : " << v.second << endl;
    return os;
}

//#####################################################

int partition(int lw, int hi, vector<int> &vec)
{
    int pvt = vec[hi];
    int pInd = lw;
    for (int i = lw; i < hi; i++)
    {
        if (vec[i] <= pvt)
        {
            swap(vec[i], vec[pInd]);
            pInd++;
        }
    }
    swap(vec[hi], vec[pInd]);
    return pInd;
}
void quickSort(int lw, int hi, vector<int> &vec, int k)
{
    if (lw >= hi)
    {
        return;
    }
    int pInd = partition(lw, hi, vec);
    if (pInd == k)
    {
        cout << vec[k] << endl;
    }
    if (pInd < k)
    {
        quickSort(lw, pInd - 1, vec, k);
    }
    else
    {
        quickSort(pInd + 1, hi, vec, k);
    }
};
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> vec(n);
    for (auto &x : vec)
    {
        cin >> x;
    }
    quickSort(0, vec.size() - 1, vec, k);
    cout << vec;
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
// for (int i = 1; i <= t; i++)
//{
// cout << "Case #" << i << ": " ;
// solve();
//}
#ifndef ONLINE_JUDGE
    cerr << "Time :" << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms";
#endif
    return 0;
}
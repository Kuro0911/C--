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

// #####################################################

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

// #####################################################

class fenwickTree
{
    vector<int> tree;
    int n;

public:
    fenwickTree(int n)
    {
        this->n = n;
        tree.assign(n, 0);
    }
    fenwickTree(vector<int> a) : fenwickTree(a.size())
    {
        for (int i = 0; i < a.size(); i++)
        {
            add(i, a[i]);
        }
    }
    void add(int idx, int delta)
    {
        for (; idx < n; idx = idx | (idx + 1))
        {
            tree[idx] += delta;
        }
    }
    int prefixSum(int i)
    {
        int sum = 0;
        for (; i >= 0; i = (i & (i + 1)) - 1)
        {
            sum += tree[i];
        }
        return sum;
    }
    int rangeQuery(int st, int ed)
    {
        return prefixSum(ed) - prefixSum(st - 1);
    }
};
void solve()
{
    int n;
    cin >> n;
    vector<int> temp(n);
    for (auto &x : temp)
    {
        cin >> x;
    }
    fenwickTree t(temp);
    cout << t.rangeQuery(1, 3);
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
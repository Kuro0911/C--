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

map<pair<int, int>, int> tree;
void build(int start, int end, int idx, int val)
{
    if (start > end or start == end and start != idx)
    {
        return;
    }
    if (start == end and start == idx)
    {
        cout << "yes\n";
        tree[{idx, idx}] = val;
    }
    else
    {
        int md = (start + end) / 2;
        pii l = {start, md}, r = {md + 1, end};
        build(start, md, idx, val);
        build(md + 1, end, idx, val);
        if (tree.find(l) != tree.end() and tree.find(r) != tree.end())
        {
            tree[{start, end}] = tree[l] + tree[r];
        }
    }
    return;
}
// void update(int i) {}
void query(int l, int r) {}

void solve()
{
    vector<int> vec{1, 2, 3, 4, 5};
    for (int i = 1; i <= vec.size(); i++)
    {
        build(1, 5, i, vec[i - 1]);
    }
    for (auto x : tree)
    {
        cout << x.first.first << " : " << x.first.second << " == " << x.second << endl;
    }
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
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
struct node
{
    int data;
    pair<int, int> range;
    node *left;
    node *right;
    node(int val, int l, int r)
    {
        data = val;
        range = {l, r};
        node *left = NULL;
        node *right = NULL;
    }
};
int merge(int x, int y)
{
    return x + y;
}
void build(int i, int l, int r, vector<int> vec, vector<int> &t)
{
    if (l == r)
    {
        t[i] = vec[i - 1];
        return;
    }
    int mid = (l + r) / 2;
    build(2 * i, l, mid, vec, t);
    build((2 * i) + 1, mid + 1, r, vec, t);
    t[i] = merge(t[2 * i], t[(2 * i) + 1]);
}
int lc(int i)
{
    return 2 * i;
}
int rc(int i)
{
    return (2 * i) + 1;
}
void update(int i, int l, int r, int pos, int val, vector<int> &t)
{
    if (l == r)
    {
        t[i] = val;
        return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid)
    {
        update(lc(i), l, mid, pos, val, t);
    }
    else
    {
        update(rc(i), mid + 1, r, pos, val, t);
    }
    t[i] = merge(t[2 * i], t[(2 * i) + 1]);
}
int query(int i, int l, int r, int ql, int qr, vector<int> &t)
{
    if (l > qr || r < ql)
    {
        return 0;
    }
    if (l >= ql && r <= qr)
    {
        return t[i];
    }
    int md = (l + r) / 2;
    int restl = query(lc(i), l, md, ql, qr, t);
    int restr = query(rc(i), md + 1, r, ql, qr, t);
    return merge(restl, restr);
}
void solve()
{
    int n;
    cin >> n;
    vector<int> vec(n);
    vector<int> t(n);
    for (auto &x : vec)
    {
        cin >> x;
    }
    build(1, 1, vec.size(), vec, t);
    cout << query(1, 1, vec.size(), 1, 3, t);
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
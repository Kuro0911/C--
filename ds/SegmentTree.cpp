// q1
// segment tree for minimum values in a range
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, int> ppi;
typedef pair<int, pii> pip;
typedef pair<pii, pii> ppp;
typedef pair<ll, ll> pll;

int n, m;
const int maxN = 2e5 + 5;
int tree[4 * maxN], arr[maxN];

void build(int v = 1, int tl = 0, int tr = n - 1)
{
    if (tl == tr)
    {
        tree[v] = arr[tl];
    }
    else
    {
        int tm = (tl + tr) / 2;
        build(v * 2, tl, tm);
        build(v * 2 + 1, tm + 1, tr);
        tree[v] = min(tree[v * 2], tree[v * 2 + 1]);
        // for addition
        // tree[v] = tree[v * 2] + tree[v * 2 + 1];
    }
}
int minQuery(int l, int r, int v = 1, int tl = 0, int tr = n - 1)
{
    if (l > r)
        return INT_MAX;
    if (l == tl and r == tr)
    {
        return tree[v];
    }
    int tm = (tl + tr) / 2;
    return min(minQuery(l, min(r, tm), v * 2, tl, tm), minQuery(max(l, tm + 1), r, v * 2 + 1, tm + 1, tr));
}
int sum(int l, int r, int v = 1, int tl = 0, int tr = n - 1)
{
    if (l > r)
        return 0;
    if (l == tl and r == tr)
    {
        return tree[v];
    }
    int tm = (tl + tr) / 2;
    return sum(l, min(r, tm), v * 2, tl, tm) + sum(max(l, tm + 1), r, v * 2 + 1, tm + 1, tr);
}
void update(int pos, int new_val, int v = 1, int tl = 0, int tr = n - 1)
{
    if (tl == tr)
    {
        tree[v] = new_val;
    }
    else
    {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
        {
            update(pos, new_val, v * 2, tl, tm);
        }
        else
        {
            update(pos, new_val, v * 2 + 1, tm + 1, tr);
        }
        tree[v] = min(tree[v * 2], tree[v * 2 + 1]);
    }
}
void solve()
{
    // write code
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
#ifndef ONLINE_JUDGE
    cerr << "Time :" << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms";
#endif
    return 0;
}
// if we want to add a lazy node to update values use this
/*
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, int> ppi;
typedef pair<int, pii> pip;
typedef pair<pii, pii> ppp;
typedef pair<ll, ll> pll;

int n, m;
const int maxN = 2e5 + 5;
int tree[4 * maxN], arr[maxN], lazy[4 * maxN];

void build(int v = 1, int tl = 0, int tr = n - 1)
{
    if (tl == tr)
    {
        tree[v] = arr[tl];
    }
    else
    {
        int tm = (tl + tr) / 2;
        build(v * 2, tl, tm);
        build(v * 2 + 1, tm + 1, tr);
        tree[v] = tree[v * 2] + tree[v * 2 + 1];
    }
}
void push(int v)
{
    tree[v * 2] += lazy[v];
    lazy[v * 2] += lazy[v];
    tree[v * 2 + 1] += lazy[v];
    lazy[v * 2 + 1] += lazy[v];
    lazy[v] = 0;
}
int sum(int l, int r, int v = 1, int tl = 0, int tr = n - 1)
{
    if (l > r)
        return 0;
    if (l == tl and r == tr)
    {
        return tree[v];
    }
    push(v);
    int tm = (tl + tr) / 2;
    return sum(l, min(r, tm), v * 2, tl, tm) + sum(max(l, tm + 1), r, v * 2 + 1, tm + 1, tr);
}
void updateRange(int l, int r, int addend, int v = 1, int tl = 0, int tr = n - 1)
{
    if (l > r)
        return;
    if (l == tl && tr == r)
    {
        tree[v] += addend;
        lazy[v] += addend;
    }
    else
    {
        push(v);
        int tm = (tl + tr) / 2;
        updateRange(l, min(r, tm), addend, v * 2, tl, tm);
        updateRange(max(l, tm + 1), r, addend, v * 2 + 1, tm + 1, tr);
        tree[v] = tree[v * 2] + tree[v * 2 + 1];
    }
}
void solve()
{
    // write code
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
#ifndef ONLINE_JUDGE
    cerr << "Time :" << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms";
#endif
    return 0;
}

//for suffix and prefix problem
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, int> ppi;
typedef pair<int, pii> pip;
typedef pair<pii, pii> ppp;
typedef pair<ll, ll> pll;
#define int long long

struct node
{
    int sum, pref, suff, ans;
};
node combine(node l, node r)
{
    node res;
    res.sum = l.sum + r.sum;
    res.pref = max(l.pref, l.sum + r.pref);
    res.suff = max(l.suff, l.sum + r.suff);
    res.ans = max(max(l.ans, r.ans), l.suff + r.pref);
    return res;
}
node make_node(int val)
{
    node res;
    res.sum = val;
    res.pref = res.suff = res.ans = max(0LL, val);
    return res;
}
int n, m;
const int maxN = 2e5 + 5;
int arr[maxN];
node tree[4 * maxN];

void build(int v = 1, int tl = 0, int tr = n - 1)
{
    if (tl == tr)
    {
        tree[v] = make_node(arr[tl]);
    }
    else
    {
        int tm = (tl + tr) / 2;
        build(v * 2, tl, tm);
        build(v * 2 + 1, tm + 1, tr);
        tree[v] = combine(tree[v * 2], tree[v * 2 + 1]);
    }
}
int sum(int l, int r, int v = 1, int tl = 0, int tr = n - 1)
{
    if (l > r)
        return 0;
    if (l == tl and r == tr)
    {
        return tree[v].ans;
    }
    int tm = (tl + tr) / 2;
    return sum(l, min(r, tm), v * 2, tl, tm) + sum(max(l, tm + 1), r, v * 2 + 1, tm + 1, tr);
}
void update(int pos, int new_val, int v = 1, int tl = 0, int tr = n - 1)
{
    if (tl == tr)
    {
        tree[v] = make_node(new_val);
    }
    else
    {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
        {
            update(pos, new_val, v * 2, tl, tm);
        }
        else
        {
            update(pos, new_val, v * 2 + 1, tm + 1, tr);
        }
        tree[v] = combine(tree[v * 2], tree[v * 2 + 1]);
    }
}
void solve()
{
    //code
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
*/
/*
#include <iostream>
#include <math.h>

using namespace std;
#define MAX 1000
bool hash[MAX + 1][2]; //or use any other key word for hash as it is reserved
bool search(int x)
{
    if (x >= 0)
    {
        if (::hash[x][0] == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        x = abs(x);
        if (::hash[x][1] == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

bool insert(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] >= 0)
        {
            ::hash[a[i]][0] = true;
        }
        else
        {
            ::hash[abs(a[i])][1] = true;
        }
    }
}
int main()
{
    int arr[] = {-1, 9, 2, -5, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    insert(arr, n);
    int find = 9;
    if (search(find))
    {
        cout << "element is present" << endl;
    }
    else
    {
        cout << "element is not present" << endl;
    }

    return 0;
}
// BINARY LIFTING ...  LONGEST COMMON ANCESTER

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

int n, q;
const int LG = 22, maxN = 2e5 + 5;
vector<int> adj[maxN];

int timer;
int tin[maxN], tout[maxN];
int up[maxN][LG + 1];
int depth[maxN];
void dfs(int v, int p, int d)
{
    tin[v] = ++timer;
    up[v][0] = p;
    depth[v] = d;

    for (int i = 1; i <= LG; i++)
    {
        up[v][i] = up[up[v][i - 1]][i - 1];
    }
    for (auto u : adj[v])
    {
        if (u != p)
        {
            dfs(u, v, d + 1);
        }
    }
    tout[v] = ++timer;
}
bool isAncestor(int u, int v)
{
    return (tin[u] <= tin[v]) and (tout[u] >= tout[v]);
}

int LCA(int a, int b)
{
    if (isAncestor(a, b))
        return a;
    if (isAncestor(b, a))
        return b;
    for (int i = LG; i >= 0; i--)
    {
        if (!isAncestor(up[a][i], b))
        {
            a = up[a][i];
        }
    }
    return up[a][0];
}
int getDist(int n1, int n2)
{
    return depth[n1] + depth[n2] - 2 * depth[LCA(n1, n2)];
}
void solve()
{
    cin >> n >> q;
    for (int i = 0; i < (n - 1); i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 1, 0);
    while (q--)
    {
        int n1, n2;
        cin >> n1 >> n2;
        cout << getDist(n1, n2) << endl;
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
#ifndef ONLINE_JUDGE
    cerr << "Time :" << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms";
#endif
    return 0;
}

#dfs oedering
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
int n, m;
const int maxN = 2e5 + 5;
vector<int> adj[maxN];
int tree[8 * maxN], values[maxN], arr[2 * maxN];

//------------------DFS ORDERING-----------------

int location;
array<int, 2> dfsM[maxN];
void dfs(int curr, int par)
{
    arr[location] = values[curr];
    dfsM[curr][0] = location++;

    for (auto x : adj[curr])
    {
        if (x != par)
        {
            dfs(x, curr);
        }
    }
    arr[location] = -values[curr];
    dfsM[curr][1] = location++;
}

//---------------------seg tree------------------
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
        tree[v] = tree[v * 2] + tree[v * 2 + 1];
    }
}
void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> values[i];
    }
    for (int i = 0; i < (n - 1); i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 1);
    n *= 2;
    build();
    while (m--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int a, b;
            cin >> a >> b;
            update(dfsM[a][0], b);
            update(dfsM[a][1], -b);
        }
        else
        {
            int node;
            cin >> node;
            cout << sum(0, dfsM[node][0]) << endl;
        }
    }
}
signed main()
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
// bin rev
int fastpow(int a, int b, int m)
{
    if (b == 0)
        return 1;
    int val = fastpow(a, b / 2, m);
    if (b & 1)
    {
        return (((a * val) % m) * val) % m;
    }
    else
    {
        return (val * val) % m;
    }
}
#define inv(a) fastpow(a, MOD - 2, MOD)

const int maxN = (int)(2e6 + 5);
int fact[maxN];

int bin(int a, int b)
{
    return (fact[a] * ((inv(fact[b]) * inv(fact[a - b])) % MOD)) % MOD;
}
// last common prefix suffix
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define en endl
#define tb ' '
typedef pair<int, int> pii;
typedef pair<pii, int> ppi;
typedef pair<int, pii> pip;
typedef pair<pii, pii> ppp;

vector<int> lps(string s)
{
    int n = s.size();
    vector<int> pi(n);

    for (int i = 1; i < n; i++)
    {
        int j = pi[i - 1];
        while (j > 0 and s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

void solve()
{
    string A;
    cin >> A;
    auto pi = lps(A);
    int n = A.size();
    int last = n - 1;
    set<int> borders;
    while (last > 0)
    {
        if (pi[last])
        {
            borders.insert(pi[last]);
            last = pi[last] - 1;
        }
        else
        {
            break;
        }
    }
    for (auto b : borders)
    {
        cout << b << tb;
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
#ifndef ONLINE_JUDGE
    cerr << "Time :" << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms";
#endif
    return 0;
*/
// matrix dp
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define en endl
#define tb ' '
#define MOD (int)(1e9 + 7)
typedef pair<int, int> pii;
typedef pair<pii, int> ppi;
typedef pair<int, pii> pip;
typedef pair<pii, pii> ppp;
#define Mat vector<vector<int>>
#define getMat(a, b) vector<vector<int>>(a, vector<int>(b))

Mat mat_mul(Mat a, Mat b)
{
    Mat res = getMat(a.size(), b[0].size());

    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < b[0].size(); j++)
        {
            for (int k = 0; k < a[0].size(); k++)
            {
                res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % MOD;
            }
        }
    }
    return res;
}

Mat mat_pow(Mat base, int pow)
{
    Mat res = base;
    pow--;
    while (pow)
    {
        if (pow & 1)
        {
            res = mat_mul(res, base);
        }
        base = mat_mul(base, base);
        pow >>= 1;
    }
    return res;
}

void solve()
{
    int n;
    cin >> n;
    if (n == 0)
    {
        cout << 0;
        return;
    }
    Mat base = {
        {1, 1},
        {1, 0}};
    base = mat_pow(base, n);

    Mat fib = {
        {1},
        {0}};
    Mat final = mat_mul(base, fib);
    cout << final[1][0];
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
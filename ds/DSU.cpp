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
// DISJOINT SET UNION

// TIME : O(alpha(n));
// alpha = inverse accerman function
// this is amoterized time complexity

class DSU
{
public:
    map<int, int> parent, size;

    void make(int v)
    {
        parent[v] = v;
        size[v] = 1;
    };

    int find(int v)
    {
        if (v == parent[v])
            return v;
        return parent[v] = find(parent[v]);
    };

    void Union(int a, int b)
    {
        a = find(a);
        b = find(b);

        if (a != b)
        {
            if (size[b] > size[a])
            {
                swap(a, b);
            }
            parent[b] = a;
            size[a] += size[b];
        }
    }
};

void solve()
{
    int n, k;
    cin >> n >> k;
    DSU node;
    for (int i = 1; i <= n; i++)
    {
        node.make(i);
    }
    for (int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        node.Union(x, y);
    }
    set<int> st;
    for (auto x : node.parent)
    {
        st.insert(x.second);
    }
    cout << st.size();
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
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

class DSU
{
public:
    map<pair<int, int>, pair<int, int>> parent;

    void make(int i, int j)
    {
        parent[{i, j}] = {i, j};
    };

    pair<int, int> find(pair<int, int> x)
    {
        if (x != parent[x])
            parent[x] = find(parent[x]);
        return parent[x];
    };

    void Union(pair<int, int> a, pair<int, int> b)
    {
        a = find(a);
        b = find(b);
        parent[a] = b;
    }
};
class Solution
{
public:
    int latestDayToCross(int row, int col, vector<vector<int>> &cells)
    {
        DSU node;
        int ans = 0;

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                node.parent[{i, j}] = {i, j};
            }
        }
        pair<int, int> l = {-1, -1}, r = {-2, -2};

        node.parent[l] = l;
        node.parent[r] = r;

        vector<pair<int, int>> dir{{1, 0}, {1, 1}, {1, -1}, {0, -1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}};
        set<pair<int, int>> vis;

        for (auto &c : cells)
        {
            int x = c[0] - 1, y = c[1] - 1;
            for (auto d : dir)
            {
                int nx = x + d.first, ny = y + d.second;
                if (nx >= 0 and nx < row)
                {
                    if (ny >= 0 and ny < col)
                    {
                        if (vis.find({nx, ny}) != vis.end())
                        {
                            node.Union({x, y}, {nx, ny});
                        }
                    }
                    else
                    {
                        if (ny == -1)
                        {
                            node.Union({x, y}, l);
                        }
                        if (ny == col)
                        {
                            node.Union({x, y}, r);
                        }
                    }
                }
                pair<int, int> tempL = node.find(l), tempR = node.find(r);
                if (tempL == tempR)
                {
                    return ans;
                };
                vis.insert({x, y});
            }
            ans++;
        }
        return ans;
    }
};
void solve()
{
    Solution x;
    vector<vector<int>> vec{
        {1, 1}, {2, 1}, {1, 2}, {2, 2}};
    cout << x.latestDayToCross(2, 2, vec);
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
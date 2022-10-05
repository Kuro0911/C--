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
        if (x == parent[x])
            return x;
        return find(parent[x]);
    };

    void Union(pair<int, int> a, pair<int, int> b)
    {
        a = find(a);
        b = find(b);

        if (a != b)
        {
            parent[b] = a;
        }
    }
};
class Solution
{
public:
    int latestDayToCross(int row, int col, vector<vector<int>> &cells)
    {
        DSU node;
        int ans = 0;
        node.make(cells[0][0], cells[0][1]);
        cout << node.parent << "next\n";
        for (int i = 1; i < cells.size(); i++)
        {
            pair<int, int> tempX = {cells[i][0], cells[i][1]}, tempY = {cells[i - 1][0], cells[i - 1][1]};
            node.make(tempX.first, tempY.second);
            node.Union(tempX, tempY);
            pair<int, int> x = node.find(tempX);
            if (x.first == 1 and tempX.first == row)
            {
                return ans;
            }
            ans++;
            cout << node.parent << "next\n";
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
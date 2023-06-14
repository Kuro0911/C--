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
class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        int st = 0, ed = citations.size() - 1;
        if (citations.size() == 1)
        {
            if (citations[0] == 0)
            {
                return 0;
            }
            else
            {
                return 1;
            }
        }
        while (st <= ed)
        {
            int md = (ed + st) / 2;
            if (citations[md] <= citations.size() - md)
            {
                st = md + 1;
            }
            else
            {
                ed = md - 1;
            }
        }
        if (ed < 0 or st >= citations.size())
        {
            if (st >= citations.size())
            {
                return citations[citations.size() - 1];
            }
            return citations.size();
        }
        return citations[ed];
    }
};
class Solution
{
public:
    set<pair<int, int>> vis;

    int helper(int i, int j, vector<vector<int>> &grid)
    {
        if (i == grid.size() - 1 and j == grid[0].size() - 1)
        {
            return 1;
        }
        if (vis.find({i, j}) != vis.end())
        {
            return INT_MAX;
        }
        vis.insert({i, j});

        vector<vector<int>> dir{{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {-1, -1}, {1, 1}, {-1, 1}, {1, -1}};
        int res = INT_MAX;
        for (auto d : dir)
        {
            int new_x = d[0] + i, new_y = d[1] + j;
            if (new_x >= 0 and new_y >= 0 and new_x < grid.size() and new_y < grid[0].size() and grid[new_x][new_y] != 1)
            {
                int x = helper(new_x, new_y, grid);
                if (x != INT_MAX)
                {
                    res = min(res, 1 + x);
                }
            }
        }
        vis.erase({i, j});
        return res;
    }
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        if (grid[0][0] == 1)
        {
            return -1;
        }
        int x = helper(0, 0, grid);
        if (x == INT_MAX)
        {
            return -1;
        }
        return x;
    }
};
void solve()
{
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
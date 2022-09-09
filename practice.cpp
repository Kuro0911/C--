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

int helper(int i, int j, int n, int m, vector<vector<int>> grid, map<pair<int, int>, int> &dp)
{
    if (i >= 0 && i < n && j >= 0 && j < m && grid[i][j] != 1)
    {
        if (dp.find({i, j}) != dp.end())
        {
            return dp[{i, j}];
        }
        if (i == n - 1 && j == m - 1)
        {
            return dp[{i, j}] = 1;
        }
        dp[{i, j}] = helper(i + 1, j, n, m, grid, dp) + helper(i, j + 1, n, m, grid, dp);
    }
    return 0;
}
int uniquePathsWithObstacles(vector<vector<int>> &grid)
{
    map<pair<int, int>, int> dp;
    helper(0, 0, grid.size(), grid[0].size(), grid, dp);
    return dp[{0, 0}];
}

void solve()
{
    vector<vector<int>> grid{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    map<pii, int> dp;
    cout << helper(0, 0, grid.size(), grid[0].size(), grid, dp);
    cout << dp;
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
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
class Solution
{
public:
    int n, m;
    int helper(int i, int j, int k, int curr, vector<vector<int>> grid, map<pair<int, int>, int> &dp)
    {
        if (dp.find({i, j}) != dp.end())
        {
            return dp[{i, j}];
        }
        if (i >= 0 and i < n and j >= 0 and j < m and grid[i][j] != -1)
        {
            int x = (curr + grid[i][j]) % k;
            if (i == n - 1 and j == m - 1 and x == 0)
            {
                return 1;
            }
            int num = grid[i][j];
            grid[i][j] = -1;
            int l = helper(i + 1, j, k, x, grid, dp);
            int r = helper(i - 1, j, k, x, grid, dp);
            int u = helper(i, j + 1, k, x, grid, dp);
            int d = helper(i, j - 1, k, x, grid, dp);
            grid[i][j] = num;
            return dp[{i, j}] = l + r + u + d;
        }
        return 0;
    }
    int numberOfPaths(vector<vector<int>> &grid, int k)
    {
        map<pair<int, int>, int> dp;
        n = grid.size(), m = grid[0].size();
        return helper(0, 0, k, 0, grid, dp);
    }
};
void solve()
{
    Solution x;
    int k = 3;
    vector<vector<int>> vec{{5, 2, 4}, {3, 0, 5}, {0, 7, 2}};
    cout << x.numberOfPaths(vec, k);
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
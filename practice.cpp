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
    int helper(int row, int col1, int col2, vector<vector<int>> grid, map<pair<int, pair<int, int>>, int> &dp)
    {
        if (col1 >= 0 and col1 < grid[0].size() and col2 >= 0 and col2 < grid[0].size())
        {
            if (dp.find({row, {col1, col2}}) != dp.end())
            {
                return dp[{row, {col1, col2}}];
            }
            int res = 0;
            res += grid[row][col1];
            if (col1 != col2)
            {
                res += grid[row][col2];
            }
            if (row != grid.size())
            {
                int mx = 0;
                for (int newCol1 = col1 - 1; newCol1 <= col1 + 1; newCol1++)
                {
                    for (int newCol2 = col2 - 1; newCol2 <= col2 + 1; newCol2++)
                    {
                        mx = max(mx, helper(row + 1, newCol1, newCol2, grid, dp));
                    }
                }
                res += mx;
            }

            return dp[{row, {col1, col2}}] = res;
        }

        return 0;
    }
    int cherryPickup(vector<vector<int>> &grid)
    {
        map<pair<int, pair<int, int>>, int> dp;
        int res = helper(0, 0, grid[0].size() - 1, grid, dp);
        return res;
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
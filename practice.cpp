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

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    bool dfs(int i, int j, vector<vector<int>> mat)
    {
        if (i >= 0 and i < mat.size() and j >= 0 and j < mat[i].size() and mat[i][j] == 0)
        {
            if (i == mat.size() - 1)
            {
                return true;
            }
            mat[i][j] = -1;
            bool u = dfs(i + 1, j, mat);
            bool d = dfs(i - 1, j, mat);
            bool r = dfs(i, j + 1, mat);
            bool l = dfs(i, j - 1, mat);
            return u || d || l || r;
        }
        return false;
    }
    int latestDayToCross(int row, int col, vector<vector<int>> &cells)
    {
        vector<vector<int>> mat(row, vector<int>(col, 0));
        for (auto x : cells)
        {
            mat[x[0] - 1][x[1] - 1] = 1;
        }
        int ans = cells.size();
        for (int i = cells.size() - 1; i >= 0; i--)
        {
            for (int j = 0; j < mat[0].size(); j++)
            {
                if (dfs(0, j, mat))
                {
                    return ans;
                }
            }
            ans--;
            mat[cells[i][0] - 1][cells[i][1] - 1] = 0;
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
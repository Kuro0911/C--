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

void helper(int i, int j, vector<vector<string>> &grid, set<vector<int>> &vis)
{
    if (i < grid.size() && i >= 0 && j < grid[i].size() && j >= 0 && grid[i][j] != "W")
    {
        if (grid[i][j] == "G")
        {
            if (vis.find({i, j}) != vis.end())
            {
                return;
            }
            else
            {
                vis.insert({i, j});
            }
        }
        else
        {
            grid[i][j] = "#";
        }
        helper(i + 1, j, grid, vis);
        helper(i - 1, j, grid, vis);
        helper(i, j + 1, grid, vis);
        helper(i, j - 1, grid, vis);
    }
    return;
};
int countUnguarded(int n, int m, vector<vector<int>> &guards, vector<vector<int>> &walls)
{
    vector<vector<string>> grid(n, vector<string>(m, "."));
    for (auto x : guards)
    {
        grid[x[0]][x[1]] = "G";
    }
    for (auto x : walls)
    {
        grid[x[0]][x[1]] = "W";
    }
    set<vector<int>> vis;
    for (auto x : guards)
    {
        helper(x[0], x[1], grid, vis);
    }
    for (auto x : grid)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }
    return 0;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> guard{{0, 0}, {1, 1}, {2, 3}};
    vector<vector<int>> walls{{0, 1}, {2, 2}, {1, 4}};
    cout << countUnguarded(n, m, guard, walls);
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
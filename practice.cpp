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

void dfs(int r, int c, vector<vector<int>> &vis, int prevHeight, vector<vector<int>> &heights)
{
    if (vis[r][c] == 1 || r < 0 || c < 0 || r == heights[0].size() - 1 || c == heights.size() - 1 || heights[r][c] < prevHeight)
    {
        return;
    }
    vis[r][c] = 1;
    dfs(r + 1, c, vis, heights[r][c], heights);
    dfs(r - 1, c, vis, heights[r][c], heights);
    dfs(r, c + 1, vis, heights[r][c], heights);
    dfs(r, c - 1, vis, heights[r][c], heights);
    return;
}
vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
{
    int cols = heights.size() - 1, rows = heights[0].size() - 1;
    vector<vector<int>> atl(cols + 1, vector<int>(rows + 1, 0)), pac(cols + 1, vector<int>(rows + 1, 0));
    dfs(0, 1, pac, heights[0][1], heights);
    for (int i = 0; i < cols; i++)
    {
        dfs(0, i, pac, heights[0][i], heights);
        dfs(rows, i, atl, heights[rows][i], heights);
    }
    for (int i = 0; i < rows; i++)
    {
        dfs(0, i, pac, heights[i][0], heights);
        dfs(rows, i, atl, heights[i][cols], heights);
    }
    vector<vector<int>> res{{1, 2}};
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; i++)
        {
            if (pac[i][j] == 0 && atl[i][j] == 0)
            {
                res.push_back({i, j});
            }
        }
    }
    return res;
}

void solve()
{
    vector<vector<int>> heights{{1, 2, 2, 3, 5}, {3, 2, 3, 4, 4}, {2, 4, 5, 3, 1}, {6, 7, 1, 4, 5}, {5, 1, 1, 2, 4}};
    vector<vector<int>> res = pacificAtlantic(heights);
    for (auto &x : res)
    {
        for (auto &y : x)
        {
            cout << y << " ";
        }
        cout << endl;
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
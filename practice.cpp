
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

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int, int>> q;
        vector<pair<int, int>> directions{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        int f = 0, t = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                    f++;
                else if (grid[i][j] == 2)
                    q.push({i, j});
            }
        }
        q.push({-2, -2});

        while (!q.empty())
        {
            pair<int, int> temp = q.front();
            q.pop();
            if (temp.first == -2 && temp.second == -2)
            {
                t++;
                if (!q.empty())
                {
                    q.push({-2, -2});
                }
            }
            else
            {
                for (auto x : directions)
                {
                    int r = x.first + temp.first;
                    int c = x.second + temp.second;
                    if (r < 0 || r >= n || c < 0 || c >= m)
                    {
                        continue;
                    }
                    if (grid[r][c] == 1)
                    {
                        f--;
                        grid[r][c] = 2;
                        q.push({r, c});
                    }
                }
            }
        }

        if (f == 0)
            return t;
        return -1;
    }
};

void solve()
{
    cout << "01";
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
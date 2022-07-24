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
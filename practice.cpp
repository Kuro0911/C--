class Solution
{
public:
    string shortestCommonSupersequence(string s1, string s2)
    {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = 0;
        }
        for (int i = 0; i <= m; i++)
        {
            dp[0][i] = 0;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (s1[i - 1] == s2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        string res;
        int x = n, y = m;
        while (x > 0 && y > 0)
        {
            if (s1[x - 1] == s2[y - 1])
            {
                res.push_back(s1[x - 1]);
                x--;
                y--;
            }
            else
            {
                if (dp[x - 1][y] > dp[x][y - 1])
                {
                    res.push_back(s1[x - 1]);
                    x--;
                }
                else
                {
                    res.push_back(s2[y - 1]);
                    y--;
                }
            }
        }
        while (x > 0)
        {
            res.push_back(s1[x - 1]);
            x--;
        }
        while (y > 0)
        {
            res.push_back(s2[y - 1]);
            y--;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
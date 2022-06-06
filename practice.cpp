// #include <iostream>

// using namespace std;

// int main()
// {
//     int n, bt[20], wt[20], tat[20], avwt = 0, avtat = 0, i, j;
//     cout << "Enter total number of processes(maximum 20):";
//     cin >> n;

//     cout << "\nEnter Process Burst Time\n";
//     for (i = 0; i < n; i++)
//     {
//         cout << "P[" << i + 1 << "]:";
//         cin >> bt[i];
//     }

//     wt[0] = 0; // waiting time for first process is 0

//     // calculating waiting time
//     for (i = 1; i < n; i++)
//     {
//         wt[i] = 0;
//         for (j = 0; j < i; j++)
//             wt[i] += bt[j];
//     }

//     cout << "\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time";

//     // calculating turnaround time
//     for (i = 0; i < n; i++)
//     {
//         tat[i] = bt[i] + wt[i];
//         avwt += wt[i];
//         avtat += tat[i];
//         cout << "\nP[" << i + 1 << "]"
//              << "\t\t" << bt[i] << "\t\t" << wt[i] << "\t\t" << tat[i];
//     }

//     avwt /= i;
//     avtat /= i;
//     cout << "\n\nAverage Waiting Time:" << avwt;
//     cout << "\nAverage Turnaround Time:" << avtat;

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
#define int long long
int lcs(string s1, string s2)
{
    int n = s1.size();
    int m = s2.size();
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
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[n][m];
}

int lps(string s)
{
    string rev = s;
    reverse(s.begin(), s.end());

    return lcs(s, rev);
}

int minInsertions(string s)
{
    return s.size() - lps(s);
}
void solve()
{
    string s;
    cin >> s;
    cout << minInsertions(s);
}

signed main()
{
    solve();
    return 0;
}
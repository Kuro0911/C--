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

// #####################################################

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

// #####################################################
class Solution
{
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, false));
        for (int i = 0; i <= s1.size(); i++)
        {
            for (int j = 0; j <= s2.size(); j++)
            {
                if (i == 0 and j == 0)
                {
                    dp[i][j] = true;
                }
                else if (i == 0)
                {
                    dp[i][j] = dp[i][j - 1] and s2[j - 1] == s3[i + j - 1];
                }
                else if (j == 0)
                {
                    dp[i][j] = dp[i - 1][j] and s1[i - 1] == s3[i + j - 1];
                }
                else
                {
                    bool c1 = dp[i - 1][j] and s1[i - 1] == s3[i + j - 1];
                    bool c2 = dp[i][j - 1] and s2[j - 1] == s3[i + j - 1];
                    dp[i][j] = c1 or c2;
                }
            }
        }
        return dp[s1.size()][s2.size()];
    }
};
void solve()
{
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    Solution x;
    x.isInterleave(s1, s2, s3);
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
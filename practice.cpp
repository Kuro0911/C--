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
bool isPalindrome(string s, int st, int ed)
{
    while (st < ed)
    {
        if (s[st] != s[ed])
            return false;
        st++;
        ed--;
    }
    return true;
}
int mcm(string s, int i, int j, vector<vector<int>> &dp)
{
    if (dp[i][j] != -1)
        return dp[i][j];
    int ans = INT_MAX;
    if (isPalindrome(s, i, j) || i >= j)
    {
        return dp[i][j] = 0;
    }
    for (int k = i; k <= j - 1; k++)
    {
        int temp = mcm(s, i, k, dp) + mcm(s, k + 1, j, dp) + 1;
        ans = min(temp, ans);
    }
    return dp[i][j] = ans;
}
void solve()
{
    string s;
    cin >> s;
    vector<vector<int>> dp(s.size() + 1, vector<int>(s.size() + 1, -1));
    cout << mcm(s, 0, s.size() - 1, dp);
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
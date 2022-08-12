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

bool check(int testA, int testB, int target, vector<vector<int>> &dp)
{
    int a = min(testA, testB);
    int b = max(testA, testB);
    if (dp[a][b] != -1)
    {
        return dp[a][b];
    }
    if (a > target || b > target || a * b > target || a < 0 || b < 0)
    {
        return dp[a][b] = false;
    }
    int temp = (a * 2) + (2 * b) + (a * b);
    if (temp == target)
    {
        return dp[a][b] = true;
    }
    if (temp < target)
    {
        return dp[a][b] = check(a + 1, b, target, dp) || check(a, b + 1, target, dp);
    }
    else
    {
        return dp[a][b] = check(a - 1, b, target, dp) || check(a, b - 1, target, dp);
    }
}

void solve()
{

    int n;
    cin >> n;
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    if (check(1, 1, n, dp))
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
}

signed main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    cin >> t;
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
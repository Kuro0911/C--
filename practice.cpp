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

int mcm(vector<int> &arr, int i, int j, vector<vector<int>> &dp)
{
    if (dp[i][j] != -1)
        return dp[i][j];
    int ans = INT_MAX;
    if (i >= j)
        return 0;
    for (int k = i; k <= j - 1; k++)
    {
        int temp = mcm(arr, i, k, dp) + mcm(arr, k + 1, j, dp) + arr[i - 1] * arr[k] * arr[j];
        ans = min(temp, ans);
    }
    return dp[i][j] = ans;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    for (auto &x : arr)
    {
        cin >> x;
    }

    cout << mcm(arr, 1, n - 1, dp);
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
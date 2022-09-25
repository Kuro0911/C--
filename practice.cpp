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

int dfs(int i, int j, int curr, vector<vector<int>> mat)
{
    if (i >= 0 && i < mat.size() && j >= 0 && j < mat[i].size())
    {
        if (i == mat.size() - 1 && j == mat[i].size() - 1)
        {
            return curr;
        }
        int down = i + 1 < mat.size() ? curr + mat[i + 1][j] : -1;
        int right = j + 1 < mat[i].size() ? curr + mat[i][j + 1] : -1;
        return max(dfs(i + 1, j, down, mat), dfs(i, j + 1, right, mat));
    }
    return -1;
}
int CollectMoney(int input1, int input2[101][101])
{
    vector<vector<int>> dp(input1 + 1, vector<int>(input1 + 1, 0));
    for (int i = 1; i <= input1; i++)
    {
        for (int j = 1; j <= input1; j++)
        {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + input2[i - 1][j - 1];
        }
    }
    return dp[input1][input1];
}
void solve()
{
    int n;
    cin >> n;
    int a[101][101];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    cout << CollectMoney(n, a);
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
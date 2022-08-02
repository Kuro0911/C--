/*
    We create a 2D vector containing "n"
    elements each having the value "vector<int> (m, 0)".
    "vector<int> (m, 0)" means a vector having "m"
    elements each of value "0".
    Here these elements are vectors.
    //vector<vector<int>> vec(n, vector<int>(m, 0));
*/
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

// recursion

bool isPresent(vector<int> &arr, int n, int target, int sm)
{
    if (sm == target)
        return true;
    else if (sm <= target || n < 0)
        return false;
    else
        return isPresent(arr, n - 1, target, sm - arr[n]) || isPresent(arr, n - 1, target, sm);
}
// memo
int isPresentMemo(vector<int> &arr, int n, int target, int sm, vector<vector<int>> &dp)
{
    if (dp[n][sm] != -1)
    {
        return dp[n][sm];
    }
    if (sm == target)
    {
        cout << "yes";
        return dp[n][sm] = 1;
    }
    else if (sm <= target || n < 0)
        return dp[n][sm] = 0;
    else
        return dp[n][sm] = isPresent(arr, n - 1, target, sm - arr[n]) || isPresent(arr, n - 1, target, sm);
}

void solve()
{
    int target;
    cin >> target;
    vector<int> arr(5);
    int sm = 0;
    for (int &X : arr)
    {
        cin >> X;
        sm += X;
    }
    vector<vector<int>> dp(arr.size() + 1, vector<int>(target + 1, -1));
    for (int i = 0; i <= target; i++)
    {
        dp[0][i] = 0;
    }
    for (int i = 0; i <= arr.size(); i++)
    {
        dp[i][0] = 1;
    }
    // isPresentMemo(arr, arr.size(), target, sm, dp);
    for (int i = 1; i <= arr.size(); i++)
    {
        for (int j = 1; j <= target; j++)
        {
            if (arr[i - 1] <= j)
                dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    cout << dp[arr.size() - 1][target];
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
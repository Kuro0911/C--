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
    int minJumps(vector<int> &arr)
    {
        map<int, vector<int>> mp;
        for (int i = 0; i < arr.size(); i++)
        {
            mp[arr[i]].push_back(i);
        }
        vector<int> dp(arr.size(), INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            if (i + 1 < arr.size())
            {
                dp[i + 1] = min(dp[i + 1], 1 + dp[i]);
            }
            if (i - 1 >= 0)
            {
                dp[i - 1] = min(dp[i - 1], 1 + dp[i]);
            }
            for (auto x : mp[arr[i]])
            {
                if (x != i)
                {
                    dp[x] = min(dp[x], dp[i] + 1);
                }
            }
        }
        for (int i = arr.size() - 1; i >= 0; i--)
        {
            if (i + 1 < arr.size())
            {
                dp[i + 1] = min(dp[i + 1], 1 + dp[i]);
            }
            if (i - 1 >= 0)
            {
                dp[i - 1] = min(dp[i - 1], 1 + dp[i]);
            }
            for (auto x : mp[arr[i]])
            {
                if (x != i)
                {
                    dp[x] = min(dp[x], dp[i] + 1);
                }
            }
        }
        for (int i = 0; i < arr.size(); i++)
        {
            cout << dp[i] << " ";
        }
        return dp[arr.size() - 1];
    }
};
void solve()
{
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
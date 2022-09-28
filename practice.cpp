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
bool isPalindrome(int left, int right, string &s)
{
    while (left < right)
    {
        if (s[left] != s[right])
            return false;
        left++;
        right--;
    }
    return true;
}
int solve(string s, int left, int right, vector<int> &dp)
{
    int sz = (int)s.size();

    if (right == sz - 1)
        return 0;
    if (dp[right] != -1)
        return dp[right];

    int op = 0;
    int temp = INT_MAX - 1;
    for (int i = sz - 1; i > right; i--)
    {

        if (isPalindrome(right + 1, i, s))
        {
            temp = min(temp, 1 + solve(s, right + 1, i, dp));
        }
    }
    op = temp;
    return dp[right] = op;
}
int minCut(string s)
{
    int sz = (int)s.size();
    vector<int> dp(sz + 1, -1);
    int ans = INT_MAX;

    for (int i = sz - 1; i >= 0; i--)
    {
        if (isPalindrome(0, i, s))
        {
            ans = min(ans, solve(s, 0, i, dp));
        }
    }
    return ans;
}
void solve()
{
    string s;
    cin >> s;
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
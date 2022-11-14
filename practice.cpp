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
class Solution
{
public:
    bool check(vector<int> x, vector<int> y)
    {
        if (x[0] == y[0])
        {
            return true;
        }
        if (x[1] == y[1])
        {
            return true;
        }
        return false;
    }
    void helper(int curr, vector<vector<int>> stones, vector<bool> &vis)
    {
        vis[curr] = true;
        for (int i = 0; i < stones.size(); i++)
        {
            if (vis[i])
                continue;
            if (check(stones[curr], stones[i]))
                helper(i, stones, vis);
        }
    }
    int removeStones(vector<vector<int>> &stones)
    {
        int n = stones.size();
        vector<bool> vis(n, false);
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (vis[i])
            {
                continue;
            }
            helper(i, stones, vis);
            ans++;
        }
        return (n - ans);
    }
};
void solve()
{
    Solution x;
    string s1, s2;
    cin >> s1 >> s2;

    cout << x.decodeMessage(s1, s2);
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
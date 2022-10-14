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
    int memo[70][70][70];
    int n, m;
    int cherryPickup(vector<vector<int>> &A)
    {
        n = A.size(), m = A[0].size();
        for (int i = 0; i < 70; i++)
            for (int j = 0; j < 70; j++)
                for (int k = 0; k < 70; k++)
                    memo[i][j][k] = -1;
        return max(0, dp(A, 0, 0, m - 1));
    }
    int dp(vector<vector<int>> &A, int r, int c1, int c2)
    {
        if (c1 < 0 || c1 == m || c2 < 0 || c2 == m)
            return -1e9;
        if (r == n)
            return 0;
        if (memo[r][c1][c2] != -1)
            return memo[r][c1][c2];
        int best = 0;
        for (int i = -1; i <= 1; i++)
            for (int j = -1; j <= 1; j++)
                best = max(best, dp(A, r + 1, c1 + i, c2 + j));
        return memo[r][c1][c2] = best + (c1 == c2 ? A[r][c1] : A[r][c1] + A[r][c2]);
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
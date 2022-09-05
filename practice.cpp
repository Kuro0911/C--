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

void helper(int i, int j, int n, vector<vector<int>> &ans, vector<pair<int, int>> dir, int &d)
{
    if (i >= ans.size() && i < 0 && j >= ans[i].size() || j < 0 || ans[i][j] != -1)
    {
        return;
    }
    ans[i][j] = n;
    int x, y;
    while (d < 4)
    {
        x = i + dir[d].first;
        y = j + dir[d].second;
        if (x < ans.size() && x >= 0 && y < ans[i].size() && y >= 0 && ans[x][y] == -1)
        {
            helper(x, y, n + 1, ans, dir, d);
            return;
        }
        d++;
    }
    d = 0;
    x = i + dir[0].first;
    y = j + dir[0].second;
    helper(x, y, n + 1, ans, dir, d);
}

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> ans(n, vector<int>(n, -1));
    vector<pair<int, int>> dir{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int d = 0;
    helper(0, 0, 1, ans, dir, d);
    for (auto x : ans)
    {
        cout << x;
    }
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
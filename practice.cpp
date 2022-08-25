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
int dfs(int i, int j, vector<vector<int>> &matrix, map<pair<int, int>, int> &mp)
{
    vector<pair<int, int>> dir{{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    if (mp.find({i, j}) != mp.end())
    {
        return mp[{i, j}];
    }
    int ans = 0;
    for (auto x : dir)
    {
        int a = i + x.first;
        int b = j + x.second;
        if (a >= 0 && a < matrix.size() && b >= 0 && b < matrix[i].size() && matrix[a][b] > matrix[i][j])
        {
            ans = max(ans, dfs(a, b, matrix, mp));
        }
    }
    return mp[{i, j}] = ans + 1;
}
int longestIncreasingPath(vector<vector<int>> &matrix)
{
    int ans = 1;
    map<pair<int, int>, int> mp;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            if (mp.find({i, j}) == mp.end())
            {
                cout << i << " " << j << endl;
                mp[{i, j}] = dfs(i, j, matrix, mp);
            }
            ans = max(ans, mp[{i, j}]);
        }
    }
    return ans;
}
void solve()
{
    vector<vector<int>> vec{{9, 9, 4}, {6, 6, 8}, {2, 1, 1}};
    cout << longestIncreasingPath(vec);
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
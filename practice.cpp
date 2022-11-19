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
static vector<vector<int>> outerTrees(vector<vector<int>> &points)
{
    // Andrew's monotone chain method.
    sort(begin(points), end(points), [](const vector<int> &a, const vector<int> &b)
         { return a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]); });
    // left to right
    const int n = size(points);
    vector<vector<int>> ans;
    ans.reserve(n);
    for (int i = 0; i < n; ++i)
    {
        while (size(ans) > 1 && orientation(ans[size(ans) - 2], ans.back(), points[i]) < 0)
            ans.pop_back();
        ans.push_back(points[i]);
    }
    // If all points are along a line, size(ans) is n after left to right procedure.
    if (size(ans) == n)
        return ans;

    // right to left
    for (int i = n - 2; i >= 0; --i)
    {
        while (size(ans) > 1 && orientation(ans[size(ans) - 2], ans.back(), points[i]) < 0)
            ans.pop_back();
        ans.push_back(points[i]);
    }
    ans.pop_back();
    return ans;
}

static int orientation(const vector<int> &a, const vector<int> &b, const vector<int> &c)
{
    return (b[0] - a[0]) * (c[1] - b[1]) - (b[1] - a[1]) * (c[0] - b[0]);
}
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
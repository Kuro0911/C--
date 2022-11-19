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
    int orientation(vector<int> p1, vector<int> p2, vector<int> p3)
    {
        int d = (p3[1] - p2[1]) * (p2[0] - p1[0]) - (p2[1] - p1[1]) * (p3[0] - p2[0]);
        if (d > 0)
        {
            return 1;
        }
        else if (d < 0)
        {
            return -1;
        }
        else
        {
            return 0;
        }
    }
    vector<vector<int>> outerTrees(vector<vector<int>> &points)
    {
        sort(begin(points), end(points), [](const vector<int> &a, const vector<int> &b)
             { return a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]); });
        vector<vector<int>> ans;
        for (int i = 0; i < points.size(); i++)
        {
            while (ans.size() > 1 and orientation(ans[ans.size() - 2], ans.back(), points[i]) < 0)
            {
                ans.pop_back();
            }
            ans.push_back(points[i]);
        }
        if (ans.size() == points.size())
        {
            return ans;
        }
        for (int i = points.size() - 2; i >= 0; i--)
        {
            while (ans.size() > 1 and orientation(ans[ans.size() - 2], ans.back(), points[i]) < 0)
            {
                ans.pop_back();
            }
            ans.push_back(points[i]);
        }
        ans.pop_back();
        return ans;
    }
};
void solve()
{
    Solution Y;
    vector<vector<int>> trees(6, vector<int>(2));
    for (auto &x : trees)
    {
        for (auto &t : x)
        {
            cin >> t;
        }
    }
    cout << Y.outerTrees(trees);
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
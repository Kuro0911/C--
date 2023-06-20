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

void solve()
{
    int n, m, st = 1;
    cin >> n >> m;
    map<pair<int, int>, int> mp;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        mp[{st, st + x - 1}] = y;
        st = st + x;
    }

    int res = 0, dist = 0;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        int curr_st = dist + 1, curr_ed = dist + x;
        dist += x;
        for (auto m : mp)
        {
            // 4 cases:
            if (m.first.first <= curr_st and m.first.second >= curr_ed)
            {
                res = max(res, y - m.second);
            }
            else if (m.first.first <= curr_st and m.first.second >= curr_st)
            {
                res = max(res, y - m.second);
            }
            else if (m.first.first <= curr_ed and m.first.second >= curr_ed)
            {

                res = max(res, y - m.second);
            }
            else if (m.first.first >= curr_st and m.first.second <= curr_ed)
            {
                res = max(res, y - m.second);
            }
        }
    }
    cout << res;
}

signed main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);

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
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
    int st, ed, x, y;
    cin >> st >> ed >> x >> y;
    int a = abs(st - ed);
    int b = abs(st - x) + abs(ed - y);
    int c = abs(st - y) + abs(ed - x);

    cout << min({a, b, c});
}

signed main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("teleport.in", "r", stdin);
    freopen("teleport.out", "w", stdout);

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
    return 0;
}
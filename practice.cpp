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
    int helper(string ring, string key, int curr)
    {
        if (key.size() == 0)
        {
            return 0;
        }
        curr %= ring.size();
        if (ring[curr] == '#')
        {
            return INT_MAX;
        }
        int tot = 1;
        if (ring[curr] == key[0])
        {
            tot++;
            key = key.substr(1);
        }
        char x = ring[curr];
        ring[curr] = '#';
        int l = helper(ring, key, curr + 1);
        int r = helper(ring, key, curr + ring.size() - 1);
        ring[curr] = x;
        tot += min(l, r);
        return tot;
    }
    int findRotateSteps(string ring, string key)
    {
        int ans = helper(ring, key, 0);
        return ans;
    }
};
void solve()
{
    Solution x;
    string r, k;
    cin >> r >> k;
    cout << x.findRotateSteps(r, k);
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
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
    int findRotateSteps(string ring, string key)
    {
        vector<int> pos[26];
        int r = ring.size();
        for (int i = 0; i < r; i++)
            pos[ring[i] - 'a'].push_back(i);
        vector<vector<int>> mem(r, vector<int>(key.size()));
        return findSteps(0, 0, ring, key, pos, mem);
    }
    int findSteps(int p1, int p2, string &ring, string &key, vector<int> pos[26], vector<vector<int>> &mem)
    {
        if (p2 == key.size())
            return 0;
        if (mem[p1][p2])
            return mem[p1][p2];
        int r = ring.size(), ms = INT_MAX;
        for (int nxt : pos[key[p2] - 'a'])
        {
            int dist = abs(p1 - nxt);
            ms = min(ms, min(dist, r - dist) + findSteps(nxt, p2 + 1, ring, key, pos, mem));
        }
        return mem[p1][p2] = ms + 1;
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
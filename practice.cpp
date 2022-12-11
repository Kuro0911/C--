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
class Solution
{
public:
    vector<int> findOriginalArray(vector<int> &c)
    {
        map<int, int> vis;
        for (auto x : c)
        {
            vis[x]++;
        }
        vector<int> res;
        for (int i = 0; i < c.size(); i++)
        {

            if (vis.find(c[i] / 2) != vis.end())
            {
                cout << c[i] << " found half: " << c[i] / 2 << endl;
                vis[c[i]] != 1 ? vis[c[i]]-- : vis.erase(c[i]);
                vis[c[i] / 2] != 1 ? vis[c[i] / 2]-- : vis.erase(c[i] / 2);
                res.push_back(c[i] / 2);
            }
            else if (vis.find(c[i] * 2) != vis.end())
            {
                cout << c[i] << " found twice: " << c[i] * 2 << endl;
                vis[c[i]] != 1 ? vis[c[i]]-- : vis.erase(c[i]);
                vis[c[i] * 2] != 1 ? vis[c[i] * 2]-- : vis.erase(c[i] * 2);
                res.push_back(c[i]);
            }
            else
            {
                if (vis.size() == 0 and res.size() == c.size() / 2)
                    return res;
                else
                    break;
            }
        }
        return {};
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
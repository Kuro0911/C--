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
    int hIndex(vector<int> &citations)
    {
        int st = 0, ed = citations.size() - 1;
        if (citations.size() == 1)
        {
            if (citations[0] == 0)
            {
                return 0;
            }
            else
            {
                return 1;
            }
        }
        while (st <= ed)
        {
            int md = (ed + st) / 2;
            if (citations[md] <= citations.size() - md)
            {
                st = md + 1;
            }
            else
            {
                ed = md - 1;
            }
        }
        if (ed < 0 or st >= citations.size())
        {
            if (st >= citations.size())
            {
                return citations[citations.size() - 1];
            }
            return citations.size();
        }
        return citations[ed];
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
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
    vector<int> findAnagrams(string s, string p)
    {
        int l = 0, r = 0;
        int winSize = p.size();
        unordered_map<char, int> mp;
        set<char> dict;
        for (auto x : p)
        {
            mp[x]++;
            dict.insert(x);
        }
        for (int i = 0; i < winSize; i++)
        {
            if (mp.count(p[i]) > 0)
            {
                if (--mp[p[i]] == 0)
                {
                    mp.erase(p[i]);
                }
            }
            r++;
        }
        vector<int> res;
        while (r != s.size())
        {
            if (mp.empty())
            {
                res.push_back(l);
            }
            if (dict.find(s[l]) != dict.end())
            {
                mp[s[l]]++;
            }
            if (dict.find(s[r + 1]) != dict.end())
            {
                mp[s[r + 1]];
            }
            l++;
            r++;
        }
    }
};

void solve()
{
    int x();
    cout << x << endl;
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
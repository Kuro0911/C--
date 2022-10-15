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
    int helper(string s, int k)
    {
        if (k == 0)
        {
            return s.size();
        }
        string new_str;
        for (int i = 0; i < s.size(); i++)
        {
            int cnt = 0;
            for (int j = i + 1; j < s.size(); j++)
            {
                if (s[i] != s[j])
                {
                    break;
                }
                else
                {
                    cnt++;
                }
            }
            new_str.push_back(s[j]);
            new_str.push_back(cnt);
        }
        cout << new_str << endl;
        return min(helper(s.substr(1), k - 1), helper(s.substr(1), k - 1));
    }
    int getLengthOfOptimalCompression(string s, int k)
    {
        int res = helper(s, k);
        return res;
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
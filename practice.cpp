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
bool helper(string s, string p, vector<char> &prev)
{
    if (s.size() == 0 && p.size() == 0)
    {
        return true;
    }
    if (p[0] != '*')
    {
        if (p.size() > 1 && p[1] == '*')
        {
            prev.push_back(p[0]);
        }
        if (s[0] != p[0] && p[0] != '.')
        {
            return false;
        }
        return helper(s.substr(1), p.substr(1), prev);
    }
    else
    {
        int same = 0;
        while (s[same] == prev[0])
        {
            same++;
        }
        return helper(s.substr(same), p.substr(1), prev);
    }
    return false;
}
bool isMatch(string s, string p)
{
    vector<char> temp;
    return helper(s, p, temp);
}
void solve()
{
    string s, p;
    cin >> s >> p;
    cout << isMatch(s, p);
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
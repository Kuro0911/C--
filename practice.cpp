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

bool closeStrings(string word1, string word2)
{
    map<char, int> mp1, mp2;

    if (word1.size() != word2.size())
    {
        return false;
    }
    for (auto x : word1)
    {
        mp1[x]++;
    }
    for (auto x : word2)
    {
        mp2[x]++;
    }
    if (mp1.size() != mp2.size())
        return false;

    for (auto x : mp2)
    {
        if (mp1.find(x.first) == mp1.end())
        {
            return false;
        }
    }
    vector<int> f(26, 0), f1(26, 0);

    for (auto x : word1)
    {
        f[x - 'a']++;
    }
    for (auto x : word2)
    {
        f1[x - 'a']++;
    }
    sort(f.begin(), f.end());
    sort(f1.begin(), f1.end());
    for (int i = 0; i < 26; i++)
    {
        if (f[i] != f1[i])
        {
            return false;
        }
    }
    return true;
}
void solve()
{
    string s1, s2;
    cin >> s1 >> s2;
    cout << closeStrings(s1, s2);
}

signed main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    // cin >> t;
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
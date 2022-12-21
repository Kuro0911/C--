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
    bool canChange(string start, string target)
    {
        int n = start.length();
        string s1 = start;
        string s2 = target;

        start.erase(remove(start.begin(), start.end(), '_'), start.end());
        target.erase(remove(target.begin(), target.end(), '_'), target.end());

        if (start != target)
        {
            return false;
        }
        int i = 0, j = 0;
        while (i < n and j < n)
        {
            if (s1[i] == '_')
            {
                i++;
            }
            else if (s2[j] == '_')
            {
                j++;
            }
            if ((s1[i] == 'L' and i < j) or (s1[i] == 'R' and i > j))
            {
                return false;
            }
            i++;
            j++;
        }
        return true;
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
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
int fact(int x)
{
    int res = 1;
    for (int i = 1; i <= x; i++)
        res *= i;
    return res;
}
string helper(string s, int k)
{
    if (s.size() == 1)
    {
        string temp;
        temp.push_back(s[0]);
        return temp;
    }
    int x = s.size() - 1, pos, curr = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (curr >= k)
        {
            break;
        }
        else
        {
            curr += fact(x);
            pos = i;
        }
    }
    curr -= fact(x);
    string temp;
    temp.push_back(s[pos]);
    s.erase(pos, 1);
    temp += helper(s, k - curr);
    return temp;
}
string getPermutation(int n, int k)
{
    string s = "";
    for (int i = 1; i <= n; i++)
    {
        s += to_string(i);
    }
    return helper(s, k);
}
void solve()
{
    int n, k;
    cin >> n >> k;
    cout << getPermutation(n, k);
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
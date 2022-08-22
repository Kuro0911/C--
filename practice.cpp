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

void opp(char op, int a, int b, vector<char> &s)
{
    int res;
    if (op == '+')
    {
        res = a + b;
    }
    else if (op == '-')
    {
        res = a - b;
    }
    else if (op == '*')
    {
        res = a * b;
    }
    else if (op == '/')
    {
        res = a / b;
    }
}
void solve()
{
    set<char> check;
    check.insert('+');
    check.insert('-');
    check.insert('/');
    check.insert('*');

    string s;
    cin >> s;
    vector<char> str;
    for (auto x : s)
    {
        str.push_back(x);
    }
    for (int i = 0; i < str.size(); i++)
    {
        if (check.find(str[i]) != check.end())
        {
            opp(str[i], str[i - 1] - '0', str[i + 1] - '0', str);
        }
    }

    cout << s;
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
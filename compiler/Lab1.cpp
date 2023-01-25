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

bool isNumber(string t)
{
    for (int i = 0; i < t.size(); i++)
    {
        if (t[i] >= '0' and t[i] <= '9')
        {
            continue;
        }
        return false;
    }
    return true;
}
bool checkOpp(string t)
{
    int x = t[0];
    if (x >= 58 and x <= 63 or x >= 33 and x <= 47)
    {
        return true;
    }
    return false;
}
void solve()
{
    string str = "while ( a > 20 ) break ;";
    map<string, string> mp;
    mp["while"] = "key-word";
    mp["break"] = "key-word";
    int ptr = 0, cnt = 0;
    string temp = "";
    while (ptr < str.size())
    {
        if (str[ptr] == ' ')
        {
            cout << temp << " : ";
            bool flag = false;
            if (mp.find(temp) != mp.end())
            {
                flag = true;
                cout << mp[temp];
            }
            if (isNumber(temp))
            {
                flag = true;
                cout << "number";
            }
            if (temp.size() <= 2)
            {
                if (checkOpp(temp))
                {
                    flag = true;
                    cout << "opp";
                }
            }
            if (!flag)
            {
                cout << "variable";
            }
            cout << endl;
            temp = "";
            cnt++;
        }
        else
        {
            temp.push_back(str[ptr]);
        }
        ptr++;
    }
    cout << "total tokens : " << cnt << endl;
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
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

vector<string> solution(string s, int limit)
{
    vector<string> ans;
    int curr = 1;
    string temp;
    map<int, string> mp;
    for (int i = 0; i < s.size(); i++)
    {
        temp.push_back(s[i]);
        if (temp.size() == limit - 5)
        {
            mp[curr] = temp;
            curr++;
            temp.clear();
        }
    }
    if (temp.size() != 0)
    {
        mp[curr] = temp;
        curr++;
    }
    for (auto x : mp)
    {
        x.second.push_back('<');
        x.second += to_string(x.first);
        x.second.push_back('/');
        x.second += to_string(mp.size());
        x.second.push_back('>');
        ans.push_back(x.second);
    }
    return ans;
}
void solve()
{
    string s = "Hello, world!";
    int n;
    cin >> n;
    cout << solution(s, n);
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
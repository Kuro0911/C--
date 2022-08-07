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

map<char, vector<char>> mp;
void helper(string s, string &temp, vector<string> &ans)
{
    if (s.size() == 0)
    {
        ans.push_back(temp);
        return;
    }
    else
    {
        string test = s.substr(1);
        for (auto x : mp[s[0]])
        {
            temp.push_back(x);
            helper(test, temp, ans);
            temp.pop_back();
        }
    }
    return;
}
vector<string> letterCombinations(string digits)
{
    mp['2'] = {'a', 'b', 'c'};
    mp['3'] = {'d', 'e', 'f'};
    mp['4'] = {'g', 'h', 'i'};
    mp['5'] = {'j', 'k', 'l'};
    mp['6'] = {'m', 'n', 'o'};
    mp['7'] = {'p', 'q', 'r', 's'};
    mp['8'] = {'t', 'u', 'v'};
    mp['9'] = {'w', 'x', 'y', 'z'};

    vector<string> ans;
    string temp = "";
    helper(digits, temp, ans);
    return ans;
}
void solve()
{
    string digits = "23";
    vector<string> ans = letterCombinations(digits);
    cout << ans;
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
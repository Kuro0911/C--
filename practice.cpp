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

void helper(int l, int r, int k, string s, vector<int> &ans, map<string, int> st, map<string, bool> &mp)
{
    if (r > s.size())
    {
        return;
    }
    string str = s.substr(l, r);
    if (mp.find(str) != mp.end())
    {
        if (mp[str])
        {
            ans.push_back(l);
        }
        helper(l + k, r + k, k, s, ans, st, mp);
    }
    else
    {
        map<string, int> temp = st;
        bool flag = true;
        for (int i = l; i < r; i += k)
        {
            string x = "";
            for (int j = i; j < i + k; j++)
            {
                x += s[j];
            }
            if (st.find(x) == st.end())
            {
                flag = false;
                break;
            }
            else
            {
                st[x]--;
            }
        }
        if (flag && st.size() == 0)
        {
            mp[str] = true;
            ans.push_back(l);
        }
        else
        {
            mp[str] = false;
        }
        helper(l + k, r + k, k, s, ans, temp, mp);
    }
    return;
}
vector<int> findSubstring(string s, vector<string> &words)
{
    int k = words[0].size();
    int ansSize = k * words.size();
    if (ansSize > s.size())
    {
        return {};
    }
    vector<int> ans;
    map<string, bool> mp;
    map<string, int> st;
    for (auto x : words)
    {
        st[x]++;
    }
    helper(0, ansSize - 1, k, s, ans, st, mp);
    return ans;
}
void solve()
{
    vector<string> word(4);
    string s;
    cin >> s;
    for (auto &x : word)
    {
        cin >> x;
    }
    cout << findSubstring(s, word);
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
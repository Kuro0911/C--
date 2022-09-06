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

void helper(string s, int l, int r, int k, int minSz, map<string, int> mp, map<string, bool> &vis, vector<int> &ans)
{
    if (s.size() < minSz)
    {
        return;
    }
    map<string, int> tempMp = mp;
    if (vis.find(s) != vis.end())
    {
        if (vis[s])
        {
            ans.push_back(l);
        }
    }
    else
    {
        for (int i = 0; i < s.size(); i += k)
        {
            string temp = "";

            for (int j = i; j < i + k; j++)
            {
                temp += s[j];
            }
            cout << temp << endl;
            if (mp.find(temp) != mp.end())
            {
                mp[temp]--;
                if (mp[temp] == 0)
                {
                    mp.erase(temp);
                }
            }
        }
        cout << mp.size() << endl;
        cout << mp;
        if (mp.size() == 0)
        {
            ans.push_back(l);
            vis[s] = true;
        }
        else
        {
            vis[s] = false;
        }
    }
    // helper(s.substr(0, s.size() - 1), l, r - 1, k, minSz, tempMp, vis, ans);
    // helper(s.substr(1), l + 1, r, k, minSz, tempMp, vis, ans);
}
vector<int> findSubstring(string s, vector<string> &words)
{
    map<string, bool> vis;
    map<string, int> mp;
    int k = words[0].size();
    int minSz = words[0].size() * words.size();
    for (auto x : words)
    {
        mp[x]++;
    }
    vector<int> ans;
    helper(s, 0, s.size() - 1, k, minSz, mp, vis, ans);
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
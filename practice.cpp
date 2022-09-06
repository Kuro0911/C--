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

void helper(string s, int l, int r, int k, int minSz, map<string, int> mp, set<int> &ans)
{
    map<string, int> tempMp = mp;
    if (r > s.size())
    {
        return;
    }
    cout << l << " " << r << endl;
    if (ans.find(l) == ans.end())
    {
        for (int i = l; i < s.size(); i += k)
        {
            string temp = "";

            for (int j = i; j < i + k; j++)
            {
                temp += s[j];
            }
            if (mp.find(temp) != mp.end())
            {
                mp[temp]--;
                if (mp[temp] == 0)
                {
                    mp.erase(temp);
                }
            }
            else
            {
                break;
            }
            if (mp.size() == 0)
            {
                ans.insert(l);
            }
        }
    }
    helper(s, l + 1, r + 1, k, minSz, tempMp, ans);
}
vector<int> findSubstring(string s, vector<string> &words)
{
    map<string, int> mp;
    int k = words[0].size();
    int minSz = words[0].size() * words.size();
    for (auto x : words)
    {
        mp[x]++;
    }
    set<int> ans;
    helper(s, 0, minSz, k, minSz, mp, ans);
    vector<int> res(ans.begin(), ans.end());
    return res;
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
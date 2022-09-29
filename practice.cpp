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
    void helper(string b, string e, vector<string> temp, set<string> dict, map<int,vector<vector<string>>> &ans)
    {
        if (b == e)
        {
            ans[temp.size()].push_back(temp);
            return;
        }
        dict.erase(b);
        for (int k = 0; k < b.size(); k++)
        {
            for (int i = 0; i < 26; i++)
            {
                char y = b[k];
                b[k] = i + 'a';
                if (dict.find(b) != dict.end())
                {
                    dict.erase(b);
                    temp.push_back(b);
                    helper(b, e, temp, dict, ans);
                    temp.pop_back();
                    // dict.insert(b);
                }
                b[k] = y;
            }
        }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        map<int,vector<vector<string>>> ans;
        vector<string> temp{beginWord};
        set<string> dict(wordList.begin(), wordList.end());
        helper(beginWord, endWord, temp, dict, ans);
        auto x = ans.begin();
        return x->second;
    }
void solve()
{
    string s;
    cin >> s;
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
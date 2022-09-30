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
void helper(string b, string e, set<string> dict, vector<vector<string>> &ans)
{
    unordered_map<string, vector<vector<string>>> mp;
    queue<string> q;
    q.push(b);
    dict.erase(b);
    mp[b].push_back({b});
    while (!mp.empty())
    {
        unordered_map<string, vector<vector<string>>> new_mp;
        for (auto [x, paths] : mp)
        {
            if (x == e)
            {
                ans = mp[x];
                return;
            }
            vector<string> nei;
            for (int k = 0; k < x.size(); k++)
            {
                string temp = x;
                char y = temp[k];
                for (int j = 0; j < 26; j++)
                {
                    temp[k] = j + 'a';
                    if (dict.find(temp) != dict.end())
                    {
                        nei.push_back(temp);
                        dict.erase(temp);
                    }
                }
                temp[k] = y;
            }
            for (auto n : nei)
            {
                for (auto path : paths)
                {
                    path.push_back(n);
                    new_mp[n].push_back(path);
                }
            }
        }
        mp.swap(new_mp);
    }
    return;
}
vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
{
    vector<vector<string>> ans;
    vector<string> temp;
    set<string> dict(wordList.begin(), wordList.end());
    helper(beginWord, endWord, dict, ans);
    return ans;
}
void solve()
{
    string b, e;
    cin >> b >> e;
    vector<string> vec{"hot", "dot", "dog", "lot", "log", "cog"};
    cout << findLadders(b, e, vec);
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
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
class Solution
{
public:
    vector<int> loudAndRich(vector<vector<int>> &richer, vector<int> &quiet)
    {
        vector<int> inDeg(quiet.size());
        vector<vector<int>> graph(quiet.size());
        for (auto x : richer)
        {
            graph[x[1]].push_back(x[0]);
            inDeg[x[0]]++;
        }
        vector<int> res(quiet.size(), 0);
        queue<int> q;
        vector<int> in = inDeg;
        for (int i = 0; i < in.size(); i++)
        {
            if (in[i] == 0)
            {
                q.push(i);
            }
        }
        vector<vector<int>> topo;
        while (!q.empty())
        {
            int sz = q.size();
            vector<int> lvl;
            for (int i = 0; i < sz; i++)
            {
                int temp = q.front();
                q.pop();
                for (auto x : graph[temp])
                {
                    in[x]--;
                    if (in[x] == 0)
                    {
                        q.push(x);
                    }
                }
                lvl.push_back(x);
            }
            topo.push_back(lvl);
        }
        for (auto t : topo)
        {
            for (auto x : t)
            {
                cout << x << " ";
            }
            cout << endl;
        }
        return res;
    }
};
void solve()
{
    string s = "abc";
    for (int i = 1; i <= s.size(); i++)
    {
        cout << s.substr(0, i) << " " << s.substr(i) << endl;
    }
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
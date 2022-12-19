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
    int helper(int curr, vector<vector<int>> graph)
    {
        queue<pair<int, string>> q;
        string bits, corr;
        bits.assign(graph.size(), '0');
        bits.assign(graph.size(), '1');
        bits[curr] = '1';
        q.push({curr, bits});
        int ans = 1;
        set<pair<int, string>> vis;
        while (!q.empty())
        {
            int sz = q.size();
            for (int i = 0; i < sz; i++)
            {
                pair<int, string> temp = q.front();
                q.pop();
                for (auto x : graph[temp.first])
                {
                    temp.second[x] = '1';
                    if (temp.second == corr)
                    {
                        return ans;
                    }
                    if (vis.find({x, temp.second}) == vis.end())
                    {
                        vis.insert({x, temp.second});
                        q.push({x, temp.second});
                    }
                }
            }
            ans++;
        }
        return ans;
    }
    int shortestPathLength(vector<vector<int>> &g)
    {
        vector<vector<int>> graph(g.size());
        for (int i = 0; i < g.size(); i++)
        {
            for (auto x : g[i])
            {
                graph[i].push_back(x);
            }
        }
        int ans = INT_MAX;
        for (int i = 0; i < graph.size(); i++)
        {
            ans = min(ans, helper(i, graph));
        }
        return ans;
    }
};
void solve()
{
    Solution x;
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
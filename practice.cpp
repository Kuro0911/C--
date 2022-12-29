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
    vector<int> getOrder(vector<vector<int>> &t)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        vector<vector<int>> tasks;
        for (int i = 0; i < t.size(); i++)
        {
            tasks.push_back({t[i][0], t[i][1], i});
        }
        sort(tasks.begin(), tasks.end());
        long long currTime = 0;
        int i = 0;
        vector<int> res;

        while (i < t.size() or !pq.empty())
        {
            if (pq.empty() and currTime < tasks[i][0])
            {
                currTime = tasks[i][0];
            }
            while (i < tasks.size() and currTime >= tasks[i][0])
            {
                pq.push({tasks[i][1], tasks[i][2]});
                i++;
            }

            currTime += pq.top().first;
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};
void solve()
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 0; i < 10; i++)
    {
        pq.push({i, -i});
    }
    while (!pq.empty())
    {
        cout << pq.top();
        pq.pop();
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
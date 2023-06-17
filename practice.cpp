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

void solve()
{
    vector<vector<char>> graph(10, vector<char>(10));
    pair<int, int> root;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cin >> graph[i][j];
            if (graph[i][j] == 'L')
                root = {i, j};
        }
    }

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
    pq.push({0, root});
    vector<pair<int, int>> dir{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    while (!pq.empty())
    {
        auto temp = pq.top();
        int dist = temp.first;
        auto curr = temp.second;
        int i = curr.first, j = curr.second;
        pq.pop();
        if (graph[i][j] == 'B')
        {
            cout << dist - 1;
            return;
        }
        graph[i][j] = '#';
        for (auto d : dir)
        {
            int new_x = i + d.first, new_y = j + d.second;
            if (new_x >= 0 and new_y >= 0 and new_x < 10 and new_y < 10 and graph[new_x][new_y] != '#' and graph[new_x][new_y] != 'R')
            {
                pq.push({dist + 1, {new_x, new_y}});
            }
        }
    }
}

signed main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("buckets.in", "r", stdin);
    freopen("buckets.out", "w", stdout);

    int t = 1;
    // cin >> t;
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
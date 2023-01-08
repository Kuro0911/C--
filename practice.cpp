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
int bfs(int r, int c, vector<int> A, vector<int> B, vector<vector<int>> graph)
{
    if (r == c)
    {
        return A[r];
    }
    set<int> vis;
    int edges = 0;
    queue<pair<int, int>> q;
    q.push({r, 0});
    while (!q.empty())
    {
        int sz = q.size();
        for (int i = 0; i < sz; i++)
        {
            int temp = q.front().first;
            int w = q.front().second;
            if (temp == c)
            {
                return A[temp] + 2 * w + edges * B[temp];
            }
            vis.insert(temp);
            q.pop();
            for (int j = 0; j < A.size(); j++)
            {
                if (j != temp and vis.find(j) == vis.end() and graph[temp][j] != -1)
                {
                    q.push({j, w + graph[temp][j]});
                }
            }
        }
        edges++;
    }
    return INT_MAX;
}

vector<int> solve2(vector<int> &A, vector<int> &B, vector<vector<int>> &C)
{
    vector<vector<int>> graph(A.size(), vector<int>(A.size(), -1));
    for (auto x : C)
    {
        graph[x[0] - 1][x[1] - 1] = x[2];
        graph[x[1] - 1][x[0] - 1] = x[2];
    }

    vector<int> res;
    for (int i = 0; i < A.size(); i++)
    {
        int mn = INT_MAX;
        for (int j = 0; j < A.size(); j++)
        {
            mn = min(mn, bfs(i, j, A, B, graph));
        }
        res.push_back(mn);
    }
    return res;
}

void solve()
{
    vector<int> A{15, 20, 25, 33};
    vector<int> B{1, 4, 1, 2};
    vector<vector<int>> C{{1, 4, 4}, {1, 3, 3}, {2, 3, 5}};

    cout << solve2(A, B, C);
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
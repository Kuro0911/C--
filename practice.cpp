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
int kthSmallest(vector<vector<int>> &mat, int k)
{
    priority_queue<vector<int>> max_heap;
    set<vector<int>> vis;
    int n = mat.size(), m = mat[0].size();
    int s = 0;
    for (int i = 0; i < n; i++)
        s += mat[i][0];
    vector<int> temp{s};
    for (int i = 0; i < n; i++)
        temp.push_back(0);
    max_heap.push(temp);
    while (k > 1)
    {
        vector<int> prev = max_heap.top();
        max_heap.pop();
        k--;
        for (int i = 0; i < n; i++)
        {
            if (prev[i + 1] == m - 1)
            {
                continue;
            }
            vector<int> next = prev;
            next[0] -= mat[i][next[i + 1]];
            next[i + 1] += 1;
            next[0] += mat[i][next[i + 1]];
            cout << next;
            if (vis.find(next) != vis.end())
            {
                cout << next;
                continue;
            }
            max_heap.push(next);
            vis.insert(next);
        }
    }
    // while (!max_heap.empty())
    // {
    //     cout << max_heap.top();
    //     max_heap.pop();
    // }
    return -1;
}
void solve()
{
    vector<vector<int>> vec{{1, 3, 11}, {2, 4, 6}};
    cout << kthSmallest(vec, 5);
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
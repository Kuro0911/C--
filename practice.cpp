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
class Solution
{
public:
    vector<vector<int>> getSkyline(vector<vector<int>> &buildings)
    {
        vector<vector<int>> ans;
        priority_queue<pair<int, int>> max_heap;
        int i = 0, len = buildings.size();
        int curr_x, curr_h;
        while (i < len || !max_heap.empty())
        {
            if (max_heap.empty() || i < len && buildings[i][0] <= max_heap.top().second)
            {
                curr_x = buildings[i][0];
                while (i < len && curr_x == buildings[i][0])
                {
                    max_heap.emplace(buildings[i][2], buildings[i][1]);
                    i++;
                }
            }
            else
            {
                curr_x = max_heap.top().second;
                while (!max_heap.empty() && curr_x >= max_heap.top().second)
                {
                    max_heap.pop();
                }
            }
            curr_h = (max_heap.empty() ? 0 : max_heap.top().first);
            if (ans.empty() || curr_h != ans.back()[1])
            {
                ans.push_back({curr_x, curr_h});
            }
        }
        return ans;
    }
};
void solve()
{
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
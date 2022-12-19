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
    int rectangleArea(vector<vector<int>> &rectangles)
    {
        int open = 0, close = 1;
        vector<vector<int>> events(rectangles.size() * 2);
        int t = 0;
        for (auto x : rectangles)
        {
            events[t++] = {x[1], open, x[0], x[2]};
            events[t++] = {x[3], close, x[0], x[2]};
        }
        sort(events.begin(), events.end());
        vector<vector<int>> act;
        int curr_Y = events[0][0];
        long ans = 0;
        for (auto x : events)
        {
            int y = x[0], typ = x[1], x1 = x[2], x2 = x[3];
            int q = 0;
            int cur = -1;
            for (auto t : act)
            {
                cur = max(cur, t[0]);
                q += t[1] - cur > 0 ? t[1] - cur : 0;
                cur = max(cur, t[1]);
            }
            ans += q * (y - curr_Y);

            if (typ == open)
            {
                act.push_back({x1, x2});
                sort(act.begin(), act.end());
            }
            else
            {
                for (int i = 0; i < act.size(); i++)
                {
                    if (act[i][0] == x1 and act[i][1] == x2)
                    {
                        act.erase(act.begin() + i);
                        break;
                    }
                }
            }
            curr_Y = y;
        }
        ans %= MOD;
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
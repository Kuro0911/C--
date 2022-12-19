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
    int snakesAndLadders(vector<vector<int>> &board)
    {
        int n = board.size();
        vector<int> bb;
        bool flag = n % 2 == 0 ? false : true;
        for (auto x : board)
        {
            if (flag)
            {
                reverse(x.begin(), x.end());
            }
            flag = !flag;
            for (auto y : x)
            {
                bb.push_back(y);
            }
        }
        reverse(bb.begin(), bb.end());
        int ans = 0;
        queue<int> q;
        q.push(1);
        set<int> vis;
        while (!q.empty())
        {
            int sz = q.size();
            ans++;
            for (int i = 0; i < sz; i++)
            {
                int temp = q.front();
                q.pop();
                int tot = min(n * n, temp + 6);
                if (vis.find(temp) != vis.end())
                {
                    continue;
                }
                vis.insert(temp);

                for (int i = temp + 1; i <= tot; i++)
                {
                    if (i == n * n or bb[i - 1] == n * n)
                    {
                        return ans;
                    }
                    if (bb[i - 1] == -1)
                    {
                        q.push(i);
                    }
                    else
                    {
                        if (bb[i - 1] != temp)
                        {
                            q.push(bb[i - 1]);
                        }
                    }
                }
            }
        }
        return -1;
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
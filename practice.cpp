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
int getWinner(vector<int> &arr, int k)
{
    vector<int> temp = arr;
    sort(begin(temp), end(temp), greater<int>());
    if (k >= arr.size())
    {
        return temp[0];
    }
    int ans = 0;
    deque<int> q(arr.begin(), arr.end());
    int x = q.front();
    while (!q.empty())
    {
        q.pop_front();
        while (q.front() <= x)
        {
            ans++;
            q.push_back(q.front());
            q.pop_front();
            if (ans == k)
            {
                return x;
            }
        }
        if (ans != k)
        {
            ans = 1;
            q.push_back(x);
            x = q.front();
        }
        else
        {
            break;
        }
        cout << x << " " << ans << endl;
    }
    return x;
}

void solve()
{
    vector<int> nums{2, 1, 3, 5, 4, 6, 7};
    cout << getWinner(nums, 3);
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
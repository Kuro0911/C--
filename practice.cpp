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
void helper(int pos, vector<int> nums, unordered_map<int, int> &mp)
{
    if (pos == nums.size() - 1)
    {
        return;
    }
    if (pos > nums.size() - 1)
    {
        return;
    };
    int f = INT_MIN;
    for (int i = 1; i <= nums[pos]; i++)
    {
        if (mp.find(pos + i) != mp.end() || pos + i > nums.size())
        {
            continue;
        }
        mp[pos + i] = mp[pos] + 1;
        f = max(f, pos + i);
    }
    helper(f, nums, mp);
    return;
}
int jump(vector<int> &nums)
{
    unordered_map<int, int> mp;
    mp[0] = 0;
    helper(0, nums, mp);
    for (auto x : mp)
    {
        cout << x.first << " : " << x.second << endl;
    }
    return 0;
}
void solve()
{
    vector<int> nums{2, 3, 1, 1, 4};
    cout << jump(nums);
    queue<int> q;
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
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
int helper(int st, int ed, vector<int> nums)
{
    if (st <= ed)
    {
        int md = (ed + st) / 2;
        if (md == 0)
        {
            if (nums[md] > nums[md] + 1)
                return md;
            else
                return -1;
        }
        if (md == nums.size() - 1)
        {
            if (nums[md] > nums[md] - 1)
                return md;
            else
                return -1;
        }
        if (nums[md] > nums[md - 1] && nums[md] > nums[md + 1])
        {
            return md;
        }
        if (nums[md] < nums[md - 1])
        {
            return helper(st, md - 1, nums);
        }
        if (nums[md] < nums[md + 1])
        {
            return helper(md + 1, ed, nums);
        }
    }
    return -1;
}
int findPeakElement(vector<int> &nums)
{
    return helper(0, nums.size() - 1, nums);
}
void solve()
{
    set<int> st;
    vector<int> vec{1, 2, 3, 1};
    cout << findPeakElement(vec);
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
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
    if (st == ed)
        return nums[st];
    int mid = (st + ed) / 2;
    int lsm = helper(st, mid, nums);
    int rsm = helper(mid + 1, ed, nums);
    int sm = 0, lCS = INT_MIN, rCS = INT_MIN;
    for (int i = mid; i <= ed; i++)
    {
        sm += nums[i];
        rCS = max(sm, rCS);
    }
    sm = 0;
    for (int i = mid - 1; i >= st; i--)
    {
        sm += nums[i];
        lCS = max(sm, lCS);
    }
    int ans = max(lsm, rsm);
    return max(lCS + rCS, ans);
}
int maxSubArray(vector<int> &nums)
{
    return helper(0, nums.size() - 1, nums);
}
int Kadnae(vector<int> &nums)
{
    int sm = 0, ans = 0;
    for (auto x : nums)
    {
        if (sm + x > 0)
        {
            sm += x;
        }
        else
        {
            sm = 0;
        }
        ans = max(sm, ans);
    }
    return ans;
}
void solve()
{
    vector<int> temp(9);
    for (auto &x : temp)
    {
        cin >> x;
    }
    cout << maxSubArray(temp);
}

signed main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

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
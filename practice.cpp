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
void helper(vector<int> nums, vector<int> temp, int &ans)
{
    cout << temp;
    int sz = temp.size();
    if (nums.size() == 0)
    {
        ans = max(ans, sz);
        return;
    }
    int x = nums[0];
    nums.erase(nums.begin());
    if (sz == 0 || temp[sz - 1] < x)
    {
        temp.push_back(x);
        ans = max(ans, sz);
        helper(nums, temp, ans);
        temp.pop_back();
    };
    helper(nums, temp, ans);
    return;
}
int lengthOfLIS(vector<int> &nums)
{
    int ans = 0;
    vector<int> temp;
    helper(nums, temp, ans);
    return ans;
}
void solve()
{
    vector<int> nums{7, 7, 7, 7, 7, 7};
    cout << lengthOfLIS(nums);
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
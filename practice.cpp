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
    vector<int> nums1;

public:
    Solution()
    {
        int n;
        cin >> n;

        vector<int> temp(n);
        for (auto &x : temp)
        {
            cin >> x;
        }
        cout << temp;
        nums1 = temp;
    }
    bool check(vector<int> nums)
    {
        if (nums.size() < 3)
        {
            return false;
        }
        int df = nums[1] - nums[0];
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i + 1] - nums[i] != df)
            {
                return false;
            }
        }
        return true;
    }
    void helper(vector<int> temp, vector<int> nums, set<vector<int>> &ans)
    {
        if (check(temp))
        {
            ans.insert(temp);
        }
        if (nums.size() == 0)
        {
            return;
        }
        int x = nums[0];
        nums.erase(nums.begin());
        temp.push_back(x);
        helper(temp, nums, ans);
        temp.pop_back();
        helper(temp, nums, ans);
    };
    int numberOfArithmeticSlices()
    {
        vector<int> temp;
        set<vector<int>> ans;
        helper(temp, nums1, ans);

        return ans.size();
    }
};
void solve()
{
    Solution x;
    cout << x.numberOfArithmeticSlices();
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
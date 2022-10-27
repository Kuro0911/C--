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
    bool check(vector<int> nums, int st, int ed)
    {
        int sz = (ed - st) + 1;
        if (sz == 2)
        {
            for (int i = st; i < ed; i++)
            {
                if (nums[i] != nums[i + 1])
                {
                    return false;
                }
            }
            return true;
        }
        else if (sz == 3)
        {
            bool flag1 = true, flag2 = true;
            for (int i = st; i < ed; i++)
            {
                if (nums[i] != nums[i + 1])
                {
                    flag1 = false;
                    break;
                }
            }
            for (int i = st; i < ed; i++)
            {
                if (nums[i] != nums[i + 1] - 1)
                {
                    flag2 = false;
                    break;
                }
            }
            return flag1 or flag2;
        }
        return false;
    }
    bool helper(int st, int ed, vector<int> nums)
    {
        if (st >= nums.size())
        {
            return true;
        }
        for (int i = st; i <= ed; i++)
        {
            if (check(nums, st, i))
            {
                return helper(i + 1, ed, nums);
            }
        }
        return false;
    }
    bool validPartition(vector<int> &nums)
    {
        return helper(0, nums.size() - 1, nums);
    }
};
void solve()
{
    string s = "0.1.2.3";
    for (int i = 0; i < 3; i++)
    {
        cout << s.substr(i + 1) << endl;
    }
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
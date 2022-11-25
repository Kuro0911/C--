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
    int n;
    vector<int> nums;

public:
    Solution()
    {
        cin >> n;
        vector<int> x(n);
        for (int i = 0; i < n; i++)
        {
            cin >> x[i];
        };
        nums = x;
    }

    bool find132pattern()
    {
        stack<int> st;
        for (int i = 0; i < nums.size(); i++)
        {
            if (st.empty())
            {
                st.push(nums[i]);
            }
            else
            {
                if (st.top() < nums[i])
                {
                    if (st.size() == 1)
                    {
                        st.push(nums[i]);
                    }
                }
                else
                {
                    if (st.size() == 2)
                    {
                        int x = st.top();
                        st.pop();
                        if (st.top() < nums[i])
                        {
                            return true;
                        }
                        else
                        {
                            st.pop();
                            st.push(nums[i]);
                        }
                    }
                    else
                    {
                        while (!st.empty() and st.top() > nums[i])
                        {
                            st.pop();
                        }
                        st.push(nums[i]);
                    }
                }
            }
        }

        while (!st.empty())
        {
            cout << st.top() << endl;
            st.pop();
        }
        return st.size() == 3;
    }
};
void solve()
{
    Solution x;
    cout << x.find132pattern();
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
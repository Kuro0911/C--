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

void solve()
{
    vector<int> nums{1, 6, 1, 5, 1, 4, 7};
    sort(nums.begin(), nums.end());
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    int mid = nums.size() / 2;
    for (int i = 0; i < mid; i++)
    {
        max_heap.push(nums[i]);
    }
    cout << endl;
    for (int i = mid; i < nums.size(); i++)
    {
        min_heap.push(nums[i]);
    }
    vector<int> ans;
    bool flag = true;
    for (int i = 0; i < nums.size(); i++)
    {
        if (flag)
        {
            ans.push_back(max_heap.top());
            max_heap.pop();
        }
        else
        {
            ans.push_back(min_heap.top());
            min_heap.pop();
        }
        flag = !flag;
    }
    cout << min_heap.size() << endl;
    cout << ans;
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
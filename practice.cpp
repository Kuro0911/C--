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
void helper(vector<int> cd, int target, int curr_sm, vector<int> temp, set<vector<int>> &ans)
{
    if (curr_sm == target)
    {
        sort(temp.begin(), temp.end());
        ans.insert(temp);
        return;
    }
    if (curr_sm > target)
    {
        return;
    }
    if (cd.size() == 0)
    {
        return;
    }
    int x = cd[0];
    temp.push_back(x);
    cd.erase(cd.begin());
    helper(cd, target, curr_sm + x, temp, ans);
    temp.pop_back();
    helper(cd, target, curr_sm, temp, ans);
    return;
}
vector<vector<int>> combinationSum2(vector<int> &cd, int target)
{
    int sm = 0;
    for (auto x : cd)
        sm += x;
    if (sm < target)
    {
        return {{}};
    }
    set<vector<int>> ans;
    vector<int> temp;
    helper(cd, target, 0, temp, ans);
    vector<vector<int>> res = {ans.begin(), ans.end()};
    return res;
}

void solve()
{
    int target, n;
    cin >> n >> target;
    vector<int> cd(n);
    for (auto &x : cd)
    {
        cin >> x;
    }
    vector<vector<int>> ans = combinationSum2(cd, target);
    for (auto x : ans)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << endl;
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
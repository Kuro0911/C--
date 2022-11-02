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

int getSum(string s)
{
    int ans = 0;
    for (auto x : s)
    {
        ans += x - '0';
    }
    return ans;
}
int helper(string a, string b)
{
    int sum_A = getSum(a);
    int sum_B = getSum(b);
    if (sum_A > sum_B)
    {
        swap(a, b);
        swap(sum_A, sum_B);
    }
    if (sum_A == sum_B)
    {
        return 0;
    }
    int ans = INT_MIN;
    char x = a[0];
    for (int i = x - '0' + 1; i <= 9; i++)
    {
        int new_num = i + '0';
        ans = min(helper(a, b) + 1, ans);
        a[0] = x;
    }
    x = b[0];
    for (int i = 0; i <= x - '0' + 1; i++)
    {
        int new_num = i + '0';
        ans = min(helper(a, b) + 1, ans);
        b[0] = x;
    }
    return ans;
}
void solve()
{
    string str;
    cin >> str;
    int n = str.size() / 2;
    string a = str.substr(0, n), b = str.substr(n);
    int ans = helper(a, b);
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
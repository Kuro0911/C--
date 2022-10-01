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
int xorAllNums(vector<int> &nums1, vector<int> &nums2)
{
    int ans = 0;
    vector<int> res;
    for (int i = 0; i < nums1.size(); i++)
    {
        ans = ans ^ nums1[i];
    }
    res.push_back(ans);
    ans = 0;
    for (int j = 0; j < nums2.size(); j++)
    {
        ans = ans ^ nums2[j];
    }
    cout << res[0] << " " << ans;
    return ans xor res[0];
}
void solve()
{
    int x = 1;
    int y = 2;
    int a = 3;
    int b = 4;

    
    int ans2 = (a ^ x) ^ (a ^ y) ^ (b ^ x) ^ (b ^ y);
    cout << ans << " " << ans2;
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
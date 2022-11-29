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
    int n;
    cin >> n;
    vector<int> vec(n);
    for (auto &x : vec)
    {
        cin >> x;
    }
    stack<pair<int, int>> st;
    vector<int> tr(vec.size()), tl(vec.size());
    for (int i = n - 1; i >= 0; i--)
    {
        int ans = 0;
        while (!st.empty() and st.top().first >= vec[i])
        {
            ans += st.top().second + 1;
            st.pop();
        }
        tr[i] = ans;
        st.push({vec[i], ans});
    }
    while (!st.empty())
    {
        st.pop();
    }
    for (int i = 0; i < n; i++)
    {
        int ans = 0;
        while (!st.empty() and st.top().first >= vec[i])
        {
            ans += st.top().second + 1;
            st.pop();
        }
        tl[i] = ans;
        st.push({vec[i], ans});
    }

    cout << "TO RIGHT => " << tr;
    cout << "TO LEFT => " << tl;
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int arr = vec[i] * (tl[i] + tr[i] + 1);
        res = max(arr, res);
    }
    cout << res;
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
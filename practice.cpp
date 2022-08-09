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
    int n, sm;
    cin >> n >> sm;
    vector<int> vec(n);
    for (auto &a : vec)
    {
        cin >> a;
    }
    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++)
    {
        mp[vec[i]].push_back(i);
    }
    for (int i = 0; i < n; i++)
    {
        int rem = sm - vec[i];
        if (mp.find(rem) != mp.end())
        {
            for (auto x : mp[rem])
            {
                set<int> st;
                st.insert(i);
                st.insert(x);
                if (sz(st) == 2)
                {
                    for (auto s : st)
                    {
                        cout << s + 1 << tb;
                    }
                    exit(0);
                }
            }
        }
    }
    cout << "IMPOSSIBLE";
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
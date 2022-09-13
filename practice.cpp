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

vector<int> helper(int T, vector<int> N, vector<int> K, vector<vector<int>> C)
{
    vector<int> ans;
    for (int i = 0; i < T; i++)
    {
        if (N[i] == 1)
        {
            if (C[i][0] >= K[i])
            {
                ans.push_back(1);
            }
            else
            {
                ans.push_back(0);
            }
        }
        else
        {
            sort(C[i].begin(), C[i].end(), greater<int>());
            int x = 0, res = 0;
            while (K[i] > 0)
            {
                K[i] -= C[i][x];
                x = !x;
                res++;
            }
            ans.push_back(res);
        }
    }
    return ans;
}
void solve()
{
    int T;
    vector<int> N(100), K(100);
    vector<vector<int>> C(1000);
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int x, y;
        cin >> x >> y;
        N[i] = x;
        K[i] = y;
        for (int j = 0; j < x; j++)
        {
            int z;
            cin >> z;
            C[i].push_back(z);
        }
    }

    vector<int> res = helper(T, N, K, C);
    for (auto x : res)
    {
        cout << x << " ";
    }
    cout << endl;
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
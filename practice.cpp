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

// #####################################################

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

// #####################################################
vector<int> sol(vector<vector<int>> A, vector<vector<int>> B)
{
    map<int, map<int, int>> mp;
    long long tot = 0;
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = A[i][0]; j <= A[i][1]; j++)
        {
            mp[j][A[i][2]]++;
            tot++;
        }
    }
    for (auto m : mp)
    {
        cout << "i : " << m.first << endl;
        for (auto x : m.second)
        {
            cout << x.first << " " << x.second << endl;
        }
    }
    vector<long long> res;
    for (int i = 0; i < B.size(); i++)
    {
        int pos = B[i][0], st = B[i][1];
        map<int, int> new_mp;
        for (auto x : mp[pos])
        {
            if (x.first < st)
            {
                tot -= x.second;
            }
            else
            {
                new_mp[x.first] = x.second;
            }
        }
        mp[pos] = new_mp;
        res.push_back(tot);
    }
    return res;
}

void solve()
{
    vector<int> temp = sol({{1, 3, 7}, {2, 5, 4}, {4, 8, 6}}, {{3, 5}, {5, 8}});
    cout << " res : " << temp;
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
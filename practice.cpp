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
int getCost(int st, vector<int> gas, vector<int> cost)
{
    int sz = gas.size();
    for (int i = 0; i < sz; i++)
    {
        gas.push_back(gas[i]);
    }
    int g = 0;
    cout << " st : " << st << endl;
    for (int i = st; i < st + sz; i++)
    {
        cout << g << "\n";
        g += gas[st];
        g -= cost[abs(sz - i) + 1];
        if (g < 0)
            return -1;
    }
    return st;
}
int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
    map<int, int> mp;
    for (int i = 0; i < gas.size(); i++)
    {
        mp[-gas[i]] = i;
    }
    int ans = -1;
    for (auto x : mp)
    {
        ans = getCost(x.second, gas, cost);
        if (ans != -1)
            return x.second;
    }
    return ans;
}
void solve()
{
    vector<int> gas{1, 2, 3, 4, 5};
    vector<int> cost{3, 4, 5, 1, 2};
    cout << canCompleteCircuit(gas, cost);
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
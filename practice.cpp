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
unordered_map<string, vector<string>> first;

vector<string> helper(vector<vector<string>> vec, unordered_map<string, vector<vector<string>>> mp)
{
    vector<string> res;
    for (auto x : vec)
    {
        string curr = x[0];
        if (mp.find(curr) == mp.end())
        {
            res.push_back(curr);
        }
        else
        {
            if (first.find(curr) == first.end())
            {
                first[curr] = helper(mp[curr], mp);
            }
            for (auto f : first[curr])
                res.push_back(f);
        }
    }
    return res;
}
void solve()
{
    unordered_map<string, vector<vector<string>>> mp;
    mp["S"] = {{"T", "E'"}};
    mp["E'"] = {{"+", "T", "E'"}, {"~"}};
    mp["T"] = {{"F", "T'"}};
    mp["T'"] = {{"*", "F", "T'"}, {"~"}};
    mp["F"] = {{"(", "E", ")"},
               {"id"}};
    for (auto x : mp)
    {
        first[x.first] = helper(mp[x.first], mp);
    }
    for (auto x : first)
    {
        cout << "FIRST[" << x.first << "] : ";
        for (auto y : x.second)
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
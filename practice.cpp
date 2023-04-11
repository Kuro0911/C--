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
void print(unordered_map<string, vector<vector<string>>> mp)
{
    for (auto x : mp)
    {
        cout << x.first << " : ";
        for (auto y : x.second)
        {
            for (auto z : y)
            {
                cout << z;
            }
            cout << " | ";
        }
        cout << endl;
    }
}

// left recursion

void remove_lr(unordered_map<string, vector<vector<string>>> &mp)
{
    for (auto x : mp)
    {
        for (auto y : x.second)
        {
            if (y[0] == x.first)
            {
                vector<vector<string>> temp;
                vector<string> beta = x.second[1];
                beta.push_back(x.first + "`");
                temp.push_back(beta);
                mp[x.first + "`"] = {beta};

                vector<string> alpha = x.second[0];
                alpha.erase(alpha.begin());
                alpha.push_back(x.first + "`");
                mp[x.first].clear();
                mp[x.first].push_back(alpha);
                mp[x.first].push_back({"~"});
            }
        }
    }
};

void solve()
{
    TopDownParser obj;
    obj.removeLeftRecursion();
    obj.displayProduction();
    cout << "----------------" << endl;
    // obj.seeNonTerminals();
    // cout << "----------------" << endl;
    obj.calculateFirst();
    // obj.displayFirst();
    // cout << "----------------" << endl;
    obj.calcuateFollow();
    // obj.displayFollow();
    obj.createTable();
    obj.displayTable();
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
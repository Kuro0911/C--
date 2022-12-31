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

void solve()
{
    string x;
    cin >> x;
    int i = 0, j = 0;
    vector<string> strs;
    while (i < x.size() and j < x.size())
    {
        i = min(x.find_first_of("/", i), x.size());
        i++;
        if (i >= x.size())
        {
            break;
        }
        j = min(x.find_first_of("/", i), x.size());
        string temp = "";
        for (int k = i; k < j; k++)
        {
            temp.push_back(x[k]);
        }
        strs.push_back(temp);
        i = j;
        // j = x.find_first_of("/", i + 1);
        // for (int k = i; k <= j; k++)
        // {
        //     cout << x[k];
        // }
    }
    for(auto s : strs){
        cout << "[ " << s << " ]";
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
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

int helper(int arr[], int len, int n)
{
    int ans = 0;
    for (int i = n - 1; i < len; i += n)
    {
        ans += arr[i];
    }
    return ans;
}
void solve()
{
    string pattern, s;
    cin >> pattern >> s;
    map<char, string> mp;
    vector<string> vec;
    stringstream str(s);
    string word;
    while (str >> word)
    {
        vec.push_back(word);
    }
    cout << vec.size();
    // if (vec.size() != pattern.size())
    // {
    //     cout << "no";
    // }
    // for (int i = 0; i < pattern.size(); i++)
    // {
    //     if (mp.find(pattern[i]) != mp.end())
    //     {
    //         if (mp[pattern[i]] != vec[i])
    //         {
    //             cout << "no";
    //         }
    //     }
    //     else
    //     {
    //         mp[pattern[i]] = vec[i];
    //     }
    // }
    // cout << "yea";
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
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

struct Json
{
    string keys;
    vector<Json> val;
    bool isKey;
};
void dfs(string s, vector<string> q, vector<string> &ans)
{
    return;
}
vector<string> helper(string text, int Q, vector<string> queries)
{
    vector<string> ans;
    stack<string> st;
    int ptr = 0;
    while (ptr < text.size())
    {
    }
    for (auto x : queries)
    {
        vector<string> q;
        string temp = "";
        for (int i = 0; i < x.size(); i++)
        {
            if (x[i] == '.')
            {
                q.push_back(temp);
                temp.clear();
            }
            else
            {
                temp += x[i];
            }
        }
        q.push_back(temp);
        dfs(text, q, ans);
    }

    return ans;
}

void solve()
{
    string s;
    cin >> s;
    int q;
    cin >> q;
    vector<string> queries(q);
    for (auto &x : queries)
    {
        cin >> x;
    };
    cout << helper(s, q, queries);
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
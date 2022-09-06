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
map<string, int> mp;
int getSm(string temp, vector<int> board)
{
    int sm = 0;
    for (auto x : temp)
    {
        sm += board[x - 'a'];
    }
    return sm;
}
void helper(string s, vector<int> board, int &ans)
{
    int n = s.size();
    for (int len = 1; len <= n; len++)
    {
        for (int i = 0; i <= n - len; i++)
        {
            int j = i + len - 1;
            string x = "";
            for (int k = i; k <= j; k++)
            {
                x += s[k];
            }
            if (mp.find(x) != mp.end())
            {
                if (mp[x] % x.size() == 0)
                {
                    ans++;
                }
            }
            else
            {
                int sm = mp[x] = getSm(x, board);
                if (sm % x.size() == 0)
                {
                    ans++;
                }
            }
        }
    }
    return;
}
int countSubstrings(string s)
{
    vector<int> board;
    board.push_back(1);
    board.push_back(1);
    int x = 2;
    for (int i = 2; i < 26; i += 3)
    {
        board.push_back(x);
        board.push_back(x);
        board.push_back(x);
        x++;
    }
    int ans = 0;
    helper(s, board, ans);
    return ans;
}
void solve()
{
    string s;
    cin >> s;
    cout << countSubstrings(s);
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
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
class Solution
{
public:
    int n, m;
    string convert(vector<vector<int>> board)
    {
        string str = "";
        for (auto x : board)
        {
            for (auto y : x)
            {
                str += to_string(y);
            }
        }
        return str;
    }
    vector<vector<int>> reset(string s)
    {
        vector<vector<int>> board(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                board[i][j] = s[0] - '0';
                s.erase(s.begin());
            }
        }
        return board;
    }
    int slidingPuzzle(vector<vector<int>> &board)
    {
        n = board.size();
        m = board[0].size();
        string root = convert(board);
        queue<string> q;
        set<string> st;
        q.push(root);
        st.insert(root);
        vector<vector<int>> test = reset(root);
        for (auto x : test)
        {
            for (auto y : x)
            {
                cout << y << " ";
            }
            cout << endl;
        }
        cout << endl
             << root << endl;
        return 0;
    }
};
void solve()
{
    vector<vector<int>> board{{1, 2, 3}, {4, 0, 5}};
    Solution x;
    cout << x.slidingPuzzle(board);
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
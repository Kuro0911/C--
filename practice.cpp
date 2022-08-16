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
void dfs(int i, int j, vector<vector<char>> &board, set<pair<int, int>> &path)
{
    if (path.empty())
        return;
    if (i >= board.size() || i < 0 || j > board[i].size() || j < 0)
    {
        return;
    }
    if (board[i][j] == 'O')
    {
        if (i == 0 || j == 0)
        {
            path.clear();
            return;
        }
        path.insert({i, j});
        dfs(i + 1, j, board, path);
        dfs(i - 1, j, board, path);
        dfs(i, j + 1, board, path);
        dfs(i, j + 1, board, path);
        return;
    }
    return;
};
void solve(vector<vector<char>> &board)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            if (board[i][j] == 0)
            {
                set<pair<int, int>> path;
                path.insert({i, j});
                dfs(i, j, board, path);
                if (!path.empty())
                {
                    cout << "yes\n";
                    for (auto x : path)
                    {
                        board[x.first][x.second] = 'X';
                    }
                }
            }
        }
    }
}
void solve()
{
    set<pii> st;
    st.insert({1, 2});
    st.insert({3, 4});
    st.insert({1, 2});
    st.insert({3, 1});
    st.insert({1, 3});
    for (auto &x : st)
    {
        cout << x.first;
    }
    st.clear();
}

signed main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    // cin >> t;
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
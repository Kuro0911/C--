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
set<pair<int, int>> vis;
void dfs(int i, int j, vector<vector<char>> &board, set<pair<int, int>> &path)
{
    if (path.empty())
    {
        cout << i << " " << j << endl;
        return;
    }
    if (path.find({i, j}) != path.end() && path.size() != 1)
    {
        return;
    }
    if (i < board.size() && i >= 0 && j < board[i].size() && j >= 0)
    {
        if (board[i][j] == 'O')
        {
            vis.insert({i, j});
            if (i == 0 || i == board.size() - 1 || j == 0 || j == board[i].size() - 1)
            {
                path.clear();
                return;
            }
            path.insert({i, j});
            dfs(i + 1, j, board, path);
            dfs(i - 1, j, board, path);
            dfs(i, j + 1, board, path);
            dfs(i, j - 1, board, path);
            return;
        }
    }
    return;
};
void solve1(vector<vector<char>> &board)
{
    for (int i = 1; i < board.size() - 1; i++)
    {
        for (int j = 1; j < board[i].size() - 1; j++)
        {
            if (board[i][j] == 'O' && vis.find({i, j}) == vis.end())
            {
                set<pair<int, int>> path;
                path.insert({i, j});
                dfs(i, j, board, path);
                for (auto x : path)
                {
                    cout << x;
                }

                if (!path.empty())
                {
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
    vector<vector<char>> board{
        {'O', 'O', 'O', 'O', 'X', 'X'}, {'O', 'O', 'O', 'O', 'O', 'O'}, {'O', 'X', 'O', 'X', 'O', 'O'}, {'O', 'X', 'O', 'O', 'X', 'O'}, {'O', 'X', 'O', 'X', 'O', 'O'}, {'O', 'X', 'O', 'O', 'O', 'O'}};
    solve1(board);
    for (auto x : board)
    {
        cout << x;
    }
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
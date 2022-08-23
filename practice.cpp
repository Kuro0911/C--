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
void update(int i, int j, vector<vector<int>> &board)
{
    vector<pair<int, int>> dir{{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {-1, -1}, {-1, 1}, {1, -1}};
    int alive = 0;
    for (auto x : dir)
    {
        int a = i + x.first, b = j + x.second;
        if(a < 0 || a > board.size() || b < 0 || b > board[a].size()){
            continue;
        }
        if (board[i + x.first][j + x.second] == 1)
        {
            alive++;
        }
    }
    if (board[i][j] == 0 && alive == 3)
        board[i][j] = 1;
    else if (board[i][j] == 1 && alive < 2 || alive > 3)
        board[i][j] = 0;
}
void gameOfLife(vector<vector<int>> &board)
{
    vector<vector<int>> ans = board;
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); i++)
        {
            update(i, j, board);
        }
    }
}
void solve()
{
    int x = sqrt(12);
    cout << x;
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
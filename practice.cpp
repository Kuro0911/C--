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
    vector<pair<int, int>> dir{{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
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
    pair<int, int> findZero(vector<vector<int>> &board)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == 0)
                {
                    return {i, j};
                }
            }
        }
        return {-1, -1};
    }
    bool check(string s)
    {
        for (int i = 1; i < s.size(); i++)
        {
            int curr = s[i] - '0';
            int prev = s[i - 1] - '0';
            if (curr != prev + 1)
            {
                if (curr == 0)
                {
                    if (i != s.size() - 1)
                        return false;
                    else
                        return true;
                }
                return false;
            }
        }
        return false;
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
        int ans = 0;
        while (!q.empty())
        {
            int sz = q.size();
            ans++;
            for (int i = 0; i < sz; i++)
            {
                vector<vector<int>> temp = reset(q.front());
                pair<int, int> z = findZero(temp);
                for (auto d : dir)
                {
                    int x = d.first + z.first;
                    int y = d.second + z.second;
                    if (x >= 0 and x < n and y >= 0 and y < m)
                    {
                        vector<vector<int>> new_temp = temp;
                        swap(new_temp[x][y], new_temp[z.first][z.second]);
                        string new_str = convert(new_temp);
                        if (check(new_str))
                        {
                            return ans;
                        }
                        if (st.find(new_str) == st.end())
                        {
                            q.push(new_str);
                            st.insert(new_str);
                        }
                    }
                }
                q.pop();
            }
        }
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
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

class Solution
{
public:
    bool valid(string s)
    {
        stack<char> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ')')
            {
                bool flag = false;
                while (!st.empty())
                {
                    if (st.top() == '(')
                    {
                        flag = true;
                        st.pop();
                        break;
                    }
                    st.pop();
                }
                if (!flag)
                    return false;
            }
            else if (s[i] == '(')
            {
                st.push(s[i]);
            }
        }
        return st.empty();
    }
    vector<string> removeInvalidParentheses(string s)
    {
        queue<string> q;
        q.push(s);
        set<string> vis;
        while (!q.empty())
        {
            int sz = q.size();
            vector<string> lvl;
            for (int i = 0; i < sz; i++)
            {
                string temp = q.front();
                q.pop();
                if (valid(temp))
                {
                    lvl.push_back(temp);
                }
                for (int k = 0; k < temp.size(); k++)
                {
                    string new_str = temp.substr(0, k) + temp.substr(k + 1);
                    if (vis.find(new_str) == vis.end())
                    {
                        q.push(new_str);
                        vis.insert(new_str);
                    }
                }
            }
            if (lvl.size() != 0)
            {
                return lvl;
            }
        }
        return {""};
    }
};
void solve()
{
    Solution x;
    cout << x.removeInvalidParentheses("(()())()(()())(aa)(a(a))a");
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
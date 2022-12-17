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
    long helper(long num1, long num2, string opp)
    {
        switch (opp[0])
        {
        case '/':
            return num1 / num2;
            break;
        case '-':
            return num1 - num2;
            break;
        case '+':
            return num1 + num2;
            break;
        case '*':
            return num1 * num2;
            break;
        }
        return 0;
    }
    int evalRPN(vector<string> &tokens)
    {
        stack<long> st;
        for (auto x : tokens)
        {
            if (x == "+" or x == "-" or x == "*" or x == "/")
            {
                long num2 = st.top();
                st.pop();
                long num1 = st.top();
                st.pop();
                st.push(helper(num1, num2, x));
            }
            else
            {
                st.push(stol(x));
            }
        }
        return st.top();
    }
};
void solve()
{
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
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

int opp(char op, int a, int b)
{
    int res;
    if (op == '+')
    {
        res = a + b;
    }
    else if (op == '-')
    {
        res = a - b;
    }
    else if (op == '*')
    {
        res = a * b;
    }
    else if (op == '/')
    {
        res = a / b;
    }
    return res;
}
void solve()
{
    string s;
    cin >> s;
    stack<string> st;
    int i = 0;
    while (i < s.size())
    {
        if (s[i] == '*' || s[i] == '/')
        {
            cout << "yes";
            int res = opp(s[i], stoi(st.top()), s[i + 1] - '0');
            st.pop();
            i += 2;
            st.push(to_string(res));
        }
        else if (s[i] == '+' || s[i] == '-')
        {
            string temp = "";
            temp += s[i];
            st.push(temp);
            i++;
        }
        else
        {
            int x = s[i] - '0';
            st.push(to_string(x));
            i++;
        }
    }
    int ans = 0;
    string x;
    while (!st.empty())
    {
        x += st.top();
        cout << st.top() << endl;
        st.pop();
    }
    i = 0;
    while (i < s.size())
    {
        if (s[i] == '+' || s[i] == '-')
        {
            int res = opp(s[i], stoi(st.top()), s[i + 1] - '0');
            st.pop();
            i += 2;
            st.push(to_string(res));
        }
        else
        {
            int x = s[i] - '0';
            st.push(to_string(x));
            i++;
        }
    }
    cout << st.top() << endl;
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
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
int printStack(stack<int> Stack)
{
    while (!Stack.empty())
    {
        cout << Stack.top() << " ";
        Stack.pop();
    }
    return 0;
}
stack<int> induct(stack<int> st, int val)
{
    if (st.empty() || st.top() <= val)
    {
        st.push(val);
        return st;
    }
    int Last = st.top();
    st.pop();
    st = induct(st, val);
    st.push(Last);
    return st;
}
stack<int> Sort(stack<int> st)
{
    if (st.empty())
    {
        return st;
    }
    int last = st.top();
    st.pop();
    st = Sort(st);
    return induct(st, last);
}

void solve()
{
    stack<int> st;

    st.push(1);
    st.push(23);
    st.push(42);
    st.push(2);

    st = Sort(st);
    printStack(st);
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
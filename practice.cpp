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

int check(string s)
{
    if (s.size() < 4)
    {
        return 0;
    }
    set<char> st;
    st.insert('e');
    st.insert('i');
    st.insert('o');
    st.insert('u');
    int ans = 1;
    for (int i = 1; i < s.size(); i++)
    {

        if (s[i - 1] > s[i])
        {
            break;
        }
        if (st.find(s[i]) != st.end())
        {
            st.erase(s[i]);
        }
        ans++;
    }
    cout << s << " " << ans << " " << st.size() << endl;
    return st.size() == 0 ? ans : 0;
}
int longestBeautifulSubstring(string s)
{
    int ans = 0;
    if (s.size() < 5)
    {
        return ans;
    }
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'a')
        {
            ans = max(ans, check(s.substr(i)));
        }
    }
    return ans;
}
void solve()
{
    string s;
    cin >> s;
    cout << longestBeautifulSubstring(s);
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
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
int largestRectangleArea(vector<int> &heights)
{
    stack<pair<int, int>> st;
    int i = 0, ans = INT_MIN;
    int n = heights.size();
    for (int i = 0; i < n; i++)
    {
        int start = i;
        while (!st.empty() && st.top().second > heights[i])
        {
            int ind = st.top().first;
            int w = i - ind;
            int h = st.top().second;
            st.pop();
            ans = max(ans, h * w);
            start = ind;
        }
        st.push({start, heights[i]});
    }

    while (!st.empty())
    {
        ans = max(ans, st.top().second * (n - st.top().first));
        st.pop();
    }
    return ans;
}
void solve()
{
    vector<int> temp{9, 3, 15, 20};
    cout << temp[temp.size() / 2];
    stack<int> st;
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
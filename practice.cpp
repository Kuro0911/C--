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
    int takeCharacters(string s, int k)
    {
        map<int, vector<int>> mp1, mp2;
        vector<int> temp1(3, 0), temp2(3, 0);
        for (int i = 0; i < s.size(); i++)
        {
            temp1[s[i] - 'a']++;
            mp1[i] = temp1;
        }
        for (int i = s.size() - 1; i >= 0; i--)
        {
            temp2[s[i] - 'a']++;
            mp2[i] = temp2;
        }
        for (auto x : mp1)
        {
            cout << x.first << " : ";
            for (auto y : x.second)
            {
                cout << y << " ";
            }
            cout << endl;
        }
        cout << endl;
        for (auto x : mp2)
        {
            cout << x.first << " : ";
            for (auto y : x.second)
            {
                cout << y << " ";
            }
            cout << endl;
        }
        int ans = INT_MAX;
        cout << endl;

        for (int i = 0; i < s.size(); i++)
        {
            for (int j = 0; j < s.size(); j++)
            {
                int a = mp1[i][0] + mp2[i][0];
                int b = mp1[i][1] + mp2[i][1];
                int c = mp1[i][2] + mp2[i][2];
                cout << mp1[i] << " " << mp2[j];
                if (a >= k and b >= k and c >= k)
                {
                    ans = min(ans, i + j + 2);
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
void solve()
{
    Solution x;
    cout << x.takeCharacters("aabaaaacaabc", 2);
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
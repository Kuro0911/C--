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
    int getConsec(string ans)
    {
        int res = 0, curr = 1;
        for (int i = 0; i < ans.size() - 1; i++)
        {
            if (ans[i] != ans[i + 1])
            {
                res = max(res, curr);
                curr = 1;
            }
            else
            {
                curr++;
            }
        }
        return curr;
    }
    int maxConsecutiveAnswers(string answerKey, int k)
    {
        vector<int> t_pos, f_pos;
        for (int i = 0; i < answerKey.size(); i++)
        {
            if (answerKey[i] == 'T')
            {
                t_pos.push_back(i);
            }
            else
            {
                f_pos.push_back(i);
            }
        }
        int res = 0, f_sz = f_pos.size() - 1, t_sz = t_pos.size() - 1;

        cout << "false pos :";
        for (auto x : f_pos)
        {
            cout << x << " ";
        }
        cout << endl;

        // true case
        int l = 0, r = min(k, f_sz);
        while (r < f_pos.size())
        {
            cout << l << " " << r << endl;
            string temp = answerKey;
            for (int i = l; i <= r; i++)
            {
                temp[i] = 'T';
            }
            res = max(getConsec(temp), res);
            l++;
            r++;
        }

        cout << "true pos :";
        for (auto x : t_pos)
        {
            cout << x << " ";
        }
        cout << endl;

        // false case
        l = 0, r = min(k, t_sz);
        while (r < t_pos.size())
        {
            cout << l << " " << r << endl;
            string temp = answerKey;
            for (int i = l; i <= r; i++)
            {
                temp[i] = 'F';
            }
            res = max(getConsec(temp), res);
            l++;
            r++;
        }
        return res;
    }
};
void solve()
{
    cout << "test" << endl;
}

signed main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen("[input].in", "r", stdin);
    // freopen("[output].out", "w", stdout);

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
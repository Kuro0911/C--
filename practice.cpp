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
// vector<int> Solve(int N, vector<int> A, int K, vector<int> h)
// {
//     vector<int> ans;
//     sort(A.begin(), A.end());
//     for (int i = 0; i < K; i++)
//     {
//         int curr = h[i];
//         int st = 0, ed = N - 1;
//         int res = 0;
//         while (st <= ed)
//         {
//             int md = st + (ed - st) / 2;
//             if (A[md] > curr)
//             {
//                 res += (ed - md) + 1;
//                 ed = md - 1;
//             }
//             else
//             {
//                 st = md + 1;
//             }
//         }
//         ans.push_back(res);
//     }
//     return ans;
// }
int N, Q;
int A[10000], L[10000], R[10000];

int Solve(string str)
{
    int n = str.size();
    int st = 0, ed = 0;
    int mxD = 0;
    unordered_set<char> chars, distinctChars;

    while (ed < n)
    {
        chars.insert(str[ed]);
        distinctChars.insert(str[ed]);

        if (chars.size() == distinctChars.size())
        {
            int sz = chars.size();
            mxD = std::max(mxD, sz);
            ed++;
        }
        else
        {
            chars.erase(str[st]);
            distinctChars.clear();
            st++;
            ed = st;
        }
    }
    return mxD;
}

void solve()
{
    string s;
    cin >> s;
    cout << Solve("abcda");
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
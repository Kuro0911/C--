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
vector<long long> Solution(vector<vector<int>> &A, vector<vector<int>> &B)
{
    long long tot = 0;
    map<int, vector<vector<int>>> mp;
    for (int i = 0; i < A.size(); i++)
    {
        int st = A[i][0], ed = A[i][1], str = A[i][2];
        tot += ed - st + 1;
        mp[str].push_back({st, ed});
    }
    vector<long long> res;
    for (int i = 0; i < B.size(); i++)
    {
        int pos = B[i][0], str = B[i][1];
        for (auto x : mp)
        {
            if (x.first < str)
            {
                vector<vector<int>> temp;
                for (int k = 0; k < x.second.size(); k++)
                {
                    if (x.second[k][0] <= pos and x.second[k][1] >= pos)
                    {
                        tot--;
                        vector<int> new_val = divide(x.second[k][0], x.second[k][1], pos);
                        if (pos == x.second[k][0])
                        {
                            x.second[k][0] = pos + 1;
                            if (x.second[k][1] >= x.second[k][0])
                                temp.push_back({x.second[k]});
                        }
                        else if (pos == x.second[k][1])
                        {
                            x.second[k][1] = pos - 1;
                            if (x.second[k][1] >= x.second[k][0])
                                temp.push_back({x.second[k]});
                        }
                        else
                        {
                            temp.push_back({x.second[k][0], pos - 1});
                            temp.push_back({pos + 1, x.second[k][1]});
                        }
                    }
                    else
                    {
                        temp.push_back(x.second[k]);
                    }
                }
                mp[x.first] = temp;
            }
        }
        res.push_back(tot);
    }
    return res;
}

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
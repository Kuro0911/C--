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
void helper(vector<int> &players, vector<int> &trainers, int &ans)
{
    if (players.size() == 0)
    {
        return;
    }
    cout << players;
    cout << trainers;
    if (players[0] < trainers[0] and trainers.size() > 0)
    {
        players.erase(players.begin());
        trainers.erase(trainers.begin());
        ans++;
        helper(players, trainers, ans);
    }
    else
    {
        while (trainers.size() > 0 and players[0] < trainers[0])
        {
            trainers.erase(trainers.begin());
        }
        if (trainers.size() == 0)
        {
            return;
        }
        ans++;
        players.erase(players.begin());
        helper(players, trainers, ans);
    }
}
int matchPlayersAndTrainers(vector<int> &players, vector<int> &trainers)
{
    sort(players.begin(), players.end());
    sort(trainers.begin(), trainers.end());
    int ans = 0;
    helper(players, trainers, ans);
    return ans;
}

void solve()
{
    vector<int> temp{1, 2, 3, 4, 5};
    vector<int> temp1{2, 3, 4, 5, 1};
    cout << matchPlayersAndTrainers(temp, temp1) << endl;
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
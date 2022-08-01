/*
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

int getMin(vector<int> vec, int st, int n)
{
    int minInd = st;
    int mn = INT_MAX;
    for (int i = st; i < n; i++)
    {
        if (vec[i] < mn)
        {
            mn = vec[i];
            minInd = i;
        }
    }
    return minInd;
}
void reverSort(vector<int> &vec, int n)
{
    int cost = 0;
    int st = 0;
    while (st < n)
    {
        int ed = getMin(vec, st, n);
        reverse(vec.begin() + st, vec.begin() + ed + 1);
        cost += distance(vec.begin() + st, vec.begin() + ed + 1);
        st++;
    }
    cout << cost - 1 << "\n";
}

void solve()
{
    int n;
    cin >> n;
    vector<int> vec(n);
    for (auto &x : vec)
    {
        cin >> x;
    }
    reverSort(vec, n);
    // for (auto x : vec)
    // {
    //     cout << x << " ";
    // }
}

signed main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cout << "Case #" << i << ": ";
        solve();
    }
    // while (t--)
    // {
    //     solve();
    // }
#ifndef ONLINE_JUDGE
    cerr << "Time :" << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms";
#endif
    return 0;
}
*/
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

void solve()
{
    int n, c;
    cin >> n >> c;
    if (c < n - 1 || c > (n * (n - 1) / 2) - 1)
    {
        cout << "IMPOSSIBLE\n";
        return;
    }
}

signed main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    cin >> t;
    // while (t--)
    // {
    //     solve();
    // }
    for (int i = 1; i <= t; i++)
    {
        cout << "Case #" << i << ": ";
        solve();
    }
#ifndef ONLINE_JUDGE
    cerr << "Time :" << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms";
#endif
    return 0;
}
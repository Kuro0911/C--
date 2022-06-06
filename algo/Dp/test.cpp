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
int memo[1001], memoGrid[1001][1001];
// memoization: recursive approach
int fib(int n)
{
    if (memo[n] != 0)
    {
        return memo[n];
    }
    if (n <= 2)
        return 1;
    memo[n] = fib(n - 1) + fib(n - 2);
    return memo[n];
}
int gridTraveler(int n, int m)
{
    if (memoGrid[n][m] != -1)
        return memoGrid[n][m];
    if (n == 0 || m == 0)
        return 0;
    if (n == 1 && m == 1)
        return 1;
    memoGrid[n][m] = gridTraveler(n - 1, m) + gridTraveler(n, m - 1);
    return memoGrid[n][m];
}
bool canSum(int target, vector<int> a)
{
    if (memo[target] != -1)
    {
        if (memo[target] == 1)
            return true;
        else
            return false;
    }
    if (target == 0)
    {
        return true;
    }
    if (target < 0)
    {
        return false;
    }
    for (auto &x : a)
    {
        if (canSum(target - x, a))
        {
            memo[target] = true;
            return true;
        }
    }
    memo[target] = false;
    return false;
}
vector<int> howSum(int target, vector<int> a)
{
    if (target == 0)
    {
        vector<int> x;
        x.push_back(0);
        return x;
    }
    if (target < 0)
    {
        vector<int> x;
        x.push_back(-1);
        return x;
    }
    for (auto &x : a)
    {
        int rem = target - x;
        vector<int> res = howSum(rem, a);
        if (res[0] != -1)
        {
            res.push_back(x);
            for (auto &x : res)
            {
                cout << x << " ";
            }
            cout << "\n";
            return res;
        }
    }
    vector<int> x;
    x.push_back(0);
    return x;
}
// tabulation : iterative approach
int TabFib(int n)
{
    int a[n + 1];
    memset(a, 0, sizeof(a));
    a[1] = 1;
    for (int i = 0; i <= n; i++)
    {
        a[i + 1] += a[i];
        a[i + 2] += a[i];
    }
    return a[n];
}
int traveler(int n, int m)
{
    int a[n + 1][m + 1];
    memset(a, 0, sizeof(a));
    a[1][1] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i + 1 <= m)
                a[i + 1][j] += a[i][j];
            if (j + 1 <= n)
                a[i][j + 1] += a[i][j];
        }
    }
    return a[n][m];
}
bool TabcanSum(vector<int> a, int target)
{
    bool ans[target + 1];
    memset(ans, false, sizeof(ans));
    ans[0] = true;
    for (int i = 0; i < target + 1; i++)
    {
        for (auto &x : a)
        {
            if (i + x <= target && ans[i + x] != true)
            {
                ans[i + x] = true;
            }
        }
    }
    return ans[target];
}
vector<int> TabHowSum(int target, vector<int> a)
{
    vector<vector<int>> ans(target + 1);
    ans[0].push_back(0);
    for (int i = 0; i < target + 1; i++)
    {
        if (ans[i].size() >= 1)
        {
            for (auto &x : a)
            {
                if (i + x < target + 1)
                {
                    ans[i + x].push_back(x);
                }
            }
        }
    }
    return ans[target];
}
vector<int> TabBestSum(int target, vector<int> a)
{
    vector<vector<int>> ans(target + 1);
    ans[0].push_back(0);
    for (int i = 0; i < target + 1; i++)
    {
        if (ans[i].size() >= 1)
        {
            for (auto &x : a)
            {
                if (i + x < target + 1)
                {
                    vector<int> temp = ans[i];
                    temp.push_back(x);
                    if (ans[i + x].size() == 0)
                    {
                        ans[i + x] = temp;
                    }
                    else
                    {
                        if (ans[i + x].size() >= temp.size())
                        {
                            ans[i + x] = temp;
                        }
                    }
                }
            }
        }
    }
    return ans[target];
}
void solve()
{
    int n, target;
    cin >> n >> target;
    vector<int> vec(n);
    for (auto &x : vec)
    {
        cin >> x;
    }
    vector<int> ans = TabBestSum(target, vec);
    ans.erase(ans.begin());
    for (auto &x : ans)
    {
        cout << x << " ";
    }
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
#ifndef ONLINE_JUDGE
    cerr << "Time :" << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms";
#endif
    return 0;
}
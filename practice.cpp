/*
// Q1
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

void getMulti(int n)
{
    for (int i = 1; i < n; i++)
    {
        if (i % 3 == 0)
        {
            cout << i << " ";
        }
    }
    cout << endl;
}
void RGetMulti(int n, int i)
{
    if (i > n)
    {
        return;
    }
    if (i % 3 == 0)
    {
        cout << i << " ";
    }
    i++;
    RGetMulti(n, i);
}
void solve()
{
    int n;
    cin >> n;
    getMulti(n);
    RGetMulti(n, 1);
    cout << endl;
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
#ifndef ONLINE_JUDGE
    cerr << "Time :" << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms";
#endif
    return 0;
}
*/

// Q2
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

void TwoSum(vector<int> &vec, int target)
{
    map<int, int> mp;
    for (auto &x : vec)
    {
        int fndTar = x - target;
        for (int i = 0; i < vec.size(); i++)
        {
            int tar = target - vec[i];
            if (mp.find(tar) != mp.end())
            {
                cout << i + 1 << " " << mp[tar] + 1;
                return;
            }
            mp[vec[i]] = i;
        }
    }
}
void AllSum(vector<int> &vec, int target)
{
    int st = 0, end = vec.size() - 1;
    while (st < end)
    {
        int crrSum = 0;
        for (int i = st; i <= end; i++)
        {
            crrSum += vec[i];
        }
        if (crrSum == target)
        {
            for (int i = st; i <= end; i++)
            {
                cout << i + 1 << " ";
            }
            cout << endl;
            return;
        }
        if (crrSum < target)
        {
            st++;
            end = vec.size() - 1;
        }
        if (crrSum > target)
        {
            end--;
        }
    }
}
void solve()
{
    int n, target;
    cin >> target >> n;
    vector<int> vec(n);
    for (auto &x : vec)
    {
        cin >> x;
    }
    // TwoSum(vec, target);
    AllSum(vec, target);
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
#ifndef ONLINE_JUDGE
    cerr << "Time :" << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms";
#endif
    return 0;
}

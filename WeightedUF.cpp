#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, int> ppi;
typedef pair<int, pii> pip;
typedef pair<pii, pii> ppp;
typedef pair<ll, ll> pll;
#define INF (int)(1e9 + 7)
#define int long long

class WeightedUF
{
private:
    vector<int> arr;
    vector<int> size;

    int __root(int a)
    {
        while (arr[a] != a)
        {
            arr[a] = arr[arr[a]];
            a = arr[a];
        }
        return a;
    }

public:
    WeightedUF(int v)
    {
        arr = vector<int>(v + 1);
        size = vector<int>(v + 1);
        for (int i = 0; i <= v; i++)
        {
            size[i] = 1;
            arr[i] = i;
        }
    }

    void __union(int a, int b)
    {
        int rootA = __root(a);
        int rootB = __root(b);

        if (rootA == rootB)
            return;

        if (size[rootA] < size[rootB])
        {
            arr[rootA] = rootB;
            size[rootB] += size[rootA];
        }
        else
        {
            arr[rootB] = rootA;
            size[rootA] += size[rootB];
        }
    }

    bool _find(int a, int b)
    {
        return __root(a) == __root(b);
    }
};

void solve()
{
    // write code
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
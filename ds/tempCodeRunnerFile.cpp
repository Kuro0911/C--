#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, int> ppi;
typedef pair<int, pii> pip;
typedef pair<pii, pii> ppp;
typedef pair<ll, ll> pll;

int distinct_elements(vector<int> a, int n)
{
    sort(a.begin(), a.end());
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        while (i < n - 1 && a[i] == a[i + 1])
        {
            i++;
        }
        count++;
    }
    return count;
}
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    while (k--)
    {
        int a, b;
        for (int i = 0; i < arr.size(); i++)
        {
            sort(arr.begin(), arr.end());

            for (int i = 0; i < arr.size(); i++)
            {
                if (arr[i + 1] == (arr[i] + 1))
                {
                    continue;
                }
                else if (i == arr.size() - 1)
                {
                    a = arr[i] + 1;
                    break;
                }
                else
                {
                    a = arr[i] + 1;
                    break;
                }
            }
        }
        b = *max_element(arr.begin(), arr.end());
        cout << a << " " << b << "\n";
        int temp = ((a+b) + 2 - 1)/2;
        arr.push_back(temp);
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
    cout << distinct_elements(arr, arr.size()) << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
#ifndef ONLINE_JUDGE
    cerr << "Time :" << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms";
#endif
    return 0;
}
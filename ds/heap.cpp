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
class MedianFinder
{
public:
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    MedianFinder() {}

    void addNum(int num)
    {
        if (max_heap.empty())
        {
            max_heap.push(num);
            return;
        }
        if (min_heap.size() < max_heap.size())
        {
            if (max_heap.top() > num)
            {
                min_heap.push(max_heap.top());
                max_heap.pop();
                max_heap.push(num);
            }
            else
            {
                min_heap.push(num);
            }
        }
        else
        {
            if (min_heap.top() < num)
            {
                max_heap.push(min_heap.top());
                min_heap.pop();
                min_heap.push(num);
            }
            else
            {
                max_heap.push(num);
            }
        }
    }

    double findMedian()
    {
        double res = 0.0;
        if (max_heap.size() == min_heap.size())
        {
            res = (max_heap.top() + min_heap.top()) / 2.0;
        }
        else
        {
            if (max_heap.size() > min_heap.size())
            {
                res = max_heap.top();
            }
            else
            {
                res = min_heap.top();
            }
        }
        return res;
    }
};
void solve()
{
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    vector<int> temp{2, 4, 14, 12};
    for (auto x : temp)
    {
        max_heap.push(x);
        min_heap.push(x);
    }
    cout << max_heap.top() << " " << min_heap.top();
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
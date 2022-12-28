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
    bool check(string word)
    {
        if (word[0] != '$' or word.size() == 1)
        {
            return false;
        }
        for (int i = 1; i < word.size(); i++)
        {
            if (word[i] < '0' or word[i] > '9')
            {
                return false;
            }
        }
        return true;
    }
    string discountPrices(string sentence, int discount)
    {
        string res = "";
        stringstream str(sentence);
        string word;
        float dis = (float)discount / 100;
        while (str >> word)
        {
            res.push_back(' ');
            if (check(word))
            {
                int num = stoi(word.substr(1));
                cout << num << endl;
                double x = num * dis;
                string y = to_string(x);
                res.push_back('$');
                res += y.substr(0, y.find('.') + 3);
            }
            else
            {
                res += word;
            }
        }
        return res.substr(1);
    }
};
void solve()
{
    Solution x;
    cout << x.discountPrices("here are $1 $2 and 5 $ candies in the shop", 50);
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
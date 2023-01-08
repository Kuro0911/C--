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
    bool isItPossible(string word1, string word2)
    {
        map<char, int> mp1, mp2;
        for (auto x : word1)
        {
            mp1[x]++;
        }
        for (auto x : word2)
        {
            mp2[x]++;
        }
        int sz1 = mp1.size(), sz2 = mp2.size();
        if (abs(sz1 - sz2) == 0)
        {
            return true;
        }
        else if (abs(sz1 - sz2) != 1)
        {
            return false;
        }
        if (mp1.size() < mp2.size())
        {
            swap(mp1, mp2);
        }
        map<char, int> tmp1, tmp2;
        tmp1 = mp1;
        tmp2 = mp2;
        cout << "###########################\n";
        for (auto x : tmp1)
        {
            cout << x.first << " " << x.second << endl;
        }
        cout << endl;
        for (auto x : tmp2)
        {
            cout << x.first << " " << x.second << endl;
        }
        cout << "###########################\n";
        for (auto [word, num] : mp1)
        {
            tmp1[word]--;
            if (tmp1[word] == 0)
            {
                tmp1.erase(word);
            }
            tmp2[word]++;

            for (auto [w2, nn] : mp2)
            {
                tmp1[w2]++;
                cout << "###########################\n";
                for (auto x : tmp1)
                {
                    cout << x.first << " " << x.second << endl;
                }
                cout << endl;
                for (auto x : tmp2)
                {
                    cout << x.first << " " << x.second << endl;
                }
                cout << "###########################\n";
                cout << endl;
                if (tmp2.size() == tmp1.size())
                {
                    return true;
                }
                tmp1[w2]--;
                if (tmp1[w2] == 0)
                {
                    tmp1.erase(word);
                }
            }
            tmp1[word]++;
            tmp2[word]--;
            if (tmp2[word] == 0)
            {
                tmp2.erase(word);
            }
        }
        return false;
    }
};
void solve()
{
    string a, b;
    cin >> a >> b;
    Solution x;
    cout << x.isItPossible(a, b);
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
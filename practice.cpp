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

class Node
{
public:
    Node *children[27];
    bool isEnd;
    Node()
    {
        for (int i = 0; i < 27; i++)
        {
            children[i] = NULL;
        }
        isEnd = false;
    }
};
class WordFilter
{
private:
    Node *root = new Node();
    map<string, int> mp;
    void insert(string word)
    {
        Node *temp = root;
        int curr = 0;
        for (int i = 0; i < word.size(); i++)
        {
            curr = word[i] - 'a';
            if (temp->children[curr] == NULL)
            {
                temp->children[curr] = new Node();
            }
            temp = temp->children[curr];
        }
        temp->isEnd = true;
    }

public:
    WordFilter(vector<string> &words)
    {
        for (int k = 0; k < words.size(); k++)
        {
            string x = words[k];
            mp[x] = k;
            for (int i = 0; i <= x.size(); i++)
            {
                string temp = x.substr(i) + "{" + x;
                insert(temp);
            }
        }
    }

    int f(string pref, string suff)
    {
        string x = find(suff + "{" + pref);
        if (x == "?")
        {
            return -1;
        }
        int mx = INT_MIN;
        for (auto x : vec)
        {
            mx = max(mp[pref + x], mx);
        }
        return mx;
    }
    string find(string str)
    {
        Node *temp = root;
        for (auto x : str)
        {
            if (temp->children[x - 'a'] == NULL)
            {
                return "?";
            }
            temp = temp->children[x - 'a'];
        }
        getAll(temp, "");
        return "ok";
    }
    vector<string> vec;
    void getAll(Node *root, string wrd)
    {
        if (root == NULL)
        {
            return;
        }
        if (root->isEnd)
        {
            vec.push_back(wrd);
        }
        for (int i = 0; i < 26; i++)
        {
            if (root->children[i] != NULL)
            {
                wrd.push_back(i + 'a');
                getAll(root->children[i], wrd);
                wrd.pop_back();
            }
        }
    }
};
void solve()
{
    vector<string> str(4);
    for (auto &x : str)
    {
        cin >> x;
    }
    WordFilter wf(str);
    cout << wf.f("a", "e");
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
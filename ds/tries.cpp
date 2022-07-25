// Tries are Prefix trees where all nodes can have atleast 26 children and we can find prefixes
// used for auto correct / spell check / word suggestions

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

class TrieNode
{
public:
    map<char, TrieNode *> children;
    bool isEnd;
    TrieNode()
    {
        isEnd = false;
    }
};
class Trie
{
public:
    TrieNode *root;
    Trie()
    {
        root = new TrieNode();
    }
    void insert(string word)
    {
        TrieNode *temp = root;
        for (auto &x : word)
        {
            if (temp->children.find(x) == temp->children.end())
            {
                temp->children[x] = new TrieNode();
            }
            temp = temp->children[x];
        }
        temp->isEnd = true;
    }

    bool search(string word)
    {
        TrieNode *temp = root;
        for (auto x : word)
        {
            if (temp->children.find(x) == temp->children.end())
            {
                return false;
            }
            temp = temp->children[x];
        }
        return temp->isEnd;
    }

    bool startsWith(string prefix)
    {
        TrieNode *temp = root;
        for (auto x : prefix)
        {
            if (temp->children.find(x) == temp->children.end())
            {
                return false;
            }
            temp = temp->children[x];
        }
        return true;
    }
};
void solve()
{
    Trie trie;
    trie.insert("hello");
    trie.insert("help");
    trie.insert("hola");

    if (trie.search("hola"))
    {
        cout << "found\n";
    }
    else
    {
        cout << "NF\n";
    }
    if (trie.startsWith("hela"))
    {
        cout << "found pre\n";
    }
    else
    {
        cout << "NF pre\n";
    }
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
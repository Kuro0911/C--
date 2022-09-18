// Tries are Prefix trees where all nodes can have atleast 26 children and we can find prefixes
// used for auto correct / spell check / word suggestions

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

class node
{
public:
    map<char, node *> chars;
    bool isEnd;
    node()
    {
        isEnd = false;
    }
};
class WordDictionary
{
public:
    node *root;
    WordDictionary()
    {
        root = new node();
    }

    void addWord(string word)
    {
        node *temp = root;
        for (auto x : word)
        {
            if (!temp->chars[x])
            {
                temp->chars[x] = new node();
            }
            temp = temp->chars[x];
        }
        temp->isEnd = true;
    }
    // bool dfs(node *curr, int st, string word)
    // {
    //     node *temp = curr;
    //     for (int i = st; i < word.size(); i++)
    //     {
    //         if (word[i] == '.')
    //         {
    //             for (auto y : temp->chars)
    //             {
    //                 if (dfs(y.second, i + 1, word))
    //                 {
    //                     return true;
    //                 }
    //             }
    //             return false;
    //         }
    //         else
    //         {
    //             if (!temp->chars[word[i]])
    //             {
    //                 return false;
    //             }
    //             temp = temp->chars[word[i]];
    //         }
    //     }
    //     return temp->isEnd;
    // }
    int dfs(node *root, string s)
    {
        node *temp = root;
        int ans = 0;
        // cout << s << endl;
        for (int i = 0; i < s.size(); i++)
        {
            if (temp->chars.find(s[i]) != temp->chars.end())
            {
                if (s.size() == 1)
                {
                    ans += temp->chars[s[i]]->chars.size();
                    if (temp->chars[s[i]]->isEnd)
                    {
                        ans++;
                    }
                    for (auto y : temp->chars[s[i]]->chars)
                    {
                        cout << y.first << " ";
                    }
                    cout << endl;
                }
                for (auto y : temp->chars)
                {
                    ans += dfs(y.second, s.substr(1));
                }
            }
        }
        return ans;
    }
    // bool search(string word)
    // {
    //     node *temp = root;
    //     return dfs(temp, 0, word);
    // }
    int helper(string s)
    {
        node *temp = root;
        return dfs(temp, s);
    }
};

void solve()
{
    WordDictionary trie;
    vector<string> vec{"abc", "ab", "bc", "b"};
    for (auto x : vec)
    {
        trie.addWord(x);
    }
    cout << trie.helper("abc");
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
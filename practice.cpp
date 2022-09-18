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

struct TrieNode
{

    map<char, TrieNode *> children;

    bool isEndOfWord;
    map<char, int> num;
};
struct TrieNode *root;

struct TrieNode *getNewTrieNode()
{
    struct TrieNode *pNode = new TrieNode;
    pNode->isEndOfWord = false;
    return pNode;
}

void insertWord(string word)
{
    struct TrieNode *current = root;

    char s;

    for (int i = 0; i < word.length(); i++)
    {
        s = word[i];
        if (current->children.find(s) == current->children.end())
        {

            struct TrieNode *p = getNewTrieNode();

            (current->children)[s] = p;
            (current->num)[s] = 1;
        }
        else
        {
            current->num[s] = (current->num)[s] + 1;
        }

        current = (current->children)[s];
    }
    current->isEndOfWord = true;
}

int countWords(vector<string> &words,
               string prefix)
{
    root = getNewTrieNode();

    int n = words.size();

    for (int i = 0; i < n; i++)
    {
        insertWord(words[i]);
    }

    struct TrieNode *current = root;
    char s;
    int wordCount = 0;

    for (int i = 0; prefix[i]; i++)
    {
        s = prefix[i];

        if (current->children.find(s) == current->children.end())
        {

            wordCount = 0;
            break;
        }

        wordCount = (current->num)[s];

        current = (current->children)[s];
    }

    return wordCount;
}

signed main()
{
    vector<string> words;
    words = {"abc", "ab", "bc", "b"};

    string prefix = "a";

    cout << countWords(words, prefix);
    return 0;
}
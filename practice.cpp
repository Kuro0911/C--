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
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
void print(TreeNode *root)
{
    if (!root)
    {
        return;
    }
    cout << root->val << " ";
    print(root->left);
    print(root->right);
}
class Solution
{
public:
    TreeNode *recoverFromPreorder(string s)
    {
        TreeNode *root = new TreeNode(s[0] - '0');
        s = s.substr(1);
        int prev = 1, curr = 1, pos_right = s.size() - 1, pos_left = s.size() - 1;

        cout << s.find_first_of("0123456789");
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] == '-')
            {
                curr++;
            }
            else
            {
                if (curr < prev)
                {
                    pos_left = i - curr;
                    pos_right = i;
                    break;
                }
                else
                {
                    prev = curr;
                    curr = 0;
                }
            }
        }
        cout << s.substr(1, pos_left - 1) << " " << s.substr(pos_right) << endl;
        // root->left = recoverFromPreorder(s.substr(1, pos - 1));
        // root->right = recoverFromPreorder(s.substr(pos));

        return root;
    }
};

void solve()
{
    Solution x;
    string s;
    cin >> s;
    TreeNode *root = x.recoverFromPreorder(s);
    print(root);
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
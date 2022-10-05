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

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    TreeNode *helper(TreeNode *root, int val, int curr_depth, int depth, bool side)
    {
        TreeNode *new_node = new TreeNode();
        if (curr_depth == depth)
        {
            new_node->val = val;
            if (side)
            {
                new_node->right = root;
            }
            else
            {
                new_node->left = root;
            }
        }
        else
        {
            new_node->val = root->val;
            if (root->left)
            {
                new_node->left = helper(root->left, val, curr_depth + 1, depth, false);
            }
            if (root->right)
            {
                new_node->right = helper(root->right, val, curr_depth + 1, depth, true);
            }
        }
        return new_node;
    }
    TreeNode *addOneRow(TreeNode *root, int val, int depth)
    {
        TreeNode *new_root = new TreeNode();
        if (depth == 1)
        {
            new_root->val = val;
            new_root->right = root;
        }
        else
        {
            new_root = helper(root, val, 1, depth, false);
        }
        return new_root;
    }
};
void solve()
{
    string s = "abaa";
    set<char> st(s.begin(), s.end());
    cout << st.size();
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
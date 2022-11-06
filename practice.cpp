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
private:
    TreeNode *insert(TreeNode *root, int data)
    {
        if (!root)
        {
            TreeNode *temp = new TreeNode(data);
            root = temp;
        }
        else if (data <= root->val)
        {
            root->left = insert(root->left, data);
        }
        else
        {
            root->right = insert(root->right, data);
        }
        return root;
    }
    TreeNode *minValNode(TreeNode *root)
    {
        TreeNode *curr = root;
        while (curr and curr->left)
        {
            curr = curr->left;
        }
        return curr;
    }
    TreeNode *del(TreeNode *root, int key)
    {
        if (!root)
        {
            return root;
        }
        if (key < root->val)
        {
            root->left = del(root->left, key);
        }
        else if (key > root->val)
        {
            root->right = del(root->right, key);
        }
        else
        {
            if (!root->left and !root->right)
            {
                return NULL;
            }
            else if (!root->left)
            {
                TreeNode *temp = root->right;
                free(root);
                return temp;
            }
            else if (!root->right)
            {
                TreeNode *temp = root->left;
                free(root);
                return temp;
            }
            TreeNode *temp = minValNode(root->right);
            root->val = temp->val;
            root->right = del(root->right, temp->val);
        }
        return root;
    }

    void print(TreeNode *root)
    {
        if (!root)
        {
            return;
        }
        print(root->left);
        cout << root->val << " ";
        print(root->right);
    }
    void printPre(TreeNode *root)
    {
        if (!root)
        {
            return;
        }
        cout << root->val << " ";
        print(root->left);
        print(root->right);
    }
    void printlvl(TreeNode *root)
    {
        vector<vector<int>> ans;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int sz = q.size();
            vector<int> lvl;
            for (int i = 0; i < sz; i++)
            {
                TreeNode *temp = q.front();
                if (temp->left)
                {
                    q.push(temp->left);
                }
                if (temp->right)
                {
                    q.push(temp->right);
                }
                lvl.push_back(temp->val);
                q.pop();
            }
            ans.push_back(lvl);
        }
        for (auto x : ans)
        {
            for (auto y : x)
            {
                cout << y << " ";
            }
            cout << endl;
        }
    }
    int size(TreeNode *temp)
    {
        if (!temp)
        {
            return 0;
        }
        return 1 + size(temp->left) + size(temp->right);
    }
    bool check(TreeNode *prev, TreeNode *curr, int dir)
    {
        if (!curr)
        {
            return true;
        }
        if (dir == 0 and prev->val >= curr->val or dir == 1 and prev->val <= curr->val)
        {
            prev = curr;
            return check(prev, curr->left, 0) and check(prev, curr->right, 1);
        }
        return false;
    }
    vector<int> Inorder(TreeNode *root)
    {
        TreeNode *curr = root;
        vector<int> res;
        while (curr)
        {
            if (!curr->left)
            {
                res.push_back(curr->val);
                curr = curr->right;
            }
            else
            {
                TreeNode *prev = curr->left;
                while (prev->right and prev->right != curr)
                {
                    prev = prev->right;
                }
                if (!prev->right)
                {
                    prev->right = curr;
                    curr = curr->left;
                }
                else
                {
                    prev->right = NULL;
                    res.push_back(prev->val);
                    curr = curr->right;
                }
            }
        }
        return res;
    }
    void Inorder(TreeNode *root, queue<int> &keys)
    {
        if (root == nullptr)
        {
            return;
        }

        Inorder(root->left, keys);
        keys.push(root->val);
        Inorder(root->right, keys);
    }
    void bstToMin(TreeNode *root, queue<int> &q)
    {
        if (!root)
        {
            return;
        }
        root->val = q.front();
        q.pop();
        bstToMin(root->left, q);
        bstToMin(root->right, q);
    }

public:
    TreeNode *root = NULL;
    Solution(vector<int> nodes)
    {
        for (auto x : nodes)
        {
            root = insert(root, x);
        }
        cout << "Inorder: ";
        print(root);
        cout << endl;
    }

    // q1
    int getSize()
    {
        return size(root);
    }

    // q2
    string getCheck()
    {
        if (check(root, root->left, 0) and check(root, root->right, 1))
        {
            return "TRUE";
        }
        else
        {
            return "FALSE";
        }
    }

    // q3
    void getQ3(int x, int y)
    {
        root = insert(root, x);
        cout << "\nAfter Insert : ";
        print(root);
        root = del(root, y);
        cout << "\nAfter Del : ";
        print(root);
    }
    // q4
    int getQ4(int k)
    {
        vector<int> inorder = Inorder(root);
        return inorder[k];
    }
    // q5
    void convert()
    {
        queue<int> q;
        Inorder(root, q);

        bstToMin(root, q);
        printlvl(root);
    }
};

void solve()
{
    int sz;
    cin >> sz;
    vector<int> temp(sz);
    for (auto &x : temp)
    {
        cin >> x;
    }
    Solution x(temp);
    cout << "A1 : " << x.getSize() << endl
         << endl;
    cout << "A2 : " << x.getCheck() << endl
         << endl;
    cout << "A3 : INSERT 12 AND DEL 21 ";
    x.getQ3(12, 21);
    cout << endl;
    cout << "A4 : KTH SMALLEST NODE K = 3 ===> " << x.getQ4(3);
    cout << "\nA5 : COVERT TO MIN HEAP\n";
    x.convert();
    cout << endl;
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
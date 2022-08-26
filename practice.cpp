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
struct node
{
    int data;
    pair<int, int> range;
    node *left;
    node *right;
    node(int l, int r)
    {
        range = {l, r};
        left = NULL;
        right = NULL;
    }
};
int merge(int x, int y)
{
    return x + y;
}
node *build(int l, int r, vector<int> vec)
{
    node *temp = new node(l, r);
    if (l == r)
    {
        temp->data = vec[l];
        return temp;
    }
    int mid = (l + r) / 2;
    temp->left = build(l, mid, vec);
    temp->right = build(mid + 1, r, vec);
    temp->data = temp->left->data + temp->right->data;
    return temp;
}
void update(int pos, int val, node *&root)
{
    node *runner = root;
    stack<node *> path;
    while (runner->range.first != runner->range.second)
    {
        path.push(runner);
        if (runner->left->range.second >= pos)
        {
            runner = runner->left;
        }
        else
        {
            runner = runner->right;
        }
    }
    int diff = val - runner->data;
    runner->data = val;

    while (!path.empty())
    {
        path.top()->data += diff;
        path.pop();
    }
    return;
}
int query(int ql, int qr, node *root)
{
    int l = root->range.first, r = root->range.second;
    if (root == NULL || l > qr || r < ql)
    {
        return 0;
    };
    if (l >= ql && r <= qr)
    {
        return root->data;
    }
    int restL = query(ql, qr, root->left);
    int restR = query(ql, qr, root->right);
    return merge(restL, restR);
}
int sumRange(int ql, int qr, node *head)
{
    if (head == NULL)
    {
        return 0;
    }
    int l = head->range.first, r = head->range.second;
    if (l == ql && r == qr)
    {
        return head->data;
    }
    int part = head->left->range.second;
    if (part >= ql)
    {
        if (part >= qr)
        {
            return sumRange(ql, qr, head->left);
        }
        else
        {
            return sumRange(ql, part, head->left) + sumRange(part + 1, qr, head->right);
        }
    }
    else
    {
        return sumRange(ql, qr, head->right);
    }
}
void solve()
{
    int n;
    cin >> n;
    vector<int> vec(n);
    for (auto &x : vec)
    {
        cin >> x;
    }
    node *root = build(0, vec.size() - 1, vec);
    update(3, 10, root);
    cout << sumRange(1, 4, root);
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
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
    node *left, *right;
};
node *root = NULL;
node *getNewNode(int data)
{
    node *temp = new node();
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
node *insert(node *curr, int info)
{
    if (curr == NULL)
    {
        curr = getNewNode(info);
        return curr;
    }
    else if (info <= curr->data)
    {
        curr->left = insert(curr->left, info);
    }
    else
    {
        curr->right = insert(curr->right, info);
    }
    return curr;
}
int diameter(node *curr, int &res)
{
    if (curr == NULL)
        return 0;
    int l = diameter(curr->left, res);
    int r = diameter(curr->right, res);
    int temp = max(l, r) + 1;
    int ans = max(temp, l + r + 1);
    res = max(res, ans);
    return temp;
}
void inOrder(node *curr)
{
    if (curr == NULL)
        return;
    inOrder(curr->left);
    cout << curr->data << " ";
    inOrder(curr->right);
}
void solve()
{
    int n;
    cin >> n;
    while (n--)
    {
        int x;
        cin >> x;
        root = insert(root, x);
    }
    inOrder(root);
    int res = INT_MIN;
    diameter(root, res);
    cout << endl
         << res - 1;
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
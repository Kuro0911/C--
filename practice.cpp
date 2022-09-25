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
    node *link;
    node(int val)
    {
        data = val;
        link = NULL;
    }
};
void insert(node **head_ref, int data)
{
    node *new_node = new node(data);
    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }
    node *temp = *head_ref;
    while (temp->link)
    {
        temp = temp->link;
    }
    temp->link = new_node;
    return;
}
void print(node *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->link;
    }
    cout << endl;
    return;
}
node *reverse(node *start, node *end)
{
    node *temp = end->link;
    node *curr = start, *prev = temp, *next;
    while (curr != temp)
    {
        next = curr->link;
        curr->link = prev;
        prev = curr;
        curr = next;
    }
    print(prev);
    start = prev;
    return start;
}
void solve()
{
    node *root = NULL;
    for (int i = 0; i < 5; i++)
    {
        int x;
        cin >> x;
        insert(&root, x);
    }
    cout << root->data << "  " << root->link->link->data << endl;
    root = reverse(root, root->link->link);
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
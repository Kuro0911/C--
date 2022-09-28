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
    node *next;
    node *prev;
    node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
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
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->prev = temp;
    return;
}
void print(node *head)
{
    cout << "print forward: ";
    node *temp = head;
    while (temp->next)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << temp->data;
    cout << "\nprint back : ";
    while (temp->prev)
    {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << temp->data << endl;
    return;
}
int getSize(node *head)
{
    int k = 0;
    while (head)
    {
        k++;
        head = head->next;
    }
    return k;
}
node *split(node *head)
{
    node *fast = head, *slow = head;
    while (fast->next && fast->next->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    node *temp = slow->next;
    slow->next = NULL;
    return temp;
}
node *merge(node *first, node *second)
{
    if (!first)
        return second;
    if (!second)
        return first;
    if (first->data < second->data)
    {
        first->next = merge(first->next, second);
        first->next->prev = first;
        first->prev = NULL;
        return first;
    }
    else
    {
        second->next = merge(first, second->next);
        second->next->prev = second;
        second->prev = NULL;
        return second;
    }
}
node *mergeSort(node *head)
{
    if (!head || !head->next)
        return head;
    node *second = split(head);
    head = mergeSort(head);
    second = mergeSort(second);
    return merge(head, second);
}
void solve()
{
    int n = 5;
    node *head = NULL;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        insert(&head, x);
    }
    print(head);
    cout << "size : " << getSize(head) << endl;
    cout << "after sorting : \n";
    head = mergeSort(head);
    print(head);
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
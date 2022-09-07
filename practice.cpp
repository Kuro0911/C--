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
    node(int val)
    {
        data = val;
        next = NULL;
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
};
void print(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// q1
void rotate(node **head_ref)
{
    node *prev = *head_ref;
    node *curr = *head_ref;
    while (curr->next != NULL)
    {
        prev = curr;
        curr = curr->next;
    }
    prev->next = NULL;
    curr->next = *head_ref;
    *head_ref = curr;
}

// q2
node *merge(node *l_temp, node *r_temp)
{
    node *l = l_temp;
    node *r = r_temp;
    node *new_head = NULL;
    while (l != NULL && r != NULL)
    {
        if (l->data <= r->data)
        {
            insert(&new_head, l->data);
            l = l->next;
        }
        else
        {
            insert(&new_head, r->data);
            r = r->next;
        }
    }
    while (l != NULL)
    {
        insert(&new_head, l->data);
        l = l->next;
    }
    while (r != NULL)
    {
        insert(&new_head, r->data);
        r = r->next;
    }
    return new_head;
}
node *mergeSort(node *head)
{
    if (head->next == NULL)
        return head;
    node *slow = head, *fast = head, *curr = head;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    node *r = mergeSort(slow->next);
    slow->next = NULL;
    node *l = mergeSort(head);
    node *new_head = merge(l, r);
    return new_head;
};

// q3
bool checkPalin(node *head)
{
    node *temp = head;
    stack<int> st;
    while (temp != NULL)
    {
        st.push(temp->data);
        temp = temp->next;
    }
    node *temp1 = head;
    while (temp1 != NULL)
    {
        if (temp1->data != st.top())
        {
            return false;
        }
        st.pop();
        temp1 = temp1->next;
    }
    return true;
}
void delEle(node **head_ref, int pos)
{
    node *temp = *head_ref, *prev = *head_ref;
    while (temp != NULL && pos != 0)
    {
        prev = temp;
        temp = temp->next;
        pos--;
    }
    prev->next = temp->next;
}
void solve()
{
    node *root = NULL;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        insert(&root, x);
    }

    // rotate(&root);
    // node *sorted = mergeSort(root);
    // print(sorted);
    // if (checkPalin(root))
    // {
    //     cout << "yes";
    // }
    // else
    // {
    //     cout << "no";
    // }
    // delEle(&root, 2);

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
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
    return;
}
void print(node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
    return;
}
void reverse(node **head_ref, node *end)
{
    node *curr = *head_ref;
    node *prev = NULL;
    while (curr != end)
    {
        node *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    *head_ref = prev;
    return;
}
void solve()
{
    node *root = NULL;
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        insert(&root, x);
    }
    // node *end = root;
    // while (k--)
    // {
    //     end = end->next;
    // }
    // reverse(&root, end);
    node *temp = new node(-1);
    temp->next = root;
    node *prev = temp, *curr = root;
    while (curr != NULL && curr->next != NULL)
    {
        node *nxt = curr;
        while (k-- && nxt != NULL)
        {
            nxt = nxt->next;
        }
        node *tempCurr, *TempPrev;
        tempCurr = curr;
        TempPrev = NULL;
        while (tempCurr != nxt)
        {
            node *x = tempCurr->next;
            tempCurr->next = TempPrev;
            TempPrev = tempCurr;
            tempCurr = x;
        }
        prev = tempCurr;
        curr = nxt;
        node *sc = curr->next;

        sc->next = curr;
        curr->next = nxt;
        prev->next = sc;

        prev = curr;
        curr = nxt;
    }
    print(temp->next);
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
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

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    void insert(ListNode **curr, int data, int pos)
    {
        ListNode *temp = new ListNode(data);
        if (pos == 0)
        {
            *curr = temp;
            return;
        }
        while (pos--)
        {
            if (pos == 0)
            {
                temp->next = *curr;
                *curr = temp;
            }
            else
            {
                curr = &(*curr)->next;
            }
        }
        return;
    }
    void print(ListNode *head_ref)
    {
        ListNode *temp = head_ref;
        while (temp != NULL)
        {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
        return;
    }
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode *head = NULL;
        for (auto x : lists)
        {
            ListNode *temp = head, *l = x;
            print(head);
            if (head == NULL)
            {
                while (l != NULL)
                {
                    int pos = 0;
                    insert(&head, l->val, pos);
                    pos++;
                }
            }
            else
            {
                while (l != NULL)
                {
                    int pos = 0;
                    if (temp->val >= l->val)
                    {
                        insert(&head, l->val, pos);
                    }
                    pos++;
                    l = l->next;
                    if (temp != NULL && temp->next != NULL)
                    {
                        temp = temp->next;
                    }
                }
            }
        }
        return head;
    }
};
void solve()
{
    int x = 0;
    while (x--)
    {
        cout << x;
    }
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
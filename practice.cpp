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
class Node
{
public:
    int key, val, cnt;
    Node *next = NULL;
    Node *prev = NULL;
    Node(int k, int v)
    {
        key = k, val = v;
        cnt = 1;
    }
};
class LFUCache
{
public:
    Node *head = NULL;
    int cap, curr;
    LFUCache(int capacity)
    {
        cap = capacity;
        curr = 0;
    }
    void print(Node *root)
    {
        Node *temp = root;
        while (temp)
        {
            cout << temp->key << " " << temp->val << " " << temp->cnt << endl;
            temp = temp->next;
        }
    }
    int get(int key)
    {
        Node *temp = head;
        while (temp != NULL and temp->key != key)
        {
            temp = temp->next;
        }
        if (temp)
        {
            if (temp != head)
            {
                if (temp->next)
                {
                    temp->next->prev = temp->prev;
                    temp->prev->next = temp->next;
                }
                else
                {
                    temp->prev->next = NULL;
                }
                temp->next = head;
                head->prev = temp;
                head = temp;
            }
            temp->cnt++;
            return temp->val;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (cap == 0)
        {
            return;
        }
        if (curr == 0)
        {
            curr++;
            Node *new_node = new Node(key, value);
            head = new_node;
            return;
        }
        if (get(key) != -1)
        {
            Node *temp = head;
            while (temp->key != key)
                temp = temp->next;
            if (temp != head)
            {
                if (temp->next)
                    temp->next->prev = temp->prev;
                temp->prev->next = temp->next;

                temp->next = head;
                head->prev = temp;
                head = temp;
            }
            head->val = value;
            head->cnt++;
            return;
        }
        else
        {
            if (curr == cap)
            {
                Node *temp = head, *ptr = head;
                while (ptr)
                {
                    if (ptr->cnt <= temp->cnt)
                    {
                        temp = ptr;
                    }
                    ptr = ptr->next;
                }
                if (temp != head)
                {
                    if (temp->next)
                    {
                        temp->next->prev = temp->prev;
                    }
                    temp->prev->next = temp->next;
                }
                else
                {
                    head = head->next;
                }

                curr--;
            }
            Node *new_node = new Node(key, value);
            if (!head)
            {
                head = new_node;
            }
            else
            {
                new_node->next = head;
                head->prev = new_node;
                head = new_node;
            }
        }
        curr++;
        cout << "round st\n";
        print(head);
        cout << "round over\n";
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
void solve()
{
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
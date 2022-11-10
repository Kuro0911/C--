#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node
{
    Node *next;
    Node *prev;
    int value;
    int key;
    Node(Node *p, Node *n, int k, int val) : prev(p), next(n), key(k), value(val){};
    Node(int k, int val) : prev(NULL), next(NULL), key(k), value(val){};
};

class Cache
{

protected:
    map<int, Node *> mp;            // map the key to the node in the linked list
    int cp;                         // capacity
    Node *tail;                     // double linked list tail pointer
    Node *head;                     // double linked list head pointer
    virtual void set(int, int) = 0; // set function
    virtual int get(int) = 0;       // get function
};

class LRUCache : public Cache
{
public:
    LRUCache(int cap)
    {
        cp = cap;
        head = NULL;
        tail = NULL;
    }
    void print()
    {
        Node *temp = head;
        cout << "\nPRINT => \n";
        cout << "HEAD : " << head->key << " , " << head->value << endl;
        cout << "TAIL : " << tail->key << " , " << tail->value << endl;

        while (temp)
        {
            cout << temp->key << " , " << temp->value << endl;
            temp = temp->next;
        }
    }
    void insert(int key, int val)
    {
        Node *new_node = new Node(key, val);
        new_node->prev = NULL;
        if (head)
        {
            mp[head->key]->prev = new_node;
            new_node->next = mp[head->key];
        }
        else
        {
            tail = new_node;
        }

        mp[key] = new_node;
        head = mp[key];
    }
    void pop(int key)
    {
        tail = mp[key]->prev;
        mp[key]->prev->next = NULL;
        mp.erase(key);
    }
    void move(int key)
    {
        if (head == mp[key])
        {
            return;
        }
        Node *prev = mp[key]->prev, *next = mp[key]->next;
        if (prev)
        {
            prev->next = next;
        }
        if (next)
        {
            next->prev = prev;
        }
        if (tail == mp[key])
        {
            if (next)
            {
                tail = next;
            }
            else
            {
                tail = prev;
            }
        }
        mp[key]->prev = NULL;
        mp[key]->next = head;
        head = mp[key];
    }
    virtual int get(int key)
    {
        if (mp.find(key) != mp.end())
        {
            return mp[key]->value;
        }
        return -1;
    }
    virtual void set(int key, int val)
    {
        if (mp.find(key) != mp.end())
        {
            mp[key]->value = val;
            move(key);
        }
        else
        {
            int sz = mp.size();
            if (sz == cp)
            {
                pop(tail->key);
            }
            insert(key, val);
        }
    }
};
int main()
{
    int n, capacity, i;
    cin >> n >> capacity;
    LRUCache l(capacity);
    for (i = 0; i < n; i++)
    {
        string command;
        cin >> command;
        if (command == "get")
        {
            int key;
            cin >> key;
            cout << l.get(key) << endl;
        }
        else if (command == "set")
        {
            int key, value;
            cin >> key >> value;
            l.set(key, value);
        }
    }
    return 0;
}
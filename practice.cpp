#include <bits/stdc++.h>
using namespace std;

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

// Question 1
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

// Question 2
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

// Question Q3
bool checkPalindrome(node *head)
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
void delElement(node **head_ref, int pos)
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
int main()
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
    if (checkPalindrome(root))
    {
        cout << "yes";
    }
    else
    {
        cout << "no";
    }
    // delElement(&root, 2);

    // print(root);
    return 0;
}
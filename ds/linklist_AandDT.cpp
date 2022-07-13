/*
#include <bits/stdc++.h>

using namespace std;
class Node{
    public:
        int data;
        Node * next;
};
void lltraversal(Node* ptr){
    while (ptr != NULL){
        cout<<ptr->data<<endl;
        ptr = ptr->next;
    }
};
int main(){

    Node * head;
    Node * second;
    Node * third;
    Node * fourth;

    //allocate memory for nodes in ll in heap
    head = (Node *)malloc(sizeof(Node));
    second = (Node *)malloc(sizeof(Node));
    third = (Node *)malloc(sizeof(Node));
    fourth = (Node *)malloc(sizeof(Node));

    //link first and second nodes;
    head->data = 4;
    head->next = second;

    //link second and third nodes;
    second->data = 45;
    second->next = third;

    //link third and fourth nodes;
    third->data = 87;
    third->next = fourth;

    //tirminate list at third node;
    fourth->data = 54;
    fourth->next = NULL;

    lltraversal(head);
    return 0;
}
***********************************************************************************
//insertion:
#include <bits/stdc++.h>

using namespace std;
class Node
{
public:
    int data;
    Node *next;
};
void lltraversal(Node *ptr)
{
    while (ptr != NULL)
    {
        cout << ptr->data << endl;
        ptr = ptr->next;
    }
};
Node *insert_at_first(Node *head, int data)
{
    Node *ptr = (Node *)malloc(sizeof(Node));
    ptr->next = head;
    ptr->data = data;
    return ptr;
};
Node *insert_at_index(Node *head, int data, int index)
{
    Node *ptr = (Node *)malloc(sizeof(Node));
    Node *p = head;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
};
Node *insert_at_end(Node *head, int data)
{
    Node *ptr = (Node *)malloc(sizeof(Node));
    ptr->data = data;
    Node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
};
Node *insert_after(Node *head, Node *prevNode, int data)
{
    Node *ptr = (Node *)malloc(sizeof(Node));
    ptr->data = data;
    ptr->next = prevNode->next;
    prevNode->next = ptr;
    return head;
};
int main()
{

    Node *head;
    Node *second;
    Node *third;
    Node *fourth;

    head = (Node *)malloc(sizeof(Node));
    second = (Node *)malloc(sizeof(Node));
    third = (Node *)malloc(sizeof(Node));
    fourth = (Node *)malloc(sizeof(Node));

    head->data = 4;
    head->next = second;

    second->data = 45;
    second->next = third;

    third->data = 87;
    third->next = fourth;

    fourth->data = 54;
    fourth->next = NULL;
    cout << "ll before insertion" << endl;
    lltraversal(head);
    cout << "ll after insertion" << endl;
    //head = insert_at_first(head , 56);
    //head = insert_at_index(head , 56 , 3);
    //head = insert_at_end(head , 56);
    head = insert_after(head, second, 56);

    lltraversal(head);
    return 0;
}
***********************************************************************************
//deletion;
#include <bits/stdc++.h>

using namespace std;
class Node
{
public:
    int data;
    Node *next;
};
void lltraversal(Node *ptr)
{
    while (ptr != NULL)
    {
        cout << ptr->data << endl;
        ptr = ptr->next;
    }
};
Node *delete_at_first(Node *head)
{
    Node *ptr = (Node *)malloc(sizeof(Node));
    head = head->next;
    free(ptr);
    return head;
};
Node *delete_at_index(Node *head, int index)
{
    Node *p = head;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    Node *q = p ->next;
    p ->next = q->next;
    free(q);
    return head;
};
Node *delete_at_end(Node *head)
{
    Node *p = head;
    Node *q = head->next;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
};
Node *delete_value(Node *head, int value)
{
    Node *p = head;
    Node *q = head->next;
    while (q->data!=value && q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    if (q->data == value)
    {
        p->next = q->next;
        free(q);
    }

    return head;
};
int main()
{

    Node *head;
    Node *second;
    Node *third;
    Node *fourth;

    head = (Node *)malloc(sizeof(Node));
    second = (Node *)malloc(sizeof(Node));
    third = (Node *)malloc(sizeof(Node));
    fourth = (Node *)malloc(sizeof(Node));

    head->data = 4;
    head->next = second;

    second->data = 45;
    second->next = third;

    third->data = 87;
    third->next = fourth;

    fourth->data = 54;
    fourth->next = NULL;
    cout << "ll before deleting" << endl;
    lltraversal(head);
    cout << "ll after deleting" << endl;
    //head = delete_at_first(head);
    //head = delete_at_index(head , 2);
    //head = delete_at_end(head);
    //head = delete_value(head, 58);
    lltraversal(head);
    return 0;
}
****************************************************************************************************************

//circular ll
#include <bits/stdc++.h>

using namespace std;
class Node{
    public:
        int data;
        Node * next;
};
void clltraversal(Node* head){
    Node *ptr = head;
    do
    {
        cout<<ptr->data<<endl;
        ptr = ptr->next;
    } while (ptr != head);
};
Node * insert_at_first(Node *head , int data){
    Node *ptr = (Node *)malloc(sizeof(Node));
    ptr->data = data;

    Node *p = head->next;
    while (p->next!=head)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
};
int main(){

    Node * head;
    Node * second;
    Node * third;
    Node * fourth;

    //allocate memory for nodes in ll in heap
    head = (Node *)malloc(sizeof(Node));
    second = (Node *)malloc(sizeof(Node));
    third = (Node *)malloc(sizeof(Node));
    fourth = (Node *)malloc(sizeof(Node));

    //link first and second nodes;
    head->data = 4;
    head->next = second;

    //link second and third nodes;
    second->data = 45;
    second->next = third;

    //link third and fourth nodes;
    third->data = 87;
    third->next = fourth;

    //tirminate list at third node;
    fourth->data = 54;
    fourth->next = head;
    cout << "ll before" << endl;
    clltraversal(head);
    cout << "ll after" << endl;
    insert_at_first(head , 80);
    clltraversal(head);
    return 0;
}

*******************************************************************************************************************************************************************
//MY CODE SCHOOL DSA
*******************************************************************************************************************************************************************

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, int> ppi;
typedef pair<int, pii> pip;
typedef pair<pii, pii> ppp;
typedef pair<ll, ll> pll;
//to create ll node;
struct Node
{
    int data;
    Node *link;
};
//to print ll
void lltraversal(Node *ptr)
{
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->link;
    }
    cout << endl;
}
Node *head = new Node();
//to insert at start
Node *insert_at_start(int x)
{
    Node *temp = new Node();
    temp->data = x;
    temp->link = head;
    return temp;
}
//to insert at INDEX
void insert_at_index(int x, int ind)
{
    Node *temp1 = new Node();
    temp1->data = x;
    temp1->link = NULL;
    if (ind == 1)
    {
        temp1->link = head;
        head = temp1;
        return;
    }
    else
    {
        Node *temp2 = new Node();
        temp2 = head;
        for (int i = 0; i < ind - 2; i++)
        {
            temp2 = temp2->link;
        }
        temp1->link = temp2->link;
        temp2->link = temp1;
    }
}
//deleting a node at index;
void delete_at_index(int n)
{
    Node *temp1 = new Node();
    temp1 = head;
    if (n == 1)
    {
        head = temp1->link;
        free(temp1);
        return;
    }
    for (int i = 0; i < n - 2; i++)
    {
        temp1 = temp1->link;
    }
    Node *temp2 = temp1->link;
    temp1->link = temp2->link;
    free(temp2);
}
int main()
{
    head = NULL;
    cout << "enter the number of ele you want to add : ";
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cout << "enter the ele : ";
        cin >> x;
        head = insert_at_start(x);
        lltraversal(head);
    }
    cout << "enter the number of ele you want to add with index : ";
    int ni;
    cin >> ni;
    for (int i = 0; i < ni; i++)
    {
        int x, ind;
        cout << "enter the ele : ";
        cin >> x;
        cout << "enter the ind : ";
        cin >> ind;
        insert_at_index(x, ind);
        lltraversal(head);
    }
    cout << "ANY deletion(Y/N) : ";
    char c;
    cin >> c;
    if (c == 'N')
    {
        cout << "final arr : ";
        lltraversal(head);
    }
    else
    {
        cout << "enter the number of ele you want to delete with index : ";
        int nd;
        cin >> nd;
        for (int i = 0; i < nd; i++)
        {
            int ind;
            cout << "enter the ind : ";
            cin >> ind;
            delete_at_index(ind);
            lltraversal(head);
        }
        cout << "final arr : ";
        lltraversal(head);
    }
#ifndef ONLINE_JUDGE
    cerr << "Time :" << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms";
#endif
    return 0;
}
//reverseing a ll;

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, int> ppi;
typedef pair<int, pii> pip;
typedef pair<pii, pii> ppp;
typedef pair<ll, ll> pll;
struct Node
{
    int data;
    Node *link;
};
void lltraversal(Node *ptr)
{
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->link;
    }
    cout << endl;
}
Node *head = new Node();

Node *insert_at_start(int x)
{
    Node *temp = new Node();
    temp->data = x;
    temp->link = head;
    return temp;
}
Node *itt_reverse(Node *head)
{
    Node *curr, *prev, *next = new Node();
    curr = head;
    prev = NULL;
    while (curr != NULL)
    {
        next = curr->link;
        curr->link = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    return head;
}
void rec_reverse_print(Node *p)
{
    if (p == NULL)
    {
        return;
    }
    rec_reverse_print(p->link);
    cout << p->data << " ";
}
void rec_reverse(Node *p)
{
    if (p->link == NULL)
    {
        head = p;
        return;
    }
    rec_reverse(p->link);
    Node *q = p->link;
    q->link = p;
    p->link = NULL;
}
int main()
{
    head = NULL;
    cout << "enter the number of ele you want to add : ";
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cout << "enter the ele : ";
        cin >> x;
        head = insert_at_start(x);
        lltraversal(head);
    }
    lltraversal(head);
    cout << "how to reverse : ";
    char c;
    cin >> c;
    if (c == 'I')
    {
        head = itt_reverse(head);
        cout << "reversed ll using itter :\n";
        lltraversal(head);
    }
    else if(c == 'P')
    {
        cout << "reversed ll using rec :\n";
        rec_reverse_print(head);
        cout << "\n";
    }
    else if(c == 'R')
    {
        cout << "reversed ll using rec :\n";
        rec_reverse(head);
        lltraversal(head);
    }else{
        assert(false);
    }

#ifndef ONLINE_JUDGE
    cerr << "Time :" << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms";
#endif
    return 0;
}
*/

// doubly ll
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, int> ppi;
typedef pair<int, pii> pip;
typedef pair<pii, pii> ppp;
typedef pair<ll, ll> pll;

struct Node
{
    int data;
    Node *next;
    Node *prev;
};
Node *head;
void lltraversal()
{
    Node *ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << "\n";
}
void rev_print()
{
    Node *ptr = head;
    if (ptr == NULL)
    {
        assert(false);
        return;
    }
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->prev;
    }
    cout << "\n";
}
Node *Get_new_node(int x)
{
    Node *newNode = new Node();
    newNode->data = x;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
void insert_at_head(int x)
{
    Node *newNode = Get_new_node(x);
    if (head == NULL)
    {
        head = Get_new_node(x);
        return;
    }
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}
void insert_at_tail(int x)
{
    Node *newNode = Get_new_node(x);
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    newNode->prev = temp;
    temp->next = newNode;
    newNode->next = NULL;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    head = NULL;
    insert_at_head(1);
    lltraversal(), rev_print();
    insert_at_head(2);
    lltraversal(), rev_print();
    insert_at_head(3);
    lltraversal(), rev_print();
    insert_at_tail(4);
    lltraversal(), rev_print();

#ifndef ONLINE_JUDGE
    cerr << "Time :" << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms";
#endif
    return 0;
}
/*
//Q1
Q 1. Write a program using functions for implementation of circular Linked List.
Q 2. Write a program to perform the following operations on Link List
a) Insertion
                       at the beginning
                       at the end
                       at the given location
                       in the sorted list
b) Deletion
                       of first node
                       of last node
                       of given item
                        of given item from sorted list.


c) Given a list, split it into two sublists — one for the front half, and one for the back half.
 If the number of elements is odd, the extra element should go in the front list. So FrontBackSplit() on the list {2, 3, 5, 7, 11} should yield the two lists {2, 3, 5} and {7,11}.


d) Given two one-way-link lists A and B. Sort them independently and then Merge as list C.

e) Two way link list insertion and Deletion

f) Header link list insertion and deletion

#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
void push(struct Node **head_ref, int data)
{
    struct Node *ptr1 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp = *head_ref;
    ptr1->data = data;
    ptr1->next = *head_ref;
    if (*head_ref != NULL)
    {
        while (temp->next != *head_ref)
            temp = temp->next;
        temp->next = ptr1;
    }
    else
        ptr1->next = ptr1;
    *head_ref = ptr1;
}
void printList(struct Node *head)
{
    struct Node *temp = head;
    if (head != NULL)
    {
        do
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        while (temp != head);
    }
}
int main()
{
    struct Node *head = NULL;
    push(&head, 12);
    push(&head, 56);
    push(&head, 2);
    push(&head, 11);
    printList(head);

    return 0;
}

//Q2
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}
// Insertion
//a
void insertAtBeginning(struct Node **head_ref, int new_data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
//b
void insertAtEnd(struct Node **head_ref, int new_data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    struct Node *last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    return;
}
//c
void insertAtPos(struct Node **curr, int new_data, int pos){
    struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
    temp->data=new_data;
    temp->next=NULL;
    while(pos--){
        if(pos==0){
            temp->next=*curr;
            *curr=temp;
        }
        else{
            curr=&(*curr)->next;
        }
    }
}
// Deletion
void deleteFirst(struct Node **head_ref)
{
    struct Node *temp = *head_ref;
    *head_ref = temp->next;
    free(temp);
    return;
}
void deleteLast(struct Node **head_ref)
{
    struct Node *temp = *head_ref, *prev;
    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    free(temp);
}
void deleteKey(struct Node **head_ref, int key)
{
    struct Node *temp = *head_ref, *prev;

    if (temp != NULL && temp->data == key)
    {
        *head_ref = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
        return;
    prev->next = temp->next;
    free(temp);
}
//C
void FrontBackSplit(struct Node **head_ref)
{
    struct Node *fast = *head_ref, *slow = *head_ref;
    while (fast!=NULL && fast->next!=NULL)
    {
        printf("%d ",slow->data);
        fast=fast->next->next;
        slow=slow->next;
    }
    printf("%d\n",slow->data);
    printList(slow->next);
}
struct Node* SortedMerge(struct Node* a, struct Node* b)
{
    struct Node* result = NULL;
    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);
    if (a->data <= b->data) {
        result = a;
        result->next = SortedMerge(a->next, b);
    }
    else {
        result = b;
        result->next = SortedMerge(a, b->next);
    }
    return (result);
}
int main()
{
    struct Node *head = NULL;

    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 3);
    insertAtEnd(&head, 4);
    insertAtPos(&head,1,4);
    printf("Linked list: ");
    printList(head);
    printf("\n");
    FrontBackSplit(&head);
    printf("\n");
    struct Node *A = NULL;
    struct Node *B = NULL;
    insertAtBeginning(&A, 5);
    insertAtBeginning(&A, 3);
    insertAtBeginning(&A, 1);
    insertAtBeginning(&B, 6);
    insertAtBeginning(&B, 4);
    insertAtBeginning(&B, 2);
    printf("A:");printList(A);
    printf("\n");
    printf("B:");printList(B);
    printf("\n");
    printList(SortedMerge(A,B));
}

//e) Two way link list insertion and Deletion
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};
void insert(struct Node** head_ref, int new_data)
{
    struct Node* new_node= (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    new_node->prev = NULL;
    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;
    (*head_ref) = new_node;
}
void deleteNode(struct Node** head_ref, struct Node* del)
{
    if (*head_ref == NULL || del == NULL)
        return;
    if (*head_ref == del)
        *head_ref = del->next;
    if (del->next != NULL)
        del->next->prev = del->prev;
    if (del->prev != NULL)
        del->prev->next = del->next;
    free(del);
    return;
}
void printList(struct Node* node)
{
    struct Node* last;
    printf("\nforward traversal \n");
    while (node != NULL) {
        printf("%d ", node->data);
        last = node;
        node = node->next;
    }
    printf("\nreverse traversal\n");
    while (last != NULL) {
        printf("%d ", last->data);
        last = last->prev;
    }
}
int main()
{
    struct Node* head = NULL;
    insert(&head, 4);
    insert(&head, 9);
    insert(&head, 5);
    insert(&head, 6);
    insert(&head, 2);
    deleteNode(&head, head->next);
    printf("LL:");
    printList(head);
    return 0;
}

//f) Header link list insertion and deletion
#include <malloc.h>
#include <stdio.h>
struct Node {
    int info;
    struct Node* next;
};
struct Node* start = NULL;
struct Node* create_header_list(int data)
{
    struct Node *new_node, *node;
    new_node = (struct Node*)
        malloc(sizeof(struct Node));
    new_node->info = data;
    new_node->next = NULL;
    if (start == NULL) {
        start = (struct Node*)
            malloc(sizeof(struct Node));
        start->next = new_node;
    }
    else {
        node = start;
        while (node->next != NULL) {
            node = node->next;
        }
        node->next = new_node;
    }
    return start;
}
void delete(struct Node** head_ref , int key){
    struct Node *temp = *head_ref, *prev;
    if (temp != NULL && temp->info == key){
        *head_ref = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->info != key){
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
        return;
    prev->next = temp->next;
    free(temp);
}

struct Node* display()
{
    struct Node* node;
    node = start;
    node = node->next;
    while (node != NULL) {
        printf("%d ", node->info);
        node = node->next;
    }
    printf("\n");
    return start;
}
int main()
{
    create_header_list(11);
    create_header_list(12);
    create_header_list(13);
    display();
    create_header_list(14);
    create_header_list(15);
    delete(&start,14);
    display();

    return 0;
}
*/
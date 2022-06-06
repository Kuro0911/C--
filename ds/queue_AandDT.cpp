/*
//implementation
#include <bits/stdc++.h>

using namespace std;
class queue_1{
    public:
        int size;
        int f;
        int r;
        int * arr;
};
int isFull(queue_1 * q){
    if(q->r == q->size-1)
        return 1;
    return 0;
};
int isEmpty(queue_1 * q){
    if(q->r == q->f)
        return 1;
    return 0;
};
void enqueue(queue_1 * q , int val ){
    if (isFull(q))
        cout<<"OVERFLOWW"<<endl;
    else
        q->r++;
        q->arr[q->r] = val;
};
int dequeue(queue_1 * q){
    int a = -1;
    if (q->f == q->r)
        cout<<"UNDERFLOWW"<<endl;
    else
        q->f++;
        a = q->arr[q->f];
        return a;
};
int main(){
    queue_1 q;
    q.size = 10;
    q.f = q.r = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));
    if (isEmpty(&q))
    {
        cout<<"q is empty "<<endl;
    }
    enqueue(&q , 12);
    enqueue(&q , 15);
    if (isEmpty(&q))
        cout<<"q is empty "<<endl;
    else
        cout<<"q is not empty "<<endl;
    dequeue(&q);
    dequeue(&q);
    if (isEmpty(&q))
        cout<<"q is empty "<<endl;
    return 0;
}

//circular queue;
#include <bits/stdc++.h>

using namespace std;
class queue_1
{
public:
    int size;
    int f;
    int r;
    int *arr;
};
int isFull(queue_1 *q)
{
    if ((q->r + 1) % q->size == q->f)
        return 1;
    return 0;
};
int isEmpty(queue_1 *q)
{
    if (q->f == q->r)
        return 1;
    return 0;
};
void enqueue(queue_1 *q, int val)
{
    if ((q->r + 1) % q->size == q->f)
        cout << "OVERFLOWW" << endl;
    else
        q->r = (q->r + 1) % q->size;
        q->arr[q->r] = val;
        cout<<"adding value "<<val<<endl;
};
int dequeue(queue_1 *q)
{
    int a = -1;
    if (q->f == q->r)
        cout << "UNDERFLOWW" << endl;
    else
        q->f = (q->f + 1) % q->size;
    a = q->arr[q->f];
    return a;
};
int main()
{
    queue_1 q;
    q.size = 5;
    q.f = q.r = 0;
    q.arr = (int *)malloc(q.size * sizeof(int));
    if (isEmpty(&q))
        cout << "q is empty " << endl;
    if (isFull(&q))
        cout << "q is FULL " << endl;
    enqueue(&q, 12);
    enqueue(&q, 15);
    enqueue(&q, 5);
    enqueue(&q, 45);
    if (isEmpty(&q))
        cout << "q is empty " << endl;
    if (isFull(&q))
        cout << "q is FULL " << endl;
    cout << "dequeing ele " << dequeue(&q) << endl;
    cout << "dequeing ele " << dequeue(&q) << endl;
    cout << "dequeing ele " << dequeue(&q) << endl;
    cout << "dequeing ele " << dequeue(&q) << endl;
    if (isEmpty(&q))
        cout << "q is empty " << endl;
    if (isFull(&q))
        cout << "q is FULL " << endl;
    return 0;
}

//implimenting usin ll;
#include <bits/stdc++.h>

using namespace std;
class Node
{
public:
    int data;
    Node *next;
};
Node * f =NULL;
Node * r =NULL;
void lltraversal(Node* ptr){
    while (ptr != NULL){
        cout<<ptr->data<<endl;
        ptr = ptr->next;
    }
};
void enqueue(int val){
    Node *n = (Node *)malloc(sizeof(Node));
    if(n==NULL)
        cout<<"OVERFLOWW";
    else
        n->data = val;
        n->next = NULL;
        if (f==NULL)
        {
            f=r=n;
        }
        else{
            r->next = n;
            r=n;
        }
        
};
int dequeue(){
    int val = -1;
    Node *n = f;
    if(f==NULL)
        cout<<"UNDERFLOWW";
    else
        f = f->next;
        val = n->data;
        free(n);
    return val;
};
int main()
{
    lltraversal(f);
    enqueue(34);
    enqueue(47);
    enqueue(14);
    enqueue(74);
    enqueue(69);
    lltraversal(f);
    cout << "dequeing ele " << dequeue() << endl;
    cout << "dequeing ele " << dequeue() << endl;
    cout << "dequeing ele " << dequeue() << endl;
    lltraversal(f);
    return 0;
}

//DEQueue;
#include <bits/stdc++.h>

using namespace std;
class queue_1
{
public:
    int size;
    int f;
    int r;
    int *arr;
};
int isFull(queue_1 *q)
{
    if (q->r == q->size - 1)
        return 1;
    return 0;
};
int isEmpty(queue_1 *q)
{
    if (q->r == q->f)
        return 1;
    return 0;
};
void enqueue(queue_1 * q , int val ){
    if (isFull(q))
        cout<<"OVERFLOWW"<<endl;
    else
        q->r++;
        q->arr[q->r] = val;
};
void enqueueF(queue_1 *q, int val)
{
    if (isFull(q))
        cout << "OVERFLOWW" << endl;
    else
        q->f++; 
        q->arr[q->f] = val;
};
void enqueueR(queue_1 *q, int val)
{
    if (isFull(q))
        cout << "OVERFLOWW" << endl;
    else
        q->r++;
        q->arr[q->r] = val;
};
int dequeueF(queue_1 *q)
{
    int a = -1;
    if (q->f == q->r)
        cout << "UNDERFLOWW" << endl;
    else
        q->f++;
    a = q->arr[q->f];
    return a;
};
int dequeueR(queue_1 *q)
{
    int a = -1;
    if (q->f == q->r)
        cout << "UNDERFLOWW" << endl;
    else
        a = q->arr[q->r];
        q->r--;
    return a;
};
int main()
{
    queue_1 q;
    q.size = 10;
    q.f = q.r = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));
    if (isEmpty(&q))
        cout << "q is empty " << endl;
    enqueue(&q, 11);
    enqueue(&q, 22);
    enqueue(&q, 33);
    enqueue(&q, 44);
    enqueue(&q, 55);
    if (isFull(&q))
        cout << "q is full " << endl;
    else
        cout << "q is not full" << endl;
    cout << "dequeing ele " << dequeueF(&q) << endl;
    enqueueF(&q, 11);
    cout << "dequeing ele " << dequeueR(&q) << endl;
    enqueueR(&q, 55);
    if (isEmpty(&q))
        cout << "q is empty " << endl;
    else
        cout<<"not empty"<<endl;
    return 0;
}
*/

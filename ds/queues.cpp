/*
#include <iostream>

using namespace std;

void enqueue(int queue[], int element, int &rear, int arraySize)
{
    if (rear == arraySize)
    {
        cout << "Overflow" << endl;
    }
    else
    {
        queue[rear] == element;
        rear++;
    }
}
void dequeue(int queue[], int &front, int rear)
{
    if (front == rear)
    {
        cout << "underflow" << endl;
    }
    else
    {
        queue[front] = 0;
        front++;
    }
}


int main()
{

    return 0;
}
#include <iostream>

using namespace std;

void enqueue(char queue[], char element, int &rear, int arraySize)
{
    if (rear == arraySize)
    {
        cout << "overflow" << endl;
    }
    else
    {
        queue[rear] = element;
        rear++;
    }
}
void dequeue(char queue[], int &front, int rear)
{
    if (front == rear)
    {
        cout << "underflow" << endl;
    }
    else
    {
        queue[front] = 0;
        front++;
    }
}
char Front(char queue[], int front)
{
    return queue[front];
}

int main()
{
    char queue[20] = {'a','b','c','d'};
    int front = 0,int rear = 4;
    int arraySize = 20;
    int N = 3;              // Number of steps
    char ch;
    for ( int i = 0; i < N; i++)
    {
        ch = Front( queue ,front);
        enqueue(queue, ch, rear, arraySize);
        dequeue(queue, front, rear);
    }
    for (int i = front; i < rear; i++)
    {
        cout<<"%c",queue[i];
    }
    cout<<endl;
    return 0;
}
*/
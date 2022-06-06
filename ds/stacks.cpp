/*
#include <iostream>

using namespace std;

void push(int stack[], int x, int n,int top)
{
    if ( top == n - 1)
    {
        cout << "STACK IS FULL OVERFLOW CONDITION" << endl;
    }
    else
    {
        top = top + 1;
        stack[top] = x;
    }
}

void pop (int stack[ ] ,int n ) 
    {

        if( isEmpty ( ) )
        {
            cout << “Stack is empty. Underflow condition! ” << endl ;
        }
        else    
        {
             top = top - 1 ; //Decrementing top’s position will detach last element from stack            
        }
    }


#include <iostream>

using namespace std;

int top = -1;

void push(int stack[], int x, int n)
{
    if (top == n - 1)
    {
        cout << "stack is full overflow condition " << endl;
    }
    else
    {
        top = top + 1;
        stack[top] = x;
    }
}
bool isEmpty()
{
    if (top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void pop()
{
    if (isEmpty())
    {
        cout << "the stack is empty under flow condition" << endl;
    }
    else
    {
        top == top - 1;
    }
}
int size()
{
    return top + 1;
}

int topElement(int stack[])
{
    return stack[top];
}

int main()
{
    int stack[3];
    push(stack, 5, 3);
    cout << "current size of stack is " << size() << endl;
    push(stack, 10, 3);
    push(stack, 24, 3);
    cout << "current size of stack is " << size() << endl;
    push(stack, 12, 3);

    cout << "the top element in stack is " << topElement(stack) << endl;

    for (int i = 0; i < 3; i++)
        pop();
    cout << "current size of stack is " << size() << endl;
    pop();
    
    return 0;
}
*/
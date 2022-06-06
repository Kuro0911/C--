/*
//implementation
#include <bits/stdc++.h>

using namespace std;

class stack_1
{
public:
    int size;
    int top;
    int *arr;
};  
int isEmpty(stack_1 ptr)
{
    if (ptr.top == -1)
    {
        return 1;
    }
    else{
        return 0;
    }
};
int isFull(stack_1 ptr)
{
    if (ptr.top == ptr.size - 1)
    {
        return 1;
    }
    else{
        return 0;
    }

};
int main()
{
    stack_1 s;
    s.size = 8;
    s.top = -1;
    s.arr = (int *)malloc(s.size * sizeof(int));
    //stack_1 *s;
    //s->size = 8;
    //s->top = -1;
    //s->arr = (int *)malloc(s->size * sizeof(int));
    cout << "enter the values : " << endl;
    for (int i = 0; i < 4; i++)
    {
        cout << "value " << i << " is : ";
        int ele;
        cin >> ele;
        s.arr[i] = ele;
        s.top++;
    }
    if (isEmpty(s))
    {
        cout << "the stack is empty" << endl;
    }
    else
    {
        cout << "the stack is not empty" << endl;
    }
    if (isFull(s))
    {
        cout << "the stack is full" << endl;
    }
    else
    {
        cout << "the stack is not full" << endl;
    }

    return 0;
}
********opperations*********

#include <bits/stdc++.h>

using namespace std;

class stack_1
{
public:
    int size;
    int top;
    int *arr;
    void push(stack_1 ptr, int ele);
};
int isEmpty(stack_1 ptr)
{
    if (ptr.top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
};
int isFull(stack_1 ptr)
{
    if (ptr.top == ptr.size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
};
void stack_1 ::push(stack_1 ptr, int ele)
{
    ptr.top++;
    ptr.arr[ptr.top] = ele;
};
int pop(stack_1 ptr)
{
    int val = ptr.arr[ptr.top];
    ptr.top--;
    return val;
};
void peak(stack_1 sp)
{
    for (int i = 1; i <= sp.top + 1; i++)  
    {
        if ((sp.top - i + 1) < 0)
        {
            cout << "NOT A VALID POS" << endl;
            break;
        }
        else{
            cout << "the value at index " << i << " is " << sp.arr[sp.top - i + 1];
        }
    }
};
int stack_top(stack_1 sp){
    return sp.arr[sp.top];
};
int stack_bottom(stack_1 sp){
    return sp.arr[0];
};
int main()
{
    stack_1 s;  
    s.size = 4;
    s.top = -1;
    s.arr = (int *)malloc(s.size * sizeof(int));
    cout << "enter the values : " << endl;
    for (int i = 0; i < s.size; i++)
    {
        cout << "value " << i << " is : ";
        int val;
        cin >> val;
        s.push(s, val);
    }
    //PUSH

    //if (isFull(s))
    //{
    //    cout << "****STACK OVERFLOW****" << endl;
    //}
    //else
    //{
    //    s.push(s);
    //}

    //POP

    //if (isEmpty(s))
    //{
    //    cout << "****STACK UNDERFLOW****" << endl;
    //}
    //else
    //{
    //    pop(s);
    //}

    //PEAK
    //peak(s);

    //STACK TOP / BOTTOM;
    cout<<"the bottom ele of the satck is : "<<stack_bottom(s)<<endl;
    cout<<"the top ele of the satck is : "<<stack_top(s)<<endl;

    return 0;
}

//STACK USING LL;
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
int isEmpty(Node *top)
{
    if (top == NULL)
    {
        return 1;
    }
};
int isFull(Node *top)
{
    Node *p = (Node *)malloc(sizeof(Node));
    if (p == NULL)
    {
        return 1;
    }
};
int push(Node *tp, int x)
{
    if (isFull(&tp))
    {
        cout << "OVERFLOW" << endl;
    }
    else
    {
        Node *n = (Node *)malloc(sizeof(Node));
        n->data = x;
        n->next = tp;
        tp = n;
        return tp;
    }
};
int push(Node *tp, int x)
{
    if (isEmpty(tp))
    {
        cout << "UNDERFLOW" << endl;
    }
    else
    {
        Node *n = (Node *)malloc(sizeof(Node));
        top = tp->next;
        int x = x.data;
        free(n);
        return x;
    }
};
int peek(int pos){
    Node * ptr = top;
    for (int i = 0;(i<pos-1 && ptr != NULL); i++)
    {
        ptr = ptr->next;
    }
    if (ptr != NULL)
    {
        return ptr->data;
    }
    else{return -1};
    
};
int stackTOP(){
    return top -> data;
}
int stackBOTTOM(){
    
}
int main()
{
    Node * top = NULL;
    top = push(top , 78);
    
    lltraversal(top);
    return 0;
}


#include <bits/stdc++.h>

using namespace std;

class stack_1
{
public:
    int size;
    char top;
    char *arr;
};
int isEmpty(stack_1 ptr)
{
    if (ptr.top == -1)
    {
        return 1;
    }
    else{
        return 0;
    }
};
int isFull(stack_1 ptr)
{
    if (ptr.top == ptr.size - 1)
    {
        return 1;
    }
    else{
        return 0;
    }

};
int main()
{
    stack_1 s;
    char exp[1000];
    cout << "enter the expression : " << endl;
    cin>>exp;
    int n =  exp.size();
    
    s.size = n;
    s.top = -1;
    s.arr = (int *)malloc(s.size * sizeof(int));

    return 0;
}

//parenthesis matching;

#include <bits/stdc++.h>

using namespace std;

class stack_1
{
public:
    int size;
    int top;
    char *arr;
};
void push(stack_1 * ptr, char ele)
{
    ptr->top++;
    ptr->arr[ptr->top] = ele;
};
char pop(stack_1 * ptr)
{
    char val = ptr->arr[ptr->top];
    ptr->top--;
    return val;
};
int isEmpty(stack_1 * ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else{
        return 0;
    }
};
int isFull(stack_1 * ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else{
        return 0;
    }

};
int p_Match(char * exp){
    stack_1 * sp;
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    for (int i = 0;exp[i]!='\0'; i++)
    {
        if (exp[i]=='(')
        {
            push(sp , '(');
        }
        else if (exp[i]==')')
        {
            if (isEmpty(sp))
            {
                return 0;
            }
            pop(sp);
        }
    }
    if (isEmpty(sp))
    {
        return 1;
    }
    return 0;
};
int main()
{
    char * exp = "8*(9";
    if (p_Match(exp))
    {
        cout<<"the p is matching"<<endl;
    }
    else
    {
        cout<<"the p is not matching"<<endl;
    }

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

class stack_1
{
public:
    int size;
    int top;
    char *arr;
};
void push(stack_1 *ptr, char ele)
{
    ptr->top++;
    ptr->arr[ptr->top] = ele;
};
char pop(stack_1 *ptr)
{
    char val = ptr->arr[ptr->top];
    ptr->top--;
    return val;
};
int isEmpty(stack_1 *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
};
int isFull(stack_1 *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
};
int match(char a, char b)
{
    if (a == '{' && b == '}')
    {
        return 1;
    }
    if (a == '[' && b == ']')
    {
        return 1;
    }
    if (a == '(' && b == ')')
    {
        return 1;
    }
    return 0;
};
int multy_p_Match(char *exp)
{
    stack_1 *sp;
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    char popped_ch;
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(sp, exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (isEmpty(sp))
            {
                return 0;
            }
            popped_ch = pop(sp);
            if (!match(popped_ch , exp[i]))
            {
                return 0;
            }
        }
    }
    if (isEmpty(sp))
    {
        return 1;
    }
    return 0;
};
int main()
{
    char *exp = "[{8(4)]*(9)";
    if (multy_p_Match(exp))
    {
        cout << "the p is matching" << endl;
    }
    else
    {
        cout << "the p is not matching" << endl;
    }

    return 0;
}
//infic to postfix
#include <bits/stdc++.h>

using namespace std;

class stack_1
{
public:
    int size;
    int top;
    char *arr;
};
void push(stack_1 *ptr, char ele)
{
    ptr->top++;
    ptr->arr[ptr->top] = ele;
};
char pop(stack_1 *ptr)
{
    char val = ptr->arr[ptr->top];
    ptr->top--;
    return val;
};
int stack_top(stack_1 * sp){
    return sp->arr[sp->top];
};
int isEmpty(stack_1 *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
};
int isFull(stack_1 *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
};
int precedence(char ch){
    if (ch == '*' || ch == '/')
        return 3;
    else if (ch == '+' || ch == '-')
        return 1;
    else
        return 0;
};
int isOperator(char ch){
    if(ch=='+' || ch=='*' || ch=='/')
        return 1;
    else
        return 0;
};
char * infix_to_postfix(char * infix){
    stack_1 * sp = (stack_1 *) malloc(sizeof(stack_1));
    sp->size = 45;
    sp->top = -1;
    sp->arr = (char *) malloc(sp->size * sizeof(char));
    char * postfix = (char *) malloc((strlen(infix)+1) * sizeof(char));
    int i = 0;
    int j = 0;
    while (infix[i]!='\0')
    {
        if (!isOperator(infix[i]))
        {
            postfix[j] = infix[i];
            j++;
            i++;
        }
        else{
            if (precedence(infix[i]) > precedence(stack_top(sp)))
            {
                push(sp , infix[i]);
                i++;
            }
            else{
                postfix[j] = pop(sp);
                j++;
            }
        }
    }
    while (!isEmpty(sp))
    {
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
};
int main()
{
    char * infix = "a-b+t/6";
    cout<<"postfix is "<<infix_to_postfix(infix)<<endl;
    return 0;
}
*/
// infix to postfix
#include <iostream>
#include <stack>
#include <string>
using namespace std;

void PF(string a)
{
  cout << a << endl;
  stack<char> S;
  string postfix = "";
  int l = a.length();
  for (int i = 0; i < l; i++)
  {
    char c = a[i];
    cout << c << endl;
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
    {
      postfix += c;
    }

    else if (c == '(')
      S.push(c);

    else if (c == ')')
    {
      while (S.top() != '(')
      {
        postfix += S.top();
        S.pop();
      }
      S.pop();
    }
    else if (c == '-')
    {
      if (!S.empty())
      {
        while (S.top() != '(' )
        {
          postfix += S.top();
          S.pop();
          if(S.empty()){
                break;
            }
        }
        S.push(c);
      }
      else
        S.push(c);
    }

    else if (c == '+')
    {
      if (!S.empty())
      {
        while ( S.top() != '(')
        {
            postfix += S.top();
            S.pop();
            if(S.empty()){
                break;
            }
        }
        S.push(c);
      }
      else
        S.push(c);
    }

    else if (c == '*')
    {
      if (!S.empty())
      {
        while (S.top() != '+' || S.top() != '-' || S.top() != '(')
        {
          postfix += S.top();
          S.pop();
          if(S.empty()){
                break;
            }
        }
        S.push(c);
      }
      else
        S.push(c);
    }
    else if (c == '/')
    {
      if (!S.empty())
      {
        while (S.top() != '+' || S.top() != '-' || S.top() != '(' )
        {
          postfix += S.top();
          S.pop();
          if(S.empty()){
                break;
            }
        }
        S.push(c);
      }
      else
        S.push(c);
    }
  }
  while (!S.empty())
  {
    postfix += S.top();
    S.pop();
  }
  cout << endl
       << postfix;
}

int main()
{
  string s;
  cin >> s;
  PF(s);
  return 0;
}
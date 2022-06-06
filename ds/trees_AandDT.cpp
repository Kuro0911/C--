/*
//implementation;
#include <bits/stdc++.h>

using namespace std;
class node{
    public:
        int data;
        node * left;
        node * right;
};
node * createNode(int data){
    node *n;
    n = (node *)malloc(sizeof(node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
};
int main(){

    //one way
    //CONSTRUCTING THE ROOT NODE;
    //node *p;
    //p = (node *)malloc(sizeof(node));
    //p->data = 2;
    //p->left = NULL;
    //p->right = NULL;
    //
    //CONSTRUCTING THE FIRST NODE;
    //node *p1;
    //p1 = (node *)malloc(sizeof(node));
    //p1->data = 4;
    //p1->left = NULL;
    //p1->right = NULL;

    //CONSTRUCTING THE SECOND NODE;
    //node *p2;
    //p2 = (node *)malloc(sizeof(node));
    //p2->data = 8;
    //p2->left = NULL;
    //p2->right = NULL;

    //linking the root node to the children
    //p->left = p1;
    //p->right = p2;

    // OR;
    //CONSTRUCTING THE ROOT NODE;
    node * p = createNode(2);
    node * p1 = createNode(4);
    node * p2 = createNode(8);
    return 0;
}

//Preorder Traversal // preorder Traversal //InOrder  Traversal
#include <bits/stdc++.h>

using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
};
node *createNode(int data)
{
    node *n;
    n = (node *)malloc(sizeof(node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
};
void preorder(node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
};
void postorder(node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
};
void inorder(node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
};
int main()
{
    node *p = createNode(4);
    node *p1 = createNode(1);
    node *p2 = createNode(6);
    node *p3 = createNode(5);
    node *p4 = createNode(2);
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    cout<<"preorder : ";
    preorder(p);
    cout<<endl;
    cout<<"postorder : ";
    postorder(p);
    cout<<endl;
    cout<<"INorder : ";
    inorder(p);
    return 0;
}

//binary search tree
#include <bits/stdc++.h>

using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
};
node *createNode(int data)
{
    node *n;
    n = (node *)malloc(sizeof(node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
};
void inorder(node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
};
bool isBST(node *root)
{
    static node *prev = NULL;
    if (root != NULL)
    {
        if(!isBST(root->left)){
            return false;
        }
        if(prev!=NULL && root->data <= prev->data){
            return false;
        }
        prev = root;
        return isBST(root->right);
    }
    else{
        return true;
    }
};
int main()
{
    node *p = createNode(5);
    node *p1 = createNode(3);
    node *p2 = createNode(6);
    node *p3 = createNode(1);
    node *p4 = createNode(4);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    inorder(p);
    cout<<endl;
    if (isBST(p))
        cout<<"is BST"<<endl;
    else
        cout<<"is not BST"<<endl;
    return 0;
}

//search in BST;

#include <bits/stdc++.h>

using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
};
node *createNode(int data)
{
    node *n;
    n = (node *)malloc(sizeof(node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
};
node * search(node * root , int key){
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == key)
    {
        return root;
    }
    else if (root->data>key)
    {
        return search(root->left , key);
    }
    else
    {
        return search(root->right, key);
    }
};
int main()
{
    node *p = createNode(5);
    node *p1 = createNode(3);
    node *p2 = createNode(6);
    node *p3 = createNode(1);
    node *p4 = createNode(4);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    node *n = search(p , 4);
    if(n!=NULL)
        cout<<"found : "<<n->data<<endl;
    else
        cout<<"not found"<<endl;
    return 0;
}

//iter search
#include <bits/stdc++.h>

using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
};
node *createNode(int data)
{
    node *n;
    n = (node *)malloc(sizeof(node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
};
node * searchITER(node * root , int key){
    while(root!=NULL){
        if (key == root->data)
        {
            return root;
        }
        else if (key<root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return NULL;
};
int main()
{
    node *p = createNode(5);
    node *p1 = createNode(3);
    node *p2 = createNode(6);
    node *p3 = createNode(1);
    node *p4 = createNode(4);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    node *n = searchITER(p , 4);
    if(n!=NULL)
        cout<<"found : "<<n->data<<endl;
    else
        cout<<"not found"<<endl;
    return 0;
}

//insertion and deletion ;
#include <bits/stdc++.h>

using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
};
node *createNode(int data)
{
    node *n;
    n = (node *)malloc(sizeof(node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
};
node * inOrderPre(node *root){
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return NULL;

};
node * searchITER(node * root , int key){
    while(root!=NULL){
        if (key == root->data)
        {
            return root;
        }
        else if (key<root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return NULL;
};
void insert(node *root , int key){
    node *prev = NULL;
    while (root!=NULL)
    {
        prev = root;
        if (key == root->data)
        {
            return;
        }
        else if (key<root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    node * New = createNode(key);
    if (key<prev->data)
    {
        prev->left = New;
    }
    else{
        prev->right = New;
    }
};
node *deletenode(node *root , int val){
    node * iPre;
    if (root == NULL)
    {
        return NULL;
    }
    if (root->left == NULL && root->right == NULL )
    {
        free(root);
        return NULL;
    }

    if (val<root->data)
    {
        root->left=deletenode(root->left , val);
    }
    else if (val>root->data)
    {
        root->right=deletenode(root->right , val);
    }
    else{
        iPre = inOrderPre(root);
        root->data = iPre->data;
        root->left = deletenode(root->left , iPre->data);
    }
    return root;
};

int main()
{
    node *p = createNode(5);
    node *p1 = createNode(3);
    node *p2 = createNode(6);
    node *p3 = createNode(1);
    node *p4 = createNode(4);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    deletenode(p , 6);
    insert(p , 6);d
    node *n = searchITER(p , 6);
    if(n!=NULL)
        cout<<"found : "<<n->data<<endl;
    else
        cout<<"not found"<<endl;

    return 0;
}
****************************************************************************************************************************************************
my code school

****************************************************************************************************************************************************

*/
#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *left;
    node *right;
};
node *root = NULL;
node *getNewNode(int data)
{
    node *newNode = new node();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
node *insert(node *root, int info)
{
    if (root == NULL)
    {
        root = getNewNode(info);
        return root;
    }
    else if (info <= root->data)
    {
        root->left = insert(root->left, info);
    }
    else
    {
        root->right = insert(root->right, info);
    }
    return root;
}
void printPreorder(node *node)
{
    if (node == NULL)
        return;
    cout << node->data << " ";
    printPreorder(node->left);
    printPreorder(node->right);
}
void printInorder(node *node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}
void printPostorder(node *node)
{
    if (node == NULL)
        return;
    printPostorder(node->left);
    printPostorder(node->right);
    cout << node->data << " ";
}
int main()
{
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        root = insert(root, x);
    }
    printPreorder(root);
    cout << "\n";
    printInorder(root);
    cout << "\n";
    printPostorder(root);
    return 0;
}

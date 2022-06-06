/*
rotation in avl tree: 
why to have a balace factor
Balance Factor: 
it is the height of r subtree - height of l subtree;
Types of Roation:
LL rotion:left of left insert -- Right rotate once wrt the first imbalanced mode
RR rotion:right of right insert -- left rotate once wrt the first imbalanced node
LR rotion:left of right insert -- Left rotate once and then right rotate once
RL rotion:right of left insert -- right rotate once and then left rotate once
*/
#include <bits/stdc++.h>
using namespace std;
struct node{
    int key;
    node * right;
    node * left;
    int height;
};

int getHeight(node *n){
    if(n==NULL) return 0;
    return n->height;
}

node *getNode(int k){
    node* temp = new node();
    temp->key = k;
    temp->right = NULL;
    temp->left = NULL;
    temp->height = 1;
    return temp;
}

int getBF(node *n){
    if(n==NULL) return 0;
    return getHeight(n->left) - getHeight(n->right);
}

node* rightRotate(node *y){
    node *x = y->left;
    node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->right) , getHeight(y->left));
    x->height = max(getHeight(x->right) , getHeight(x->left));


    return x;
}

node* leftRotate(node *x){
    node *y = x->right;
    node* T2 = y->left;
    
    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->right) , getHeight(x->left)) + 1;
    y->height = max(getHeight(y->right) , getHeight(y->left)) + 1;


    return y;
}

node *insert(node* node,int k){
    if(node == NULL) return(getNode(k));
    if(k<node->key) node->left = insert(node->left, k);
    else if(k>node->key) 
        node->right = insert(node->right, k);
    node->height = 1 + max(getHeight(node->right) , getHeight(node->left));
    int bf = getBF(node);
    //4 cases : 
    //LL
    if(bf>1 && k < node->left->key){
        return rightRotate(node);
    }
    //RR
    if(bf<-1 && k > node->right->key){
        return leftRotate(node);
    }
    //LR
    if(bf>1 && k > node->left->key){
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    //RL
    if(bf<-1 && k < node->right->key){
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

void preOrder(node *root){
    if(root!=NULL){
        cout<<root->key<<" ";
        preOrder(root->left);
        preOrder(root->right);
    }
}
void inOrder(node *root){
    if(root!=NULL){
        inOrder(root->left);
        cout<<root->key<<" ";
        inOrder(root->right);
    }
}
void postOrder(node *root){
    if(root!=NULL){
        postOrder(root->left); 
        postOrder(root->right);
        cout<<root->key<<" ";
    }
}
int main(){
    node *root = NULL;
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 3);
    preOrder(root);cout<<endl;
    inOrder(root);cout<<endl;
    postOrder(root);
    return 0;
}
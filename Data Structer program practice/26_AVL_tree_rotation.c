
// AVL tree rotation 
// LL rotation
// RR rotation
// LR rotation
// RR rotation

#include<stdio.h>
#include<stdlib.h>


struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    int height;
};

int getHeight(struct Node *n)
{
    if(n == NULL)
    {
        return 0;
    }
    else
        return n->height;
}

struct Node* CreateNode(int key)
{
    struct Node *node = (struct Node*)malloc(sizeof(struct Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

int getbalance_factor(struct Node *n)
{
    if(n==NULL)
         return 0;
    return getHeight(n->left) - getHeight(n->right);

}

struct Node* Right_rotate(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *T2 = x->right;
    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->right), getHeight(y->left))+1;
    x->height = max(getHeight(x->right), getHeight(x->left))+1;

    return x;

}

struct Node* Left_rotate(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *T2 = y->left;
    y->left = x;
    x->right = T2;

    y->height = max(getHeight(y->right), getHeight(y->left))+1;
    x->height = max(getHeight(x->right), getHeight(x->left))+1;

    return x;

}

struct Node* Insert(struct Node *node)
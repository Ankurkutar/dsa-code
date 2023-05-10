
// Deletion in binary tree;

//  the node is a leaf Node
//  the node is a none leaf node
//  the node is the root node

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *right;
    struct Node *left;
};

struct Node *CreateNode(int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;
}

void InOrder(struct Node *root)
{
    if (root != NULL)
    {
        InOrder(root->left);
        printf("%d ", root->data);
        InOrder(root->right);
    }
}

void Binary_Insertion(struct Node *root, int key)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = key;
    ptr->left = NULL;
    ptr->right = NULL;

    struct Node *prev = NULL;
    while (root != NULL)
    {
        prev = root;
        if (key == root->data)
        {
            printf("Invalid Insertion this Node already exist:\n");
            return;
        }
        else if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    if (key < prev->data)
    {
        prev->left = ptr;
    }
    else
    {
        prev->right = ptr;
    }
    printf("Node Inserted: %d\n", key);
}

struct Node* inOrderPredecessor(struct Node *root)
{
    root = root->left;
    while(root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

struct Node* DeleteNode(struct Node *root,int value)
{
    struct Node *ipre;
    if(root == NULL)
    {
        return NULL;
    }
    else if(root->left == NULL && root->right == NULL)
    {
        free(root);
        return NULL;
    }
    else if(value < root->data)
    {
        root->left = DeleteNode(root->left,value);
    }
    else if(value > root->data)
    {
        root->right = DeleteNode(root->right,value);
    }
    else
    {
        ipre = inOrderPredecessor(root);
        root->data = ipre->data;
        root->left = DeleteNode(root->left,ipre->data);
    }
    return root;
}

int main()
{
    struct Node *p1 = CreateNode(75);
    struct Node *p2 = CreateNode(65);
    struct Node *p3 = CreateNode(95);
    struct Node *p4 = CreateNode(55);
    struct Node *p5 = CreateNode(69);

    p1->left = p2;
    p1->right = p3;

    p2->left = p4;
    p2->right = p5;

    printf("InOrder traversal is:\n");
    InOrder(p1);
    printf("\n");
    printf("After Deletion:\n");
    DeleteNode(p1,55);
    // printf("\n");
    InOrder(p1);
    return 0;
}
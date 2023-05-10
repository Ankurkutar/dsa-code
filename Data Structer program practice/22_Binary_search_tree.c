

/// binary search tree in this program we search any specific item

// binary tree using linked list

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    struct Node *right;
    int data;
    struct Node *left;
};

struct Node *CreateNode(int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->right = NULL;
    ptr->left = NULL;
    return ptr;
}

void InOrder_traversing(struct Node *root)
{
    if (root != NULL)
    {
        InOrder_traversing(root->left);
        printf("%d ", root->data);
        InOrder_traversing(root->right);
    }
}

void preOrder_traversing(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        InOrder_traversing(root->left);
        InOrder_traversing(root->right);
    }
}

void postOrder_traversing(struct Node *root)
{
    if (root != NULL)
    {
        InOrder_traversing(root->left);
        InOrder_traversing(root->right);
        printf("%d ", root->data);
    }
}

struct Node *search(struct Node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (key == root->data)                  // using recursion part
    {
        return root;
    }
    else if (key > root->data)
    {
        return search(root->right, key);
    }
    else
    {
        return search(root->left, key);
    }
}

int main()
{
    struct Node *p1 = CreateNode(54);
    struct Node *p2 = CreateNode(45);
    struct Node *p3 = CreateNode(60);
    struct Node *p4 = CreateNode(40);
    struct Node *p5 = CreateNode(48);

    p1->left = p2;
    p1->right = p3;
    p2->left = p4;
    p2->right = p5;

    preOrder_traversing(p1);
    printf("\n");
    postOrder_traversing(p1);
    printf("\n");
    InOrder_traversing(p1);

    struct Node *n = search(p1,48);

    if(n != NULL)
    {
        printf("\nElement found: %d\n",n->data);
    }
    else
    {
        printf("\nElement not found:");
    }

    return 0;
}
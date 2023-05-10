
// Binary tree check if is it Binary or not 
// this function is very complicated


// binary tree using linked list

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    struct Node *right;
    int data;
    struct Node *left;
};

struct Node* CreateNode(int data)
{
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->right = NULL;
    ptr->left = NULL;
    return ptr;
}

void InOrder_traversing(struct Node *root)
{
    if(root != NULL)
    {
        InOrder_traversing(root->left);
        printf("%d ",root->data);
        InOrder_traversing(root->right);
    }
}

void preOrder_traversing(struct Node *root)
{
    if(root != NULL)
    {
        printf("%d ",root->data);
        InOrder_traversing(root->left);
        InOrder_traversing(root->right);
    }
}

void postOrder_traversing(struct Node *root)
{
    if(root != NULL)
    {
        InOrder_traversing(root->left);
        InOrder_traversing(root->right);
        printf("%d ",root->data);
    }
}

int isBST(struct Node *root)
{
    static struct Node *prev = NULL;         // this function is very complicated
    if(root != NULL)
    {
        if(!isBST(root->left))
        {
            return 0;
        }
        if(prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return(isBST(root->right));
    }
    else{
        return 1;
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
    printf("\n");
    
    if(isBST(p1))
    {
        printf("this is bst:\n");
    }
    else
    {
        printf("this is not bst:\n");
    }

    return 0;
}
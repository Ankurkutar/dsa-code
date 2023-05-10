
// insertion in binary tree


#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *right;
    struct Node *left;
};

struct Node* CreateNode(int data)
{
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;
}

void InOrder(struct Node *root)
{
    if(root != NULL)
    {
        InOrder(root->left);
        printf("%d ",root->data);
        InOrder(root->right);
    }
   
}

void Binary_Insertion(struct Node *root, int key)
{
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = key;
    ptr->left = NULL;
    ptr->right = NULL;

    struct Node *prev = NULL;
    while(root != NULL)
    {
        prev = root;
        if(key == root->data)
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
    if(key < prev->data)
    {
        prev->left = ptr;
    }
    else{
        prev->right = ptr;
    }
    printf("Node Inserted: %d\n", key);
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
    Binary_Insertion(p1,69);
    printf("\n");
    InOrder(p1);
    return 0;
}
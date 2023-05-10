

//  linked list using stack peek operation;

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

    struct Node *head = NULL;

void linkedlist_traversal(struct Node *head)
{
    struct Node *ptr = head;
    while(ptr != NULL)
    {
        printf("%d\n",ptr->data);
        ptr = ptr->next;
    }
}

int isEmpty(struct Node *top)
{
    // struct Node *p = ptr;..
    if(top == NULL)
    {
        return 1;
    }else{
        return 0;
    }
}

int isFull(struct Node *ptr)
{
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    if(temp == NULL)
    {
        return 1;
    }else{
        return 0;
    }
}

struct Node* push(struct Node *ptr, int value)
{
    if(isFull(ptr))
    {
        printf("Stack is overflow:\n");
    }
    else{
        struct Node *p = (struct Node*)malloc(sizeof(struct Node));
        p->data = value;
        p->next = ptr;
        ptr = p;
        printf("Element is pushed %d\n",value);
        return ptr;

    }
}

int pop(struct Node *ptr)
{
    if(isEmpty(ptr)){
        printf("Stack is underflow:\n");
    }
    else{
        struct Node *p = ptr;
        ptr = ptr->next;
        int x = p->data;
        free(p);
        return(x);
    }
}

int peek(int position)
{
    struct Node *ptr = head;
    for(int i = 0; (i < position-1 && ptr != NULL); i++)
    {
        ptr = ptr->next;
    }
    if(ptr != NULL)
    {
        return ptr->data;
    }
    else{
        return -1;
    }
}

int main()
{
    // struct Node *head = NULL;
    // if(isEmpty(head)){
    //     printf("list is empty:\n");
    // }else{
    //     printf("list is full\n");
    // }
    head = push(head,35);
    head = push(head,16);
    head = push(head,10);
    head = push(head,33);
    head = push(head,43);

    // printf("popped element %d",pop(head));
    printf("peek element is %d ",peek(3));

    return 0;
}

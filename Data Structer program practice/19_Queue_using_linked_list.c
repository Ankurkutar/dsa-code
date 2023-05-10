
// Queue implementation  using linked list

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *f = NULL;
struct Node *r = NULL;

void linked_list_traversal(struct Node *ptr)
{
    printf("Element is printing...........\n");
    while(ptr != NULL)
    {
        printf("Element is %d\n",ptr->data);
        ptr = ptr->next;
    }
}

int isEmpty(struct Node *ptr)
{
    if(ptr == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct Node *ptr)
{
    struct Node *p = (struct Node*)malloc(sizeof(struct Node));
    if(p == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueue(int data)
{
    struct Node *p = (struct Node*)malloc(sizeof(struct Node));
    if(p == NULL)
    {
        printf("linked list is full:\n");
    }
    else
    {
        p->data = data;
        p->next = NULL;
        if(f == NULL)
        {
            r = f = p;
            printf("Element enqueued %d\n",data);
        }
        else
        {
            r->next = p;
            r = p;
            printf("Element enqueued %d\n",data);
        }
    }
}

int dequeue()
{
    int a = -1;
    struct Node *ptr = f;
    if(f == NULL)
    {
        printf("linked list is Empty:\n");
    }
    else
    {
        
        a = f->data;
        f = f->next;
        free(ptr);
    }
    return a;
}

int main()
{
    printf("linked list has been succesfully created:\n");

    enqueue(20);
    enqueue(23);
    enqueue(18);
    enqueue(15);

    linked_list_traversal(f);

    printf("dequeued element is %d\n",dequeue());
    printf("dequeued element is %d\n",dequeue());
    printf("dequeued element is %d\n",dequeue());
    linked_list_traversal(f);

    return 0;
}
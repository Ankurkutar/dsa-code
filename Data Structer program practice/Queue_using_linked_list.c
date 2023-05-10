

// Implementation of Queue using singly linked list

#include<stdio.h>
#include<stdlib.h>

struct Node 
{
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;


void enqueue();
void dequeue();
void show();

int main()
{
    // printf("Enter Size of Element: ");
    // scanf("%d",&n);

    int choice = 0;
    printf("\n***************Queue Operation Using Linked list***************\n\n");
    printf("-----------------------------------------\n");

    while (choice != 4)
    {
        printf("\nChoose one from given option:\n");
        printf("=====================");
        printf("\n1.Enqueue\n2.Dequeue\n3.show\n4.Exit(0)\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            show();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("please enter valid choice\n");
            break;
        }
    }
    return 0;
}

void enqueue()
{
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    if(ptr == NULL){
        printf("Queue is Overflow");
    }
    else
    {
        int data;
        printf("Enter a Node: ");
        scanf("%d",&data);
        ptr->data = data;
        if(front == NULL)
        {
            ptr->next = NULL;
            front = rear = ptr;
            printf("Enqueued %d:\n",data);
        }
        else
        {
            rear->next = ptr;
            ptr->next = NULL;
            rear = ptr;
            printf("Enqueued %d: ",data);
        }
    }
}

void dequeue()
{
    if(front == rear)
    {
        printf("Queue is Underflow:\n");
    }
    else
    {
        struct Node *ptr = front;
        int val = front->data;
        front = front->next;
        free(ptr);
        printf("Dqueued %d:\n",val);
    }
}

void show()
{
    if(rear == front)
    {
        printf("Queue is Empty:\n");
    }
    else{
        struct Node *ptr = front;
        while (ptr != NULL)
        {
            printf("%d  ",ptr->data);
            ptr = ptr->next;
        }
        
    }
}
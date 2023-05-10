

// Circular queue using linked list by the javatpoint

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *front = -1;
struct Node *rear = -1;

void enqueue()
{
    int data;
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    if (ptr == NULL)
    {
        printf("List is full:\n");
    }
    printf("Enter node: ");
    scanf("%d", &data);
    ptr->data = data;
    ptr->next = NULL;
    if (rear == -1)
    {
        front = rear = ptr;
        rear->next = front;
    }
    else
    {
        rear->next = ptr;
        rear = ptr;
        rear->next = front;
    }
}

void dequeued()
{
    struct Node *ptr = front;
    int data;
    if ((front == -1) && (rear == -1))
    {
        printf("linked list is empty:\n");
    }
    else if (front == rear)
    {
        data = front->data;
        front = rear = -1;
        free(ptr);
        printf("dequed element %d \n",data);
    }
    else
    {
        data = front->data;
        front = front->next;
        rear->next = front;
        free(ptr);
        printf("dequed element %d \n",data);
    }
}

void display()
{
    struct Node *ptr = front;
    if((front == -1)&&(rear == -1))
    {
    printf("linked list is empty:\n");

    }
    else
    {
        printf("Element are:\n");
        while(ptr->next != front)
        {
            printf("%d  ",ptr->data);
            ptr= ptr->next;
        }
        printf("%d  ",ptr->data);
    }
}

void peek()
{
    if((front == -1)&&(rear == -1))
    {
    printf("linked list is empty:\n");
    }
    else
    {
        printf("%d  ",front->data);
    }
}

int main()
{
    int choice;
   printf("\n*************************Circular Queue Using Linked list***********************\n\n");
    printf("---------------------------------------------------------------\n\n");
    while (1)
    {
        printf("\nChoose one Option from the list:\n");
        printf("=======================\n");
        printf("\n1.Enqueue\n2.Dequeue\n3.Show\n4.peek()\n5.Exit(0)\n");
        printf("\nEnter Your Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeued();
            break;
        case 3:
            display();
            break;
        case 4:
            peek();
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("Enter the valid Choice:\n");
            break;
        }
    }
    return 0;
}
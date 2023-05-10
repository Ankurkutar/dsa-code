

// Implementation of circular queue using Array by javatpoint

#include <stdio.h>
#include <stdlib.h>
#define max 6

int queue[max];
int front = -1;
int rear = -1;
int number;

void enqueue()
{
    int data;
    printf("Enter the number: ");
    scanf("%d", &data);
    if (front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
        queue[rear] = data;
        // queue[front] = data;
        printf("pushed %d ", data);
    }
    else if ((rear + 1) % max == front)
    {
        printf("Queue is Overflow:\n");
    }
    else
    {
        rear = (rear + 1) % max;
        queue[rear] = data;
        printf("pushed %d ", data);
    }
}

void dequeue()
{
    int val;
    if (front == -1 && rear == -1)
    {
        printf("Queue is underflow:\n");
    }
    else if (front == rear)
    {
        printf("the dequeue element is: %d ", queue[front]);
        front = -1;
        rear = -1;
    }
    else
    {
        printf("the dequeue element is: %d ", queue[front]);
        front = (front + 1) % max;
    }
}

void display()
{
    int i;
    if (front == -1 && rear == -1)          // display function is not working properly
    {
        printf("Queue is Empty:\n");
    }
    else
    {
        printf("The Element of Queue are:\n");
        for (i = front; i <= rear; i = (i + 1) % max)
        {
            printf("%d  ", queue[i]);
        }
    }
}

int main()
{
    int choice = 0;
    // printf("Enter the Size of Queue: ");
    // scanf("%d", &number);
    printf("\n*************************Circular Queue Using Array***********************\n\n");
    printf("---------------------------------------------------------------\n\n");
    while (1)
    {
        printf("\nChoose one Option from the list:\n");
        printf("=======================\n");
        printf("\n1.Enqueue\n2.Dequeue\n3.Show\n4.Exit(0)\n");
        printf("\nEnter Your Choice: ");
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
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Enter the valid Choice:\n");
            break;
        }
    }
    return 0;
}
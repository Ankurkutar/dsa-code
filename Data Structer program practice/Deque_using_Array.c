

//  dequeue means double ended queue

// overflow condition is not working properly means after overflow it delete few element


#include <stdio.h>
#include <stdlib.h>
#define size 5

int deque[size];

int front = -1, rear = -1;

void insert_front()
{
    int data;
    if ((front == 0 && rear == size - 1) || (front == rear + 1))
    {
        printf("Overflow:\n");
    }

    printf("Enter the Element: ");
    scanf("%d", &data);

    if ((front == -1) && (rear == -1))
    {
        front = rear = 0;
        deque[front] = data;
    }
    else if (front == 0)
    {
        front = size - 1;
        deque[front] = data;
    }
    else
    {
        front = front - 1;
        deque[front] = data;
    }
}

void insert_rear()
{
    int data;
    if ((front == 0 && rear == size - 1) || (front == rear + 1))
    {
        printf("Overflow:\n");
    }
    printf("Enter the Element: ");
    scanf("%d", &data);
    if ((front == -1) && (rear == -1))
    {
        rear = 0;
        deque[rear] = data;
    }
    else if (rear == size - 1)
    {
        rear = 0;
        deque[rear] = data;
    }
    else
    {
        rear++;
        deque[rear] = data;
    }
}

void display()
{
    int i = front;
    if (front == -1 && rear == -1)
    {
        printf("Deque is Empty:\n");
    }
    else
    {
        printf("\nElement in a deque are:\n");
        while (i != rear)
        {
            printf("%d  ", deque[i]);
            i = (i + 1) % size;
        }
        printf("%d  ", deque[rear]);
    }
}

void get_front()
{
    if (front == -1 && rear == -1)
    {
        printf("Deque is Empty:\n");
    }
    else
    {
        printf("The value of the front is %d", deque[front]);
    }
}

void get_rear()
{
    if (front == -1 && rear == -1)
    {
        printf("Deque is Empty:\n");
    }
    else
    {
        printf("The value of the front is %d", deque[rear]);
    }
}

void delete_front()
{
    int data;
    if (front == -1 && rear == -1)
    {
        printf("Deque is Empty:\n");
    }
    else if (front == rear)
    {
        printf("Dequeued Element %d: ", deque[front]);
        front = -1;
        rear = -1;
    }
    else if (front == size - 1)
    {
        printf("Dequeued Element %d: ", deque[front]);
        front = 0;
    }
    else
    {
        printf("Dequeued Element %d: ", deque[front]);
        front++;
    }
}

void delete_rear()
{
    if (front == -1 && rear == -1)
    {
        printf("Deque is Empty:\n");
    }
    else if (front == rear)
    {
        printf("Dequeued Element %d: ", deque[rear]);
        front = -1;
        rear = -1;
    }
    else if (rear == 0)
    {
        printf("Dequeued Element %d: ", deque[rear]);
        rear = size - 1;
    }
    else
    {
        printf("Dequeued Element %d: ", deque[rear]);
        rear = rear - 1;
    }
}

int main()
{
    int choice;
    printf("\n*************************Dqueue Using Array***********************\n\n");
    printf("---------------------------------------------------------------\n\n");
    while (1)
    {
        printf("\nChoose one Option from the list:\n");
        printf("=======================\n");
        printf("\n1.Insert_front\n2.Insert_rear\n3.Show\n4.get_front()\n5.get_rear()\n6.delete_front()\n7.delete_rear()\n8.Exit(0)\n");
        printf("\nEnter Your Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert_front();
            break;
        case 2:
            insert_rear();
            break;
        case 3:
            display();
            break;
        case 4:
            get_front();
            break;
        case 5:
            get_rear();
            break;
        case 6:
            delete_front();
            break;
        case 7:
            delete_rear();
            break;
        case 8:
            exit(0);
            break;
        default:
            printf("Enter the valid Choice:\n");
            break;
        }
    }
    return 0;
}
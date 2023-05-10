
// Queue implementation using array 

#include<stdio.h>
#include<stdlib.h>

int queue[100],n;
int front  = 0,rear = 0;


void enqueue();
void dequeue();
void show();

int main()
{
    printf("Enter Size of Element: ");
    scanf("%d",&n);

    int choice = 0;
    printf("\n***************Queue Operation Using Array***************\n\n");
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
    if(n == rear) 
    {
        printf("Queue is Overflow:\n");
    }
    else
    {
        int item;
        printf("Enter the Element: ");
        scanf("%d",&item);
        rear++;
        queue[rear] = item;
        printf("Enqueued %d \n",item);
    }
}

void dequeue()
{
    if(rear == front)
    {
        printf("Queue is Undeflow:\n");
    }
    else
    {
        int item;
        front++;
        item = queue[front];
        printf("Dqueued %d \n",item);
    }
}

void show()
{
    if(front == rear)
    {
        printf("Queue is Undeflow:\n");
    }
    else
    {
        for(int i = front+1; i <= rear; i++)
        {
            printf("%d  ",queue[i]);
        }
    }
}
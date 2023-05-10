

// Array implementation of stack using array

#include <stdio.h>
#include<stdlib.h>

int stack[100],n,choice = 0;
// int top = -1;
int top = 0;

void pop();
void push();
void show();

int main()
{
    printf("Enter the number of Element of stack: ");
    scanf("%d", &n);
    printf("\n***************Stack Operation Using Array***************\n\n");
    printf("-----------------------------------------\n");

    while (choice != 4)
    {
        printf("\nChoose one from given option:\n");
        printf("=====================");
        printf("\n1.push\n2.pop\n3.show\n4.Exit(0)\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
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

void push()
{
    int val;
    if(top == n)
    {
        printf("Stack Overflow:\n");
    }
    else
    {
        printf("Enter the element: ");
        scanf("%d",&val);
        top++;
        stack[top] = val;
        printf("pushed %d\n",val);
    }
}

void pop()
{
    int val;
    if(top == 0)
    {
        printf("Stack is Underflow:\n");
    }
    else
    {
        val = stack[top];
        top--;
        printf("popped %d ",val);
    }
}

void show()
{
    if(top == -1)
    {
        printf("Stack is Underflow:\n");
    }
    else
    {
        for(int i = top; i >= 1; i--)
        {
            printf("%d ",stack[i]);
        }
    }
    printf("\n");
}


// stack implementation using linked list

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void pop();
void push();
void show();

int main()
{
    int choice = 0;
    printf("\n***************Stack Operation Using Linked List***************\n\n");
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
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    int data;
    if(ptr == NULL)
    {
        printf("Stack Overflow:\n");
    }
    else
    {
        printf("Enter a Node: ");
        scanf("%d",&data);
        ptr->data = data;

        if(head == NULL)
        {
            ptr->next = NULL;
            head = ptr;
            printf("pushed %d\n",data);
        }
        else
        {
            ptr->next = head;
            head = ptr;
            printf("pushed %d\n",data);
        }

    }

}
void pop()
{
    struct Node *ptr = head;
    int val;
    if(head == NULL)
    {
        printf("Stack is Underflow:\n");
    }
    else
    {
        if(head->next == NULL)
        {
            val = head->data;
            free(head);
            head = NULL;
            printf("popped %d ",val);
        }
        val = ptr->data;
        head = head->next;
        free(ptr);
        printf("popped %d ",val);
    }
}
void show()
{
    struct Node *ptr = head;
    if(head == NULL)
    {
        printf("Stack is Underflow:\n");
    }
    else
    {
        while (ptr != NULL)
        {
            printf("%d  ",ptr->data);
            ptr = ptr->next;
        }
        
    }
}
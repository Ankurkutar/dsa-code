
// linked list 

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linked_list_traversal(struct Node *head)
{
    while(head != NULL)
    {
        printf("%d\n",head->data);
        head = head->next;
    }
    // return head;
}

int main()
{
    struct Node *head = (struct Node*)malloc(sizeof(struct Node));
    struct Node *second = (struct Node*)malloc(sizeof(struct Node));
    struct Node *third = (struct Node*)malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node*)malloc(sizeof(struct Node));

    head->data = 12;
    head->next = second;

    second->data = 32;
    second->next = third;

    third->data = 15;
    third->next = fourth;

    fourth->data = 80;
    fourth->next = NULL;

     linked_list_traversal(head);

    return 0;

}
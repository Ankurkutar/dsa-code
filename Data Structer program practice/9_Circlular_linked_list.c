//  circular linked list in dsa

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void traversal(struct Node *head){
    struct Node *ptr = head;
    do{
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }while(ptr != head);
}

struct Node* insertNode(struct Node* head,int value)
{
    struct Node *ptr  =  (struct Node*)malloc(sizeof(struct Node));
    ptr->data;
    struct Node *p = head->next;
    while(p->next != head)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;

}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    // Allowcating the memory

    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    fourth = (struct Node*)malloc(sizeof(struct Node));

    head->data = 12;
    head->next = second;

    second->data = 21;
    second->next = third;

    third->data = 14;
    third->next = fourth;

    fourth->data = 44;
    fourth->next = NULL;

    traversal(head);

    return 0;
}
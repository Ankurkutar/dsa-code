
// delete Node from the linked list

// delete from the first
// delete from the last
// delete the Element given index
// delete the Node given value


#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linked_list_traversal(struct Node *head)
{
    struct Node *ptr = head;
    while(ptr != NULL)
    {
        printf("%d\n",ptr->data);
        ptr = ptr->next;
    }
}

struct Node *delete_At_begining(struct Node *head)
{
    struct Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

struct Node* deletelast(struct Node *head)
{
    struct Node *ptr = head;
    struct Node *p = head->next;
    while(p->next != NULL)
    {
        ptr = ptr->next;
        p = p->next;
    }
    ptr->next = NULL;
    free(p);
    return head;
}

struct Node* delete_between(struct Node *head, int value)
{
    struct Node *ptr  = head;
    struct Node *p = head->next;
    while(p->data != value && p->next != NULL)
    {
        ptr = ptr->next;
        p = p->next;
    }
    if(p->data == value)
    {
        ptr->next = p->next;
        free(p);
    }
    return head;
}

struct Node* delete_given_Index(struct Node *head, int Index)
{
    struct Node *ptr = head;
    struct Node *p = head->next;
    for(int i =0; i < Index-1; i++)
    {
        ptr = ptr->next;
        p = p->next;
    }
    ptr->next = p->next;
    free(p);
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

    linked_list_traversal(head);

    // printf("After Deleting first Node: \n");
    // head = delete_At_begining(head);
    // head = delete_At_begining(head);
    // linked_list_traversal(head);

    // printf("After Deleting last Node: \n");
    // head = deletelast(head);
    // head = deletelast(head);
    // linked_list_traversal(head);

    // printf("After Deleting given value Node: \n");
    // head = delete_between(head,21);
    // head = delete_between(head,44);
    // linked_list_traversal(head);


    printf("After Deleting given Index Node: \n");
    head = delete_given_Index(head,1);
    linked_list_traversal(head);


    return 0;
}
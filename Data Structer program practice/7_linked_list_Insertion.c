// Insertion in the linked list 

// insertion at the begining
// insertion at the End;
// Insertion in between  mean with the help of index no
// Insertion in the after;

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linked_list_traversal(struct Node *ptr)
{
    while(ptr != NULL)
    {
        printf("%d\n",ptr->data);
        ptr = ptr->next;
    }
}

struct Node* Insert_at_begining(struct Node *head, int value)
{
    struct Node *ptr = (struct Node*)malloc(sizeof(struct  Node));
    ptr->data = value;
    ptr->next = head;
    head = ptr;
    return head;
}

struct Node* Insert_at_Last(struct Node *head, int value)
{
    struct Node *ptr,*temp;
    ptr = head;
    temp = (struct Node*)malloc(sizeof(struct Node));
    while(ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    temp->data = value;
    temp->next = NULL;
    ptr->next = temp;
    return head;
}

struct Node* Insert_After(struct Node *head,struct Node *prevNode, int value)
{
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = value;
   
    ptr->next = prevNode->next;
    prevNode->next = ptr;
    return head;
}

struct Node *Insert_After_index(struct Node *head,int index, int value)
{
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = value;
    struct Node *p = head;
    int i =0;
    while(i != index-1)
    {
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    p->next = ptr;
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

    // linked_list_traversal(head);
    head = Insert_at_begining(head,36);
    head = Insert_at_begining(head,7);
    linked_list_traversal(head);

    printf("Insert at the last point:\n");
    head = Insert_at_Last(head,19);
    head = Insert_at_Last(head,23);
    head = Insert_at_Last(head,6);
    linked_list_traversal(head);
    
    printf("insertion After a paritcular Node:\n");
    head = Insert_After(head,second,50);
    head = Insert_After(head,second,62);
    linked_list_traversal(head);

    printf("Insertion After a particular Index:\n");
    head = Insert_After_index(head,2,99);
    head = Insert_After_index(head,8,300);
    linked_list_traversal(head);

    return 0;
    
}

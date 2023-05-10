
// Singly linked list implementation

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;


void Insert_at_begining();
void Insert_at_last();
void Insert_at_After_Node();
void Delete_from_firstNode();
void Delete_from_LastNode();
void Delete_from_between();
void Search_Node();
void Traversing();

int main()
{
    int choice = 0;

    while (choice != 9)
    {
        printf("\n***************************Main Menu***************************\n\n");
        printf("Choose One Option from the following List......\n\n");
        printf("=================================================\n\n");
        printf("1.Insert at first position:\n2.Insert at last position:\n3.Insert at random position:\n4.Delete from begining:\n5.Delete from last:\n6.Delete from After a Node:\n7.Search Element:\n8.Display List:\n9.Exit(0)\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            Insert_at_begining();
            break;
        case 2:
            Insert_at_last();
            break;
        case 3:
            Insert_at_After_Node();
            break;
        case 4:
            Delete_from_firstNode();
            break;
        case 5:
            Delete_from_LastNode();
            break;
        case 6:
            Delete_from_between();
            break;
        case 7:
            Search_Node();
            break;
        case 8:
            Traversing();
            break;
        case 9:
            exit(0);
            break;
        default:
            printf("Enter a Valid Choice:\n");
            // break;
        }
    }
    return 0;
}

void Insert_at_begining()
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    int data;
    if (ptr == NULL)
    {
        printf("Linked list is full:\n");
    }
    else
    {
        printf("Enter a Element: ");
        scanf("%d", &data);
        ptr->data = data;
        ptr->next = head;
        head = ptr;
        printf("Node Inserted %d\n", data);
    }
}

void Insert_at_last()
{
    int data;
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;

    if (ptr == NULL)
    {
        printf("Linked list is full:\n");
    }
    else
    {
        printf("Enter a Element: ");
        scanf("%d", &data);
        ptr->data = data;
        ptr->next = NULL;

        if (head == NULL)
        {
            head = ptr;
            printf("Node Inserted:\n");
        }
        else
        {
            while (p->next != NULL)
            {
                p = p->next;
            }
            p->next = ptr;
            printf("Node Inserted: %d\n",data);
        }
    }
}

void Insert_at_After_Node()  
{
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node *p = head;
    struct Node *q = head->next;
    int data,pos;
    if(ptr == NULL)
    {
        printf("Linked list is full:\n");
    }
    else
    {
        printf("Enter a Elemnet: ");
        scanf("%d",&data);
        ptr->data = data;
        printf("Enter the Location where do you want to Insert: ");
        scanf("%d",&pos);
        for(int i = 1; i < pos - 1; i++)
        {
            p = p->next;
            q = q->next;
            if(p == NULL)
            {
                printf("\nCann't Insert please input valid poistion:\n");
                return;
            }
        }
        ptr->next = q;
        p->next = ptr;
        p->next = ptr;
        printf("Node Inserted:\n");

    }
}


void Delete_from_firstNode()
{
    if(head == NULL)
    {
        printf("Linked list is Empty:\n");
    }
    else
    {
        int val = head->data;
        struct Node *ptr = head;
        head = head->next;
        free(ptr);
        printf("Node Deleted %d ",val);
    }
}

void Delete_from_LastNode()
{
    struct Node *p = head;
    struct Node *ptr = head->next;
    if(p == NULL)
    {
        printf("Linked list is Empty:\n");
    }
    else
    {
        if(head->next == NULL)
        {
            int data = p->data;
            free(head);
            printf("Node Deleted %d ",data);
        }
        while(ptr->next != NULL)
        {
            ptr = ptr->next;
            p = p->next;
        }
        int val = ptr->data;
        p->next = NULL;
        free(ptr);
        printf("Node Deleted %d ",val);
    }
}

void Delete_from_between()
{
    struct Node *ptr = head;
    struct Node *p = head->next;
    if(ptr == NULL)
    {
        printf("Linked list is Empty:\n");
    }
    else
    {
        int pos;
        printf("Enter a Position wich Node you want to delete: ");
        scanf("%d",&pos);
        for(int i = 1; i < pos-1; i++)
        {
            p = p->next;
            ptr = ptr->next;
        }
        int data = p->data;;
        ptr->next = p->next;
        free(p);
        printf("Node Deleted %d ",data);
    }
}

void Search_Node()
{
    struct Node *ptr = head;
    int flag,item,i=0;
    if(ptr == NULL)
    {
        printf("Linked list is Empty: ");
    }
    else
    {
        printf("Enter the Element which you want to search: ");
        scanf("%d",&item);
        while(ptr != NULL)
        {
            if(ptr->data == item)
            {
                printf("Element found at location: %d",i+1);
                return;
            }
            ptr = ptr->next;
            i++;
            if(ptr->next == NULL)
            {
            printf("Element not found inside the linked list: ");
            }
        }
        
    }
}

void Traversing()
{
    struct Node *ptr = head;
    if(ptr == NULL)
    {
        printf("Linked List is Empty:\n");
    }
    else
    {
        while(ptr != NULL)
        {
            printf("%d  ",ptr->data);
            ptr = ptr->next;
        }
        printf("\n");
    }
}
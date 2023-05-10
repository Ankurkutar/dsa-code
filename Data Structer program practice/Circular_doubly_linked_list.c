

// Circular doubly linked list implementation

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *head = NULL;

void Insert_at_Begining();
void Insert_at_Last();
void Insert_After_Node(); 
void Delete_From_Begining();
void Delete_From_Last();
void Delete_After_Node(); // remeaining
void Search_Node();
void Traversing();
struct Node *Create_Node();
void display();

int main()
{
    int choice = 0;
    while (choice != 9)
    {
        printf("\n*******************Main Menu*********************\n\n");
        printf("Choose One Option From the following List........\n\n");
        printf("=================================================\n\n");
        printf("1.Insert at Begining\n2.Insert at Last\n3.Insert after Node\n4.Delete From Begining\n5.Delete From Last\n6.Delete After Node\n7.Search Node\n8.Display Node\n9.Exit(0)");

        printf("\nEnter your Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            Insert_at_Begining();
            break;
        case 2:
            Insert_at_Last();
            break;
        case 3:
            Insert_After_Node();
            break;
        case 4:
            Delete_From_Begining();
            break;
        case 5:
            Delete_From_Last();
            break;
        case 6:
            Delete_After_Node();
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
            printf("please Enter Valid choice:\n");
        }
    }
    return 0;
}

void Insert_at_Begining()
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    int data;
    if (ptr == NULL)
    {
        printf("Linked list is Empty:\n");
    }
    else
    {
        printf("Enter the Element: ");
        scanf("%d",&data);
        ptr->data = data;
        if (head == NULL)
        {
            head = ptr;
            ptr->next = head;
            ptr->prev = head;
            printf("Node Inserted: %d", data);
        }
        else
        {
            struct Node *p = head;
            while (p->next != head)
            {
                p = p->next;
            }
            ptr->next = head;
            p->next = ptr;
            ptr->prev = p;
            // head->prev = ptr;
            head->prev = p;
            head = ptr;
            printf("Node Inserted: %d", data);
        }
    }
}

void Insert_at_Last()
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    int data;
    if (ptr == NULL)
    {
        printf("Linked list is Empty:\n");
    }
    else
    {
        printf("Enter the Element: ");
        scanf("%d",&data);
        ptr->data = data;
        if (head == NULL)
        {
            head = ptr;
            ptr->next = head;
            ptr->prev = head;
        }
        else
        {
            struct Node *p = head;
            while (p->next != head)
            {
                p = p->next;
            }
            ptr->prev = p;
            ptr->next = head;
            p->next = ptr;
            head->prev = ptr;
            printf("Node Inserted: %d", data);
        }
    }
}

void Delete_From_Begining()
{
    struct Node *ptr = head;
    int val;
    if (head == NULL)
    {
        printf("Linked list is Empty:\n");
    }
    else if (head->next == head)
    {
        val = head->data;
        free(head);
        head = NULL;
        printf("Node Deleted: %d", val);
    }
    else
    {
        while (ptr->next != head)
        {
            ptr = ptr->next;
        }
        val = head->data;
        ptr->next = head->next;
        head->next->prev = ptr;
        free(head);
        head = ptr->next;
        printf("Node Deleted: %d", val);
    }
}

void Delete_From_Last()
{
    struct Node *ptr = head;
    int val;
    if (head == NULL)
    {
        printf("Linked list is Empty:\n");
    }
    else if (head->next == head)
    {
        val = head->data;
        free(head);
        head = NULL;
        printf("Node Deleted: %d", val);
    }
    else
    {
        while (ptr->next != head)
        {
            ptr = ptr->next;
        }
        val = ptr->data;
        ptr->prev->next = head; // head
        head->prev = ptr->prev;
        printf("Node Deleted: %d", val);
    }
}

void Traversing()
{
    struct Node *ptr = head;
    if (head == NULL)
    {
        printf("Linked list is Empty:\n");
    }
    else
    {
        printf("\n printing values ... \n");
        while (ptr->next != head)
        {
            printf("%d  ", ptr->data);
            ptr = ptr->next;
        }
        printf("%d  ", ptr->data);
    }
}

void Search_Node()
{
    struct Node *ptr = head;
    int item, i = 1;
    int flag = 1;
    if (head == NULL)
    {
        printf("Linked list is Empty:\n");
    }
    else
    {
        printf("Enter the Node which you want to search: ");
        scanf("%d", &item);
        while (ptr->next != head)
        {
            if (ptr->data == item)
            {
                printf("Element found at index %d: ", i);
                flag = 0;
            }
            ptr = ptr->next;
            i++;
        }
        if(ptr->data == item)
        {
            printf("Element found at index %d: ", i);
            flag = 0;
        }
    }
    if (flag == 1)
    {
        printf("Element not found:\n");
    }
}

void Insert_After_Node()
{
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node *p = head;
    // struct Node *q = head->next;
    int data,pos;
    if(ptr == NULL)
    {
        printf("Linked List is full:\n");
    }                                           // this function not working properly remaining
    else
    {
        printf("Enter Element: ");
        scanf("%d",&data);
        printf("Enter the postion where you want insert: ");
        scanf("%d",&pos);
        ptr->data = data;
        for(int i = 1; i < pos-1; i++)
        {
            p = p->next;
            if(head == NULL)
            {
                head = ptr;
                ptr->next = head;
                ptr->prev = head;
                return;
            }
            
        }
        ptr->next = p->next;
        ptr->prev = p;
        p->next->prev = ptr;
        p->next = ptr;
    }
    printf("Node Inserted: %d\n",data);
}

void Delete_After_Node()
{
    struct Node *ptr = head;
    int val,pos;
    int flag = 1;
    if(head == NULL)
    {
        printf("Linked list is Underflow:\n");
    }
    else
    {
        printf("Enter the Position: ");
        scanf("%d",&pos);
        for(int i = 1; i < pos-1; i++)
        {
            ptr = ptr->next;
        }
        val = ptr->data;
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
        printf("Node Deleted %d ",val);
        flag = 0;
    }
    if(flag == 1)
    {
        printf("Invalid Deletion:\n");
    }
}
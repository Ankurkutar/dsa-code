
// Doubly linked list implementation with all operation

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *head = NULL;

void Insert_at_begining();
void Insert_at_Last();
void Insert_After_Node();
void Delete_from_beginging();
void Delete_from_Last();
void Delete_After_Node();
void Linked_list_traversal();
void Search_Node();
struct Node *CreateNode(int);

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
            Insert_at_Last();
            break;
        case 3:
            Insert_After_Node();
            break;
        case 4:
            Delete_from_beginging();
            break;
        case 5:
            Delete_from_Last();
            break;
        case 6:
            Delete_After_Node();
            break;
        case 7:
            Search_Node();
            break;
        case 8:
            Linked_list_traversal();
            break;
        case 9:
            exit(0);
            break;
        default:
            printf("Enter a valid choice:\n");
            break;
        }
    }
    return 0;
}

void Insert_at_begining()
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    int data;
    printf("Enter the Element: ");
    scanf("%d", &data);
    if (ptr == NULL)
    {
        printf("List is Full:\n");
    }

    ptr->data = data;
    ptr->prev = NULL;

    if (head == NULL)
    {
        ptr->next = NULL;
        head = ptr;
        printf("Element Inserted %d ", data);
    }
    else
    {
        ptr->next = head;
        head->prev = ptr;
        head = ptr;
        printf("Element Inserted %d ", data);
    }
}

void Insert_at_Last()
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    int data;
    if (ptr == NULL)
    {
        printf("List is full:\n");
    }
    else
    {
        printf("Enter the element: ");
        scanf("%d", &data);
        ptr->data = data;
        ptr->next = NULL;
        while (p->next != NULL)
        {
            p = p->next;
        }
        ptr->prev = p;
        p->next = ptr;
        printf("Element Inserted %d ", data);
    }
}

void Insert_After_Node()
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    int data, pos;
    struct Node *p = head;
    // struct Node *q = head->next;
    if (ptr == NULL)
    {
        printf("List is Full:\n");
    }
    else
    {
        printf("Enter the Position: ");
        scanf("%d", &pos);
        for (int i = 1; i < pos - 1; i++)
        {
            p = p->next;
            // q = q->next;
            if (p == NULL)
            {
                printf("Invalid postion please give the correct position:\n");
                return;
            }
        }
        printf("Enter the Element: ");
        scanf("%d", &data);
        ptr->data = data;
        ptr->next = p->next;
        p->next = ptr;
        ptr->prev = p;
        p->next->prev = ptr;
        printf("Element Inserted %d", data);
    }
}

void Linked_list_traversal()
{
    struct Node *ptr = head;
    if (ptr == NULL)
    {
        printf("List is Empty:\n");
    }
    else
    {
        while (ptr != NULL)
        {
            printf("%d  ", ptr->data);
            ptr = ptr->next;
        }
    }
}

void Delete_from_beginging()
{
    struct Node *ptr;
    int val = -1;
    if (head == NULL)
    {
        printf("List is Empty:\n");
    }
    else if (head->next == NULL)
    {
        val = head->data;
        head = NULL;
        free(head);
    }
    else
    {
        ptr = head;
        head = head->next;
        head->prev = NULL;
        val = ptr->data;
        free(ptr);
    }
    printf("Node Deleted %d ", val);
}

void Delete_from_Last()
{
    struct Node *ptr = head;
    int val = -1;
    if (head == NULL)
    {
        printf("List is Empty:\n");
    }
    else if (head->next == NULL)
    {
        val = head->data;
        head = NULL;
        free(head);
    }
    else
    {
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        val = ptr->data;
        ptr->prev->next = NULL;
        free(ptr);
    }
    printf("Node Deleted %d ", val);
}

void Delete_After_Node()
{
    struct Node *ptr = head;
    int val = -1; //   this function is not worling properly
    int pos;
    if (head == NULL)
    {
        printf("List is Empty:\n");
        return;

    }
    printf("Enter the position Which Element want to delete: ");
    scanf("%d", &pos);

    for (int i = 1; i <= pos - 1; i++)
    {
        ptr = ptr->next;
    }
    if (ptr->prev == NULL)
    {
        val = ptr->data;
        head = ptr->next;
        free(ptr);
    }
    else if (ptr->next == NULL)
    {
        val = ptr->data;
        ptr->prev->next = NULL;
        free(ptr);
    }
    else
    {
        val = ptr->data;
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
    }
    printf("Node Deleted %d ", val);
}

void Search_Node()
{
    struct Node *ptr = head;
    int element, i = 0;
    int flag;
    if (head == NULL) // this function not working for first and last element
    {
        printf("List is Empty:\n");
    }
    else
    {
        printf("Enter the Element which you want to search: ");
        scanf("%d", &element);
        while (ptr != NULL)
        {
            if (ptr->data == element)
            {
                printf("Element found at location: %d", i + 1);
                flag = 0;
                return;
            }
            i++;
            ptr = ptr->next;
        }
    }
    if (flag == 1)
    {
        printf("Element not found any location:\n");
    }
}

struct Node *CreateNode(int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = NULL;
    ptr->prev = NULL;
    return ptr;
}
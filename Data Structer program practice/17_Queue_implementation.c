
// Queue impelmentation using Array

#include<stdio.h>
#include<stdlib.h>

struct Queue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isEmpty(struct Queue *ptr)
{
    if(ptr->f == ptr->r)
    {
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(struct Queue *ptr)
{
    if(ptr->f == ptr->size-1)
    {
        return 1;
    }else{
        return 0;
    }
}

void enqueue(struct Queue *ptr, int data)
{
    if(isFull(ptr))
    {
        printf("Queue is Full:\n");
    }
    else
    {
        ptr->f++;
        ptr->arr[ptr->f] = data;
        printf("Enqueued element is %d\n",data);
    }
}

int dequeue(struct Queue *ptr)
{
    if(isEmpty(ptr))
    {
        printf("Queue is Empty:\n");
    }
    else{
        ptr->r++;
        int val = ptr->arr[ptr->r];
        return val;
    }
}



int main()
{
    struct Queue *ptr = (struct Queue*)malloc(sizeof(struct Queue));
    ptr->size = 5;
    ptr->f = ptr->r = -1;
    ptr->arr = (int*)malloc(ptr->size * sizeof(int));

    
    enqueue(ptr,35);
    enqueue(ptr,11);
    enqueue(ptr,54);
    enqueue(ptr,65);
    enqueue(ptr,12);
    enqueue(ptr,1);
    enqueue(ptr,16);

    
    printf(" dequeued Element is %d\n",dequeue(ptr));
    printf(" dequeued Element is %d\n",dequeue(ptr));
    printf(" dequeued Element is %d\n",dequeue(ptr));
    printf(" dequeued Element is %d\n",dequeue(ptr));

    // enqueue(ptr,16);

    
    return 0;
}
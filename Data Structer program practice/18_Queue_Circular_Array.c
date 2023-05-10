
// Queue implementation using circular array 

#include<stdio.h>
#include<stdlib.h>

struct Circular_Queue
{
    int size;
    int f;
    int r;
    int*arr;
};

int isEmpty(struct Circular_Queue *ptr)
{
    if(ptr->f == ptr->r)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct Circular_Queue *ptr)
{
    if(ptr->f == (ptr->r+1)%ptr->size)
    {
        return 1;
    }
    else{
        return 0;
    }
}

void enqueue(struct Circular_Queue *ptr, int data)
{
    if(isFull(ptr))
    {
        printf("Queue is Overflow:\n");
    }
    else
    {
        ptr->r = (ptr->r+1)%ptr->size;
        ptr->arr[ptr->r] = data;
        printf("Enqueued at %d Element %d\n",ptr->r,data);
    }
}

int dequeue(struct Circular_Queue *ptr)
{
    if(isEmpty(ptr))
    {
        printf("Queue is underflow:\n");
    }
    else
    {
        ptr->f = (ptr->f+1)%ptr->size;
        int val = ptr->arr[ptr->f];
        return val;
    }
}

int main()
{
    struct Circular_Queue *top = (struct Circular_Queue*)malloc(sizeof(struct Circular_Queue));
    top->size = 5;
    top->f = top->r = 0;
    top->arr = (int*)malloc(top->size * sizeof(int));


    if(isEmpty(top))
    {
        printf("Queue is empty:\n");
    }
    if(isFull(top))
    {
        printf("Queue is not empty:\n");
    }

    enqueue(top,25);
    enqueue(top,2);
    enqueue(top,5);
    enqueue(top,255);
    //enqueue(top,20);
    printf(" Dequeue element %d\n",dequeue(top));
    printf(" Dequeue element %d\n",dequeue(top));
    printf(" Dequeue element %d\n",dequeue(top));
    printf(" Dequeue element %d\n",dequeue(top));
    // printf(" Dequeue element %d\n",dequeue(top));

    enqueue(top,33);
    enqueue(top,12);
    enqueue(top,40);
    enqueue(top,3);
    enqueue(top,33);

    printf(" Dequeue element %d\n",dequeue(top));
    printf(" Dequeue element %d\n",dequeue(top));
    printf(" Dequeue element %d\n",dequeue(top));
    printf(" Dequeue element %d\n",dequeue(top));

    enqueue(top,11);
    enqueue(top,12);
    enqueue(top,13);
    enqueue(top,14 );
    enqueue(top,15 );
    enqueue(top,16 );

    return 0;
}
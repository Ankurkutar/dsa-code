
#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int isFull(struct stack *ptr)
{
    if(ptr->top == ptr->size-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty(struct stack *ptr)
{
    if(ptr->top == -1)
    {
        return 1;
    }else{
        return 0;
    }
}

void push(struct stack *ptr, int value)
{
    if(isFull(ptr)){
        printf("stack is Overflow we cannot push element inside the satck:\n");
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = value;
        printf("Element %d is pussed:\n",value);
    }
}

int pop(struct stack *ptr)
{
    int temp;
    if(isEmpty(ptr)){
        printf("stack is Underflow:\n");
    }
    else{
            temp = ptr->arr[ptr->top];
            ptr->arr--;
            return temp;
    }
}

int stackTop(struct stack *ptr)
{
    return ptr->arr[ptr->top];
}

int stackBottom(struct stack *ptr)
{
    return ptr->arr[0];
}

int peek(struct stack *ptr, int i)
{
    int arrayInd = ptr->top - i +1;
    if(arrayInd < 0){
        printf("this is not a valid position for the peek operation please give the input positive number:\n");
    }
    else{
        return ptr->arr[arrayInd];
    }
}

int main()
{
    // struct stack sp;
    // sp.size = 10;
    // sp.top = -1;
    // sp.arr = (int*)malloc(sp.size*sizeof(int));


    
    struct stack *sp = (struct stack*)malloc(sizeof(struct stack));
    sp->size = 5;
    sp->top = -1;
    sp->arr  = (int*)malloc(sp->size*sizeof(int));

    // if(isFull(sp)){
    //     printf("stack is Overfllow:\n");
    // }
    // else{
    //     printf("stack is Underflow:\n");
    // }

    // if(isEmpty(sp)){
    //     printf("stack is Underflow:\n");
    // }
    // else{
    //     printf("stack is Overflow:\n");
    // }

    push(sp,25);
    push(sp,13);
    push(sp,11);
    push(sp,79);
    push(sp,7);
    push(sp,71);
    

    // printf("stack top most element is: %d\n",stackTop(sp));
    // printf("stack Bottom most element is: %d\n",stackBottom(sp));

    printf("peek Element is %d: \n",peek(sp,2));
    return 0;
    
}
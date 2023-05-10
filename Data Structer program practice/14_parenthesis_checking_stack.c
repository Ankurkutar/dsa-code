
// parentesis matching using stack implementastion

#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

int top(struct stack *ptr)
{
    return ptr->arr[ptr->top];
}

int bottom(struct stack *ptr)
{
    return ptr->arr[0];
}

int isEmpty(struct stack *ptr)
{
    if(ptr->top == -1)
    {
        return 1;
    }else
    {
        return 0;
    }
}

int isFull(struct stack *ptr)
{
    if(ptr->top == ptr->size-1)
    {
        return 1;
    }
    else{
        return 0;
    }
}

void push(struct stack *ptr, char data)
{
    if(isFull(ptr))
    {
        printf("stack is overflow");
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = data;
        // printf("element pushed succesfully: %d\n",data);
    }
}

char pop(struct stack *ptr)
{
    if(isEmpty(ptr))
    {
        printf("stack is undeflow:\n");
        return -1;
    }
    else
    {
        char value = ptr->arr[ptr->top];
        ptr->top--;
        return value;
    }
}

// int peek(struct stack *ptr,int index)
// {
//     // struct stack p = ptr;       // this function is not working implemented by me that need some impleamentaion
//     for(int i =0; i < index; i++);
//     // ptr->top = 
//     return ptr->arr[i];  
// }


int parenthesis_Match(char *expression)
{
    struct stack *sp = (struct stack*)malloc(sizeof(struct stack));
    sp->top = -1;
    sp->size = 50;
    sp->arr = (char*)malloc(sp->size * sizeof(char));

    for(int i =0; expression[i] != '\0'; i++)
    {
        if(expression[i] == '(')
        {
            push(sp, '(');
        }
        if (expression[i] == ')')
        {
            if(isEmpty(sp))
            {
                return 0;
            }
            else{
                pop(sp);
            }
        }
    }
    if(isEmpty(sp))
    {
        return 1;
    }
    else {
        return 0;
    }
}
int main()
{
    // char *exp = "(5*2(--1-3)))";
    // char *exp = "(5*2((--1-3)())";
    char *exp = "(5*2(--1-3))";
    if(parenthesis_Match(exp))
    {
        printf("parenthesis match: \n");
    }
    else
    {
        printf("parenthesis not match: \n");
        
    }

    
    return 0;
}
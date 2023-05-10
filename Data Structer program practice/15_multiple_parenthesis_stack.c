

// multiple parenthesis matching

#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

int isEmpty(struct stack *ptr)
{
    if(ptr->top == -1)
    {
        return 1;
    }
    else{
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

void push(struct stack *ptr, char value)
{
    if(isFull(ptr))
    {
        printf("stack is overflow: \n");
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
}

char pop(struct stack *ptr)
{
    if(isEmpty(ptr))
    {
        printf("stack is underflow:\n");
    }
    else{
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

// int Multiple_parenthesis_match(char *expression)
// {
//     struct stack *sp;
//     sp->top = -1;
//     sp->size = 200;
//     sp->arr = (char*)malloc(sp->size * sizeof(char));
//     char popped_ch;

//     for(int i =0; expression[i] <= '\0'; i++)
//     {
//         if(expression[i] == '(')
//         {
//             push(sp, '(');
//         }
//         else if(expression[i] == '{')
//         {
//             push(sp, '{');
//         }
//         else if(expression[i] == '[')
//         {
//             push(sp,'[');
//         }
//          else if(expression[i] == ')')
//         {
//             if(isEmpty(sp))
//             {
//                 return 0;
//             }
//             popped_ch = pop(sp);
//         }
//         else if(expression[i] == '}')
//         {
//              if(isEmpty(sp))
//             {
//                 return 0;
//             }
//             popped_ch = pop(sp);
//         }
//         else if(expression[i] == ']')
//         {
//              if(isEmpty(sp))
//             {
//                 return 0;
//             }
//             popped_ch = pop(sp);
//         }
//     }

//     if(isEmpty(sp))
//     {
//         return 1;
//     }
//     else{
//         return 0;
//     }
// }

int match(char a, char b)
{
    if(a == '(' && b == ')')
    {
        return 1;
    }
    if(a == '{' && b == '}')
    {
        return 1;
    }
    if(a == '[' && b == ']')
    {
        return 1;
    }
    return 0;
}

int Multiple_parenthesis_match(char *expression)
{
    struct stack *sp = (struct stack*)malloc(sizeof(struct stack));
    sp->top = -1;
    sp->size = 200;
    sp->arr = (char*)malloc(sp->size * sizeof(char));
    char popped_ch;

    for(int i =0; expression[i] <= '\0'; i++)
    {
        if(expression[i] == '(' || expression[i] == '{' || expression[i] == '[')
        {
            push(sp, expression[i]);
        }
        
         else if(expression[i] == ')' || expression[i] == '}' || expression[i] == ']')
        {
            if(isEmpty(sp))
            {
                return 0;
            }
            popped_ch = pop(sp);

            if(!match(popped_ch, expression[i]))
            {
                return 0;
            }
        }    
    }
    if(isEmpty(sp))
    {
        return 1;
    }
    else{
        return 0;
    }
}


int main()
{
    char *exp = "[4-6((8){(9-8)}";

    if(Multiple_parenthesis_match(exp))
    {
        printf("parenthesis balanced:\n");
    }
    else{
        printf("parenthesis not balanced:\n");
    }
    return 0;

    
}
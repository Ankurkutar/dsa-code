
#include<stdio.h>
#include<stdlib.h>

struct Array
{
    int total_size;
    int used_size;
    int *ptr;
};

void CreateArray(struct Array *a, int t_size,int u_size)
{
    a->total_size = t_size;
    a->used_size = u_size;
    a->ptr = (int*)malloc(t_size * sizeof(int));

    // (*a).total_size = t_size;
    // (*a).used_size = u_size;
    // (*a).ptr = (int*)malloc(t_size * sizeof(int));
}

void set_value(struct Array *a)
{
    int temp;
    for(int i = 0; i < a->used_size; i++)
    {
        printf("Enter the Element of Array at index[%d]: ",i);
        scanf("%d",&temp);
        (a->ptr)[i] = temp;
    }
}

void show(struct Array *a)
{
    for(int i = 0; i < a->used_size; i++)
    {
        printf("Element of at index[%d] is: %d\n",i,a->ptr[i]);
    }
}

int main()
{
    struct Array marks;
    CreateArray(&marks, 15,5);
    set_value(&marks);
    show(&marks);
    
    return 0;
}
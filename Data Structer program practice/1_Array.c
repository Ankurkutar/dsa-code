
// ctrl + c = for infinite loop

#include<stdio.h>
#include<stdlib.h>

struct Array
{
    int total_size;
    int used_size;
    int *ptr;
};

void createArray(struct Array *a, int t_size, int u_size)
{
    // (*a).total_size = t_size;
    // (*a).used_size = u_size;
    // (*a).ptr = (int*)malloc(t_size*sizeof(int));

    a->total_size = t_size;
    a->used_size = u_size;
    a->ptr = (int*)malloc(t_size*sizeof(int));

}

void show(struct Array *a)
{
    for(int i=0; i < a->used_size; i++)
    {
        printf("Element is %d at index[%d]\n",a->ptr[i],i);
    }
}

void setvalue(struct Array *a)
{
    int n;
    for(int i =0; i < a->used_size; i++)
    {
       printf("Enter the element of array at index[%d]: ",i);
       scanf("%d",&n);
       (a->ptr)[i] = n;
    }
}

int main()
{
    struct Array marks;
    createArray(&marks,20,5);
    setvalue(&marks);
    show(&marks);
    return 0;
}

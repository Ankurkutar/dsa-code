
#include<stdio.h>

void display(int arr[], int size)
{
    for(int i =0; i<size; i++)
    {
        printf("%d\n",arr[i]);
    }
}

Index_insertion(int arr[], int size,int index,int element,int capacity)
{
    if(size >= capacity)
    {
        return -1;
    }
    for(int i = size-1; i >= index; i--)
    {
        arr[i+1] = arr[i];
    }
    arr[index] = element;
    return 1;
}

int main()
{
    int arr[15] = {32,4,14,10,35};
    int size = 5;
    int element = 27;
    display(arr,size);

    // code for insertion 
    int index = 5;
    int capacity = 15;
    printf("after insertion:\n");
    Index_insertion(arr, size, index, element,capacity);
    size +=1;
    display(arr,size);
    return 0;
}
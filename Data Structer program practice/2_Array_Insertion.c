// Insertion in array

#include<stdio.h>

int Ind_insertion(int arr[], int size, int index, int element,int capacity)
{
    if(size >= capacity)
    {
        return -1;
    }
    for(int i = size-1; i >= index; i-- )
    {
        arr[i+1] = arr[i];
    }
    arr[index] = element;
    return 1;
}


void display(int arr[], int size)
{
    for(int i=0; i<size; i++)
    {
        printf("%d\n",arr[i]);
    }
}

int main()
{
    int Array[100] = {4,65,25,10,34,33,41,17,21,29};
    int size = 10;
    int element = 30;
    int index = 10;
    int capacity = 100;
    display(Array,size);
    Ind_insertion(Array,size,index,element,capacity);
    // size = size+1;
    size += 1;

    printf("After insertion: \n");
    display(Array, size);
    return 0;
}


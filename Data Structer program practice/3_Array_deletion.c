
#include<stdio.h>



int Index_deletion1(int array[], int size, int index)
{
    for(int i = index; i < size-1; i++)
    {
        array[i] = array[i+1];
    }
}

void display(int arr[], int size)
{
    for(int i =0; i <size; i++)
    {
        printf("%d\n",arr[i]);
    }
}

int main()
{
    // int arr[15] = {14,21,30,16,40};
    // int size = 5;

    int arr[] = {14,21,30,16,40};
    int size = sizeof(arr)/sizeof(int);

    display(arr,size);

    printf("after deletion:\n");
    int index = 2;
    Index_deletion1(arr , size, index);
    size -= 1;
    display(arr,size);

    return 0;
}
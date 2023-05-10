
#include<stdio.h>

void display(int arr[], int size)
{
    for(int i =0; i < size; i++)
    {
        printf("%d\n",arr[i]);
    }
}

int Linear_Search(int arr[], int size,int element)
{
    for(int i =0; i < size; i++)
    {
        if(arr[i] == element)
        {
            printf("element found at index: %d\n",i);
            return i;
        }
    }
     printf("element not found at any index: ");
}

int main()
{
    int Arr[] = {4,3,8,17,21,36,25,19,10};
    int size = sizeof(Arr)/sizeof(int);

    display(Arr,size);
    int found = Linear_Search(Arr,size,25);

    // if(found){
    //        printf("element found at index: %d\n",found);
    // }
    // else{
    //         printf("element not found: ");
    // }
    return 0;
}
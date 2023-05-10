
// In binary search Array must be sorted

#include<stdio.h>

void display(int arr[], int size)
{
    for(int i =0; i < size; i++)
    {
        printf("%d\n",arr[i]);
    }
}

int Binary_Search(int *A,int element, int size)
{
    int low =0, mid , high = size-1;
    while(low <= high)
    {
        mid = (low + high)/2;
        if(A[mid] == element){
            // printf("Element found: \n");
            return mid;
        }
        else if(A[mid] > element)
        {
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
         return -1;
}

int main()
{
    int Arr[] = {5,11,32,35,40,55,75,89,93,100};
    int size = sizeof(Arr)/sizeof(int);
    // display(Arr,size);


    int found =  Binary_Search(Arr,89,size);
    printf("element found at index: %d",found);
    return 0;
}
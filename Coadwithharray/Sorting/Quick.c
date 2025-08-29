#include <stdio.h>
#include <stdlib.h>
void quicSort(int arr[], int low, int high)
{
    int pindex;
    if (low < high)
        {
            pindex = partition(arr, low, high);
            quickSort(arr, low, pindex - 1);   // sort left sub array
            quickSort(arr, pindex + 1, high); // sort right sub array
        }
    }
int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low + 1; // Index of smaller element
    int j = high; // Index of larger element
    int temp;
    do
    {
        while (arr[i] <= pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
             temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    } while (i < j);
    temp=arr[low];
    arr[low]=arr[j];
    arr[j]=temp;

    return j;
}
void print(int arr[], int n)
{

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main()
{
    int arr[] = {4, 9, 3, 7, 10, 12, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    print(arr, n);
quicSort(arr,0,n-1);
    printf("\n");
    print(arr, n);

    return 0;
}

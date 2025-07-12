#include <stdio.h>
#include <stdlib.h>
void quicSort(int arr[], int low, int high)
{
    int partitonind;
    if (low < high)
    {
        partitonind = partition(arr, low, high);
        quicSort(arr, low, partitonind - 1);   // sort left sub arrry
        quicSort(arr, partitonind + 1, high); // sort right sub array
    }
}
int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low + 1;
    int j = high;
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
// it is not complited

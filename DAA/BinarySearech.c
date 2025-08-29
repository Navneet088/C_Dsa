#include <stdio.h>

void binarysearch(int arr[], int size, int target) {
    int low = 0;
    int high = size - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == target) {
            printf("Element found at index %d\n", mid);
            return;
        }
        else if (arr[mid] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    printf("Element not found\n");
}



int main() {
     int size ;
     printf("Enter the Size  of the Array: ");
     scanf("%d", &size);
    int arr[size];
    printf("Enter %d elements: ", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    int target;
    printf("Enter the element to search for: ");
    scanf("%d", &target);
    binarysearch(arr, size, target);

    return 0;
}
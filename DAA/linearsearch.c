#include <stdio.h>

int search(int arr[], int key, int size) {
    for (int i = 0; i < size; i++) { // use i < size
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int main() {
    int size;
    printf("Enter the size  of Array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    int key;
    printf("Enter the key to search: ");
    scanf("%d", &key);

    int index = search(arr, key, size);
    if (index != -1)
        printf("Index of key %d: %d\n", key, index);
    else
        printf("Key %d not found\n", key);

    return 0;
}
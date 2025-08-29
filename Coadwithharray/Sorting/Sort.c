#include<stdio.h>
#include<stdlib.h>

void insertionSort(int arr[],int n){
int key, j;
for(int i = 1; i < n; i++){
    j= i - 1;
    key = arr[i];
    while (j >= 0 && arr[j] > key)
    {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = key;
}
}
void bubbleSort(int arr[],int n){
    int temp;
    for(int i = 0; i < n; i++){// Traverse through all array elements
        // Last i elements are already sorted
        // So we can skip them
        // n-i-1 is the last index of the unsorted part 
       for(int j=0; j<n-i-1; j++){// Traverse the array from 0 to n-i-1
            // Swap if the element found is greater than the next element   
            if(arr[j] > arr[j + 1]){  
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

}
// selection sort
   int selectionSort(int arr[],int n){
     int min_idx, temp;
     for (size_t i = 0; i < n; i++) // Traverse through all array elements
     {
        min_idx = i;
        for (int j = i + 1; j < n; j++)  // Find the minimum element in unsorted array
        {
            if (arr[j] < arr[min_idx])// If current element is smaller than min_idx
            {
                min_idx = j;// Update min_idx to current element index
            }
        }
        temp = arr[i];// Swap the found minimum element with the first element
        arr[i] = arr[min_idx];  // Swap operation
        arr[min_idx] = temp;// Swap operation
     }

   }
// function of merge sort
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1; // Size of left subarray
    int n2 = r - m;     // Size of right subarray
    int L[n1], R[n2]; // Temporary arrays for left and right subarrays
    // Copy data to temporary arrays L[] and R[]
    for (i = 0; i < n1; i++)  // Copying elements from left subarray
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
        while(i < n1 && j < n2) { // Merging the temporary arrays back into arr[l..r]
            if (L[i] <= R[j]) { // If current element of left subarray is smaller or equal
                arr[k++] = L[i++]; // Place it in the merged array and move to next element
            } else {
                arr[k++] = R[j++]; // Otherwise, place the right subarray element
            }
        }   

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k++] = L[i++];
    }                               
    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k++] = R[j++];
    }

}
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2; // Find the middle point
        mergeSort(arr, l, m);   // Sort first half
        mergeSort(arr, m + 1, r); // Sort second half
        merge(arr, l, m, r);     // Merge the sorted halves
    }
}

void print(int arr[], int n) {

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}

//Quick sort function
int partition(int arr[], int low, int high) {   
    int pivot = arr[high]; // Choosing the last element as pivot
    int i = (low - 1); // Index of smaller element
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) { // If current element is smaller than pivot
            i++; // Increment index of smaller element
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp; // Swap elements
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp; // Swap pivot with the element at i+1
    return (i + 1); // Return the partitioning index
}
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // Partitioning index
        quickSort(arr, low, pi - 1); // Recursively sort elements before partition
        quickSort(arr, pi + 1, high); // Recursively sort elements after partition
    }
}

int main(){
    int arr[] = {4, 9, 3, 7, 10, 2, 13};
    int n = sizeof(arr) / sizeof(arr[0]); 
    print(arr, n);
    printf("\n");  
    printf("Insertion Sort:\n");
    insertionSort(arr, n);
    print(arr, n);
    printf("\n");
    printf("Bubble Sort:\n");
    bubbleSort(arr, n);
    print(arr, n);
    printf("\n");
    printf("Selection Sort:\n");
    selectionSort(arr, n);
    print(arr, n);
    printf("\n");
    printf("Merge Sort:\n");
    mergeSort(arr, 0, n - 1);
    print(arr, n);
     printf("\n");
    printf("Quick Sort:\n");
    quickSort(arr, 0, n - 1);
    print(arr, n);
    return 0;
}
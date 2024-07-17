#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mergeSort(int arr[], int low, int high);
void merge(int arr[], int low, int mid, int high);
void printArray(int arr[], int size);

int main() {
    int a[15000], n, i, j, ch;
    clock_t start, end;

    while (1) {
        printf("\n1: For manual entry of N value and array elements");
        printf("\n2: To display time taken for sorting number of elements N in the range 500 to 14500");
        printf("\n3: To exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("\nEnter the number of elements: ");
                scanf("%d", &n);
                printf("\nEnter array elements: ");
                for (i = 0; i < n; i++) {
                    scanf("%d", &a[i]);
                }
                start = clock();
                mergeSort(a, 0, n - 1);
                end = clock();
                printf("\nSorted array is: ");
                printArray(a, n);
                printf("\nTime taken to sort %d numbers is %f Secs", n, ((double)(end - start)) / CLOCKS_PER_SEC);
                break;
            case 2:
                n = 500;
                while (n <= 14500) {
                    for (i = 0; i < n; i++) {
                        a[i] = n - i;
                    }
                    start = clock();
                    mergeSort(a, 0, n - 1);
                    end = clock();
                    printf("\nTime taken to sort %d numbers is %f Secs", n, ((double)(end - start)) / CLOCKS_PER_SEC);
                    n = n + 1000;
                }
                break;
            case 3:
                exit(0);
        }
        getchar();
    }

    return 0;
}

// Function to perform merge sort
void mergeSort(int arr[], int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

// Function to merge two halves
void merge(int arr[], int low, int mid, int high) {
    int temp[high - low + 1];
    int i = low;
    int j = mid + 1;
    int k = 0;

    // Merge the two halves into temp[]
    while (i <= mid && j <= high) {
        if (arr[i] < arr[j]) {
            temp[k] = arr[i];
            i++;
        } else {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of left half, if any
    while (i <= mid) {
        temp[k] = arr[i];
        i++;
        k++;
    }

    // Copy the remaining elements of right half, if any
    while (j <= high) {
        temp[k] = arr[j];
        j++;
        k++;
    }

    // Copy the sorted subarray into the original array
    for (i = low, k = 0; i <= high; i++, k++) {
        arr[i] = temp[k];
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

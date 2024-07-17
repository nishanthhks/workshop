#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void swap(int arr[], int i, int j);
void printArray(int arr[], int size);

int main() {
    int a[15000], n, i, j, ch, temp;
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
                quickSort(a, 0, n - 1);
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
                    quickSort(a, 0, n - 1);
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

// Function to perform quick sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to partition the array
int partition(int arr[], int low, int high) {
    int pivot = arr[low];  // Choosing the first element as pivot
    int i = low + 1;
    int j = high;

    while (1) {
        while (i <= high && arr[i] <= pivot) {
            i++;
        }
        while (j >= low && arr[j] > pivot) {
            j--;
        }
        if (i < j) {
            swap(arr, i, j);
        } else {
            break;
        }
    }
    swap(arr, low, j);
    return j;
}

// Function to swap two elements
void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

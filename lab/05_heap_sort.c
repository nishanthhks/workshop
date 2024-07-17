#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void heapSort(int arr[], int n);
void heapify(int arr[], int n, int i);
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
                heapSort(a, n);
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
                    heapSort(a, n);
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

// Function to perform heap sort
void heapSort(int arr[], int n) {
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // One by one extract an element from heap
    for (int i = n - 1; i >= 0; i--) {
        // Move current root to end
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // Call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

// To heapify a subtree rooted with node i which is an index in arr[]. n is size of heap
void heapify(int arr[], int n, int i) {
    int largest = i;   // Initialize largest as root
    int left = 2 * i + 1;  // left = 2*i + 1
    int right = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        int swap = arr[i];
        arr[i] = arr[largest];
        arr[largest] = swap;

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

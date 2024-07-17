#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define LEFT 0
#define RIGHT 1

void printPermutation(int arr[], int n){
    for(int i = 0; i < n; i++){
        printf("%d", arr[i]);
    }
    printf("\n");
}

int greatestMobileIndex(int arr[], bool direction[], int n){
    int mobileIndex = -1; // Start with an invalid index
    int mobileValue = 0;  // Start with zero since array elements are positive

    // Identify the largest mobile value
    for(int i = 0; i < n; i++){
        if(direction[arr[i] - 1] == LEFT && i != 0){
            if(arr[i] > arr[i - 1] && arr[i] > mobileValue){
                mobileValue = arr[i];
                mobileIndex = i;
            }
        }
        if(direction[arr[i] - 1] == RIGHT && i != n - 1){
            if(arr[i] > arr[i + 1] && arr[i] > mobileValue){
                mobileValue = arr[i];
                mobileIndex = i;
            }
        }
    }
    return mobileIndex;
}

void swap(int arr[], int a, int b){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void printAllPermutations(int n) {
    int arr[n];
    bool dir[n];
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
        dir[i] = LEFT;
    }

    while (1) {
        printPermutation(arr, n);

        int mobileIndex = greatestMobileIndex(arr, dir, n);
        if (mobileIndex == -1) {
            break; // No more mobile elements
        }

        int mobile = arr[mobileIndex];

        if (dir[mobile - 1] == LEFT) {
            swap(arr, mobileIndex, mobileIndex - 1);
        } else if (dir[mobile - 1] == RIGHT) {
            swap(arr, mobileIndex, mobileIndex + 1);
        }

        // Reverse direction
        for (int i = 0; i < n; i++) {
            if (arr[i] > mobile) {
                dir[arr[i] - 1] = !dir[arr[i] - 1]; 
            }
        }
    }
}

int main() {
    int n = 7;
    printf("Permutations of %d elements:\n", n);
    printAllPermutations(n);
    return 0;
}

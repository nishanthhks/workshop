#include <stdio.h>

// Function to return the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to solve the 0/1 Knapsack problem
int knapSack(int W, int wt[], int val[], int n) {
    int K[n + 1][W + 1];

    // Build table K[][] in bottom-up manner
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0) // 1st row and 1st column are all 0
                K[i][w] = 0;
            else if (wt[i - 1] <= w) // to avoid -ve index (index out of bound)
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }

    // Return the maximum value that can be put in a knapsack of capacity W
    return K[n][W];
}

int main() {
    int val[] = {2, 3, 4, 1};
    int wt[] = {3, 4, 5, 6};
    int W = 8;
    int n = sizeof(val) / sizeof(val[0]);
    printf("Maximum value in Knapsack = %d\n", knapSack(W, wt, val, n));
    return 0;
}

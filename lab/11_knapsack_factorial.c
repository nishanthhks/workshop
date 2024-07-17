#include <stdio.h>

// A structure to represent an item in the knapsack
struct Item {
    int value;
    int weight;
};

// Function to swap two items
void swap(struct Item* a, struct Item* b) {
    struct Item temp = *a;
    *a = *b;
    *b = temp;
}

// Function to sort items based on value-to-weight ratio
void sortItems(struct Item items[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            double r1 = (double)items[i].value / items[i].weight;
            double r2 = (double)items[j].value / items[j].weight;
            if (r1 < r2) {
                swap(&items[i], &items[j]);
            }
        }
    }
}

// Function to calculate the maximum value we can get in the knapsack
double fractionalKnapsack(int W, struct Item items[], int n) {
    sortItems(items, n);

    double totalValue = 0.0;
    int currentWeight = 0;

    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= W) {
            currentWeight += items[i].weight;
            totalValue += items[i].value;
        } else {
            int remain = W - currentWeight;
            totalValue += items[i].value * ((double)remain / items[i].weight);
            break;
        }
    }

    return totalValue;
}

int main() {
    int W = 8;  // Weight of knapsack
    struct Item items[] = { {2,3}, {3,4}, {4,5}, {1,6} };
    int n = sizeof(items) / sizeof(items[0]);

    double maxValue = fractionalKnapsack(W, items, n);
    printf("Maximum value in Knapsack = %.2f\n", maxValue);

    return 0;
}

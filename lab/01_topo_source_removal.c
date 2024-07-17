#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // Define the maximum number of vertices

// Function to find the topological order using the Source Removal Technique
void topological_order(int n, int a[MAX][MAX]) {
    int in_degree[MAX] = {0}; // Array to store in-degrees of each vertex
    int res[MAX]; // Array to store the topological order
    int j = 0; // Index for the result array

    // Step 1: Calculate in-degrees of all vertices
    for (int u = 0; u < n; u++) {
        for (int v = 0; v < n; v++) {
            if (a[u][v] == 1) {
                in_degree[v]++;
            }
        }
    }

    // Step 2: Initialize the queue for vertices with in-degree 0
    int queue[MAX], front = 0, rear = 0;
    
    for (int i = 0; i < n; i++) {
        if (in_degree[i] == 0) {
            queue[rear++] = i; // Enqueue vertices with in-degree 0
        }
    }

    // Step 3: Process the queue
    while (front < rear) {
        int u = queue[front++]; // Dequeue a vertex

        res[j++] = u; // Add it to the result

        // Step 4: Decrease the in-degree of adjacent vertices
        for (int v = 0; v < n; v++) {
            if (a[u][v] == 1) {
                in_degree[v]--; // Decrease in-degree
                if (in_degree[v] == 0) {
                    queue[rear++] = v; // Enqueue if in-degree becomes 0
                }
            }
        }
    }

    // Step 5: Print the topological order
    printf("\nTopological order:\n");
    for (int i = 0; i < j; i++) {
        printf("-->%d", res[i]);
    }
    printf("\n");
}

int main() {
    int a[MAX][MAX] = { 
        {0, 1, 0, 0, 0}, 
        {0, 0, 1, 0, 0}, 
        {0, 0, 0, 0, 0}, 
        {0, 0, 1, 0, 1}, 
        {0, 0, 0, 0, 0} 
    };

    printf("\nTopological order using Source Removal Technique:\n");
    topological_order(5, a); // Call the topological order function

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int s[100], j, res[100]; /* GLOBAL VARIABLES */ //s-> visited, res-> 0

void dfs(int u, int n, int a[5][5]) {
    int v;
    s[u] = 1;
    for (v = 0; v < n; v++) {  /* Change n-1 to n to include all vertices */
        if (a[u][v] == 1 && s[v] == 0) {
            dfs(v, n, a);
        }
    }
    res[j++] = u; /* Increment j after assignment */
}

void topological_order(int n, int a[5][5]) {
    // make all vertex not visited
    for (int i = 0; i < n; i++) {
        s[i] = 0;
    }
    j = 0;
    for (int u = 0; u < n; u++) {
        if (s[u] == 0) {
            dfs(u, n, a);
        }
    }
}

int main() {
    int a[5][5] = { 
        {0, 1, 0, 0, 0}, 
        {0, 0, 1, 0, 0}, 
        {0, 0, 0, 0, 0}, 
        {0, 0, 1, 0, 1}, 
        {0, 0, 0, 0, 0} 
    };
    
    printf("\nTopological order:\n");
    topological_order(5, a);
    
    for (int i = j - 1; i >= 0; i--) {
        printf("-->%d", res[i]);
    }
    
    printf("\n");
    return 0;
}


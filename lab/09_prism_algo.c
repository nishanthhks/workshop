// Prim's Algorithm in C

#include<stdio.h>
#include<stdbool.h> 

#define INF 9999999

// number of vertices in graph
#define V 5

// create a 2d array of size 5x5
//for adjacency matrix to represent graph
int G[V][V] = { {0, 2, 0, 6, 0},
                        {2, 0, 3, 8, 5},
                        {0, 3, 0, 0, 7},
                        {6, 8, 0, 0, 9},
                        {0, 5, 7, 9, 0} };

int main() {
  int no_edge;  // number of edge

  int selected[V];

  // set selected false initially
  memset(selected, false, sizeof(selected));

  no_edge = 0;

  selected[0] = true;

  int x;  //  row number
  int y;  //  col number

  printf("Edge : Weight\n");

  while (no_edge < V - 1) {
    
    int min = INF;
    x = 0;
    y = 0;

    for (int i = 0; i < V; i++) {
      if (selected[i]) {
        for (int j = 0; j < V; j++) {
          if (!selected[j] && G[i][j]) {  // not in selected and there is an edge
            if (min > G[i][j]) {
              min = G[i][j];
              x = i;
              y = j;
            }
          }
        }
      }
    }
    printf("%d - %d : %d\n", x, y, G[x][y]);
    selected[y] = true;
    no_edge++;
  }

  return 0;
}
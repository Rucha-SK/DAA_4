#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 10

int graph[MAX_VERTICES][MAX_VERTICES];
bool visited[MAX_VERTICES];

void add_edge(int u, int v) {
    graph[u][v] = graph[v][u] = 1;
}

void print_vertex_cover(int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        if (!visited[i]) {
            for (j = 0; j < n; j++) {
                if (graph[i][j] && !visited[j]) {
                    visited[i] = visited[j] = true;
                    break;
                }
            }
        }
    }

    for(int i=0;i<n;i++){
        if(i==0){
            printf("{");
        }
        if(visited[i])
          printf(" %d",i);

         if(i==n-1){
            printf("}");
        } 
    }
  
}

int main() {
    int n, m;
    int i, u, v;
    
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    
    printf("Enter the number of edges: ");
    scanf("%d", &m);
    
    for (i = 0; i < m; i++) {
        printf("Enter edge %d: ", i+1);
        scanf("%d %d", &u, &v);
        add_edge(u, v);
    }
    
    printf("The vertex cover is: ");
    print_vertex_cover(n);
    
    return 0;
}

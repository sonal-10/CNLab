#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define INT_MAX 9999
const int nV = 4;

// Function to find the vertex with the minimum distance
int minDistance(int distance[], bool shortestPathTree[]) {
    int min = INT_MAX, min_index;
    for (int vertex = 0; vertex < nV; vertex++) {
        if (!shortestPathTree[vertex] && distance[vertex] <= min) {
            min = distance[vertex];
            min_index = vertex;
        }
    }
    return min_index;
}

// Function to perform Dijkstra's Algorithm
void dijkstra(int graph[nV][nV], int source) {
    int distance[nV];
    bool shortestPathTree[nV];

    // Initialization
    for (int i = 0; i < nV; i++) {
        distance[i] = INT_MAX;
        shortestPathTree[i] = false;
    }
    distance[source] = 0;

    // Dijkstra's algorithm
    for (int count = 0; count < nV - 1; count++) {
        int u = minDistance(distance, shortestPathTree);
        shortestPathTree[u] = true;

        for (int vertex = 0; vertex < nV; vertex++) {
            if (!shortestPathTree[vertex] && graph[u][vertex] != 0 && distance[u] != INT_MAX &&
                distance[u] + graph[u][vertex] < distance[vertex]) {
                distance[vertex] = distance[u] + graph[u][vertex];
            }
        }
    }

    // Displaying the result
    printf("\nDistance from source %d\n", source);
    printf("Vertex\tDistance\n");
    for (int i = 0; i < nV; i++) {
        printf("%d\t%d\n", i, distance[i]);
    }
}

// Function to get user input for the cost matrix
void getCostMatrix(int graph[nV][nV]) {
    printf("\nEnter the cost matrix\n");
    for (int i = 0; i < nV; i++) {
        for (int j = 0; j < nV; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
}

int main() {
    int graph[nV][nV];

    // Get user input for the cost matrix
    getCostMatrix(graph);

    // Perform Dijkstra's algorithm starting from source vertex 3
    dijkstra(graph, 3);

    return 0;
}

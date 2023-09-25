/*
pra4.3 MST using krushkal and prims
AIM: Find Minimum Cost spanning tree of a given undirected graph using Kruskal and Prim’s algorithm. Also observe effect on experiment result of choosing those algorithms.
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#define MAX_VERTICES 100
// Structure to represent an edge
struct Edge {
    int src, dest, weight;
};
// Structure to represent a graph
struct Graph {
    int V, E;
    struct Edge* edges;
};
// Function to create a graph with V vertices and E edges
struct Graph* createGraph(int V, int E) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    graph->edges = (struct Edge*)malloc(E * sizeof(struct Edge));
    return graph;
}
// Function to compare edges for sorting
int compareEdges(const void* a, const void* b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}
// Kruskal's algorithm to find MST
void kruskalMST(struct Graph* graph) {
    int V = graph->V;
    int E = graph->E;
    struct Edge* result = (struct Edge*)malloc((V - 1) * sizeof(struct Edge));
    struct Edge* edges = graph->edges;
    // Sort the edges by weight in non-decreasing order
    qsort(edges, E, sizeof(struct Edge), compareEdges);
    int* parent = (int*)malloc(V * sizeof(int));
    for (int i = 0; i < V; i++) {
        parent[i] = i;
    }
    int mstEdges = 0;
    // Add edges to the MST until V-1 edges are included
    for (int i = 0; mstEdges < V - 1 && i < E; i++) {
        struct Edge nextEdge = edges[i];
        int x = parent[nextEdge.src];
        int y = parent[nextEdge.dest];
        // Check if including this edge forms a cycle
        if (x != y) {
            result[mstEdges++] = nextEdge;
            // Merge the sets of x and y
            for (int j = 0; j < V; j++) {
                if (parent[j] == x) {
                    parent[j] = y;
                }
            }
        }
    }
    // Print the MST
    printf("Minimum Spanning Tree (Kruskal's algorithm):\n");
    for (int i = 0; i < V - 1; i++) {
        printf("Edge %d-%d: Weight %d\n", result[i].src, result[i].dest, result[i].weight);
    }
    free(parent);
    free(result);
}
// Prim's algorithm to find MST
void primMST(struct Graph* graph) {
    int V = graph->V;
    int E = graph->E;
    int parent[V];
    int key[V];
    bool mstSet[V];
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }
   key[0] = 0;
    parent[0] = -1;
    for (int count = 0; count < V - 1; count++) {
        int u = -1;
        int minKey = INT_MAX;
        for (int v = 0; v < V; v++) {
            if (!mstSet[v] && key[v] < minKey) {
                u = v;
                minKey = key[v];
            }
        }
        mstSet[u] = true;
        for (int i = 0; i < E; i++) {
            if (graph->edges[i].src == u && !mstSet[graph->edges[i].dest] &&
                graph->edges[i].weight < key[graph->edges[i].dest]) {
                parent[graph->edges[i].dest] = u;
                key[graph->edges[i].dest] = graph->edges[i].weight;
            }
        }
    }
    printf("\nMinimum Spanning Tree (Prim's algorithm):\n");
    for (int i = 1; i < V; i++) {
        printf("Edge %d-%d: Weight %d\n", parent[i], i, key[i]);
    }
}
int main() {
    int V, E;
    printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &V, &E);
    struct Graph* graph = createGraph(V, E);
    printf("Enter the edges (source, destination, weight):\n");
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &graph->edges[i].src, &graph->edges[i].dest, &graph->edges[i].weight);
    }
    // Kruskal's MST
    kruskalMST(graph);
    // Prim's MST
    primMST(graph);
    free(graph->edges);
    free(graph);
    return 0; }


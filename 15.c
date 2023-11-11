#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 100

struct graph {
    int num_vertices;
    int adj_matrix[MAX_VERTICES][MAX_VERTICES];
};

struct graph *create_graph(int num_vertices) {
    struct graph *new_graph = (struct graph*) malloc(sizeof(struct graph));
    new_graph->num_vertices = num_vertices;
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            new_graph->adj_matrix[i][j] = 0;
        }
    }
    return new_graph;
}

void add_edge(struct graph *g, int source, int dest, int weight) {
    g->adj_matrix[source][dest] = weight;
    g->adj_matrix[dest][source] = weight;
}

int min_key(int key[], int mst_set[], int num_vertices) {
    int min = INT_MAX;
    int min_index = -1;
    for (int i = 0; i < num_vertices; i++) {
        if (!mst_set[i] && key[i] < min) {
            min = key[i];
            min_index = i;
        }
    }
    return min_index;
}

void prim_mst(struct graph *g) {
    int parent[MAX_VERTICES];
    int key[MAX_VERTICES];
    int mst_set[MAX_VERTICES] = {0};

    for (int i = 0; i < g->num_vertices; i++) {
        key[i] = INT_MAX;
    }
    key[0] = 0;
    parent[0] = -1;

    for (int i = 0; i < g->num_vertices - 1; i++) {
        int u = min_key(key, mst_set, g->num_vertices);
        mst_set[u] = 1;
        for (int v = 0; v < g->num_vertices; v++) {
            if (g->adj_matrix[u][v] && !mst_set[v] && g->adj_matrix[u][v] < key[v]) {
                parent[v] = u;
                key[v] = g->adj_matrix[u][v];
            }
        }
    }

    printf("Minimum Spanning Tree:\n");
    for (int i = 1; i < g->num_vertices; i++) {
        printf("%d - %d\n", parent[i], i);
    }
}

int main() {
    // Create a graph with 5 vertices
    struct graph *g = create_graph(5);

    // Add edges to the graph
    add_edge(g, 0, 1, 2);
    add_edge(g, 0, 3, 6);
    add_edge(g, 1, 2, 3);
    add_edge(g, 1, 3, 8);
    add_edge(g, 1, 4, 5);
    add_edge(g, 2, 4, 7);
    add_edge(g, 3, 4, 9);

    // Find the minimum spanning tree of the graph
    prim_mst(g);

    return 0;
}
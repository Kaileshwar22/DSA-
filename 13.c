#include <stdio.h>
#include <stdlib.h>

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

void add_edge(struct graph *g, int source, int dest) {
    g->adj_matrix[source][dest] = 1;
    g->adj_matrix[dest][source] = 1;
}

void print_graph(struct graph *g) {
    for (int i = 0; i < g->num_vertices; i++) {
        printf("%d: ", i);
        for (int j = 0; j < g->num_vertices; j++) {
            if (g->adj_matrix[i][j] == 1) {
                printf("%d ", j);
            }
        }
        printf("\n");
    }
}

int main() {
    // Create a graph with 5 vertices
    struct graph *g = create_graph(5);

    // Add edges to the graph
    add_edge(g, 0, 1);
    add_edge(g, 0, 2);
    add_edge(g, 1, 2);
    add_edge(g, 2, 3);
    add_edge(g, 3, 4);

    // Print the graph
    print_graph(g);

    return 0;
}
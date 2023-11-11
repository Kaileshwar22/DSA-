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

int dijkstra(struct graph *g, int source, int dest) {
    int dist[MAX_VERTICES];
    int visited[MAX_VERTICES] = {0};

    for (int i = 0; i < g->num_vertices; i++) {
        dist[i] = INT_MAX;
    }
    dist[source] = 0;

    for (int i = 0; i < g->num_vertices - 1; i++) {
        int min_dist = INT_MAX;
        int min_index = -1;
        for (int j = 0; j < g->num_vertices; j++) {
            if (!visited[j] && dist[j] < min_dist) {
                min_dist = dist[j];
                min_index = j;
            }
        }
        visited[min_index] = 1;
        for (int j = 0; j < g->num_vertices; j++) {
            if (g->adj_matrix[min_index][j] && !visited[j]) {
                int new_dist = dist[min_index] + g->adj_matrix[min_index][j];
                if (new_dist < dist[j]) {
                    dist[j] = new_dist;
                }
            }
        }
    }

    return dist[dest];
}

int main() {
    // Create a graph with 5 vertices
    struct graph *g = create_graph(5);

    // Add edges to the graph
    add_edge(g, 0, 1, 10);
    add_edge(g, 0, 2, 3);
    add_edge(g, 1, 2, 1);
    add_edge(g, 1, 3, 2);
    add_edge(g, 2, 1, 4);
    add_edge(g,
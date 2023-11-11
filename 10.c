#include <stdio.h>

#define MAX_NODES 100

struct node {
    int data;
    int left_child;
    int right_child;
};

struct node tree[MAX_NODES];
int num_nodes = 0;

// Add a new node to the tree
void add_node(int data) {
    if (num_nodes >= MAX_NODES) {
        printf("Error: tree is full.\n");
        return;
    }
    tree[num_nodes].data = data;
    tree[num_nodes].left_child = -1;
    tree[num_nodes].right_child = -1;
    num_nodes++;
}

// Traverse the tree in-order
void traverse_in_order(int node_index) {
    if (node_index == -1) {
        return;
    }
    traverse_in_order(tree[node_index].left_child);
    printf("%d ", tree[node_index].data);
    traverse_in_order(tree[node_index].right_child);
}

int main() {
    // Add nodes to the tree
    add_node(5);
    add_node(3);
    add_node(7);
    add_node(2);
    add_node(4);
    add_node(6);
    add_node(8);

    // Set the child indices for each node
    tree[0].left_child = 1;
    tree[0].right_child = 2;
    tree[1].left_child = 3;
    tree[1].right_child = 4;
    tree[2].left_child = 5;
    tree[2].right_child = 6;

    // Traverse the tree in-order
    traverse_in_order(0);
    printf("\n");

    return 0;
}
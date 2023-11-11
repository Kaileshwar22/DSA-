#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;

// Add a new node to the tree
void add_node(int data) {
    struct node *new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    if (root == NULL) {
        root = new_node;
        return;
    }

    struct node *current = root;
    while (1) {
        if (data < current->data) {
            if (current->left == NULL) {
                current->left = new_node;
                return;
            }
            current = current->left;
        } else {
            if (current->right == NULL) {
                current->right = new_node;
                return;
            }
            current = current->right;
        }
    }
}

// Traverse the tree in-order
void traverse_in_order(struct node *node) {
    if (node == NULL) {
        return;
    }
    traverse_in_order(node->left);
    printf("%d ", node->data);
    traverse_in_order(node->right);
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

    // Traverse the tree in-order
    traverse_in_order(root);
    printf("\n");

    return 0;
}
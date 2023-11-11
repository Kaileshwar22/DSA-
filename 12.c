#include <stdio.h>
#include <stdlib.h>

#define MAX_KEYS 3

struct node {
    int num_keys;
    int keys[MAX_KEYS];
    struct node *children[MAX_KEYS + 1];
};

struct node *root = NULL;

// Create a new node
struct node *create_node(int key) {
    struct node *new_node = (struct node*) malloc(sizeof(struct node));
    new_node->num_keys = 1;
    new_node->keys[0] = key;
    for (int i = 0; i < MAX_KEYS + 1; i++) {
        new_node->children[i] = NULL;
    }
    return new_node;
}

// Insert a key into the tree
void insert_key(int key) {
    if (root == NULL) {
        root = create_node(key);
        return;
    }

    struct node *current = root;
    struct node *parent = NULL;
    int child_index = 0;

    while (1) {
        if (current->num_keys == MAX_KEYS) {
            // Split the node if it is full
            struct node *new_node = create_node(current->keys[1]);
            new_node->children[0] = current;
            new_node->children[1] = create_node(current->keys[2]);
            new_node->num_keys = 1;
            current->num_keys = 1;
            current->children[2] = NULL;
            if (parent == NULL) {
                root = new_node;
            } else {
                parent->children[child_index] = new_node;
            }
            current = new_node;
        }

        if (current->children[0] == NULL) {
            // Insert the key into the node
            int i = current->num_keys - 1;
            while (i >= 0 && key < current->keys[i]) {
                current->keys[i + 1] = current->keys[i];
                i--;
            }
            current->keys[i + 1] = key;
            current->num_keys++;
            return;
        }

        // Traverse to the next child node
        parent = current;
        child_index = current->num_keys;
        current = current->children[child_index];
    }
}

// Traverse the tree in-order
void traverse_in_order(struct node *node) {
    if (node == NULL) {
        return;
    }
    for (int i = 0; i < node->num_keys; i++) {
        traverse_in_order(node->children[i]);
        printf("%d ", node->keys[i]);
    }
    traverse_in_order(node->children[node->num_keys]);
}

int main() {
    // Insert keys into the tree
    insert_key(5);
    insert_key(3);
    insert_key(7);
    insert_key(2);
    insert_key(4);
    insert_key(6);
    insert_key(8);

    // Traverse the tree in-order
    traverse_in_order(root);
    printf("\n");

    return 0;
}
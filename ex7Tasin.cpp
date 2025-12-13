#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

int maxDepth(Node* node) {
    if (node == NULL) return 0;
    int left = maxDepth(node->left);
    int right = maxDepth(node->right);
    return (left > right ? left : right) + 1;
}

int main() {
    
    Node* root1 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(3);
    root1->left->left = newNode(4);

  
    Node* root2 = newNode(10);
    root2->left = newNode(20);
    root2->right = newNode(30);
    root2->left->left = newNode(40);
    root2->left->left->right = newNode(50);

    printf("Depth of Tree 1: %d\n", maxDepth(root1));
    printf("Depth of Tree 2: %d\n", maxDepth(root2));

    return 0;
}


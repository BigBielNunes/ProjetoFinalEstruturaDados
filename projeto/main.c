#include <stdio.h>
#include "arvoreBinaria.h"

int main() {
    Tree root = NULL;

    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");

    printf("Preorder traversal: ");
    preorder(root);
    printf("\n");

    printf("Postorder traversal: ");
    postorder(root);
    printf("\n");

    printf("Search for 70: %s\n", search(root, 70) ? "Found" : "Not found");
    printf("Search for 25: %s\n", search(root, 25) ? "Found" : "Not found");

    printf("Minimum value in the tree: %d\n", minValueNode(root)->key);
    printf("Maximum value in the tree: %d\n", maxValueNode(root)->key);

    root = deleteNode(root, 20);
    printf("Inorder traversal after deleting 20: ");
    inorder(root);
    printf("\n");

    freeTree(root); // Liberando memória

    return 0;
}

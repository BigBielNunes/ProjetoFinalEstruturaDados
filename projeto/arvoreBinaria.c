#include "arvoreBinaria.h"
#include <stdio.h>
#include <stdlib.h>

// Função para criar um novo nó
Tree newNode(int value) {
    Tree node = (Tree)malloc(sizeof(struct TreeNode));
    node->key = value;
    node->left = node->right = NULL;
    return node;
}

// Função para inserir um novo valor na árvore
Tree insert(Tree root, int value) {
    if (root == NULL) {
        return newNode(value);
    }

    if (value < root->key) {
        root->left = insert(root->left, value);
    } else if (value > root->key) {
        root->right = insert(root->right, value);
    }

    return root;
}

// Função para buscar um valor na árvore
int search(Tree root, int value) {
    if (root == NULL) {
        return 0;
    }

    if (root->key == value) {
        return 1;
    } else if (value < root->key) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}

// Função para percorrer a árvore em ordem (inorder)
void inorder(Tree root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

// Função para percorrer a árvore em pré-ordem (preorder)
void preorder(Tree root) {
    if (root != NULL) {
        printf("%d ", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

// Função para percorrer a árvore em pós-ordem (postorder)
void postorder(Tree root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->key);
    }
}

// Função para encontrar o valor mínimo na árvore
Tree minValueNode(Tree node) {
    Tree current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

// Função para encontrar o valor máximo na árvore
Tree maxValueNode(Tree node) {
    Tree current = node;
    while (current && current->right != NULL) {
        current = current->right;
    }
    return current;
}

// Função para remover um valor da árvore
Tree deleteNode(Tree root, int value) {
    if (root == NULL) {
        return root;
    }

    if (value < root->key) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->key) {
        root->right = deleteNode(root->right, value);
    } else {
        if (root->left == NULL) {
            Tree temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Tree temp = root->left;
            free(root);
            return temp;
        }

        Tree temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

// Função para liberar a memória alocada para a árvore
void freeTree(Tree root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

#ifndef ARVOREBINARIA_H
#define ARVOREBINARIA_H

// Estrutura do nó da árvore
struct TreeNode {
    int key;                // Valor do nó
    struct TreeNode* left;  // Ponteiro para o filho esquerdo
    struct TreeNode* right; // Ponteiro para o filho direito
};

// Ponteiro para o nó raiz
typedef struct TreeNode* Tree;

// Protótipos das funções
Tree newNode(int value);
Tree insert(Tree root, int value);
Tree deleteNode(Tree root, int value);
int search(Tree root, int value);
void inorder(Tree root);
void preorder(Tree root);
void postorder(Tree root);
Tree minValueNode(Tree node);
Tree maxValueNode(Tree node);
void freeTree(Tree root);

#endif /* ARVOREBINARIA_H */

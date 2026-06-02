#include <stdio.h>
#include<stdlib.h>
#include <math.h>

struct TreeNode {
    int val;
    struct TreeNode* right;
    struct TreeNode* left;
};

struct TreeNode* Inserir(struct TreeNode* root, int val) {
    if(root==NULL) {
        struct TreeNode* aux = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        aux->val = val;
        aux->right = NULL;
        aux->left = NULL;
        return aux;
    } else {
        if(val < root->val) {
            root->left = Inserir(root->left, val);
        } else {
            root->right = Inserir(root->right, val);
        }
        return root;
    }
}

void Imprimir(struct TreeNode* root) {
    if(root!=NULL) {
        Imprimir(root->left);
        printf("%d ", root->val);
        Imprimir(root->right);
    }
}

int Altura(struct TreeNode *root) {
    if(root == NULL) {
        return -1;
    }

    int esq = Altura(root->left);
    int dir = Altura(root->right);

    if(esq > dir) {
        return esq + 1;
    } else {
        return dir + 1;
    }
}

void Busca(struct TreeNode* root, int nivel, int altura, int* resposta, int* achei) {

    if(root == NULL || *achei != 0) {
        return;
    }

    if(nivel == altura) {
        *resposta = root->val;
        *achei = 1;
    }

    Busca(root->left, nivel + 1, altura, resposta, achei);
    Busca(root->right, nivel + 1, altura, resposta, achei);
}

int findBottomLeftValue(struct TreeNode* root) {

    int altura = Altura(root);

    int resposta = 0;
    int achei = 0;

    Busca(root, 0, altura, &resposta, &achei);

    return resposta;
}

int main() {
    struct TreeNode* arv = NULL;

    arv = Inserir(arv, 10);
    arv = Inserir(arv, 5);
    arv = Inserir(arv, 12);
    arv = Inserir(arv, 4);

    printf("Arvore: ");
    Imprimir(arv);
    printf("\nValor mais baixo a esquerda da arvore: %d", findBottomLeftValue(arv));
}

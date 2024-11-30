#include <stdio.h>
#include <stdlib.h>

// Estrutura para representar um nó da árvore BST
typedef struct No {
    int valor;                  // Valor armazenado no nó
    struct No *esquerda, *direita; // Ponteiros para os nós filho (esquerda e direita)
} No;

// Função para criar um novo nó
No* criarNo(int valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->valor = valor;
    novoNo->esquerda = novoNo->direita = NULL;
    return novoNo;
}

// Inserir um valor na árvore BST
No* inserirBST(No* no, int valor) {
    if (!no) return criarNo(valor); // Criar um novo nó se a posição estiver vazia

    // Inserir o valor no lado esquerdo ou direito
    if (valor < no->valor)
        no->esquerda = inserirBST(no->esquerda, valor);
    else if (valor > no->valor)
        no->direita = inserirBST(no->direita, valor);

    return no; // Retornar o nó atualizado
}

// Exibir a árvore BST em ordem (menor para maior)
void exibirEmOrdem(No* raiz) {
    if (raiz) {
        exibirEmOrdem(raiz->esquerda);
        printf("%d ", raiz->valor);
        exibirEmOrdem(raiz->direita);
    }
}

int main() {
    No* raiz = NULL;

    // Inserir valores na árvore BST
    raiz = inserirBST(raiz, 50);
    raiz = inserirBST(raiz, 30);
    raiz = inserirBST(raiz, 20);
    raiz = inserirBST(raiz, 40);
    raiz = inserirBST(raiz, 70);
    raiz = inserirBST(raiz, 60);
    raiz = inserirBST(raiz, 80);

    // Exibir a árvore em ordem
    printf("Árvore BST em ordem (menor para maior): ");
    exibirEmOrdem(raiz);
    printf("\n");

    return 0;
}

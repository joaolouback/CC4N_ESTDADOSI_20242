#include <stdio.h>
#include <stdlib.h>

// Estrutura para representar um nó da árvore AVL
typedef struct No {
    int valor;                   // Valor armazenado no nó
    int altura;                  // Altura do nó
    struct No *esquerda, *direita; // Ponteiros para os nós filho (esquerda e direita)
} No;

// Função para obter a altura de um nó
int obterAltura(No *no) {
    return no ? no->altura : 0;
}

// Função para calcular o fator de balanceamento de um nó
int calcularBalanceamento(No *no) {
    return no ? obterAltura(no->esquerda) - obterAltura(no->direita) : 0;
}

// Função para criar um novo nó
No* criarNo(int valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->valor = valor;
    novoNo->altura = 1; // Todo novo nó inicia com altura 1
    novoNo->esquerda = novoNo->direita = NULL;
    return novoNo;
}

// Rotação para a direita (usada para balancear a árvore)
No* rotacaoDireita(No* y) {
    No* x = y->esquerda;
    No* T2 = x->direita;

    x->direita = y;
    y->esquerda = T2;

    // Atualizar alturas dos nós
    y->altura = 1 + (obterAltura(y->esquerda) > obterAltura(y->direita) ? obterAltura(y->esquerda) : obterAltura(y->direita));
    x->altura = 1 + (obterAltura(x->esquerda) > obterAltura(x->direita) ? obterAltura(x->esquerda) : obterAltura(x->direita));

    return x; // Novo nó raiz após a rotação
}

// Rotação para a esquerda (usada para balancear a árvore)
No* rotacaoEsquerda(No* x) {
    No* y = x->direita;
    No* T2 = y->esquerda;

    y->esquerda = x;
    x->direita = T2;

    // Atualizar alturas dos nós
    x->altura = 1 + (obterAltura(x->esquerda) > obterAltura(x->direita) ? obterAltura(x->esquerda) : obterAltura(x->direita));
    y->altura = 1 + (obterAltura(y->esquerda) > obterAltura(y->direita) ? obterAltura(y->esquerda) : obterAltura(y->direita));

    return y; // Novo nó raiz após a rotação
}

// Inserir um valor na árvore AVL
No* inserirAVL(No* no, int valor) {
    if (!no) return criarNo(valor); // Criar um novo nó se a posição estiver vazia

    // Inserir o valor no lado esquerdo ou direito
    if (valor < no->valor)
        no->esquerda = inserirAVL(no->esquerda, valor);
    else if (valor > no->valor)
        no->direita = inserirAVL(no->direita, valor);
    else
        return no; // Evitar duplicação de valores

    // Atualizar a altura do nó atual
    no->altura = 1 + (obterAltura(no->esquerda) > obterAltura(no->direita) ? obterAltura(no->esquerda) : obterAltura(no->direita));

    // Verificar o balanceamento do nó atual
    int balanceamento = calcularBalanceamento(no);

    // Rotação à direita (desbalanceado para a esquerda)
    if (balanceamento > 1 && valor < no->esquerda->valor)
        return rotacaoDireita(no);

    // Rotação à esquerda (desbalanceado para a direita)
    if (balanceamento < -1 && valor > no->direita->valor)
        return rotacaoEsquerda(no);

    // Rotação dupla esquerda-direita
    if (balanceamento > 1 && valor > no->esquerda->valor) {
        no->esquerda = rotacaoEsquerda(no->esquerda);
        return rotacaoDireita(no);
    }

    // Rotação dupla direita-esquerda
    if (balanceamento < -1 && valor < no->direita->valor) {
        no->direita = rotacaoDireita(no->direita);
        return rotacaoEsquerda(no);
    }

    return no; // Retornar o nó atualizado
}

// Exibir a árvore AVL em ordem (menor para maior)
void exibirEmOrdem(No* raiz) {
    if (raiz) {
        exibirEmOrdem(raiz->esquerda);
        printf("%d ", raiz->valor);
        exibirEmOrdem(raiz->direita);
    }
}

int main() {
    No* raiz = NULL;

    // Inserir valores na árvore AVL
    raiz = inserirAVL(raiz, 10);
    raiz = inserirAVL(raiz, 20);
    raiz = inserirAVL(raiz, 30);
    raiz = inserirAVL(raiz, 40);
    raiz = inserirAVL(raiz, 50);
    raiz = inserirAVL(raiz, 25);

    // Exibir a árvore em ordem
    printf("Árvore AVL em ordem (menor para maior): ");
    exibirEmOrdem(raiz);
    printf("\n");

    return 0;
}

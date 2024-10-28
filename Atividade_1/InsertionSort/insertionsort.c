#include <stdio.h>
#include <stdlib.h>
#include <time.h>  // Para srand e time()

int main() {
    int arr[50];  // Array com 50 números inteiros
    int len = sizeof(arr) / sizeof(int);  // Tamanho do array
    int i, j, chave;

    // Inicializa a semente para a geração de números aleatórios
    srand(time(NULL));

    // Preenche o array com números aleatórios entre 0 e 100
    for (i = 0; i < len; i++) {
        arr[i] = rand() % 101;  // Gera números entre 0 e 100
    }

    // Imprime o array original
    printf("ARRAY ORIGINAL: \n");
    printf("{");
    for (int x = 0; x < len; x++) {
        printf("%d", arr[x]);
        if (x < len - 1) {
            printf(", ");
        }
    }
    printf("}\n");

    // Algoritmo de ordenação por Inserção (Insertion Sort)
    for (i = 1; i < len; i++) {
        chave = arr[i];  // Elemento atual a ser inserido
        j = i - 1;

        // Move os elementos maiores que a chave para a frente
        while (j >= 0 && arr[j] > chave) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = chave;  // Insere a chave na posição correta
    }

    // Imprime o array ordenado
    printf("ARRAY ORDENADO COM INSERTION SORT: \n");
    printf("{");
    for (int y = 0; y < len; y++) {
        printf("%d", arr[y]);
        if (y < len - 1) {
            printf(", ");
        }
    }
    printf("}\n");

    return 0;
}

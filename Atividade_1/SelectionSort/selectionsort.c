#include <stdio.h>
#include <stdlib.h>
#include <time.h>  // Para srand e time()

int main() {
    int arr[50];  // Array com 50 números inteiros
    int len = sizeof(arr) / sizeof(int);  // Tamanho do array
    int i, j, minIndex, temp;

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

    // Algoritmo de ordenação por Seleção (Selection Sort)
    for (i = 0; i < len - 1; i++) {
        minIndex = i;  // Assume que o menor elemento está na posição atual
        for (j = i + 1; j < len; j++) {
            if (arr[j] < arr[minIndex]) {  // Encontra o menor elemento
                minIndex = j;
            }
        }
        // Troca o menor elemento encontrado com o elemento na posição 'i'
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }

    // Imprime o array ordenado
    printf("ARRAY ORDENADO COM SELECTION SORT: \n");
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

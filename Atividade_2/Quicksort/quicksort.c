#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void trocar(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int particionar(int array[], int inicio, int fim) {
    int pivo = array[fim];
    int i = inicio - 1;

    for (int j = inicio; j < fim; j++) {
        if (array[j] <= pivo) {
            i++;
            trocar(&array[i], &array[j]);
        }
    }
    trocar(&array[i + 1], &array[fim]);
    return i + 1;
}

void quickSort(int array[], int inicio, int fim) {
    if (inicio < fim) {
        int pi = particionar(array, inicio, fim);
        quickSort(array, inicio, pi - 1);
        quickSort(array, pi + 1, fim);
    }
}

void imprimirArray(int array[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int tamanho = 10; // Tamanho do array (reduzido para exibição)
    int array[tamanho];

    // Gera um array ordenado para simular o pior caso
    for (int i = 0; i < tamanho; i++) {
        array[i] = i;
    }

    printf("Array original (Pior Caso):\n");
    imprimirArray(array, tamanho);

    clock_t inicio = clock();
    quickSort(array, 0, tamanho - 1);
    clock_t fim = clock();

    printf("Array ordenado (Pior Caso):\n");
    imprimirArray(array, tamanho);

    double tempoExecucao = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Tempo de execução (Pior Caso): %.6f segundos\n", tempoExecucao);

    return 0;
}

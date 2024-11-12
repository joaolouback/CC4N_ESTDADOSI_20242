#include <stdio.h>

// Função para trocar dois elementos
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função para ajustar o heap
void heapify(int arr[], int n, int i) {
    int largest = i;          // Inicialmente, assume que o maior elemento é a raiz
    int left = 2 * i + 1;     // Índice do filho à esquerda
    int right = 2 * i + 2;    // Índice do filho à direita

    // Verifica se o filho à esquerda é maior que a raiz
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Verifica se o filho à direita é maior que o maior atual
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // Se o maior elemento não é a raiz, troca e ajusta o heap recursivamente
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

// Função principal do Heapsort
void heapsort(int arr[], int n) {
    // Constrói o heap máximo (reorganiza o array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extrai elementos do heap, um por um
    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);      // Move a raiz atual para o final
        heapify(arr, i, 0);          // Chama heapify na árvore reduzida
    }
}

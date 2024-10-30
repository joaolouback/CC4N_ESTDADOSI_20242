#include <stdio.h>
#include <stdlib.h>
#include <time.h> // Necessário para usar time() e srand()

int main()
{
    int arr[50];                         // Array para armazenar 50 números inteiros
    int len = sizeof(arr) / sizeof(int); // Tamanho do array
    int i, j, temporal;

    // Inicializa a semente para números aleatórios
    srand(time(NULL));

    // Preenche o array com números aleatórios entre 0 e 100
    for (i = 0; i < len; i++)
    {
        arr[i] = rand() % 101; // Números entre 0 e 100
    }

    // Imprime o array original
    printf("ARRAY ORIGINAL: \n");
    printf("{");
    for (int x = 0; x < len; x++)
    {
        printf("%d", arr[x]);
        if (x < len - 1)
        {
            printf(", ");
        }
    }
    printf("}\n");

    // Algoritmo de ordenação Bubble Sort
    for (i = 0; i < len - 1; i++)
    {
        for (j = 0; j < len - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // Troca os elementos de posição
                temporal = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temporal;
            }
        }
    }

    // Imprime o array ordenado
    printf("ARRAY ORDENADO COM BUBBLE SORT: \n");
    printf("{");
    for (int y = 0; y < len; y++)
    {
        printf("%d", arr[y]);
        if (y < len - 1)
        {
            printf(", ");
        }
    }
    printf("}\n");

    return 0;
}

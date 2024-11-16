#include <stdio.h>
#include <stdlib.h>

// Função para combinar duas metades do array
void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1; // Tamanho do subarray esquerdo
    int n2 = r - m;     // Tamanho do subarray direito

    // Arrays temporários para armazenar as duas metades
    int L = (int)malloc(n1 * sizeof(int));
    int R = (int)malloc(n2 * sizeof(int));

    // Copia os dados para os arrays temporários
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Indices iniciais para as duas metades e para a mesclagem
    int i = 0, j = 0, k = l;

    // Mescla as duas metades de volta no array original
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copia os elementos restantes de L[], se houver
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copia os elementos restantes de R[], se houver
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }

    // Libera a memória alocada para os arrays temporários
    free(L);
    free(R);
}

// Função principal do Mergesort
void mergesort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2; // Calcula o ponto médio

        mergesort(arr, l, m);     // Ordena a primeira metade
        mergesort(arr, m + 1, r); // Ordena a segunda metade

        merge(arr, l, m, r); // Mescla as duas metades ordenadas
            
    }
}
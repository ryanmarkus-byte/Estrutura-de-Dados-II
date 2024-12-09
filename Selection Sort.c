//Desenvolva o Selection Sort e acompanhe cada iteração mostrando como a lista é organizada passo a passo:

#include <stdio.h>

// Função para trocar dois elementos
void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// Função para implementar o Selection Sort
void selectionSort(int arr[], int size) {
    int i, j, min_idx;

    // Mover a fronteira do subarray não ordenado um a um
    for (i = 0; i < size-1; i++) {
        // Encontrar o menor elemento no subarray não ordenado
        min_idx = i;
        for (j = i+1; j < size; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }

        // Trocar o menor elemento encontrado com o primeiro elemento do subarray não ordenado
        swap(&arr[min_idx], &arr[i]);

        // Imprimir o array a cada iteração
        printf("Iteração %d: ", i+1);
        for (int k = 0; k < size; k++) {
            printf("%d ", arr[k]);
        }
        printf("\n");
    }
}

// Função principal para testar o Selection Sort
int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Array original:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    selectionSort(arr, size);

    printf("\nArray ordenado:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}




//Analise o desempenho do Selection Sort em listas pequenas, médias e grandes:

//Desempenho em Listas Pequenas
//Para listas pequenas, o Selection Sort pode ser eficiente devido à sua simplicidade e facilidade de implementação. 
//No entanto, mesmo em listas pequenas, o número de comparações ainda pode ser significativo, com complexidade de tempo O(n²).

//Desempenho em Listas Médias
//À medida que o tamanho da lista aumenta, o número de comparações e trocas cresce quadraticamente. 
//Em listas médias, o desempenho do Selection Sort começa a ser inferior comparado a algoritmos mais eficientes como Merge Sort e Quick Sort.

//Desempenho em Listas Grandes
//Para listas grandes, o Selection Sort é ineficiente devido ao grande número de comparações e trocas necessárias. 
//O tempo de execução torna-se impraticável para grandes conjuntos de dados.
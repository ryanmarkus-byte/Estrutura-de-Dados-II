//Implemente o Shell Sort com diferentes sequências de intervalo (ex.: Shell, Knuth, Hibbard):

#include <stdio.h>
#include <time.h>

// Função para imprimir o array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Implementação do Shell Sort com a sequência de intervalos padrão
void shellSortShell(int arr[], int size) {
    for (int gap = size / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < size; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

// Implementação do Shell Sort com a sequência de intervalos de Knuth
void shellSortKnuth(int arr[], int size) {
    int gap = 1;
    while (gap < size / 3) {
        gap = 3 * gap + 1;
    }

    while (gap > 0) {
        for (int i = gap; i < size; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
        gap /= 3;
    }
}

// Implementação do Shell Sort com a sequência de intervalos de Hibbard
void shellSortHibbard(int arr[], int size) {
    int k = 1;
    while ((1 << k) - 1 < size) {
        k++;
    }
    k--;

    while (k > 0) {
        int gap = (1 << k) - 1;
        for (int i = gap; i < size; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
        k--;
    }
}

// Função para medir e comparar os tempos de execução das diferentes sequências de Shell Sort
void measureTime(int arr[], int size) {
    int arrShell[size], arrKnuth[size], arrHibbard[size];

    for (int i = 0; i < size; i++) {
        arrShell[i] = arr[i];
        arrKnuth[i] = arr[i];
        arrHibbard[i] = arr[i];
    }

    clock_t start, end;
    double time_used;

    // Medir tempo do Shell Sort com sequência padrão
    start = clock();
    shellSortShell(arrShell, size);
    end = clock();
    time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Shell Sort (sequência Shell) time: %f seconds\n", time_used);

    // Medir tempo do Shell Sort com sequência de Knuth
    start = clock();
    shellSortKnuth(arrKnuth, size);
    end = clock();
    time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Shell Sort (sequência Knuth) time: %f seconds\n", time_used);

    // Medir tempo do Shell Sort com sequência de Hibbard
    start = clock();
    shellSortHibbard(arrHibbard, size);
    end = clock();
    time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Shell Sort (sequência Hibbard) time: %f seconds\n", time_used);
}

int main() {
    int arr[] = {23, 42, 4, 16, 8, 15, 9, 55, 0, 34};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Array original:\n");
    printArray(arr, size);

    printf("\nComparação dos tempos de execução:\n");
    measureTime(arr, size);

    return 0;
}




//Explique como a escolha da sequência de intervalos afeta a eficiência do algoritmo:

//A escolha da sequência de intervalos no Shell Sort pode ter um impacto significativo na eficiência do algoritmo. 
//As sequências mais complexas, como Knuth e Hibbard, tendem a ser mais eficientes que a sequência original de Shell, 
//pois reduzem o número de comparações e movimentos necessários para ordenar a lista.

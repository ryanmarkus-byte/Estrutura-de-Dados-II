//Implemente o Quick Sort utilizando diferentes critérios para escolha do pivô (ex.: primeiro elemento, último elemento, elemento do meio):

#include <stdio.h>
#include <time.h>

// Função para trocar dois elementos
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função para particionar o array usando o primeiro elemento como pivô
int partitionFirst(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low + 1;

    for (int j = low + 1; j <= high; j++) {
        if (arr[j] < pivot) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[low], &arr[i - 1]);
    return i - 1;
}

// Função para particionar o array usando o último elemento como pivô
int partitionLast(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Função para particionar o array usando o elemento do meio como pivô
int partitionMiddle(int arr[], int low, int high) {
    int mid = low + (high - low) / 2;
    int pivot = arr[mid];
    swap(&arr[mid], &arr[high]); // Mover pivô para o final
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Implementação do Quick Sort usando o primeiro elemento como pivô
void quickSortFirst(int arr[], int low, int high) {
    if (low < high) {
        int pi = partitionFirst(arr, low, high);
        quickSortFirst(arr, low, pi - 1);
        quickSortFirst(arr, pi + 1, high);
    }
}

// Implementação do Quick Sort usando o último elemento como pivô
void quickSortLast(int arr[], int low, int high) {
    if (low < high) {
        int pi = partitionLast(arr, low, high);
        quickSortLast(arr, low, pi - 1);
        quickSortLast(arr, pi + 1, high);
    }
}

// Implementação do Quick Sort usando o elemento do meio como pivô
void quickSortMiddle(int arr[], int low, int high) {
    if (low < high) {
        int pi = partitionMiddle(arr, low, high);
        quickSortMiddle(arr, low, pi - 1);
        quickSortMiddle(arr, pi + 1, high);
    }
}

// Função para medir o tempo de execução do Quick Sort
void measureTime(int arr[], int size, void (*quickSort)(int[], int, int)) {
    int arrCopy[size];
    for (int i = 0; i < size; i++) {
        arrCopy[i] = arr[i];
    }

    clock_t start, end;
    double cpu_time_used;

    start = clock();
    quickSort(arrCopy, 0, size - 1);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Quick Sort time for size %d: %f seconds\n", size, cpu_time_used);
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Desempenho para Lista Desordenada:\n");
    measureTime(arr, size, quickSortFirst);
    measureTime(arr, size, quickSortLast);
    measureTime(arr, size, quickSortMiddle);

    int arrNearlySorted[] = {1, 2, 3, 4, 5, 6};
    int sizeNearlySorted = sizeof(arrNearlySorted) / sizeof(arrNearlySorted[0]);

    printf("\nDesempenho para Lista Quase Ordenada:\n");
    measureTime(arrNearlySorted, sizeNearlySorted, quickSortFirst);
    measureTime(arrNearlySorted, sizeNearlySorted, quickSortLast);
    measureTime(arrNearlySorted, sizeNearlySorted, quickSortMiddle);

    return 0;
}




//Analise o desempenho do Quick Sort em listas quase ordenadas e completamente desordenadas:

//O desempenho do Quick Sort depende da escolha do pivô e da distribuição dos dados na lista. 
//Vamos analisar o desempenho em duas situações:

//Listas Quase Ordenadas

//Pivô Primeiro/Último Elemento: Pode resultar em um desempenho ruim (O(n²)), pois o pivô escolhido pode não dividir bem a lista, levando a partições desbalanceadas.

//Pivô Elemento do Meio: Tendência a melhor desempenho (O(n log n)) para listas quase ordenadas, pois o pivô do meio divide a lista de maneira mais uniforme.

//Listas Completamente Desordenadas

//Pivô Primeiro/Último Elemento: Funciona bem na maioria dos casos, mas ainda pode ter casos desfavoráveis com complexidade O(n²).

//Pivô Elemento do Meio: Geralmente mais estável e eficiente com complexidade O(n log n), já que tende a dividir a lista de forma mais equilibrada.
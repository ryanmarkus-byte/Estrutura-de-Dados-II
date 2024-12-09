//Implemente o Bucket Sort para ordenar uma lista de números em ponto flutuante no intervalo [0, 1):

#include <stdio.h>
#include <stdlib.h>

// Função para ordenar um bucket usando Insertion Sort
void insertionSort(float arr[], int n) {
    int i, j;
    float key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Função para implementar o Bucket Sort
void bucketSort(float arr[], int n) {
    // 1. Cria n baldes vazios
    float** buckets = (float**)malloc(n * sizeof(float*));
    int* bucketCounts = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        buckets[i] = (float*)malloc(n * sizeof(float));
        bucketCounts[i] = 0;
    }

    // 2. Distribui os elementos nos baldes
    for (int i = 0; i < n; i++) {
        int bucketIndex = (int)(arr[i] * n); // Index = arr[i] * n
        buckets[bucketIndex][bucketCounts[bucketIndex]++] = arr[i];
    }

    // 3. Ordena cada balde individualmente
    for (int i = 0; i < n; i++) {
        insertionSort(buckets[i], bucketCounts[i]);
    }

    // 4. Concatena todos os baldes ordenados
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < bucketCounts[i]; j++) {
            arr[index++] = buckets[i][j];
        }
    }

    // Libera memória alocada
    for (int i = 0; i < n; i++) {
        free(buckets[i]);
    }
    free(buckets);
    free(bucketCounts);
}

// Função principal para testar o Bucket Sort
int main() {
    float arr[] = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array inicial:\n");
    for (int i = 0; i < n; i++) {
        printf("%f ", arr[i]);
    }
    printf("\n");

    bucketSort(arr, n);

    printf("Array ordenado:\n");
    for (int i = 0; i < n; i++) {
        printf("%f ", arr[i]);
    }
    printf("\n");

    return 0;
}




//Explique como os "baldes" são preenchidos e ordenados:

//Distribuição nos Baldes: Cada elemento do array é distribuído em um balde com base no valor. 
//Para números no intervalo [0, 1), o índice do balde é calculado multiplicando o valor pelo número total de baldes.

//Exemplo: Para 0.897, o índice do balde é 0.897 * n.

//Ordenação dos Baldes: Cada balde é ordenado individualmente usando um algoritmo de ordenação simples, como o Insertion Sort.

//Concatenação dos Baldes: Todos os baldes ordenados são então concatenados para formar o array final ordenado.




//Adapte o Bucket Sort para ordenar números inteiros positivos em intervalos maiores:

#include <stdio.h>
#include <stdlib.h>

// Função para ordenar um bucket usando Insertion Sort
void insertionSort(int arr[], int n) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Função para encontrar o valor máximo no array
int findMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

// Função para implementar o Bucket Sort para inteiros
void bucketSortInt(int arr[], int n) {
    int max = findMax(arr, n);
    int bucketRange = max / n + 1;

    // 1. Cria n baldes vazios
    int** buckets = (int**)malloc(n * sizeof(int*));
    int* bucketCounts = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        buckets[i] = (int*)malloc(n * sizeof(int));
        bucketCounts[i] = 0;
    }

    // 2. Distribui os elementos nos baldes
    for (int i = 0; i < n; i++) {
        int bucketIndex = arr[i] / bucketRange; // Index = arr[i] / bucketRange
        buckets[bucketIndex][bucketCounts[bucketIndex]++] = arr[i];
    }

    // 3. Ordena cada balde individualmente
    for (int i = 0; i < n; i++) {
        insertionSort(buckets[i], bucketCounts[i]);
    }

    // 4. Concatena todos os baldes ordenados
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < bucketCounts[i]; j++) {
            arr[index++] = buckets[i][j];
        }
    }

    // Libera memória alocada
    for (int i = 0; i < n; i++) {
        free(buckets[i]);
    }
    free(buckets);
    free(bucketCounts);
}

// Função principal para testar o Bucket Sort para inteiros
int main() {
    int arr[] = {78, 17, 39, 26, 72, 94, 21, 12, 23, 68};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array inicial:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    bucketSortInt(arr, n);

    printf("Array ordenado:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

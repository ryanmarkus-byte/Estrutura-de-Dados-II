//Adapte os algoritmos de ordenação (Merge Sort e Quick Sort) para ordenar palavras em ordem alfabética.
//Utilize Binary Search para verificar se uma palavra específica está presente em uma lista de palavras ordenadas.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Função para troca de elementos
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Implementação do Shell Sort
void shellSort(int arr[], int size) {
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

// Função para mesclar duas sublistas de strings
void mergeStrings(char* arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    char* leftArr[n1];
    char* rightArr[n2];

    for (int i = 0; i < n1; i++) leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++) rightArr[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (strcmp(leftArr[i], rightArr[j]) <= 0) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

// Função recursiva para implementar o Merge Sort para strings
void mergeSortStrings(char* arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSortStrings(arr, left, mid);
        mergeSortStrings(arr, mid + 1, right);
        mergeStrings(arr, left, mid, right);
    }
}

// Função para particionar o array de strings usando o último elemento como pivô
int partitionStrings(char* arr[], int low, int high) {
    char* pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (strcmp(arr[j], pivot) < 0) {
            i++;
            char* temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    char* temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

// Implementação do Quick Sort para strings
void quickSortStrings(char* arr[], int low, int high) {
    if (low < high) {
        int pi = partitionStrings(arr, low, high);
        quickSortStrings(arr, low, pi - 1);
        quickSortStrings(arr, pi + 1, high);
    }
}

// Implementação do Binary Search para strings
int binarySearchStrings(char* arr[], int left, int right, char* target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        int res = strcmp(arr[mid], target);
        if (res == 0) {
            return mid;
        }
        if (res < 0) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1; // Palavra não encontrada
}

// Função para medir o tempo de execução de algoritmos de ordenação
void measureSortTime(void (*sortFunc)(char*[], int, int), char* arr[], int size, const char *sortName) {
    char** arrCopy = (char **)malloc(size * sizeof(char *));
    for (int i = 0; i < size; i++) {
        arrCopy[i] = arr[i];
    }

    clock_t start, end;
    double cpu_time_used;

    start = clock();
    sortFunc(arrCopy, 0, size - 1);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("%s:\n", sortName);
    printf("Tempo de execução: %f segundos\n", cpu_time_used);

    free(arrCopy);
}

int main() {
    char* words[] = {"apple", "orange", "banana", "pear", "grape"};
    int size = sizeof(words) / sizeof(words[0]);
    char* target = "banana";

    // Ordenação com Merge Sort
    mergeSortStrings(words, 0, size - 1);
    printf("Palavras ordenadas com Merge Sort:\n");
    for (int i = 0; i < size; i++) {
        printf("%s ", words[i]);
    }
    printf("\n");

    // Reordenação com Quick Sort
    char* words2[] = {"apple", "orange", "banana", "pear", "grape"};
    quickSortStrings(words2, 0, size - 1);
    printf("Palavras ordenadas com Quick Sort:\n");
    for (int i = 0; i < size; i++) {
        printf("%s ", words2[i]);
    }
    printf("\n");

    // Busca binária em lista ordenada
    int result = binarySearchStrings(words, 0, size - 1, target);
    if (result == -1) {
        printf("Palavra '%s' não encontrada.\n", target);
    } else {
        printf("Palavra '%s' encontrada no índice: %d\n", target, result);
    }

    return 0;
}

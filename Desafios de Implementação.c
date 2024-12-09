//Crie um programa que permita ao usuário escolher um algoritmo de busca e ordenação para ordenar uma lista ou procurar um elemento, oferecendo comparações automáticas entre os métodos:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Função para imprimir o array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Função para troca de elementos
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função para gerar um array aleatório
void generateRandomArray(int arr[], int size, int max_val) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % max_val;
    }
}

// Implementação do Merge Sort
void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Implementação do Quick Sort
int partition(int arr[], int low, int high) {
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

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Implementação do Selection Sort
void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(&arr[min_idx], &arr[i]);
    }
}

// Implementação do Binary Search
int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        }
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1; // Elemento não encontrado
}

// Implementação do Interpolation Search
int interpolationSearch(int arr[], int size, int target) {
    int low = 0, high = size - 1;
    while (low <= high && target >= arr[low] && target <= arr[high]) {
        if (low == high) {
            if (arr[low] == target) return low;
            return -1;
        }
        int pos = low + ((double)(high - low) / (arr[high] - arr[low]) * (target - arr[low]));
        if (arr[pos] == target) {
            return pos;
        }
        if (arr[pos] < target) {
            low = pos + 1;
        } else {
            high = pos - 1;
        }
    }
    return -1; // Elemento não encontrado
}

// Função para medir o tempo de execução e executar o algoritmo
void measureSortTime(void (*sortFunc)(int[], int), int arr[], int size, const char *sortName) {
    int *arrCopy = (int *)malloc(size * sizeof(int));
    memcpy(arrCopy, arr, size * sizeof(int));

    clock_t start, end;
    double cpu_time_used;

    start = clock();
    sortFunc(arrCopy, size);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("%s:\n", sortName);
    printf("Tempo de execução: %f segundos\n", cpu_time_used);

    free(arrCopy);
}

// Função para medir o tempo de execução e executar o algoritmo com índices
void measureSortTimeWithIndices(void (*sortFunc)(int[], int, int), int arr[], int size, const char *sortName) {
    int *arrCopy = (int *)malloc(size * sizeof(int));
    memcpy(arrCopy, arr, size * sizeof(int));

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

// Função principal
int main() {
    int choice, searchChoice;
    int size, target;

    printf("Escolha o tamanho do array: ");
    scanf("%d", &size);

    int *arr = (int *)malloc(size * sizeof(int));
    generateRandomArray(arr, size, 100);

    printf("Array original:\n");
    printArray(arr, size);

    printf("\nEscolha um algoritmo de ordenação:\n");
    printf("1. Merge Sort\n");
    printf("2. Quick Sort\n");
    printf("3. Selection Sort\n");
    printf("Escolha: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            measureSortTimeWithIndices(mergeSort, arr, size, "Merge Sort");
            break;
        case 2:
            measureSortTimeWithIndices(quickSort, arr, size, "Quick Sort");
            break;
        case 3:
            measureSortTime(selectionSort, arr, size, "Selection Sort");
            break;
        default:
            printf("Escolha inválida!\n");
            break;
    }

    printf("\nEscolha um algoritmo de busca:\n");
    printf("1. Binary Search\n");
    printf("2. Interpolation Search\n");
    printf("Escolha: ");
    scanf("%d", &searchChoice);

    printf("Digite o valor a ser procurado: ");
    scanf("%d", &target);

    int result = -1;
    switch (searchChoice) {
        case 1:
            result = binarySearch(arr, 0, size - 1, target);
            break;
        case 2:
            result = interpolationSearch(arr, size, target);
            break;
        default:
            printf("Escolha inválida!\n");
            break;
    }

    if (result != -1) {
        printf("Elemento encontrado no índice: %d\n", result);
    } else {
        printf("Elemento não encontrado.\n");
    }

    free(arr);
    return 0;
}

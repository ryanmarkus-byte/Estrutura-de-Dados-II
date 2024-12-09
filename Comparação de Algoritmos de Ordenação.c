//Ordene a mesma lista utilizando Shell Sort, Merge Sort, Selection Sort, Quick Sort, Bucket Sort e Radix Sort. 
//Registre os tempos de execução e número de comparações realizadas:

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int comparisons;

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
                comparisons++;
            }
            arr[j] = temp;
        }
    }
}

// Função para mesclar duas sublistas
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int leftArr[n1], rightArr[n2];

    for (int i = 0; i < n1; i++) leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++) rightArr[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        comparisons++;
        if (leftArr[i] <= rightArr[j]) {
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

// Função recursiva para implementar o Merge Sort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Implementação do Selection Sort
void selectionSort(int arr[], int size) {
    for (int i = 0; i < size-1; i++) {
        int min_idx = i;
        for (int j = i+1; j < size; j++) {
            comparisons++;
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(&arr[min_idx], &arr[i]);
    }
}

// Função para particionar o array usando o elemento do meio como pivô
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        comparisons++;
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Implementação do Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void insertionSort(float arr[], int n) {
    int i, j;
    float key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            comparisons++;
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Implementação do Bucket Sort para números inteiros
void bucketSort(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) max = arr[i];
    }

    int bucketRange = max / n + 1;
    int** buckets = (int**)malloc(n * sizeof(int*));
    int* bucketCounts = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        buckets[i] = (int*)malloc(n * sizeof(int));
        bucketCounts[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        int bucketIndex = arr[i] / bucketRange;
        buckets[bucketIndex][bucketCounts[bucketIndex]++] = arr[i];
    }

    for (int i = 0; i < n; i++) {
        insertionSort(buckets[i], bucketCounts[i]);
    }

    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < bucketCounts[i]; j++) {
            arr[index++] = buckets[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        free(buckets[i]);
    }
    free(buckets);
    free(bucketCounts);
}

int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) max = arr[i];
    }
    return max;
}

void countingSort(int arr[], int n, int exp) {
    int output[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// Implementação do Radix Sort
void radixSort(int arr[], int n) {
    int max = getMax(arr, n);
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSort(arr, n, exp);
    }
}

void measureSortTime(void (*sortFunc)(int[], int), int arr[], int size, const char *sortName) {
    int *arrCopy = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        arrCopy[i] = arr[i];
    }

    comparisons = 0;
    clock_t start, end;
    double cpu_time_used;

    start = clock();
    sortFunc(arrCopy, size);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("%s:\n", sortName);
    printf("Tempo de execução: %f segundos\n", cpu_time_used);
    printf("Comparações: %d\n\n", comparisons);

    free(arrCopy);
}

void measureSortTimeWithIndices(void (*sortFunc)(int[], int, int), int arr[], int size, const char *sortName) {
    int *arrCopy = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        arrCopy[i] = arr[i];
    }

    comparisons = 0;
    clock_t start, end;
    double cpu_time_used;

    start = clock();
    sortFunc(arrCopy, 0, size - 1);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("%s:\n", sortName);
    printf("Tempo de execução: %f segundos\n", cpu_time_used);
    printf("Comparações: %d\n\n", comparisons);

    free(arrCopy);
}

int main() {
    int arr[] = {64, 25, 12, 22, 11, 34, 78, 9, 87, 61};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Comparação dos Algoritmos de Ordenação:\n\n");

    measureSortTime(shellSort, arr, size, "Shell Sort");
    measureSortTimeWithIndices(mergeSort, arr, size, "Merge Sort");
    measureSortTime(selectionSort, arr, size, "Selection Sort");
    measureSortTimeWithIndices(quickSort, arr, size, "Quick Sort");
    measureSortTime(bucketSort, arr, size, "Bucket Sort");
    measureSortTime(radixSort, arr, size, "Radix Sort");

    return 0;
}

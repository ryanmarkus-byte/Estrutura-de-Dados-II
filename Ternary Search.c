//Desenvolva o algoritmo Ternary Search para localizar um elemento em uma lista ordenada:

#include <stdio.h>
#include <time.h>

// Função para trocar dois elementos
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função para implementar o Ternary Search
int ternarySearch(int arr[], int left, int right, int target) {
    if (right >= left) {
        // Calcula os dois pivôs
        int mid1 = left + (right - left) / 3;
        int mid2 = right - (right - left) / 3;

        // Verifica se o alvo está em um dos pivôs
        if (arr[mid1] == target) {
            return mid1;
        }
        if (arr[mid2] == target) {
            return mid2;
        }

        // Decide em qual parte do array continuar a busca
        if (target < arr[mid1]) {
            return ternarySearch(arr, left, mid1 - 1, target);
        } else if (target > arr[mid2]) {
            return ternarySearch(arr, mid2 + 1, right, target);
        } else {
            return ternarySearch(arr, mid1 + 1, mid2 - 1, target);
        }
    }
    return -1; // Elemento não encontrado
}

// Função para implementar o Binary Search
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

// Função para medir o tempo de execução do Ternary Search e Binary Search
void measureTime(int arr[], int size, int target, int (*search)(int[], int, int, int)) {
    clock_t start, end;
    double cpu_time_used;

    start = clock();
    search(arr, 0, size - 1, target);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Tempo de execução: %f segundos\n", cpu_time_used);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 5;

    printf("Ternary Search:\n");
    measureTime(arr, size, target, ternarySearch);

    printf("\nBinary Search:\n");
    measureTime(arr, size, target, binarySearch);

    return 0;
}






//Identifique situações em que o Ternary Search seria mais eficiente que o Binary Search:
//Datasets Específicos: Em alguns casos específicos onde os dados são distribuídos de tal forma que a divisão em três partes permite uma busca mais rápida, o Ternary Search pode ser ligeiramente mais eficiente.

//Complexidade de Comparações: O Ternary Search realiza mais comparações por iteração do que o Binary Search, o que pode reduzir o número total de iterações em certas distribuições de dados.

//No entanto, na prática, o Binary Search geralmente é mais eficiente devido ao seu menor número de comparações por iteração e simplicidade. 
//Em termos de complexidade de tempo, ambos os algoritmos têm complexidade O(log n).
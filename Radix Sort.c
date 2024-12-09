//Implemente o Radix Sort para ordenar uma lista de números inteiros:

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Função para encontrar o maior número no array
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

// Função para fazer o Counting Sort baseado no dígito exp (exp é 10^i onde i é o dígito atual)
void countingSort(int arr[], int n, int exp) {
    int output[n]; // array de saída
    int count[10] = {0}; // array para armazenar contagens de ocorrências

    // Armazenar a contagem de ocorrências
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    // Alterar count[i] para que count[i] contenha a posição atual desse dígito em output[]
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Construir o array de saída
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copiar o array de saída para arr[], para que arr[] agora contenha números ordenados por dígito atual
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// Função principal para implementar o Radix Sort
void radixSort(int arr[], int n) {
    int max = getMax(arr, n);

    // Fazer counting sort para cada dígito. Em vez de passar o número do dígito, exp é passado. exp é 10^i onde i é o dígito atual.
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSort(arr, n, exp);
    }
}

// Função principal para testar o Radix Sort
int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array inicial:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    radixSort(arr, n);

    printf("Array ordenado:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}




//Explique como o algoritmo lida com bases diferentes (ex.: base 10 e base 2):

//O Radix Sort pode ser adaptado para trabalhar com diferentes bases ajustando a forma como os dígitos são extraídos e contabilizados:

//Base 10 (Decimal):

//Neste exemplo, usamos a base 10. Os dígitos são extraídos usando (arr[i] / exp) % 10 onde exp é 10^i.

//Exemplo: para exp = 10, (170 / 10) % 10 = 7.

//Base 2 (Binário):

//Para adaptar o Radix Sort para base 2, a função countingSort pode ser ajustada para trabalhar com 2 baldes (0 e 1) e exp deve ser ajustado para potências de 2 (1, 2, 4, 8, ...).

//Exemplo: exp = 1, 2, 4, 8, ..., então (arr[i] / exp) % 2 extrai o i-ésimo bit do número.


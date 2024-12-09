//Implemente o Merge Sort para ordenar uma lista de números inteiros:

#include <stdio.h>
#include <stdlib.h>

// Função para mesclar duas sublistas
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Criar arrays temporários
    int leftArr[n1], rightArr[n2];

    // Copiar dados para os arrays temporários
    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

    // Mesclar os arrays temporários de volta no array original
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Copiar os elementos restantes de leftArr[], se houver
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // Copiar os elementos restantes de rightArr[], se houver
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

        // Ordenar a primeira e a segunda metade
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Mesclar as duas metades ordenadas
        merge(arr, left, mid, right);
    }
}

// Função principal para testar o Merge Sort
int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Array inicial:\n");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");

    mergeSort(arr, 0, size - 1);

    printf("Array ordenado:\n");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}




//Explique o conceito de "dividir para conquistar" usado nesse algoritmo:

//Dividir: A lista é dividida recursivamente em duas metades até que cada sublista contenha apenas um elemento.

//Conquistar: Cada sublista é ordenada.

//Mesclar: As sublistas ordenadas são combinadas para formar a lista final ordenada.




//Modifique o Merge Sort para ordenar strings em ordem alfabética:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função para mesclar duas sublistas de strings
void mergeStrings(char* arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Criar arrays temporários
    char* leftArr[n1];
    char* rightArr[n2];

    // Copiar dados para os arrays temporários
    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

    // Mesclar os arrays temporários de volta no array original
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

    // Copiar os elementos restantes de leftArr[], se houver
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // Copiar os elementos restantes de rightArr[], se houver
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

        // Ordenar a primeira e a segunda metade
        mergeSortStrings(arr, left, mid);
        mergeSortStrings(arr, mid + 1, right);

        // Mesclar as duas metades ordenadas
        mergeStrings(arr, left, mid, right);
    }
}

// Função principal para testar o Merge Sort para strings
int main() {
    char* arr[] = {"banana", "apple", "orange", "grape", "pear"};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Array inicial:\n");
    for (int i = 0; i < size; i++)
        printf("%s ", arr[i]);
    printf("\n");

    mergeSortStrings(arr, 0, size - 1);

    printf("Array ordenado:\n");
    for (int i = 0; i < size; i++)
        printf("%s ", arr[i]);
    printf("\n");

    return 0;
}

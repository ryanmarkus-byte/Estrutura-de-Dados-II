//Implemente o algoritmo Exponential Search para localizar um elemento em uma lista ordenada:

#include <stdio.h>

// Função Binary Search para uso no Exponential Search
int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;

        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

// Função Exponential Search
int exponentialSearch(int arr[], int size, int target) {
    if (arr[0] == target)
        return 0;

    int i = 1;
    while (i < size && arr[i] <= target)
        i = i * 2;

    return binarySearch(arr, i / 2, fmin(i, size - 1), target);
}

// Função principal para testar o Exponential Search
int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 7;

    int result = exponentialSearch(arr, size, target);
    (result != -1) ? printf("Elemento encontrado no índice: %d\n", result) : printf("Elemento não encontrado.\n");

    return 0;
}




//Explique como ele combina elementos do Jump Search e Binary Search:

//Exponential Growth (Jump Search):

//O algoritmo começa com um salto de tamanho 1, depois 2, 4, 8, etc., duplicando o tamanho do salto a cada iteração. 
//Esse comportamento é similar ao Jump Search, onde procuramos em saltos, mas aqui os saltos aumentam exponencialmente.

//Binary Search:

//Uma vez que o intervalo é identificado (isto é, quando o elemento atual é maior que o alvo), o Exponential Search realiza uma busca binária dentro desse intervalo. 
//A combinação da busca exponencial e binária torna o algoritmo eficiente tanto para grandes quanto para pequenas listas.



//Analise o desempenho do Exponential Search em listas muito grandes e pequenas:

//Análise do Desempenho
//Listas Pequenas: Para listas pequenas, o Exponential Search pode ser menos eficiente que o Binary Search devido ao overhead de duplicar saltos e realizar uma busca binária subsequente.

//Listas Grandes: Para listas muito grandes, o Exponential Search pode ser mais eficiente, especialmente se o alvo estiver localizado nos primeiros segmentos da lista. 
//O crescimento exponencial permite reduzir rapidamente o intervalo de busca, e a subsequente busca binária garante eficiência.
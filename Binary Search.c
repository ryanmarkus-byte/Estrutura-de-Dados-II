//Implemente o algoritmo Binary Search em uma lista ordenada e encontre o índice de um elemento dado:

#include <stdio.h>

// Função Binary Search
int binarySearch(int arr[], int size, int target) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Verifica se o alvo está no meio
        if (arr[mid] == target)
            return mid;

        // Se o alvo é maior, ignore a metade esquerda
        if (arr[mid] < target)
            left = mid + 1;
        // Se o alvo é menor, ignore a metade direita
        else
            right = mid - 1;
    }

    // Alvo não encontrado
    return -1;
}

// Função principal para testar o algoritmo
int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 10;
    int result = binarySearch(arr, size, target);

    if (result == -1)
        printf("Elemento não presente no array\n");
    else
        printf("Elemento encontrado no índice: %d\n", result);

    return 0;
}

//Explique por que a lista deve estar ordenada para que o Binary Search funcione corretamente. Forneça exemplos:

//O Binary Search funciona com o princípio de dividir e conquistar. Ele começa comparando o elemento do meio da lista com o alvo. Se o alvo é igual ao elemento do meio, ele retorna o índice. Se o alvo é menor que o elemento do meio, ele repete o processo na metade esquerda da lista. Se o alvo é maior, ele repete na metade direita.

//Isso só é possível porque a lista está ordenada. Sem a ordenação, não podemos garantir que todas as ocorrências do alvo estarão de um lado ou de outro do ponto de comparação.

//Exemplo:
//Considere a lista ordenada: [2, 3, 4, 10, 40]

//Vamos procurar o número 10.

//Comparar 10 com o elemento do meio 4. Como 10 é maior, ignoramos a metade esquerda [2, 3, 4].

//Agora, a nova sub-lista é [10, 40]. Comparar 10 com 10 (novo meio). Encontramos o alvo!

//Se a lista não fosse ordenada, não poderíamos aplicar essa lógica de redução eficiente do espaço de busca.
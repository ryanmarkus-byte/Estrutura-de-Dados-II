//Desenvolva o algoritmo Jump Search:

#include <stdio.h>
#include <math.h>

// Função Jump Search
int jumpSearch(int arr[], int size, int target) {
    int step = sqrt(size); // Tamanho do salto
    int prev = 0;

    // Encontrar o bloco onde o elemento está presente
    while (arr[fmin(step, size) - 1] < target) {
        prev = step;
        step += sqrt(size);
        if (prev >= size)
            return -1;
    }

    // Realizar busca linear no bloco
    while (arr[prev] < target) {
        prev++;
        if (prev == fmin(step, size))
            return -1;
    }

    // Verifica se o elemento está presente
    if (arr[prev] == target)
        return prev;

    return -1;
}

// Função principal para testar o Jump Search
int main() {
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 7;
    
    int result = jumpSearch(arr, size, target);
    (result != -1) ? printf("Elemento encontrado no índice: %d\n", result) : printf("Elemento não encontrado.\n");

    return 0;
}




//Determine o tamanho ideal do "salto" para uma lista de tamanho:

//O tamanho ideal do "salto" (step) para o Jump Search é a raiz quadrada do tamanho da lista. Isso minimiza o número de comparações feitas durante a busca.



//Compare o tempo de execução do Jump Search com o Binary Search em listas de diferentes tamanhos:

//Lista Pequena (size = 10)

//Lista Média (size = 100)

//Lista Grande (size = 1000)

//Jump Search: É eficiente em listas grandes com elementos uniformemente distribuídos. O tempo de execução é aproximadamente O(\sqrt{n}).

//Binary Search: É mais eficiente em listas com distribuição não uniforme e geralmente tem tempo de execução O(log n).

//Use o Binary Search para procurar um livro específico por ISBN em uma lista ordenada de registros de biblioteca:

#include <stdio.h>
#include <string.h>

// Estrutura para armazenar os registros de biblioteca
typedef struct {
    char isbn[13];
    char title[100];
} Book;

// Função para implementar o Binary Search para procurar um livro por ISBN
int binarySearchISBN(Book arr[], int left, int right, char* targetISBN) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        int res = strcmp(arr[mid].isbn, targetISBN);
        if (res == 0) {
            return mid; // ISBN encontrado
        }
        if (res < 0) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1; // ISBN não encontrado
}

int main() {
    // Lista de registros de biblioteca ordenada por ISBN
    Book library[] = {
        {"0001234567890", "Introduction to Algorithms"},
        {"0001234567891", "The C Programming Language"},
        {"0001234567892", "Artificial Intelligence: A Modern Approach"},
        {"0001234567893", "Clean Code"},
        {"0001234567894", "Design Patterns: Elements of Reusable Object-Oriented Software"},
    };
    int size = sizeof(library) / sizeof(library[0]);
    char targetISBN[] = "0001234567892"; // ISBN a ser procurado

    // Executar a busca binária
    int result = binarySearchISBN(library, 0, size - 1, targetISBN);
    if (result != -1) {
        printf("Livro encontrado:\n");
        printf("ISBN: %s\n", library[result].isbn);
        printf("Título: %s\n", library[result].title);
    } else {
        printf("Livro com ISBN '%s' não encontrado.\n", targetISBN);
    }

    return 0;
}

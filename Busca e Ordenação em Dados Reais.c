//Implemente Bucket Sort para ordenar as notas de uma turma de alunos, classificadas entre 0 e 100. 
//Em seguida, utilize o Interpolation Search para encontrar um aluno com uma nota específica:

#include <stdio.h>
#include <stdlib.h>

// Estrutura para armazenar as notas e nomes dos alunos
typedef struct {
    char name[100];
    int score;
} Student;

// Função de troca de dois elementos
void swap(Student *a, Student *b) {
    Student temp = *a;
    *a = *b;
    *b = temp;
}

// Função para ordenar os baldes usando o Insertion Sort
void insertionSort(Student arr[], int n) {
    int i, j;
    Student key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j].score > key.score) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Implementação do Bucket Sort
void bucketSort(Student arr[], int n) {
    int i, j, k, bucketCount = 10;
    int bucketRange = 101 / bucketCount;
    Student **buckets = (Student **)malloc(bucketCount * sizeof(Student *));
    int *bucketSizes = (int *)malloc(bucketCount * sizeof(int));
    
    for (i = 0; i < bucketCount; i++) {
        buckets[i] = (Student *)malloc(n * sizeof(Student));
        bucketSizes[i] = 0;
    }

    for (i = 0; i < n; i++) {
        int bucketIndex = arr[i].score / bucketRange;
        if (bucketIndex >= bucketCount) bucketIndex = bucketCount - 1;
        buckets[bucketIndex][bucketSizes[bucketIndex]++] = arr[i];
    }

    for (i = 0, k = 0; i < bucketCount; i++) {
        insertionSort(buckets[i], bucketSizes[i]);
        for (j = 0; j < bucketSizes[i]; j++) {
            arr[k++] = buckets[i][j];
        }
    }

    for (i = 0; i < bucketCount; i++) {
        free(buckets[i]);
    }
    free(buckets);
    free(bucketSizes);
}

// Implementação do Interpolation Search
int interpolationSearch(Student arr[], int size, int target) {
    int low = 0, high = size - 1;
    while (low <= high && target >= arr[low].score && target <= arr[high].score) {
        if (low == high) {
            if (arr[low].score == target) return low;
            return -1;
        }
        int pos = low + ((double)(high - low) / (arr[high].score - arr[low].score) * (target - arr[low].score));
        if (arr[pos].score == target) {
            return pos;
        }
        if (arr[pos].score < target) {
            low = pos + 1;
        } else {
            high = pos - 1;
        }
    }
    return -1; // Nota não encontrada
}

// Função principal para testar o Bucket Sort e o Interpolation Search
int main() {
    Student students[] = {
        {"Alice", 78},
        {"Bob", 85},
        {"Charlie", 93},
        {"David", 62},
        {"Eva", 90},
        {"Frank", 75},
        {"Grace", 88},
        {"Hannah", 95},
        {"Ivy", 70},
        {"Jack", 82}
    };
    int size = sizeof(students) / sizeof(students[0]);
    int targetScore = 90;

    // Ordenar as notas usando Bucket Sort
    bucketSort(students, size);
    printf("Notas ordenadas:\n");
    for (int i = 0; i < size; i++) {
        printf("%s: %d\n", students[i].name, students[i].score);
    }

    // Procurar um aluno com uma nota específica usando Interpolation Search
    int result = interpolationSearch(students, size, targetScore);
    if (result != -1) {
        printf("\nAluno encontrado:\n");
        printf("Nome: %s\n", students[result].name);
        printf("Nota: %d\n", students[result].score);
    } else {
        printf("\nAluno com nota %d não encontrado.\n", targetScore);
    }

    return 0;
}

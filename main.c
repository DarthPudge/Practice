#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include "Function.h"

int main() {
    setlocale(LC_ALL, "RUS");
    // Задание Первое <Нахождение обратной матрицы>
    /*int size, a;
    float matrix[MAX_SIZE][MAX_SIZE];
    do
    {
        printf("Введите размерность матрицы: MxN\n");
        scanf_s("%d", &a);
        scanf_s("%d", &size);
        if (size != a) {
            printf("Обратную матрицу для не квадратной матрицы найти невозможно.\n\n");
        }
        else
            break;
    } while (size = a);
    
    printf("Введите элементы матрицы:\n");

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("Введите элемент [%d][%d]: ", i, j);
            scanf_s("%f", &matrix[i][j]);
        }
    }

    printf("\nИсходная матрица:\n");
    displayMatrix(matrix, size);
    inverseMatrix(matrix, size);
    return 0;*/

    // Задание Второе <Решение СЛАУ методом Крамера>
    int size;
    printf("Введите размерность системы линейных уравнений: ");
    scanf_s("%d", &size);
    if (size <= 0 || size > MAX_SIZE) {
        printf("Система не имеет единственного решения\n");
        return 0;
    }
    

    double** matrix = inputMatrix(size);
    printf("Введите вектор правых частей системы:\n");
    double* vector = (double*)malloc(size * sizeof(double));
    for (int i = 0; i < size; i++) {
        printf("Введите элемент [%d]: ", i+1);
        scanf_s("%lf", &vector[i]);
    }

    printMatrix(matrix, size);
    double det = calculateDeterminant(matrix, size);
    printf("Определитель матрицы: %.2lf\n", det);

    solveSystem(matrix, vector, size);

    deallocateMatrix(matrix, size);
    free(vector);

    return 0;
}

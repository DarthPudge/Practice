#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include "Function.h"

int main() {
    setlocale(LC_ALL, "RUS");
    // ������� ������ <���������� �������� �������>
    /*int size, a;
    float matrix[MAX_SIZE][MAX_SIZE];
    do
    {
        printf("������� ����������� �������: MxN\n");
        scanf_s("%d", &a);
        scanf_s("%d", &size);
        if (size != a) {
            printf("�������� ������� ��� �� ���������� ������� ����� ����������.\n\n");
        }
        else
            break;
    } while (size = a);
    
    printf("������� �������� �������:\n");

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("������� ������� [%d][%d]: ", i, j);
            scanf_s("%f", &matrix[i][j]);
        }
    }

    printf("\n�������� �������:\n");
    displayMatrix(matrix, size);
    inverseMatrix(matrix, size);
    return 0;*/

    // ������� ������ <������� ���� ������� �������>
    int size;
    printf("������� ����������� ������� �������� ���������: ");
    scanf_s("%d", &size);
    if (size <= 0 || size > MAX_SIZE) {
        printf("������� �� ����� ������������� �������\n");
        return 0;
    }
    

    double** matrix = inputMatrix(size);
    printf("������� ������ ������ ������ �������:\n");
    double* vector = (double*)malloc(size * sizeof(double));
    for (int i = 0; i < size; i++) {
        printf("������� ������� [%d]: ", i+1);
        scanf_s("%lf", &vector[i]);
    }

    printMatrix(matrix, size);
    double det = calculateDeterminant(matrix, size);
    printf("������������ �������: %.2lf\n", det);

    solveSystem(matrix, vector, size);

    deallocateMatrix(matrix, size);
    free(vector);

    return 0;
}

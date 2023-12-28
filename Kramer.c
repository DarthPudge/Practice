#include <stdio.h>
#include "Function.h"

double** allocateMatrix(int size) {
    double** matrix = (double**)calloc(size, sizeof(double*));
    for (int i = 0; i < size; i++) {
        matrix[i] = (double*)calloc(size, sizeof(double));
    }
    return matrix;
}

// ������� ��� ������������ ������, ���������� ��� �������
void deallocateMatrix(double** matrix, int size) {
    for (int i = 0; i < size; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

// ������� ��� ����� �������
double** inputMatrix(int size) {
    double** matrix = allocateMatrix(size);
    printf("������� �������� �������:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("������� ������� [%d][%d]: ", i, j);
            scanf_s("%lf", &matrix[i][j]);
        }
    }
    return matrix;
}

// ������� ��� ������ �������
void printMatrix(double** matrix, int size) {
    printf("�������:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {

            printf("|%.1lf", matrix[i][j]);

        }
        printf("|\n");
    }
}

// ������� ��� ���������� ������������ ������� ����������� n
double calculateDeterminant(double** matrix, int size) {
    double det = 0;
    if (size == 1) {
        det = matrix[0][0];
    }
    else {
        int sign = 1;
        for (int i = 0; i < size; i++) {
            double** submatrix = allocateMatrix(size - 1);
            for (int j = 1; j < size; j++) {
                for (int k = 0; k < size; k++) {
                    if (k < i) {
                        submatrix[j - 1][k] = matrix[j][k];
                    }
                    else if (k > i) {
                        submatrix[j - 1][k - 1] = matrix[j][k];
                    }
                }
            }
            det += sign * matrix[0][i] * calculateDeterminant(submatrix, size - 1);
            sign = -sign;
            deallocateMatrix(submatrix, size - 1);
        }
    }
    return det;
}

// ������� ��� ������� ������� �������� ��������� ������� �������
void solveSystem(double** matrix, double* vector, int size) {
    double detA = calculateDeterminant(matrix, size);
    if (detA != 0) {
        double* solution = (double*)malloc(size * sizeof(double));
        for (int i = 0; i < size; i++) {
            double** submatrix = allocateMatrix(size);
            for (int j = 0; j < size; j++) {
                for (int k = 0; k < size; k++) {
                    if (k == i) {
                        submatrix[j][k] = vector[j];
                    }
                    else {
                        submatrix[j][k] = matrix[j][k];
                    }
                }
            }
            solution[i] = calculateDeterminant(submatrix, size) / detA;
            deallocateMatrix(submatrix, size);
        }
        printf("������� �������:\n");
        for (int i = 0; i < size; i++) {
            if (solution[i] == 0)
                printf("x%d = 0\n", i + 1);
            else
                printf("x%d = %.2lf\n", i + 1, solution[i]);
        }
        free(solution);
    }
    else {
        printf("������� ��������� �����������, �� ���������� �������.\n");
    }
}

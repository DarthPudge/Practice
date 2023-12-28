#include <stdio.h>
#include "Function.h"

void displayMatrix(float matrix[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%.2f\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void inverseMatrix(float matrix[MAX_SIZE][MAX_SIZE], int size) {
    float identity[MAX_SIZE][MAX_SIZE];
    float scalar, temp;
    int i, j, k;

    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if (i == j)
                identity[i][j] = 1;
            else
                identity[i][j] = 0;
        }
    }

    for (k = 0; k < size; k++) {
        scalar = matrix[k][k];

        for (j = 0; j < size; j++) {
            matrix[k][j] /= scalar;
            identity[k][j] /= scalar;
        }

        for (i = 0; i < size; i++) {
            if (i != k) {
                temp = matrix[i][k];

                for (j = 0; j < size; j++) {
                    matrix[i][j] -= temp * matrix[k][j];
                    identity[i][j] -= temp * identity[k][j];
                }
            }
        }
    }

    printf("\n\nОбратная матрица:\n");
    displayMatrix(identity, size);
}

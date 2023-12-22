#include <stdio.h>
#include <locale.h>
#include "Function.h"

int main() {
    setlocale(LC_ALL, "RUS");
    int size, a;
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

    return 0;
}
#pragma once
#define MAX_SIZE 50
/*
* @breaf Функция для отображения матрицы
* @param size: Размер квадратичной матрицы
*/
void displayMatrix(float matrix[MAX_SIZE][MAX_SIZE], int size);
/*
* @breaf Функция для нахождения обратной матрицы
* @param size: Размер квадратичной матрицы
*/
void inverseMatrix(float matrix[MAX_SIZE][MAX_SIZE], int size);

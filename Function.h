#pragma once
#define MAX_SIZE 10
/*
* @breaf Функция для отображения матрицы
* @param matrix: Матрица
* @param size: Размер квадратичной матрицы
*/
void displayMatrix(float matrix[MAX_SIZE][MAX_SIZE], int size);
/*
* @breaf Функция для нахождения обратной матрицы
* @param matrix: Матрица
* @param size: Размер квадратичной матрицы
*/
void inverseMatrix(float matrix[MAX_SIZE][MAX_SIZE], int size);
/*
* @breaf  Функция для решения системы линейных уравнений методом Крамера
* @param matrix: Матрица
* @param size: Размер квадратичной матрицы
*/
void solveSystem(double** matrix, double* vector, int size);
/*
* @breaf  Функция для вычисления определителя матрицы размерности n
* @param matrix: Матрица
* @param size: Размер квадратичной матрицы
*/
double calculateDeterminant(double** matrix, int size);
/*
* @breaf Функция для отображения матрицы
* @param matrix: Матрица
* @param size: Размер квадратичной матрицы
*/
void printMatrix(double** matrix, int size);
/*
* @breaf Функция для ввода матрицы
* @param size: Размер квадратичной матрицы
*/
double** inputMatrix(int size);
/*
* @breaf  Функция для освобождения памяти, выделенной под матрицу
* @param matrix: Матрица
* @param size: Размер квадратичной матрицы
*/
void deallocateMatrix(double** matrix, int size);
/*
* @breaf Функция для выделения памяти под матрицу
* @param size: Размер квадратичной матрицы
*/
double** allocateMatrix(int size);
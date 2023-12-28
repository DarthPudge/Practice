#pragma once
#define MAX_SIZE 10
/*
* @breaf ������� ��� ����������� �������
* @param matrix: �������
* @param size: ������ ������������ �������
*/
void displayMatrix(float matrix[MAX_SIZE][MAX_SIZE], int size);
/*
* @breaf ������� ��� ���������� �������� �������
* @param matrix: �������
* @param size: ������ ������������ �������
*/
void inverseMatrix(float matrix[MAX_SIZE][MAX_SIZE], int size);
/*
* @breaf  ������� ��� ������� ������� �������� ��������� ������� �������
* @param matrix: �������
* @param size: ������ ������������ �������
*/
void solveSystem(double** matrix, double* vector, int size);
/*
* @breaf  ������� ��� ���������� ������������ ������� ����������� n
* @param matrix: �������
* @param size: ������ ������������ �������
*/
double calculateDeterminant(double** matrix, int size);
/*
* @breaf ������� ��� ����������� �������
* @param matrix: �������
* @param size: ������ ������������ �������
*/
void printMatrix(double** matrix, int size);
/*
* @breaf ������� ��� ����� �������
* @param size: ������ ������������ �������
*/
double** inputMatrix(int size);
/*
* @breaf  ������� ��� ������������ ������, ���������� ��� �������
* @param matrix: �������
* @param size: ������ ������������ �������
*/
void deallocateMatrix(double** matrix, int size);
/*
* @breaf ������� ��� ��������� ������ ��� �������
* @param size: ������ ������������ �������
*/
double** allocateMatrix(int size);
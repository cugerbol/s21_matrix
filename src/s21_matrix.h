#ifndef S21_MATRIX_H
#define S21_MATRIX_H

#define SUCCESS 1
#define FAILURE 0
#define OK 0
#define INCORRECT_MATRIX 1
#define CALCULATION_ERROR 2

#include <stdio.h>
#include <stdlib.h>

typedef struct matrix_struct {
double **matrix;
  int rows;
  int columns;
} matrix_t;

// targeted
int s21_create_matrix(int rows, int columns, matrix_t *result);

#endif

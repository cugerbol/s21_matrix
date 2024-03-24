#ifndef S21_MATRIX_H
#define S21_MATRIX_H

#define SUCCESS 1
#define FAILURE 0
#define OK 0
#define INCORRECT_MATRIX 1
#define CALCULATION_ERROR 2

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

// targeted
int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);
int s21_eq_matrix(matrix_t *A, matrix_t *B);
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
// secondary
int matrix_is_correct(matrix_t *matrix);

#endif

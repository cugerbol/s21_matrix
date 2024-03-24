// by cugerbol
#include "../s21_matrix.h"
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error = OK;
  if (!matrix_is_correct(A) || !matrix_is_correct(B)) {
    error = INCORRECT_MATRIX;
  } else if (!((A->rows == B->columns) || (A->columns == B->rows))) {
    error = CALCULATION_ERROR;
  }
  int rows = A->rows;
  int cols = B->columns;
  int k_max = A->columns;
  if (s21_create_matrix(rows, cols, result)) {
    error = INCORRECT_MATRIX;
  }
  for (int row = 0; row < rows; row++)
    for (int col = 0; col < cols; col++) {
      double value = 0;
      for (int k = 0; k < k_max; k++)
        value += A->matrix[row][k] * B->matrix[k][col];
      if (isinf(fabs(value)) || isnan(fabs(value))) {
        error = CALCULATION_ERROR;
      }
      if (!error) {
        result->matrix[row][col] = value;
      }
    }
  return error;
}
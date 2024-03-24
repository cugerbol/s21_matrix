// by cugerbol
#include "../s21_matrix.h"
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error = OK;
  if (matrix_is_correct(A) == FAILURE || matrix_is_correct(B) == FAILURE) {
    error = INCORRECT_MATRIX;
  } else if (A->rows != B->rows || A->columns != B->columns) {
    error = CALCULATION_ERROR;
  } else {
    if (matrix_is_correct(result) == FAILURE) {
      s21_create_matrix(A->rows, A->columns, result);
    }
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        double a = A->matrix[i][j];
        double b = B->matrix[i][j];
        result->matrix[i][j] = a - b;
      }
    }
  }
  return error;
}

// by cugerbol
#include "../s21_matrix.h"
int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int error = OK;
  if (A && A->matrix && number && result) {
    if (matrix_is_correct(A) == FAILURE)
      error = INCORRECT_MATRIX;
    else {
      if (matrix_is_correct(result) == FAILURE) {
        s21_create_matrix(A->rows, A->columns, result);
      }
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          double a = A->matrix[i][j];
          result->matrix[i][j] = a * number;
        }
      }
    }
  } else
    error = INCORRECT_MATRIX;
  return error;
}

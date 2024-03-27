// by cugerbol
#include "../s21_matrix.h"
int s21_determinant(matrix_t *A, double *result) {
  int error = OK;
  if (A == NULL || A->matrix == NULL || result == NULL) {
    error = INCORRECT_MATRIX;
  } else if (!matrix_is_correct(A)) {
    error = CALCULATION_ERROR;
  }
  if (error == OK) {
    if (A->rows == 1) {
      *result = A->matrix[0][0];
    } else if (A->rows == 2) {
      *result =
          A->matrix[0][0] * A->matrix[1][1] - A->matrix[1][0] * A->matrix[0][1];
    } else if (A->rows > 2) {
      int sign = 1;
      *result = 0;
      for (int i = 0; i < A->columns && error == OK; i++) {
        matrix_t *minor = s21_create_minor(0, i, A);
        if (minor == NULL) {
          error = INCORRECT_MATRIX;
        } else {
          double minor_det = 0;
          error = s21_determinant(minor, &minor_det);
          if (!error) {
            *result += sign * A->matrix[0][i] * minor_det;
            sign = -sign;
          }
          s21_remove_matrix(minor);
          free(minor);
          minor = NULL;
        }
      }
    }
  }
  return error;
}

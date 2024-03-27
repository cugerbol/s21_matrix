// by cugerbol
#include "../s21_matrix.h"
int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int error = OK;
  if (A == NULL || A->matrix == NULL || result == NULL) {
    error = INCORRECT_MATRIX;
  } else if (A->rows == 1 || A->columns == 1) {
    error = CALCULATION_ERROR;
  }
  if (error == OK) {
    error = s21_create_matrix(A->rows, A->columns, result);
    if (error == OK) {
      for (int i = 0; i < A->rows && error == OK; i++) {
        int sign = i % 2 == 0 ? 1 : -1;
        for (int j = 0; j < A->columns && error == OK; j++) {
          matrix_t *minor = s21_create_minor(i, j, A);
          if (minor == NULL) {
            error = INCORRECT_MATRIX;
          } else {
            double det = 0;
            error = s21_determinant(minor, &det);
            if (!isfinite(det)) {
              error = CALCULATION_ERROR;
            }
            if (!error) {
              result->matrix[i][j] = sign * det;
              sign = -sign;
            }
            s21_remove_matrix(minor);
            free(minor);
            minor = NULL;
          }
        }
      }
    }
  }

  return error;
}
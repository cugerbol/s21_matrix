// by cugerbol
#include "../s21_matrix.h"
int matrix_is_correct(matrix_t *matrix) {
  int result = SUCCESS;
  if (matrix == NULL || matrix->matrix == NULL || matrix->rows < 1 ||
      matrix->columns < 1) {
    result = FAILURE;
  }
  return result;
}

matrix_t *s21_create_minor(int excluded_row, int excluded_column, matrix_t *A) {
  if (A == NULL || A->matrix == NULL) {
    return NULL;
  }
  matrix_t *minor = calloc(1, sizeof(matrix_t));
  if (minor != NULL) {
    if (s21_create_matrix(A->rows - 1, A->columns - 1, minor) == OK) {
      for (int i = 0, minor_row = 0; i < A->rows; i++) {
        if (i != excluded_row) {
          for (int j = 0, minor_column = 0; j < A->columns; j++) {
            if (j != excluded_column) {
              minor->matrix[minor_row][minor_column] = A->matrix[i][j];
              minor_column++;
            }
          }
          minor_row++;
        }
      }
    }
  }

  return minor;
}

// by cugerbol
#include "../s21_matrix.h"
int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int result = SUCCESS;
  if (A == NULL || B == NULL) {
    result = FAILURE;
  } else if (A->rows == B->rows && A->columns == B->columns) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        if (fabs(A->matrix[i][j] - B->matrix[i][j]) >= EPS) {
          result = FAILURE;
          break;
        }
      }
      if (result == FAILURE) break;
    }
  } else {
    result = FAILURE;
  }
  return result;
}

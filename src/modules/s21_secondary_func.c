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

#include "../s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int error = OK;
  if (A == NULL || A->matrix == NULL) {
    error = INCORRECT_MATRIX;
  } else {
    double det = 0.;
    s21_determinant(A, &det);
    if (fabs(det - 0) < EPS) {
      error = CALCULATION_ERROR;

    } else if (A->rows == 1) {
      s21_create_matrix(1, 1, result);
      result->matrix[0][0] = 1 / (A->matrix[0][0]);
    } else {
      matrix_t alg_comp = {0};
      s21_calc_complements(A, &alg_comp);
      matrix_t transpose_m = {0};
      s21_transpose(&alg_comp, &transpose_m);
      s21_mult_number(&transpose_m, 1. / det, result);
      s21_remove_matrix(&alg_comp);
      s21_remove_matrix(&transpose_m);
    }
  }
  return error;
}
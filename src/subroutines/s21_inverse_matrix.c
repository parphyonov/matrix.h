#include "../s21_matrix.h"

void s21_im_det_division(matrix_t* S, matrix_t* D, double det);

/**
 * inverses a matrix (raised to the power of -1)
 *
 * @param A pointer to matrix A
 * @param result pointer to the resulting matrix
 * @return RETURN CODE_OK
 *         -- success
 *
 *         RETURN_CODE_INCORRECT_MATRIX
 *         -- incorrect matriсes at input
 *
 *         RETURN_CODE_CALCULATION_ERROR
 *         -- mismatched sizes, calculations cannot be performed
 *
 */
int s21_inverse_matrix(matrix_t* A, matrix_t* result) {
  // NULL & RESULT NULL CHECKS
  if (!s21_matrix_check(A) || !result) return RETURN_CODE_INCORRECT_MATRIX;

  // ROWS & COLUMNS CHECKS
  if (A->rows != A->columns) return RETURN_CODE_CALCULATION_ERROR;

  // CALC DET
  double det = 0.0;
  s21_determinant(A, &det);

  // MATRIX HAS NO INVERSE
  if (s21_is_val_nearly_zero(det)) return RETURN_CODE_CALCULATION_ERROR;

  // CREATE RESULT
  if (s21_create_matrix(A->rows, A->columns, result) != RETURN_CODE_OK)
    return RETURN_CODE_CALCULATION_ERROR;

  // PLACEHOLDERS MATRICES
  matrix_t COMPL, TRANSP;

  // CALC COMPLEMENTS
  int complemented = s21_calc_complements(A, &COMPL) == RETURN_CODE_OK;

  // TRANSPOSE COMPLEMENTS
  int transposed = s21_transpose(&COMPL, &TRANSP) == RETURN_CODE_OK;

  // DIVIDE BY DET
  if (complemented && transposed) s21_im_det_division(&TRANSP, result, det);

  // FREE COMPLEMENTS & TRANSPOSED
  s21_remove_matrix(&COMPL);
  s21_remove_matrix(&TRANSP);

  return RETURN_CODE_OK;
}

void s21_im_det_division(matrix_t* S, matrix_t* D, double det) {
  if (D->rows == 1) {
    D->matrix[0][0] = 1 / det;
    return;
  }

  for (int row = 0; row < D->rows; row++)
    for (int col = 0; col < D->columns; col++)
      D->matrix[row][col] = S->matrix[row][col] / det;
}
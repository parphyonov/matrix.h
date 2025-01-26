#include "../s21_matrix.h"

void s21_tm_transpose(matrix_t *, matrix_t *);

/**
 * transposes the initial matrix (PIVOTS it)
 *
 * @param A pointer to matrix A
 * @param result pointer to the resulting matrix
 * @return RETURN CODE_OK
 *         -- success
 *
 *         RETURN_CODE_INCORRECT_MATRIX
 *         -- incorrect matrix at input
 *
 *         RETURN_CODE_CALCULATION_ERROR
 *         -- mismatched sizes, calculations cannot be performed
 *
 */
int s21_transpose(matrix_t *A, matrix_t *result) {
  // NULL & RESULT NULL CHECKS
  if (!s21_matrix_check(A) || !result) return RETURN_CODE_INCORRECT_MATRIX;

  // CREATE RESULT
  if (s21_create_matrix(A->columns, A->rows, result) != RETURN_CODE_OK)
    return RETURN_CODE_CALCULATION_ERROR;

  // TRANSPOSITION PROPER
  s21_tm_transpose(A, result);

  return RETURN_CODE_OK;
}

// ROUTINES BELOW

void s21_tm_transpose(matrix_t *M, matrix_t *RES) {
  for (int row = 0; row < RES->rows; row++)
    for (int col = 0; col < RES->columns; col++)
      // does the transposition
      RES->matrix[row][col] = M->matrix[col][row];
}

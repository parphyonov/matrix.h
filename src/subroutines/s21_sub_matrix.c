#include "../s21_matrix.h"

void s21_subm_subtract(matrix_t *, matrix_t *, matrix_t *);

/**
 * subtracts two matrices and writes the result into RESULT matrix
 *
 * @param A pointer to matrix A
 * @param B pointer to matrix B
 * @param result pointer to the resulting matrix
 * @return RETURN CODE_OK
 *         -- success
 *
 *         RETURN_CODE_INCORRECT_MATRIX
 *         -- incorrect matrices at input
 *
 *         RETURN_CODE_CALCULATION_ERROR
 *         -- mismatched sizes, calculations cannot be performed
 *
 */
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  // NULL & RESULT NULL CHECKS
  if (!s21_matrix_check(A) || !s21_matrix_check(B) || !result)
    return RETURN_CODE_INCORRECT_MATRIX;

  // ROWS & COLUMNS CHECK
  if (!s21_same_size_check(A, B)) return RETURN_CODE_CALCULATION_ERROR;

  // CREATE RESULT
  if (s21_create_matrix(A->rows, A->columns, result) != RETURN_CODE_OK)
    return RETURN_CODE_CALCULATION_ERROR;

  // SUBTRACTION PROPER
  s21_subm_subtract(A, B, result);

  return RETURN_CODE_OK;
}

// ROUTINES BELOW

void s21_subm_subtract(matrix_t *M1, matrix_t *M2, matrix_t *RES) {
  for (int row = 0; row < M1->rows; row++)
    for (int col = 0; col < M1->columns; col++)
      // subtraction of each B el from each correspondingly indexed A el
      RES->matrix[row][col] = M1->matrix[row][col] - M2->matrix[row][col];
}

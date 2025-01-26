#include "../s21_matrix.h"

void s21_mn_multiplicate(matrix_t *, matrix_t *, double);

/**
 * multiplies each A matrix's value by the specified number (lambda)
 * and fills the RESULT matrix with the modified values
 *
 * @param A pointer to matrix A
 * @param number a number of type double
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
int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  //  NULL & RESULT NULL CHECKS
  if (!s21_matrix_check(A) || !result) return RETURN_CODE_INCORRECT_MATRIX;

  // DOUBLE CHECK
  if (isnan(number)) return RETURN_CODE_CALCULATION_ERROR;

  // CREATE RESULT
  if (s21_create_matrix(A->rows, A->columns, result) != RETURN_CODE_OK)
    return RETURN_CODE_CALCULATION_ERROR;

  // MULTIPLICATION BY SCALAR PROPER
  s21_mn_multiplicate(A, result, number);

  return RETURN_CODE_OK;
}

// ROUTINES BELOW

void s21_mn_multiplicate(matrix_t *M, matrix_t *RES, double number) {
  for (int r = 0; r < M->rows; r++)
    for (int c = 0; c < M->columns; c++)
      RES->matrix[r][c] = M->matrix[r][c] * number;
}

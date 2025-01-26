#include "../s21_matrix.h"

// local helpers

double s21_mm_calc_mvalue(matrix_t *, matrix_t *, int, int, int);

// local routines

void s21_mm_multiplicate(matrix_t *, matrix_t *, matrix_t *);

/**
 * multiplies two matrices
 *
 * @param A pointer to matrix A
 * @param B pointer to matrix B
 * @param result pointer to matrix RESULT
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
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  // NULL && RESULT NULL CHECKS
  if (!s21_matrix_check(A) || !s21_matrix_check(B) || !result)
    return RETURN_CODE_INCORRECT_MATRIX;

  // ROWS & COLUMNS CHECKS
  if (A->columns != B->rows) return RETURN_CODE_CALCULATION_ERROR;

  // CREATE RESULT
  if (s21_create_matrix(A->rows, B->columns, result) != RETURN_CODE_OK)
    return RETURN_CODE_CALCULATION_ERROR;

  // MATRICES MULTIPLICATION PROPER
  s21_mm_multiplicate(A, B, result);

  return RETURN_CODE_OK;
}

// HELPERS BELOW

double s21_mm_calc_mvalue(matrix_t *M1, matrix_t *M2, int r, int c, int size) {
  double result = 0.0;

  // if size of iteration is 0, then the returned result will be 0.0
  if (size != 0)
    for (int k = 0; k < size; k++)
      result += M1->matrix[r][k] * M2->matrix[k][c];

  return result;
}

// ROUTINES BELOW

void s21_mm_multiplicate(matrix_t *M1, matrix_t *M2, matrix_t *RES) {
  // does the correct calculcation with the use of a separate function
  for (int row = 0; row < M1->rows; row++)
    for (int col = 0; col < M2->columns; col++)
      RES->matrix[row][col] = s21_mm_calc_mvalue(M1, M2, row, col, M1->columns);
}

#include "../s21_matrix.h"

/**
 * checks for equality of two matrices, meaning they have the same dimentions
 * and the corresponding elements are identical up to and including 7 decimal
 * places
 *
 * @param A pointer to matrix A
 * @param B pointer to matrix B
 * @return SUCCESS if identical, FAILURE if not identical
 *
 */
int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  // INPUT CHECKS
  if (!s21_matrix_check(A) || !s21_matrix_check(B)) return FAILURE;

  // ROWS & COLUMNS CHECKS
  if (A->columns != B->columns || A->rows != B->rows) return FAILURE;

  // ELEMENTWISE COMPARISON PROPER
  for (int row = 0; row < A->rows; row++)
    for (int col = 0; col < A->columns; col++) {
      double a = A->matrix[row][col];
      double b = B->matrix[row][col];
      if (isnan(a) || isnan(b) || fabs(a - b) > EPSILON) return FAILURE;
    }

  return SUCCESS;
}

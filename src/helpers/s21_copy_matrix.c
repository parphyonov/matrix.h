#include "../s21_matrix.h"

/**
 * copies contents of one matrix to another
 *
 * @param SM pointer to Source Matrix
 * @param DM pointer to Destination Matrix
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
int s21_copy_matrix(matrix_t* SM, matrix_t* DM) {
  // NULL CHECKS
  if (!s21_matrix_check(SM) || !s21_matrix_check(DM))
    return RETURN_CODE_INCORRECT_MATRIX;

  // ROWS & COLUMNS CHECKS
  if (!s21_same_size_check(SM, DM)) return RETURN_CODE_INCORRECT_MATRIX;

  // COPYING PROPER
  for (int row = 0; row < SM->rows; row++)
    for (int col = 0; col < SM->columns; col++)
      DM->matrix[row][col] = SM->matrix[row][col];

  return RETURN_CODE_OK;
}

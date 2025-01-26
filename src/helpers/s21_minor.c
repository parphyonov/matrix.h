#include "../s21_matrix.h"

/**
 * calculates a minor of matrix A based on provided row & column
 * and writes it into result
 *
 * @param M pointer to matrix M
 * @param el_row specifies A's element row
 * @param el_col specifies A's element column
 * @param RES pointer to the resulting matrix
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
int s21_minor(matrix_t* M, int el_row, int el_col, matrix_t* RES) {
  // NULL CHECKS
  if (!s21_matrix_check(M) || !s21_matrix_check(RES))
    return RETURN_CODE_INCORRECT_MATRIX;

  // ROWS & COLUMNS CHECKS
  int els_below_0 = el_row < 0 || el_col < 0;
  int els_outside_range = el_row > M->rows - 1 || el_col > M->columns;
  if (els_below_0 || els_outside_range) return RETURN_CODE_CALCULATION_ERROR;

  // FILLING VALUES OF MINOR PROPER
  for (int row = 0; row < RES->rows; row++)
    for (int col = 0; col < RES->columns; col++) {
      int res_row = row < el_row ? row : row + 1;
      int res_col = col < el_col ? col : col + 1;
      RES->matrix[row][col] = M->matrix[res_row][res_col];
    }

  return RETURN_CODE_OK;
}

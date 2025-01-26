#include "../s21_matrix.h"

/**
 * checks if a matrix is not NULL and its rows and columns values
 * are strictly greater than 0
 *
 * @param M pointer to matrix M
 * @return SUCCESS or FAILURE
 *
 */
int s21_matrix_check(const matrix_t* M) {
  // NULL CHECKS
  if (M == NULL || M->matrix == NULL) return FAILURE;

  // ROWS & COLUMNS CHECK
  if (M->rows <= 0 || M->columns <= 0) return FAILURE;

  // NULL ROWS & ELEMENTS CHECK
  for (int row = 0; row < M->rows; row++)
    for (int col = 0; col < M->columns; col++)
      if (M->matrix[row] == NULL || isnan(M->matrix[row][col])) return FAILURE;

  return SUCCESS;
}

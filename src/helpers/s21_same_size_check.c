#include "../s21_matrix.h"

/**
 * checks if two matrices are of the same size
 *
 * @param M1 pointer to matrix M1
 * @param M2 pointer to matrix M2
 * @return SUCCESS if they are, FAILURE if they aren't
 *
 */
int s21_same_size_check(const matrix_t *M1, const matrix_t *M2) {
  // NULL CHECKS
  if (!s21_matrix_check(M1) || !s21_matrix_check(M2)) return FAILURE;

  // ROWS & COLUMNS CHECKS
  int same_size = M1->rows == M2->rows && M1->columns == M2->columns;
  if (!same_size) return FAILURE;

  return SUCCESS;
}

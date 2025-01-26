#include "../s21_matrix.h"

/**
 * prints the matrix values to the terminal screen
 *
 * @param M pointer to matrix M
 * @param precision sets a floating-point precision 0..6
 */

int s21_print_matrix(const matrix_t *M, int precision) {
  int condition = precision >= 0 && precision <= 6;

  if (!s21_matrix_check(M)) return FAILURE;

  for (int row = 0; row < M->rows; row++) {
    for (int col = 0; col < M->columns; col++)
      printf("%-.*lf ", condition ? precision : 2, M->matrix[row][col]);

    printf("\n");
  }

  printf("\n");

  return SUCCESS;
}

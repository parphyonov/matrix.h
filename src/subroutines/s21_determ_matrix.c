#include "../s21_matrix.h"

#define NON_ZERO_ROW_FOUND -1

// local helpers

int s21_dm_find_nonzero_row(const matrix_t *, int, int);
void s21_dm_gaussian_step(matrix_t *, int, int);
void s21_dm_swap_rows(matrix_t *, int, int);
double s21_dm_diagonal_infinity_check(matrix_t *);

// local routines

void s21_dm_gauss_routine(matrix_t *, int *);
void s21_dm_swap_routine(matrix_t *, int *);

/**
 * the determinant is a number that is associated to each square matrix
 * and calculated from the elements using special formulas
 *
 * @param A pointer to the matrix_t
 * @param result pointer to the resulting double which would hold a determinant
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
int s21_determinant(matrix_t *A, double *result) {
  // NULL CHECKS
  if (!s21_matrix_check(A)) return RETURN_CODE_INCORRECT_MATRIX;

  // SQUARE CHECKS
  if (A->rows != A->columns) return RETURN_CODE_CALCULATION_ERROR;

  // RESULT CHECKS
  if (isnan(*result)) return RETURN_CODE_CALCULATION_ERROR;
  *result = 1.0;  // escapes multiplication by ZERO

  // TEMP MATRIX
  matrix_t M_TEMP = {0};

  // COPY A TO TEMP
  if (s21_create_matrix(A->rows, A->columns, &M_TEMP) != RETURN_CODE_OK)
    return RETURN_CODE_CALCULATION_ERROR;
  s21_copy_matrix(A, &M_TEMP);

  // DO SWAPS
  int swaps_ctr = 0;
  s21_dm_swap_routine(&M_TEMP, &swaps_ctr);

  // GAUSSIAN ELIMINATION
  s21_dm_gauss_routine(&M_TEMP, &swaps_ctr);

  // INFINITY CHECKS
  *result *= s21_dm_diagonal_infinity_check(&M_TEMP);

  // DETERMINANT CALCULATION PROPER
  for (int lead = 0; lead < M_TEMP.rows; lead++)
    *result *= M_TEMP.matrix[lead][lead];

  // IF SWAPS, APPLY SIGN
  if (swaps_ctr % 2 != 0) *result *= -1;

  // FREE TEMP MATRIX
  s21_remove_matrix(&M_TEMP);

  return RETURN_CODE_OK;
}

// HELPERS BELOW

int s21_dm_find_nonzero_row(const matrix_t *M, int col, int start_row) {
  for (int row = start_row + 1; row < M->rows; row++)
    if (!s21_is_val_nearly_zero(M->matrix[row][col])) return row;

  return NON_ZERO_ROW_FOUND;
}

void s21_dm_gaussian_step(matrix_t *M, int pivot_row, int col) {
  // inner loop which iterates over rows
  for (int row = pivot_row + 1; row < M->rows; row++) {
    double divisor = M->matrix[row][col] / M->matrix[pivot_row][col];
    if (s21_is_val_nearly_zero(divisor)) continue;

    // each row element (with offset) gets modified then
    for (int k = col; k < M->columns; k++)
      M->matrix[row][k] -= divisor * M->matrix[pivot_row][k];
  }
}

void s21_dm_swap_rows(matrix_t *M, int row1, int row2) {
  double *temp = M->matrix[row1];

  M->matrix[row1] = M->matrix[row2];
  M->matrix[row2] = temp;
}

double s21_dm_diagonal_infinity_check(matrix_t *M) {
  for (int i = 0; i < M->rows; i++)
    if (isinf(M->matrix[i][i])) return INFINITY;

  return 1.0;
}

// ROUTINES BELOW

void s21_dm_gauss_routine(matrix_t *M, int *swaps_ctr) {
  // outer loop which iterates over columns
  for (int col = 0; col < M->columns - 1; col++) {
    int pivot_row = col;

    // zero check on the matrix's main diagonal
    if (s21_is_val_nearly_zero(M->matrix[col][col])) {
      int new_pivot_row = s21_dm_find_nonzero_row(M, col, pivot_row);

      if (new_pivot_row != NON_ZERO_ROW_FOUND) {
        s21_dm_swap_rows(M, pivot_row, new_pivot_row);
        (*swaps_ctr)++;
      } else
        return;
    }

    // gaussian elimination step
    s21_dm_gaussian_step(M, pivot_row, pivot_row);
  }
}

void s21_dm_swap_routine(matrix_t *M, int *swaps_ctr) {
  int swap_row = 1;
  int row = swap_row - 1;

  while (s21_is_val_nearly_zero(M->matrix[row][row]) && swap_row < M->rows) {
    s21_dm_swap_rows(M, row, swap_row);
    swap_row++;
    row++;
    (*swaps_ctr)++;
  }

  if (fabs(M->matrix[0][0]) < fabs(M->matrix[M->rows - 1][0])) {
    s21_dm_swap_rows(M, 0, M->rows - 1);
    (*swaps_ctr)++;
  }
}

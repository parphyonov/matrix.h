#include "../s21_matrix.h"

int s21_cm_undo_successfull_allocations(matrix_t *, int);

/**
 * creates a matrix of the given size.
 * All initial values are set to 0s
 *
 * @param rows the number of rows
 * @param columns the number of culumns
 * @param result pointer to the resulting matrix
 * @return RETURN_CODE_OK
 *         -- the matrix successfully created
 *
 *         RETURN_CODE_INCORRECT_MATRIX
 *         -- incorrect matrix was provided
 *
 *         RETURN_CODE_CALCULATION_ERROR
 *         -- mismatched matrix sizes
 *         -- matrix for which calculations cannot be performed
 *
 */
int s21_create_matrix(int rows, int columns, matrix_t *result) {
  // CHECKS
  if (result != NULL) result->matrix = NULL;
  if (rows <= 0 || columns <= 0 || result == NULL)
    return RETURN_CODE_INCORRECT_MATRIX;

  // ROWS & COLS SET
  result->rows = rows;
  result->columns = columns;

  // MEMORY ALLOCATION FOR COLUMNS
  result->matrix = (double **)calloc(result->rows, sizeof(double *));

  // ADDITIONAL CHECK FOR COLUMN ALLOCATION
  if (!result->matrix) return RETURN_CODE_CALCULATION_ERROR;

  // MEMORY ALLOCATION FOR ROWS
  for (int row = 0; row < rows; row++) {
    result->matrix[row] = (double *)calloc(result->columns, sizeof(double));

    // ROW ALLOCATION CHECK
    if (!result->matrix[row]) {
      s21_cm_undo_successfull_allocations(result, row);
      return RETURN_CODE_CALCULATION_ERROR;
    }
  }

  return RETURN_CODE_OK;
}

int s21_cm_undo_successfull_allocations(matrix_t *M, int row) {
  for (int failed_row = 0; failed_row < row; failed_row++)
    free(M->matrix[failed_row]);

  free(M->matrix);

  return SUCCESS;
}
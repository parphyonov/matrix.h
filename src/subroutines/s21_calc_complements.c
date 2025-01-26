#include "../s21_matrix.h"

int s21_cc_calculate(matrix_t*, matrix_t*);

/**
 * returns a matrix of algebraic complement
 *
 * @param A pointer to matrix A
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
int s21_calc_complements(matrix_t* A, matrix_t* result) {
  // NULL & RESULT NULL CHECKS
  if (!s21_matrix_check(A) || !result) return RETURN_CODE_INCORRECT_MATRIX;

  // ROWS & COLUMNS CHECK
  if (A->rows != A->columns) return RETURN_CODE_CALCULATION_ERROR;

  // CREATE RESULT
  if (s21_create_matrix(A->rows, A->columns, result) != RETURN_CODE_OK)
    return RETURN_CODE_CALCULATION_ERROR;

  // ADDRESSING 1x1 MATRIX
  if (A->rows == 1) {  // columns already checked above
    result->matrix[0][0] = A->matrix[0][0];
    return RETURN_CODE_OK;
  }

  // COMPLEMENTS CALCULCATION PROPER
  if (!s21_cc_calculate(A, result)) return RETURN_CODE_CALCULATION_ERROR;

  return RETURN_CODE_OK;
}

// ROUTINES BELOW

int s21_cc_calculate(matrix_t* M, matrix_t* RES) {
  for (int row = 0; row < RES->rows; row++)
    for (int col = 0; col < RES->columns; col++) {
      int flow = 1;
      matrix_t MINOR = {0};

      int created = s21_create_matrix(M->rows - 1, M->columns - 1, &MINOR);
      if (created != RETURN_CODE_OK) flow = 0;

      if (flow && s21_minor(M, row, col, &MINOR) != RETURN_CODE_OK) flow = 0;

      double det = 0.0;
      if (flow && s21_determinant(&MINOR, &det) != RETURN_CODE_OK) flow = 0;

      if (created == RETURN_CODE_OK) s21_remove_matrix(&MINOR);
      if (!flow) return FAILURE;

      RES->matrix[row][col] = det * pow(-1, row + col);
    }

  return SUCCESS;
}

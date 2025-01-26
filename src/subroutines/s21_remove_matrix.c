#include "../s21_matrix.h"

void s21_rm_clean_routine(matrix_t*);

/**
 * frees matrix's rows and matrix itself from dynamic memory
 *
 * @param A pointer to the matrix structure that needs to be freed
 *
 */
void s21_remove_matrix(matrix_t* A) {
  // NULL CHECK
  if (A == NULL) return;

  // MATRIX EXISTS CHECK
  if (A->matrix != NULL) {
    for (int r = 0; r < A->rows; r++) {
      free(A->matrix[r]);
    }

    free(A->matrix);
  }

  // CLEAN & NULL
  s21_rm_clean_routine(A);

  return;
}

// ROUTINES BELOW

void s21_rm_clean_routine(matrix_t* M) {
  // check for NULL before accessing fields
  if (M == NULL) return;

  // clean up matrix structure
  M->matrix = NULL;
  M->rows = 0;
  M->columns = 0;
}

#include "../s21_matrix.h"

/**
 * swaps the specified matrix A's rows
 *
 * @param value value to check against EPSILON
 * @return SUCCESS || FAILURE
 *
 */
int s21_is_val_nearly_zero(double value) { return fabs(value) < EPSILON; }
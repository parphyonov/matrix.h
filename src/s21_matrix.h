#ifndef __S21_MATRIX__
#define __S21_MATRIX__

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RETURN_CODE_OK 0
#define RETURN_CODE_INCORRECT_MATRIX 1
#define RETURN_CODE_CALCULATION_ERROR 2

#define SUCCESS 1
#define FAILURE 0

#define EPSILON 1e-8

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

// MAIN FUNCTIONS

int s21_create_matrix(int rows, int columns, matrix_t *result);
int s21_eq_matrix(matrix_t *A, matrix_t *B);
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_transpose(matrix_t *A, matrix_t *result);
int s21_calc_complements(matrix_t *A, matrix_t *result);
int s21_determinant(matrix_t *A, double *result);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);
void s21_remove_matrix(matrix_t *A);

// HELPER FUNCTIONS

int s21_copy_matrix(matrix_t *source, matrix_t *destination);
int s21_is_val_nearly_zero(double value);
int s21_matrix_check(const matrix_t *A);
int s21_minor(matrix_t *A, int el_row, int el_col, matrix_t *result);
int s21_print_matrix(const matrix_t *A, int precision);
int s21_same_size_check(const matrix_t *M1, const matrix_t *M2);

// ROUTINE FUNCTIONS
int s21_cm_undo_successfull_allocations(matrix_t *M, int row);

#endif  // __S21_MATRIX__

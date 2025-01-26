#ifndef __S21_MATRIX_TEST__
#define __S21_MATRIX_TEST__

#include <check.h>
#include <stdio.h>

#include "../s21_matrix.h"

void run_tests(void);
void run_testcase(Suite *testcase, int counter_testcase);

Suite *s21_create_tests(void);
Suite *s21_remove_tests(void);
Suite *s21_eq_tests(void);
Suite *s21_sum_tests(void);
Suite *s21_sub_tests(void);
Suite *s21_mult_number_tests(void);
Suite *s21_mult_matrix_tests(void);
Suite *s21_transpose_tests(void);
Suite *s21_calc_complements_tests(void);
Suite *s21_determinant_tests(void);
Suite *s21_inverse_matrix_tests(void);
Suite *s21_extra_tests(void);

#endif  // __S21_MATRIX_TEST__

#include "s21_matrix_tests.h"

START_TEST(s21_mult_number_null_pointer) {
  matrix_t result = {0};
  ck_assert_int_eq(s21_mult_number(NULL, 1, &result),
                   RETURN_CODE_INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_mult_number_null_pointer_res) {
  matrix_t A = {0};
  ck_assert_int_eq(s21_mult_number(&A, 1, NULL), RETURN_CODE_INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_mult_number_null_pointer_matrix) {
  matrix_t A = {0};
  A.matrix = NULL;
  matrix_t result = {0};
  ck_assert_int_eq(s21_mult_number(&A, 1, &result),
                   RETURN_CODE_INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_mult_number_null_pointer_rows) {
  matrix_t A = {0};
  A.rows = 3;
  A.columns = 3;
  A.matrix = (double **)malloc(3 * sizeof(double *));
  A.matrix[0] = NULL;
  A.matrix[1] = NULL;
  A.matrix[2] = NULL;
  matrix_t result = {0};
  ck_assert_int_eq(s21_mult_number(&A, 1, &result),
                   RETURN_CODE_INCORRECT_MATRIX);
  free(A.matrix);
}
END_TEST

START_TEST(s21_mult_number_normal) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  matrix_t result;
  matrix_t check;
  s21_create_matrix(3, 3, &check);
  ck_assert_int_eq(s21_mult_number(&A, 2, &result), RETURN_CODE_OK);
  ck_assert_int_eq(s21_eq_matrix(&check, &result), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_mult_number_normal2) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  matrix_t check;
  s21_create_matrix(3, 3, &check);
  for (int i = 0; i < A.rows; ++i) {
    for (int j = 0; j < A.columns; ++j) {
      A.matrix[i][j] = i + j + 2;
      check.matrix[i][j] = (i + j + 2) * 2;
    }
  }
  matrix_t result;
  ck_assert_int_eq(s21_mult_number(&A, 2, &result), RETURN_CODE_OK);
  ck_assert_int_eq(s21_eq_matrix(&check, &result), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_mult_number_normal3) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  matrix_t check;
  s21_create_matrix(3, 3, &check);
  for (int i = 0; i < A.rows; ++i) {
    for (int j = 0; j < A.columns; ++j) {
      A.matrix[i][j] = i + j + 2;
      check.matrix[i][j] = (i + j + 2) * 0;
    }
  }
  matrix_t result;
  ck_assert_int_eq(s21_mult_number(&A, 0, &result), RETURN_CODE_OK);
  ck_assert_int_eq(s21_eq_matrix(&check, &result), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_mult_number_normal4) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  matrix_t check;
  s21_create_matrix(3, 3, &check);
  for (int i = 0; i < A.rows; ++i) {
    for (int j = 0; j < A.columns; ++j) {
      A.matrix[i][j] = i + j + 2;
      check.matrix[i][j] = (i + j + 2) * (-1.5);
    }
  }
  matrix_t result;
  ck_assert_int_eq(s21_mult_number(&A, -1.5, &result), RETURN_CODE_OK);
  ck_assert_int_eq(s21_eq_matrix(&check, &result), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_mult_number_inf) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  matrix_t check;
  s21_create_matrix(3, 3, &check);

  for (int i = 0; i < A.rows; ++i) {
    for (int j = 0; j < A.columns; ++j) {
      A.matrix[i][j] = i + j + 2;
      check.matrix[i][j] = INFINITY;
    }
  }

  matrix_t result;
  ck_assert_int_eq(s21_mult_number(&A, INFINITY, &result), RETURN_CODE_OK);
  ck_assert_int_eq(s21_eq_matrix(&check, &result), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_mult_number_inf_neg) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  matrix_t check;
  s21_create_matrix(3, 3, &check);
  for (int i = 0; i < A.rows; ++i) {
    for (int j = 0; j < A.columns; ++j) {
      A.matrix[i][j] = i + j + 2;
      check.matrix[i][j] = -INFINITY;
    }
  }
  matrix_t result;
  ck_assert_int_eq(s21_mult_number(&A, -INFINITY, &result), RETURN_CODE_OK);
  ck_assert_int_eq(s21_eq_matrix(&check, &result), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_mult_number_one_div_by_inf) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  matrix_t check;
  s21_create_matrix(3, 3, &check);
  for (int i = 0; i < A.rows; ++i) {
    for (int j = 0; j < A.columns; ++j) {
      A.matrix[i][j] = i + j + 2;
      check.matrix[i][j] = 0;
    }
  }
  matrix_t result;
  ck_assert_int_eq(s21_mult_number(&A, 1 / INFINITY, &result), RETURN_CODE_OK);
  ck_assert_int_eq(s21_eq_matrix(&check, &result), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_mult_number_one_div_by_inf_neg) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  matrix_t check;
  s21_create_matrix(3, 3, &check);
  for (int i = 0; i < A.rows; ++i) {
    for (int j = 0; j < A.columns; ++j) {
      A.matrix[i][j] = i + j + 2;
      check.matrix[i][j] = -0;
    }
  }
  matrix_t result;
  ck_assert_int_eq(s21_mult_number(&A, 1 / (-INFINITY), &result),
                   RETURN_CODE_OK);
  ck_assert_int_eq(s21_eq_matrix(&check, &result), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

Suite *s21_mult_number_tests(void) {
  Suite *c = suite_create("s21_mult_number");
  TCase *tc = tcase_create("s21_mult_number_tc");
  tcase_add_test(tc, s21_mult_number_null_pointer);
  tcase_add_test(tc, s21_mult_number_null_pointer_res);
  tcase_add_test(tc, s21_mult_number_null_pointer_matrix);
  tcase_add_test(tc, s21_mult_number_null_pointer_rows);
  tcase_add_test(tc, s21_mult_number_normal);
  tcase_add_test(tc, s21_mult_number_normal2);
  tcase_add_test(tc, s21_mult_number_normal3);
  tcase_add_test(tc, s21_mult_number_normal4);
  tcase_add_test(tc, s21_mult_number_inf);
  tcase_add_test(tc, s21_mult_number_inf_neg);
  tcase_add_test(tc, s21_mult_number_one_div_by_inf);
  tcase_add_test(tc, s21_mult_number_one_div_by_inf_neg);
  suite_add_tcase(c, tc);
  return c;
}

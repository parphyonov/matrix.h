#include "s21_matrix_tests.h"

START_TEST(s21_sub_null_pointer) {
  matrix_t A = {0};
  matrix_t result = {0};
  ck_assert_int_eq(s21_sub_matrix(&A, NULL, &result),
                   RETURN_CODE_INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_sub_null_pointer_res) {
  matrix_t A = {0};
  matrix_t B = {0};
  ck_assert_int_eq(s21_sub_matrix(&A, &B, NULL), RETURN_CODE_INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_sub_null_pointer_matrix) {
  matrix_t A = {0};
  A.matrix = NULL;
  matrix_t B = {0};
  matrix_t result = {0};
  s21_create_matrix(3, 3, &B);
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result),
                   RETURN_CODE_INCORRECT_MATRIX);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_sub_null_pointer_matrix_B) {
  matrix_t A = {0};
  matrix_t B = {0};
  B.matrix = NULL;
  matrix_t result = {0};
  s21_create_matrix(3, 3, &A);
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result),
                   RETURN_CODE_INCORRECT_MATRIX);
  s21_remove_matrix(&B);
  s21_remove_matrix(&A);
}
END_TEST  // RETURN_CODE_INCORRECT_MATRIX

START_TEST(s21_sub_null_pointer_rows) {
  matrix_t A = {0};
  A.rows = 3;
  A.columns = 3;
  A.matrix = (double **)malloc(3 * sizeof(double *));
  A.matrix[0] = NULL;
  A.matrix[1] = NULL;
  A.matrix[2] = NULL;
  matrix_t B = {0};
  matrix_t result = {0};
  s21_create_matrix(3, 3, &B);
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result),
                   RETURN_CODE_INCORRECT_MATRIX);
  s21_remove_matrix(&B);
  free(A.matrix);
}
END_TEST

START_TEST(s21_sub_normal) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  matrix_t B;
  s21_create_matrix(3, 3, &B);
  matrix_t result;
  matrix_t check;
  s21_create_matrix(3, 3, &check);
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), RETURN_CODE_OK);
  ck_assert_int_eq(s21_eq_matrix(&check, &result), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_sub_normal2) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  matrix_t B;
  s21_create_matrix(3, 4, &B);
  matrix_t result;
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result),
                   RETURN_CODE_CALCULATION_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_sub_normal3) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  matrix_t B;
  s21_create_matrix(3, 3, &B);
  matrix_t check;
  s21_create_matrix(3, 3, &check);
  for (int i = 0; i < A.rows; ++i) {
    for (int j = 0; j < A.columns; ++j) {
      A.matrix[i][j] = i + j + 2;
      B.matrix[i][j] = i + j + 4;
      check.matrix[i][j] = -2;
    }
  }
  matrix_t result;
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), RETURN_CODE_OK);
  ck_assert_int_eq(s21_eq_matrix(&check, &result), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_sub_normal4) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  matrix_t B;
  s21_create_matrix(3, 3, &B);
  matrix_t check;
  s21_create_matrix(3, 3, &check);
  for (int i = 0; i < A.rows; ++i) {
    for (int j = 0; j < A.columns; ++j) {
      A.matrix[i][j] = i + j + 2;
      B.matrix[i][j] = i + j + 4;
      check.matrix[i][j] = -2;
    }
  }
  B.matrix[0][2] = -1;
  check.matrix[0][2] = 5;
  matrix_t result;
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), RETURN_CODE_OK);
  ck_assert_int_eq(s21_eq_matrix(&check, &result), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

Suite *s21_sub_tests(void) {
  Suite *c = suite_create("s21_sub");
  TCase *tc = tcase_create("s21_sub_tc");
  tcase_add_test(tc, s21_sub_null_pointer);
  tcase_add_test(tc, s21_sub_null_pointer_res);
  tcase_add_test(tc, s21_sub_null_pointer_matrix);
  tcase_add_test(tc, s21_sub_null_pointer_matrix_B);
  tcase_add_test(tc, s21_sub_null_pointer_rows);
  tcase_add_test(tc, s21_sub_normal);
  tcase_add_test(tc, s21_sub_normal2);
  tcase_add_test(tc, s21_sub_normal3);
  tcase_add_test(tc, s21_sub_normal4);
  suite_add_tcase(c, tc);
  return c;
}

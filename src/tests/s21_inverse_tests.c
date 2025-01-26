#include "s21_matrix_tests.h"

START_TEST(s21_inverse_matrix_null_pointer) {
  matrix_t result;
  ck_assert_int_eq(s21_inverse_matrix(NULL, &result),
                   RETURN_CODE_INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_inverse_matrix_null_pointer_res) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  ck_assert_int_eq(s21_inverse_matrix(&A, NULL), RETURN_CODE_INCORRECT_MATRIX);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_inverse_matrix_null_pointer_matrix) {
  matrix_t A;
  A.matrix = NULL;
  matrix_t result;
  ck_assert_int_eq(s21_inverse_matrix(&A, &result),
                   RETURN_CODE_INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_inverse_matrix_null_pointer_rows) {
  matrix_t A;
  A.rows = 3;
  A.columns = 3;
  A.matrix = (double **)malloc(3 * sizeof(double *));
  A.matrix[0] = NULL;
  A.matrix[1] = NULL;
  A.matrix[2] = NULL;
  matrix_t result;
  ck_assert_int_eq(s21_inverse_matrix(&A, &result),
                   RETURN_CODE_INCORRECT_MATRIX);
  free(A.matrix);
}
END_TEST

START_TEST(s21_inverse_matrix_normal) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  matrix_t result;
  ck_assert_int_eq(s21_inverse_matrix(&A, &result),
                   RETURN_CODE_CALCULATION_ERROR);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_inverse_matrix_normal2) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);

  matrix_t check;
  s21_create_matrix(3, 3, &check);

  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;

  check.matrix[0][0] = -13.0 / 198.0;
  check.matrix[0][1] = 29.0 / 198.0;
  check.matrix[0][2] = -7.0 / 198.0;
  check.matrix[1][0] = 5.0 / 22.0;
  check.matrix[1][1] = -1.0 / 22.0;
  check.matrix[1][2] = 1.0 / 22.0;
  check.matrix[2][0] = -2.0 / 9.0;
  check.matrix[2][1] = 1.0 / 9.0;
  check.matrix[2][2] = 1.0 / 9.0;

  matrix_t result;
  ck_assert_int_eq(s21_inverse_matrix(&A, &result), RETURN_CODE_OK);
  ck_assert_int_eq(s21_eq_matrix(&check, &result), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_inverse_matrix_normal3) {
  matrix_t A;
  s21_create_matrix(3, 4, &A);

  matrix_t result;
  ck_assert_int_eq(s21_inverse_matrix(&A, &result),
                   RETURN_CODE_CALCULATION_ERROR);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_inverse_matrix_01) {
  int res = 0;
  matrix_t A = {0};
  matrix_t result = {0};
  matrix_t check = {0};

  s21_create_matrix(4, 4, &A);
  A.matrix[0][0] = -1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[0][2] = 7.0;
  A.matrix[0][3] = 9.0;
  A.matrix[1][0] = 1.0;
  A.matrix[1][1] = 0.0;
  A.matrix[1][2] = 0.0;
  A.matrix[1][3] = 0.0;
  A.matrix[2][0] = 47.0;
  A.matrix[2][1] = 13.0;
  A.matrix[2][2] = 17.0;
  A.matrix[2][3] = 21.0;
  A.matrix[3][0] = 22.0;
  A.matrix[3][1] = 7.0;
  A.matrix[3][2] = 1.0;
  A.matrix[3][3] = 3.0;

  s21_inverse_matrix(&A, &result);

  s21_create_matrix(4, 4, &check);

  check.matrix[0][0] = 0.0;
  check.matrix[0][1] = 1.0;
  check.matrix[0][2] = 0.0;
  check.matrix[0][3] = 0.0;
  check.matrix[1][0] = -5.0 / 23.0;
  check.matrix[1][1] = -121.0 / 23.0;
  check.matrix[1][2] = 2.0 / 23.0;
  check.matrix[1][3] = 1.0 / 23.0;
  check.matrix[2][0] = -18.0 / 23.0;
  check.matrix[2][1] = -379.0 / 46.0;
  check.matrix[2][2] = 19.0 / 46.0;
  check.matrix[2][3] = -25.0 / 46.0;
  check.matrix[3][0] = 53.0 / 69.0;
  check.matrix[3][1] = 1061.0 / 138.0;
  check.matrix[3][2] = -47.0 / 138.0;
  check.matrix[3][3] = 19.0 / 46.0;

  res = s21_eq_matrix(&check, &result);

  s21_remove_matrix(&A);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);

  ck_assert_int_eq(res, SUCCESS);
}
END_TEST

START_TEST(s21_inverse_matrix_02) {
  matrix_t A = {0};
  matrix_t Z = {0};

  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 2;

  s21_inverse_matrix(&A, &Z);

  ck_assert_int_eq(Z.matrix[0][0] == (1.0 / A.matrix[0][0]), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&Z);
}
END_TEST

START_TEST(s21_inverse_matrix_03) {
  int res = 0;
  matrix_t A = {0};
  matrix_t Z = {0};
  matrix_t X = {0};

  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2.0;
  A.matrix[0][1] = 5.0;
  A.matrix[0][2] = 7.0;
  A.matrix[1][0] = 6.0;
  A.matrix[1][1] = 3.0;
  A.matrix[1][2] = 4.0;
  A.matrix[2][0] = 5.0;
  A.matrix[2][1] = -2.0;
  A.matrix[2][2] = -3.0;

  s21_inverse_matrix(&A, &Z);

  s21_create_matrix(3, 3, &X);

  X.matrix[0][0] = 1.0;
  X.matrix[0][1] = -1.0;
  X.matrix[0][2] = 1.0;
  X.matrix[1][0] = -38.0;
  X.matrix[1][1] = 41.0;
  X.matrix[1][2] = -34.0;
  X.matrix[2][0] = 27.0;
  X.matrix[2][1] = -29.0;
  X.matrix[2][2] = 24.0;

  res = s21_eq_matrix(&X, &Z);

  s21_remove_matrix(&A);
  s21_remove_matrix(&X);
  s21_remove_matrix(&Z);

  ck_assert_int_eq(res, SUCCESS);
}
END_TEST

Suite *s21_inverse_matrix_tests(void) {
  Suite *c = suite_create("s21_inverse_matrix");
  TCase *tc = tcase_create("s21_inverse_matrix_tc");
  tcase_add_test(tc, s21_inverse_matrix_null_pointer);
  tcase_add_test(tc, s21_inverse_matrix_null_pointer_res);
  tcase_add_test(tc, s21_inverse_matrix_null_pointer_matrix);
  tcase_add_test(tc, s21_inverse_matrix_null_pointer_rows);
  tcase_add_test(tc, s21_inverse_matrix_normal);
  tcase_add_test(tc, s21_inverse_matrix_normal2);
  tcase_add_test(tc, s21_inverse_matrix_normal3);
  tcase_add_test(tc, s21_inverse_matrix_01);
  tcase_add_test(tc, s21_inverse_matrix_02);
  tcase_add_test(tc, s21_inverse_matrix_03);
  suite_add_tcase(c, tc);
  return c;
}

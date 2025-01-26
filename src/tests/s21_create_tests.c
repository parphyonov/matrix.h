#include "s21_matrix_tests.h"

START_TEST(s21_create_null_pointer) {
  ck_assert_int_eq(s21_create_matrix(3, 3, NULL), RETURN_CODE_INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_create_zero_rows) {
  matrix_t A;
  ck_assert_int_eq(s21_create_matrix(0, 3, &A), RETURN_CODE_INCORRECT_MATRIX);
  ck_assert_ptr_eq(A.matrix, NULL);
}
END_TEST

START_TEST(s21_create_zero_columns) {
  matrix_t A;
  ck_assert_int_eq(s21_create_matrix(3, 0, &A), RETURN_CODE_INCORRECT_MATRIX);
  ck_assert_ptr_eq(A.matrix, NULL);
}
END_TEST

START_TEST(s21_create_normal) {
  matrix_t A;

  ck_assert_int_eq(s21_create_matrix(3, 3, &A), RETURN_CODE_OK);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_create_matrix_09) {
  int res = 0;
  matrix_t A = {0};

  res = s21_create_matrix(-1, 1, &A);
  ck_assert_int_eq(res, RETURN_CODE_INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_undoing_successfull_allocations) {
  matrix_t A = {0};
  int A_created = s21_create_matrix(3, 3, &A);
  ck_assert_int_eq(A_created, RETURN_CODE_OK);
  int row = 3;
  int undone = s21_cm_undo_successfull_allocations(&A, row);
  ck_assert_int_eq(undone, SUCCESS);
}
END_TEST

Suite *s21_create_tests(void) {
  Suite *c = suite_create("s21_create");
  TCase *tc = tcase_create("s21_create_tc");
  tcase_add_test(tc, s21_create_null_pointer);
  tcase_add_test(tc, s21_create_zero_rows);
  tcase_add_test(tc, s21_create_zero_columns);
  tcase_add_test(tc, s21_create_normal);
  tcase_add_test(tc, s21_create_matrix_09);
  tcase_add_test(tc, s21_undoing_successfull_allocations);
  suite_add_tcase(c, tc);
  return c;
}

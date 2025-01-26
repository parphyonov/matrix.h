#include "s21_matrix_tests.h"

START_TEST(s21_copy_matrix_NULL_as_source) {
  matrix_t DESTINATION = {0};

  int res = s21_copy_matrix(NULL, &DESTINATION);

  ck_assert_int_eq(res, RETURN_CODE_INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_copy_matrix_NULL_as_dest) {
  matrix_t SOURCE = {0};

  int res = s21_copy_matrix(&SOURCE, NULL);

  ck_assert_int_eq(res, RETURN_CODE_INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_copy_matrix_NULL_as_source_and_dest) {
  int res = s21_copy_matrix(NULL, NULL);

  ck_assert_int_eq(res, RETURN_CODE_INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_minor_NULL_as_matrix) {
  matrix_t RES = {0};
  int RES_created = s21_create_matrix(3, 3, &RES);

  int res = s21_minor(NULL, 0, 0, &RES);

  ck_assert_int_eq(RES_created, RETURN_CODE_OK);
  ck_assert_int_eq(res, RETURN_CODE_INCORRECT_MATRIX);

  s21_remove_matrix(&RES);
}
END_TEST

START_TEST(s21_minor_NULL_as_res) {
  matrix_t M = {0};
  int M_created = s21_create_matrix(3, 3, &M);

  int res = s21_minor(&M, 0, 0, NULL);

  ck_assert_int_eq(M_created, RETURN_CODE_OK);
  ck_assert_int_eq(res, RETURN_CODE_INCORRECT_MATRIX);

  s21_remove_matrix(&M);
}
END_TEST

START_TEST(s21_minor_NULL_as_matrix_and_res) {
  int res = s21_minor(NULL, 0, 0, NULL);
  ck_assert_int_eq(res, RETURN_CODE_INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_print_regular_matrix) {
  matrix_t TO_PRINT = {0};
  int TO_PRINT_created = s21_create_matrix(3, 3, &TO_PRINT);
  int TO_PRINT_printed = s21_print_matrix(&TO_PRINT, 2);
  ck_assert_int_eq(TO_PRINT_created, RETURN_CODE_OK);
  ck_assert_int_eq(TO_PRINT_printed, SUCCESS);
  s21_remove_matrix(&TO_PRINT);
}
END_TEST

START_TEST(s21_print_NULL_matrix) {
  int NULL_printed = s21_print_matrix(NULL, 2);
  ck_assert_int_eq(NULL_printed, FAILURE);
}
END_TEST

Suite *s21_extra_tests(void) {
  Suite *c = suite_create("s21_extra_tests");
  TCase *tc = tcase_create("s21_extra_tests_tc");
  tcase_add_test(tc, s21_copy_matrix_NULL_as_source);
  tcase_add_test(tc, s21_copy_matrix_NULL_as_dest);
  tcase_add_test(tc, s21_copy_matrix_NULL_as_source_and_dest);
  tcase_add_test(tc, s21_minor_NULL_as_matrix);
  tcase_add_test(tc, s21_minor_NULL_as_res);
  tcase_add_test(tc, s21_minor_NULL_as_matrix_and_res);
  tcase_add_test(tc, s21_print_regular_matrix);
  tcase_add_test(tc, s21_print_NULL_matrix);
  suite_add_tcase(c, tc);
  return c;
}

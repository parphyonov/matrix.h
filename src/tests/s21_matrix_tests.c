#include "s21_matrix_tests.h"

int main(void) {
  // run tests
  run_tests();

  return 0;
}

void run_tests() {
  int counter_testcase = 1;

  Suite *list_cases[] = {s21_create_tests(),
                         s21_remove_tests(),
                         s21_eq_tests(),
                         s21_sum_tests(),
                         s21_sub_tests(),
                         s21_mult_number_tests(),
                         s21_mult_matrix_tests(),
                         s21_transpose_tests(),
                         s21_calc_complements_tests(),
                         s21_determinant_tests(),
                         s21_inverse_matrix_tests(),
                         s21_extra_tests(),
                         NULL};

  for (Suite **testcase = list_cases; *testcase != NULL; testcase++) {
    run_testcase(*testcase, counter_testcase);
    counter_testcase++;
  }
}

void run_testcase(Suite *testscase, int counter_testcase) {
  if (counter_testcase > 1) putchar('\n');

  printf("Test %d:\n", counter_testcase);

  SRunner *sr = srunner_create(testscase);
  srunner_set_fork_status(sr, CK_NOFORK);

  // изменить CK_ENV на CK_VERBOSE , для более  подробного вывода информации о
  // тестах. CK_NORMAL для стандартного вывода.
  srunner_run_all(sr, CK_ENV);

  srunner_free(sr);
}
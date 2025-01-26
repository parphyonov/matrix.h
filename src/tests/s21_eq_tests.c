#include "s21_matrix_tests.h"

START_TEST(s21_eq_null_pointer) {
  matrix_t A = {0};
  ck_assert_int_eq(s21_eq_matrix(&A, NULL), FAILURE);
}
END_TEST

START_TEST(s21_eq_null_pointer_matrix) {
  matrix_t A = {0};
  A.matrix = NULL;
  matrix_t B = {0};
  s21_create_matrix(3, 3, &B);
  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_null_pointer_rows) {
  matrix_t A;
  A.rows = 3;
  A.columns = 3;
  A.matrix = (double **)malloc(3 * sizeof(double *));
  A.matrix[0] = NULL;
  A.matrix[1] = NULL;
  A.matrix[2] = NULL;

  matrix_t B = {0};
  s21_create_matrix(3, 3, &B);

  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);

  free(A.matrix);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_not_all_null_pointer_rows) {
  int rows = 3, columns = 3;
  matrix_t A;
  A.rows = rows;
  A.columns = columns;
  A.matrix = (double **)malloc(3 * sizeof(double *));
  A.matrix[0] = NULL;
  A.matrix[1] = (double *)malloc(3 * sizeof(double));
  A.matrix[2] = NULL;
  matrix_t B = {0};
  B.rows = rows;
  B.columns = columns;
  B.matrix = (double **)malloc(3 * sizeof(double *));
  B.matrix[0] = NULL;
  B.matrix[1] = NULL;
  B.matrix[2] = (double *)malloc(3 * sizeof(double));
  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_normal) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  matrix_t B;
  s21_create_matrix(3, 3, &B);
  ck_assert_int_eq(s21_eq_matrix(&A, &B), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_normal2) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  matrix_t B;
  s21_create_matrix(3, 4, &B);
  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_normal3) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  matrix_t B;
  s21_create_matrix(3, 3, &B);
  for (int i = 0; i < A.rows; ++i) {
    for (int j = 0; j < A.columns; ++j) {
      A.matrix[i][j] = i + j + 2;
      B.matrix[i][j] = i + j + 2;
    }
  }
  ck_assert_int_eq(s21_eq_matrix(&A, &B), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_normal4) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  matrix_t B;
  s21_create_matrix(3, 3, &B);
  for (int i = 0; i < A.rows; ++i) {
    for (int j = 0; j < A.columns; ++j) {
      A.matrix[i][j] = i + j + 2;
      B.matrix[i][j] = i + j + 2;
    }
  }
  B.matrix[0][2] = -1;
  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_inf_normal) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  matrix_t B;
  s21_create_matrix(3, 3, &B);
  for (int i = 0; i < A.rows; ++i) {
    for (int j = 0; j < A.columns; ++j) {
      A.matrix[i][j] = i + j + 2;
      B.matrix[i][j] = i + j + 2;
    }
  }
  A.matrix[0][2] = INFINITY;
  B.matrix[0][2] = INFINITY;
  ck_assert_int_eq(s21_eq_matrix(&A, &B), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_inf_neg_normal) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  matrix_t B;
  s21_create_matrix(3, 3, &B);
  for (int i = 0; i < A.rows; ++i) {
    for (int j = 0; j < A.columns; ++j) {
      A.matrix[i][j] = i + j + 2;
      B.matrix[i][j] = i + j + 2;
    }
  }
  A.matrix[0][2] = -INFINITY;
  B.matrix[0][2] = -INFINITY;
  ck_assert_int_eq(s21_eq_matrix(&A, &B), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_inf_neq) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  matrix_t B;
  s21_create_matrix(3, 3, &B);
  for (int i = 0; i < A.rows; ++i) {
    for (int j = 0; j < A.columns; ++j) {
      A.matrix[i][j] = i + j + 2;
      B.matrix[i][j] = i + j + 2;
    }
  }
  A.matrix[0][2] = INFINITY;
  B.matrix[0][2] = -INFINITY;
  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_nan) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  matrix_t B;
  s21_create_matrix(3, 3, &B);
  for (int i = 0; i < A.rows; ++i) {
    for (int j = 0; j < A.columns; ++j) {
      A.matrix[i][j] = i + j + 2;
      B.matrix[i][j] = i + j + 2;
    }
  }
  B.matrix[0][2] = NAN;
  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_nan2) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  matrix_t B;
  s21_create_matrix(3, 3, &B);
  for (int i = 0; i < A.rows; ++i) {
    for (int j = 0; j < A.columns; ++j) {
      A.matrix[i][j] = i + j + 2;
      B.matrix[i][j] = i + j + 2;
    }
  }
  B.matrix[0][2] = -NAN;
  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_nan3) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);

  matrix_t B;
  s21_create_matrix(3, 3, &B);

  for (int i = 0; i < A.rows; ++i) {
    for (int j = 0; j < A.columns; ++j) {
      A.matrix[i][j] = i + j + 2;
      B.matrix[i][j] = i + j + 2;
    }
  }

  A.matrix[0][2] = NAN;
  B.matrix[0][2] = NAN;

  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

Suite *s21_eq_tests(void) {
  Suite *c = suite_create("s21_eq");
  TCase *tc = tcase_create("s21_eq_tc");
  tcase_add_test(tc, s21_eq_null_pointer);
  tcase_add_test(tc, s21_eq_null_pointer_matrix);
  tcase_add_test(tc, s21_eq_null_pointer_rows);
  tcase_add_test(tc, s21_eq_not_all_null_pointer_rows);
  tcase_add_test(tc, s21_eq_normal);
  tcase_add_test(tc, s21_eq_normal2);
  tcase_add_test(tc, s21_eq_normal3);
  tcase_add_test(tc, s21_eq_normal4);
  tcase_add_test(tc, s21_eq_inf_normal);
  tcase_add_test(tc, s21_eq_inf_neg_normal);
  tcase_add_test(tc, s21_eq_inf_neq);
  tcase_add_test(tc, s21_eq_nan);
  tcase_add_test(tc, s21_eq_nan2);
  tcase_add_test(tc, s21_eq_nan3);
  suite_add_tcase(c, tc);
  return c;
}

#include "s21_matrix_tests.h"

START_TEST(s21_determinant_null_pointer) {
  double result = {0};
  ck_assert_int_eq(s21_determinant(NULL, &result),
                   RETURN_CODE_INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_determinant_null_pointer_res) {
  matrix_t A = {0};
  ck_assert_int_eq(s21_determinant(&A, NULL), RETURN_CODE_INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_determinant_null_pointer_matrix) {
  matrix_t A = {0};
  A.matrix = NULL;
  double result = 0.0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_determinant_null_pointer_rows) {
  matrix_t A = {0};
  A.rows = 3;
  A.columns = 3;
  A.matrix = (double **)malloc(3 * sizeof(double *));
  A.matrix[0] = NULL;
  A.matrix[1] = NULL;
  A.matrix[2] = NULL;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_INCORRECT_MATRIX);
  free(A.matrix);
}
END_TEST

START_TEST(s21_determinant_normal) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);

  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal2) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-198, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal3) {
  matrix_t A;
  s21_create_matrix(3, 4, &A);

  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_CALCULATION_ERROR);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal4) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-224, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal5) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-18, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal6) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-154, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal7) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(5, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal8) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-225, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal9) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-176, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal10) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-177, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal11) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-153, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal12) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-66, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal13) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);

  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;

  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-44, result, EPSILON);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal14) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-180, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal15) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);

  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;

  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-21, result, EPSILON);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal16) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-215, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal17) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-212, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal18) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-203, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal19) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-189, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal20) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-56, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal21) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(26, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal22) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(17, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal23) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-45, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal24) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-8, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal25) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);

  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;

  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-9, result, EPSILON);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal26) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(27, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal27) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-54, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal28) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(14, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal29) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-190, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal30) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-132, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal31) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-142, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal32) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-144, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal33) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-22, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal34) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-22, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal35) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(27, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal36) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(26, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal37) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(15, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal38) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-31, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal39) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-203, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal40) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-213, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal41) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-180, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal42) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-57, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal43) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-167, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal44) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-141, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal45) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-44, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal46) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-132, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal47) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-45, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal48) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-21, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal49) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal50) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-9, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal51) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-35, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal52) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-44, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal53) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-35, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal54) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-9, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal55) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-44, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal56) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-12, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal57) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-180, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal58) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-168, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal59) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-168, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal60) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-180, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal61) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-12, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal62) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-12, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal63) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-9, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal64) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal65) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-21, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal66) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-21, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal67) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-203, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal68) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-203, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal69) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-180, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal70) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-47, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal71) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-203, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal72) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-177, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal73) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-44, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal74) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-168, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal75) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-35, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal76) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-21, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal77) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(26, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal78) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-10, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal79) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(36, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal80) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(26, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal81) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(36, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal82) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-10, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal83) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-10, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal84) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(27, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal85) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(26, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal86) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(27, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal87) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-19, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal88) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-35, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal89) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-45, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal90) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal91) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-45, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal92) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(1, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal93) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(27, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal94) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-44, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal95) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(36, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal96) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-45, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal97) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-9, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal98) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-22, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal99) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(36, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal100) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(26, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal101) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(24, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal102) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-22, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal103) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-168, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal104) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-178, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal105) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-180, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal106) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-22, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal107) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-132, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal108) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-132, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal109) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal110) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-132, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal510) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-10, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal111) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-12, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal112) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal113) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-10, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal114) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-12, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal115) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-22, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal116) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(36, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal117) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(27, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal118) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-9, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal119) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(36, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal120) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-10, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal121) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-21, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal122) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-203, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal123) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-168, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal124) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-35, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal125) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-168, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal126) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-45, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal127) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-12, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal128) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-132, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal129) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-35, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal130) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-9, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal131) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal132) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal133) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal134) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal135) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal136) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal137) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal138) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal139) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-9, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal140) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal141) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-9, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal142) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-9, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal143) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-35, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal144) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-35, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal145) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal146) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-35, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal147) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-35, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal148) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-9, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal149) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-44, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal150) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal151) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-35, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal152) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-9, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal153) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-12, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal154) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal155) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal156) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-12, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal157) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-12, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal158) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-168, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal159) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-168, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal160) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-180, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal161) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-12, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal162) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-168, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal163) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-168, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal164) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal165) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-168, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal166) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal167) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-12, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal168) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal169) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal170) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-12, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal171) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-12, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal172) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal173) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-9, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal174) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-9, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal175) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal176) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal177) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-21, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal178) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-203, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal179) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-168, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal180) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-35, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal181) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-168, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal182) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-35, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal183) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-12, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal184) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-168, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal185) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-35, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal186) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-9, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal187) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal188) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-10, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal189) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(36, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal190) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(26, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal191) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(36, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal192) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-10, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal193) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal194) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-10, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal195) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal196) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-10, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal197) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(36, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal198) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(36, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal199) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal200) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(36, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal201) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-10, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal202) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal203) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal204) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-10, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal205) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal206) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-10, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal207) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(36, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal208) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(27, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal209) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-9, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal210) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(36, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal211) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-10, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal212) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-9, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal213) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-35, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal214) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal215) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-35, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal216) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal217) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-45, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal218) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal219) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(36, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal220) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-35, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal221) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-9, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal222) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal223) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal224) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-10, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal225) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-12, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal226) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-22, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal227) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(36, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal228) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(36, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal229) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal230) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(36, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal231) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-10, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal232) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-12, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal233) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-168, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal234) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-168, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal235) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal236) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-168, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal237) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-10, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal238) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-12, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal239) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-132, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal240) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal241) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal242) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal243) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal244) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal245) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal246) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal247) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-10, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal248) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-12, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal249) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(36, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal250) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal251) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-9, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal252) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal253) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-168, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal502) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-35, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal503) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal504) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal505) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal254) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal255) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal256) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal257) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal258) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal259) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal260) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal261) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal262) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal263) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal264) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal265) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal266) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal267) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal268) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal269) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal270) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal271) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal272) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal273) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal274) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-9, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal275) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-9, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal276) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal277) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal278) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-9, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal279) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-35, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal280) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal281) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-35, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal282) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal283) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-35, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal284) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal285) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal286) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-35, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal287) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-9, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal288) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal289) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal290) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal291) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-12, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal292) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-12, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal293) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal294) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal295) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal296) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal297) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal298) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-12, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal299) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-168, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal300) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-168, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal301) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal302) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-168, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal303) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal304) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-12, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal305) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-168, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal306) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal307) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal308) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal309) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal310) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal311) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal312) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal313) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal314) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-12, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal315) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal316) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal317) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-9, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal318) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal319) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-168, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal320) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-35, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal321) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal322) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal323) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal324) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal325) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-10, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal326) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal327) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-10, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal328) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(36, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal329) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(36, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal330) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal331) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(36, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal332) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-10, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal333) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal334) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal335) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal336) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal337) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal338) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-10, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal339) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal340) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(36, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal341) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal342) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal343) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal344) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal345) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal346) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal347) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal348) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-10, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal349) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal350) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(36, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal351) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal352) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-9, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal353) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal354) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal355) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-35, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal356) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal357) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal358) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal359) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal360) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal361) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal362) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal363) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-10, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal364) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-12, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal365) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(36, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal366) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal367) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal368) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal369) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-168, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal370) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal371) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal372) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal373) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal374) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal375) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal376) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal377) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal378) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal379) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal380) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal381) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal382) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal383) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal384) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal385) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal386) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal387) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal388) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal389) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal390) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal391) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal392) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal393) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal394) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal395) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal396) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal511) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal397) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal398) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal399) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal400) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal401) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal402) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal403) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal404) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal405) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal406) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal407) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-9, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal408) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal409) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal410) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-35, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal411) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal412) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal413) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal414) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal415) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal416) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal417) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal418) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal419) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-12, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal420) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal421) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal422) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal423) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal424) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-168, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal425) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal426) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal427) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal428) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal429) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal430) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal431) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal432) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal433) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal434) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal435) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal436) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal437) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal438) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal439) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(-10, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal440) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal441) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(36, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal442) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal443) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal444) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal445) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal446) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal447) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal448) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal449) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal450) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal451) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal452) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal453) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal454) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal455) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal456) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal506) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal507) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal508) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal509) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal512) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal513) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);

  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;

  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal457) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal458) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal459) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal460) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal461) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal462) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal463) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal464) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal465) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal466) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal467) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal468) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal469) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal470) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal471) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal472) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal473) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal474) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal475) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal476) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal477) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal478) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal479) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal480) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal481) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal482) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal483) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal484) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal485) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal486) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal487) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal488) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal489) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal490) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal491) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal492) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal493) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal494) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal495) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal496) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal497) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal498) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal499) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal500) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal501) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), RETURN_CODE_OK);
  ck_assert_double_eq_tol(0, result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_04) {
  double determ = 0.0;
  matrix_t A = {0};

  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 4000.87;
  A.matrix[0][1] = 454.0;
  A.matrix[0][2] = 4.0;
  A.matrix[1][0] = 2.0;
  A.matrix[1][1] = 1.897;
  A.matrix[1][2] = 3.0;
  A.matrix[2][0] = 0.000087;
  A.matrix[2][1] = 2.5668;
  A.matrix[2][2] = 1.0;

  s21_determinant(&A, &determ);
  ck_assert_double_eq(determ, -24105.996724156);
  s21_remove_matrix(&A);
}
END_TEST

void s21_init_matrix(double number, matrix_t *A) {
  for (int x = 0; x < A->rows; x += 1) {
    for (int y = 0; y < A->columns; number += 1.0, y += 1)
      A->matrix[x][y] = number;
  }
}

START_TEST(s21_determinant_06) {
  double determ = 0.0;
  matrix_t A = {0};

  s21_create_matrix(8, 8, &A);
  s21_init_matrix(1.0, &A);

  s21_determinant(&A, &determ);
  ck_assert_double_eq_tol(determ, 0.0, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

Suite *s21_determinant_tests(void) {
  Suite *c = suite_create("s21_determinant");
  TCase *tc = tcase_create("s21_determinant_tc");
  tcase_add_test(tc, s21_determinant_null_pointer);
  tcase_add_test(tc, s21_determinant_null_pointer_res);
  tcase_add_test(tc, s21_determinant_null_pointer_matrix);
  tcase_add_test(tc, s21_determinant_null_pointer_rows);
  tcase_add_test(tc, s21_determinant_normal);
  tcase_add_test(tc, s21_determinant_normal2);
  tcase_add_test(tc, s21_determinant_normal3);
  tcase_add_test(tc, s21_determinant_normal4);
  tcase_add_test(tc, s21_determinant_normal5);
  tcase_add_test(tc, s21_determinant_normal6);
  tcase_add_test(tc, s21_determinant_normal7);
  tcase_add_test(tc, s21_determinant_normal8);
  tcase_add_test(tc, s21_determinant_normal9);
  tcase_add_test(tc, s21_determinant_normal10);
  tcase_add_test(tc, s21_determinant_normal11);
  tcase_add_test(tc, s21_determinant_normal12);
  tcase_add_test(tc, s21_determinant_normal13);
  tcase_add_test(tc, s21_determinant_normal14);
  tcase_add_test(tc, s21_determinant_normal15);
  tcase_add_test(tc, s21_determinant_normal16);
  tcase_add_test(tc, s21_determinant_normal17);
  tcase_add_test(tc, s21_determinant_normal18);
  tcase_add_test(tc, s21_determinant_normal19);
  tcase_add_test(tc, s21_determinant_normal20);
  tcase_add_test(tc, s21_determinant_normal21);
  tcase_add_test(tc, s21_determinant_normal22);
  tcase_add_test(tc, s21_determinant_normal23);
  tcase_add_test(tc, s21_determinant_normal24);
  tcase_add_test(tc, s21_determinant_normal25);
  tcase_add_test(tc, s21_determinant_normal26);
  tcase_add_test(tc, s21_determinant_normal27);
  tcase_add_test(tc, s21_determinant_normal28);
  tcase_add_test(tc, s21_determinant_normal29);
  tcase_add_test(tc, s21_determinant_normal30);
  tcase_add_test(tc, s21_determinant_normal31);
  tcase_add_test(tc, s21_determinant_normal32);
  tcase_add_test(tc, s21_determinant_normal33);
  tcase_add_test(tc, s21_determinant_normal34);
  tcase_add_test(tc, s21_determinant_normal35);
  tcase_add_test(tc, s21_determinant_normal36);
  tcase_add_test(tc, s21_determinant_normal37);
  tcase_add_test(tc, s21_determinant_normal38);
  tcase_add_test(tc, s21_determinant_normal39);
  tcase_add_test(tc, s21_determinant_normal40);
  tcase_add_test(tc, s21_determinant_normal41);
  tcase_add_test(tc, s21_determinant_normal42);
  tcase_add_test(tc, s21_determinant_normal43);
  tcase_add_test(tc, s21_determinant_normal44);
  tcase_add_test(tc, s21_determinant_normal45);
  tcase_add_test(tc, s21_determinant_normal46);
  tcase_add_test(tc, s21_determinant_normal47);
  tcase_add_test(tc, s21_determinant_normal48);
  tcase_add_test(tc, s21_determinant_normal49);
  tcase_add_test(tc, s21_determinant_normal50);
  tcase_add_test(tc, s21_determinant_normal51);
  tcase_add_test(tc, s21_determinant_normal52);
  tcase_add_test(tc, s21_determinant_normal53);
  tcase_add_test(tc, s21_determinant_normal54);
  tcase_add_test(tc, s21_determinant_normal55);
  tcase_add_test(tc, s21_determinant_normal56);
  tcase_add_test(tc, s21_determinant_normal57);
  tcase_add_test(tc, s21_determinant_normal58);
  tcase_add_test(tc, s21_determinant_normal59);
  tcase_add_test(tc, s21_determinant_normal60);
  tcase_add_test(tc, s21_determinant_normal61);
  tcase_add_test(tc, s21_determinant_normal62);
  tcase_add_test(tc, s21_determinant_normal63);
  tcase_add_test(tc, s21_determinant_normal64);
  tcase_add_test(tc, s21_determinant_normal65);
  tcase_add_test(tc, s21_determinant_normal66);
  tcase_add_test(tc, s21_determinant_normal67);
  tcase_add_test(tc, s21_determinant_normal68);
  tcase_add_test(tc, s21_determinant_normal69);
  tcase_add_test(tc, s21_determinant_normal70);
  tcase_add_test(tc, s21_determinant_normal71);
  tcase_add_test(tc, s21_determinant_normal72);
  tcase_add_test(tc, s21_determinant_normal73);
  tcase_add_test(tc, s21_determinant_normal74);
  tcase_add_test(tc, s21_determinant_normal75);
  tcase_add_test(tc, s21_determinant_normal76);
  tcase_add_test(tc, s21_determinant_normal77);
  tcase_add_test(tc, s21_determinant_normal78);
  tcase_add_test(tc, s21_determinant_normal79);
  tcase_add_test(tc, s21_determinant_normal80);
  tcase_add_test(tc, s21_determinant_normal81);
  tcase_add_test(tc, s21_determinant_normal82);
  tcase_add_test(tc, s21_determinant_normal83);
  tcase_add_test(tc, s21_determinant_normal84);
  tcase_add_test(tc, s21_determinant_normal85);
  tcase_add_test(tc, s21_determinant_normal86);
  tcase_add_test(tc, s21_determinant_normal87);
  tcase_add_test(tc, s21_determinant_normal88);
  tcase_add_test(tc, s21_determinant_normal89);
  tcase_add_test(tc, s21_determinant_normal90);
  tcase_add_test(tc, s21_determinant_normal91);
  tcase_add_test(tc, s21_determinant_normal92);
  tcase_add_test(tc, s21_determinant_normal93);
  tcase_add_test(tc, s21_determinant_normal94);
  tcase_add_test(tc, s21_determinant_normal95);
  tcase_add_test(tc, s21_determinant_normal96);
  tcase_add_test(tc, s21_determinant_normal97);
  tcase_add_test(tc, s21_determinant_normal98);
  tcase_add_test(tc, s21_determinant_normal99);
  tcase_add_test(tc, s21_determinant_normal100);
  tcase_add_test(tc, s21_determinant_normal101);
  tcase_add_test(tc, s21_determinant_normal102);
  tcase_add_test(tc, s21_determinant_normal103);
  tcase_add_test(tc, s21_determinant_normal104);
  tcase_add_test(tc, s21_determinant_normal105);
  tcase_add_test(tc, s21_determinant_normal106);
  tcase_add_test(tc, s21_determinant_normal107);
  tcase_add_test(tc, s21_determinant_normal108);
  tcase_add_test(tc, s21_determinant_normal109);
  tcase_add_test(tc, s21_determinant_normal110);
  tcase_add_test(tc, s21_determinant_normal111);
  tcase_add_test(tc, s21_determinant_normal112);
  tcase_add_test(tc, s21_determinant_normal113);
  tcase_add_test(tc, s21_determinant_normal114);
  tcase_add_test(tc, s21_determinant_normal115);
  tcase_add_test(tc, s21_determinant_normal116);
  tcase_add_test(tc, s21_determinant_normal117);
  tcase_add_test(tc, s21_determinant_normal118);
  tcase_add_test(tc, s21_determinant_normal119);
  tcase_add_test(tc, s21_determinant_normal120);
  tcase_add_test(tc, s21_determinant_normal121);
  tcase_add_test(tc, s21_determinant_normal122);
  tcase_add_test(tc, s21_determinant_normal123);
  tcase_add_test(tc, s21_determinant_normal124);
  tcase_add_test(tc, s21_determinant_normal125);
  tcase_add_test(tc, s21_determinant_normal126);
  tcase_add_test(tc, s21_determinant_normal127);
  tcase_add_test(tc, s21_determinant_normal128);
  tcase_add_test(tc, s21_determinant_normal129);
  tcase_add_test(tc, s21_determinant_normal130);
  tcase_add_test(tc, s21_determinant_normal131);
  tcase_add_test(tc, s21_determinant_normal132);
  tcase_add_test(tc, s21_determinant_normal133);
  tcase_add_test(tc, s21_determinant_normal134);
  tcase_add_test(tc, s21_determinant_normal135);
  tcase_add_test(tc, s21_determinant_normal136);
  tcase_add_test(tc, s21_determinant_normal137);
  tcase_add_test(tc, s21_determinant_normal138);
  tcase_add_test(tc, s21_determinant_normal139);
  tcase_add_test(tc, s21_determinant_normal140);
  tcase_add_test(tc, s21_determinant_normal141);
  tcase_add_test(tc, s21_determinant_normal142);
  tcase_add_test(tc, s21_determinant_normal143);
  tcase_add_test(tc, s21_determinant_normal144);
  tcase_add_test(tc, s21_determinant_normal145);
  tcase_add_test(tc, s21_determinant_normal146);
  tcase_add_test(tc, s21_determinant_normal147);
  tcase_add_test(tc, s21_determinant_normal148);
  tcase_add_test(tc, s21_determinant_normal149);
  tcase_add_test(tc, s21_determinant_normal150);
  tcase_add_test(tc, s21_determinant_normal151);
  tcase_add_test(tc, s21_determinant_normal152);
  tcase_add_test(tc, s21_determinant_normal153);
  tcase_add_test(tc, s21_determinant_normal154);
  tcase_add_test(tc, s21_determinant_normal155);
  tcase_add_test(tc, s21_determinant_normal156);
  tcase_add_test(tc, s21_determinant_normal157);
  tcase_add_test(tc, s21_determinant_normal158);
  tcase_add_test(tc, s21_determinant_normal159);
  tcase_add_test(tc, s21_determinant_normal160);
  tcase_add_test(tc, s21_determinant_normal161);
  tcase_add_test(tc, s21_determinant_normal162);
  tcase_add_test(tc, s21_determinant_normal163);
  tcase_add_test(tc, s21_determinant_normal164);
  tcase_add_test(tc, s21_determinant_normal165);
  tcase_add_test(tc, s21_determinant_normal166);
  tcase_add_test(tc, s21_determinant_normal167);
  tcase_add_test(tc, s21_determinant_normal168);
  tcase_add_test(tc, s21_determinant_normal169);
  tcase_add_test(tc, s21_determinant_normal170);
  tcase_add_test(tc, s21_determinant_normal171);
  tcase_add_test(tc, s21_determinant_normal172);
  tcase_add_test(tc, s21_determinant_normal173);
  tcase_add_test(tc, s21_determinant_normal174);
  tcase_add_test(tc, s21_determinant_normal175);
  tcase_add_test(tc, s21_determinant_normal176);
  tcase_add_test(tc, s21_determinant_normal177);
  tcase_add_test(tc, s21_determinant_normal178);
  tcase_add_test(tc, s21_determinant_normal179);
  tcase_add_test(tc, s21_determinant_normal180);
  tcase_add_test(tc, s21_determinant_normal181);
  tcase_add_test(tc, s21_determinant_normal182);
  tcase_add_test(tc, s21_determinant_normal183);
  tcase_add_test(tc, s21_determinant_normal184);
  tcase_add_test(tc, s21_determinant_normal185);
  tcase_add_test(tc, s21_determinant_normal186);
  tcase_add_test(tc, s21_determinant_normal187);
  tcase_add_test(tc, s21_determinant_normal188);
  tcase_add_test(tc, s21_determinant_normal189);
  tcase_add_test(tc, s21_determinant_normal190);
  tcase_add_test(tc, s21_determinant_normal191);
  tcase_add_test(tc, s21_determinant_normal192);
  tcase_add_test(tc, s21_determinant_normal193);
  tcase_add_test(tc, s21_determinant_normal194);
  tcase_add_test(tc, s21_determinant_normal195);
  tcase_add_test(tc, s21_determinant_normal196);
  tcase_add_test(tc, s21_determinant_normal197);
  tcase_add_test(tc, s21_determinant_normal198);
  tcase_add_test(tc, s21_determinant_normal199);
  tcase_add_test(tc, s21_determinant_normal200);
  tcase_add_test(tc, s21_determinant_normal200);
  tcase_add_test(tc, s21_determinant_normal201);
  tcase_add_test(tc, s21_determinant_normal202);
  tcase_add_test(tc, s21_determinant_normal203);
  tcase_add_test(tc, s21_determinant_normal204);
  tcase_add_test(tc, s21_determinant_normal205);
  tcase_add_test(tc, s21_determinant_normal206);
  tcase_add_test(tc, s21_determinant_normal207);
  tcase_add_test(tc, s21_determinant_normal208);
  tcase_add_test(tc, s21_determinant_normal209);
  tcase_add_test(tc, s21_determinant_normal210);
  tcase_add_test(tc, s21_determinant_normal211);
  tcase_add_test(tc, s21_determinant_normal212);
  tcase_add_test(tc, s21_determinant_normal213);
  tcase_add_test(tc, s21_determinant_normal214);
  tcase_add_test(tc, s21_determinant_normal215);
  tcase_add_test(tc, s21_determinant_normal216);
  tcase_add_test(tc, s21_determinant_normal217);
  tcase_add_test(tc, s21_determinant_normal218);
  tcase_add_test(tc, s21_determinant_normal219);
  tcase_add_test(tc, s21_determinant_normal220);
  tcase_add_test(tc, s21_determinant_normal221);
  tcase_add_test(tc, s21_determinant_normal222);
  tcase_add_test(tc, s21_determinant_normal223);
  tcase_add_test(tc, s21_determinant_normal224);
  tcase_add_test(tc, s21_determinant_normal225);
  tcase_add_test(tc, s21_determinant_normal226);
  tcase_add_test(tc, s21_determinant_normal227);
  tcase_add_test(tc, s21_determinant_normal228);
  tcase_add_test(tc, s21_determinant_normal229);
  tcase_add_test(tc, s21_determinant_normal230);
  tcase_add_test(tc, s21_determinant_normal231);
  tcase_add_test(tc, s21_determinant_normal232);
  tcase_add_test(tc, s21_determinant_normal233);
  tcase_add_test(tc, s21_determinant_normal234);
  tcase_add_test(tc, s21_determinant_normal235);
  tcase_add_test(tc, s21_determinant_normal236);
  tcase_add_test(tc, s21_determinant_normal237);
  tcase_add_test(tc, s21_determinant_normal238);
  tcase_add_test(tc, s21_determinant_normal239);
  tcase_add_test(tc, s21_determinant_normal240);
  tcase_add_test(tc, s21_determinant_normal241);
  tcase_add_test(tc, s21_determinant_normal242);
  tcase_add_test(tc, s21_determinant_normal243);
  tcase_add_test(tc, s21_determinant_normal244);
  tcase_add_test(tc, s21_determinant_normal245);
  tcase_add_test(tc, s21_determinant_normal246);
  tcase_add_test(tc, s21_determinant_normal247);
  tcase_add_test(tc, s21_determinant_normal248);
  tcase_add_test(tc, s21_determinant_normal249);
  tcase_add_test(tc, s21_determinant_normal250);
  tcase_add_test(tc, s21_determinant_normal251);
  tcase_add_test(tc, s21_determinant_normal252);
  tcase_add_test(tc, s21_determinant_normal253);
  tcase_add_test(tc, s21_determinant_normal254);
  tcase_add_test(tc, s21_determinant_normal255);
  tcase_add_test(tc, s21_determinant_normal256);
  tcase_add_test(tc, s21_determinant_normal257);
  tcase_add_test(tc, s21_determinant_normal258);
  tcase_add_test(tc, s21_determinant_normal259);
  tcase_add_test(tc, s21_determinant_normal260);
  tcase_add_test(tc, s21_determinant_normal261);
  tcase_add_test(tc, s21_determinant_normal262);
  tcase_add_test(tc, s21_determinant_normal263);
  tcase_add_test(tc, s21_determinant_normal264);
  tcase_add_test(tc, s21_determinant_normal265);
  tcase_add_test(tc, s21_determinant_normal266);
  tcase_add_test(tc, s21_determinant_normal267);
  tcase_add_test(tc, s21_determinant_normal268);
  tcase_add_test(tc, s21_determinant_normal269);
  tcase_add_test(tc, s21_determinant_normal270);
  tcase_add_test(tc, s21_determinant_normal271);
  tcase_add_test(tc, s21_determinant_normal272);
  tcase_add_test(tc, s21_determinant_normal273);
  tcase_add_test(tc, s21_determinant_normal274);
  tcase_add_test(tc, s21_determinant_normal275);
  tcase_add_test(tc, s21_determinant_normal276);
  tcase_add_test(tc, s21_determinant_normal277);
  tcase_add_test(tc, s21_determinant_normal278);
  tcase_add_test(tc, s21_determinant_normal279);
  tcase_add_test(tc, s21_determinant_normal280);
  tcase_add_test(tc, s21_determinant_normal281);
  tcase_add_test(tc, s21_determinant_normal282);
  tcase_add_test(tc, s21_determinant_normal283);
  tcase_add_test(tc, s21_determinant_normal284);
  tcase_add_test(tc, s21_determinant_normal285);
  tcase_add_test(tc, s21_determinant_normal286);
  tcase_add_test(tc, s21_determinant_normal287);
  tcase_add_test(tc, s21_determinant_normal288);
  tcase_add_test(tc, s21_determinant_normal289);
  tcase_add_test(tc, s21_determinant_normal290);
  tcase_add_test(tc, s21_determinant_normal291);
  tcase_add_test(tc, s21_determinant_normal292);
  tcase_add_test(tc, s21_determinant_normal293);
  tcase_add_test(tc, s21_determinant_normal294);
  tcase_add_test(tc, s21_determinant_normal295);
  tcase_add_test(tc, s21_determinant_normal296);
  tcase_add_test(tc, s21_determinant_normal297);
  tcase_add_test(tc, s21_determinant_normal298);
  tcase_add_test(tc, s21_determinant_normal299);
  tcase_add_test(tc, s21_determinant_normal300);
  tcase_add_test(tc, s21_determinant_normal300);
  tcase_add_test(tc, s21_determinant_normal301);
  tcase_add_test(tc, s21_determinant_normal302);
  tcase_add_test(tc, s21_determinant_normal303);
  tcase_add_test(tc, s21_determinant_normal304);
  tcase_add_test(tc, s21_determinant_normal305);
  tcase_add_test(tc, s21_determinant_normal306);
  tcase_add_test(tc, s21_determinant_normal307);
  tcase_add_test(tc, s21_determinant_normal308);
  tcase_add_test(tc, s21_determinant_normal309);
  tcase_add_test(tc, s21_determinant_normal310);
  tcase_add_test(tc, s21_determinant_normal311);
  tcase_add_test(tc, s21_determinant_normal312);
  tcase_add_test(tc, s21_determinant_normal313);
  tcase_add_test(tc, s21_determinant_normal314);
  tcase_add_test(tc, s21_determinant_normal315);
  tcase_add_test(tc, s21_determinant_normal316);
  tcase_add_test(tc, s21_determinant_normal317);
  tcase_add_test(tc, s21_determinant_normal318);
  tcase_add_test(tc, s21_determinant_normal319);
  tcase_add_test(tc, s21_determinant_normal320);
  tcase_add_test(tc, s21_determinant_normal321);
  tcase_add_test(tc, s21_determinant_normal322);
  tcase_add_test(tc, s21_determinant_normal323);
  tcase_add_test(tc, s21_determinant_normal324);
  tcase_add_test(tc, s21_determinant_normal325);
  tcase_add_test(tc, s21_determinant_normal326);
  tcase_add_test(tc, s21_determinant_normal327);
  tcase_add_test(tc, s21_determinant_normal328);
  tcase_add_test(tc, s21_determinant_normal329);
  tcase_add_test(tc, s21_determinant_normal330);
  tcase_add_test(tc, s21_determinant_normal331);
  tcase_add_test(tc, s21_determinant_normal332);
  tcase_add_test(tc, s21_determinant_normal333);
  tcase_add_test(tc, s21_determinant_normal334);
  tcase_add_test(tc, s21_determinant_normal335);
  tcase_add_test(tc, s21_determinant_normal336);
  tcase_add_test(tc, s21_determinant_normal337);
  tcase_add_test(tc, s21_determinant_normal338);
  tcase_add_test(tc, s21_determinant_normal339);
  tcase_add_test(tc, s21_determinant_normal340);
  tcase_add_test(tc, s21_determinant_normal341);
  tcase_add_test(tc, s21_determinant_normal342);
  tcase_add_test(tc, s21_determinant_normal343);
  tcase_add_test(tc, s21_determinant_normal344);
  tcase_add_test(tc, s21_determinant_normal345);
  tcase_add_test(tc, s21_determinant_normal346);
  tcase_add_test(tc, s21_determinant_normal347);
  tcase_add_test(tc, s21_determinant_normal348);
  tcase_add_test(tc, s21_determinant_normal349);
  tcase_add_test(tc, s21_determinant_normal350);
  tcase_add_test(tc, s21_determinant_normal351);
  tcase_add_test(tc, s21_determinant_normal352);
  tcase_add_test(tc, s21_determinant_normal353);
  tcase_add_test(tc, s21_determinant_normal354);
  tcase_add_test(tc, s21_determinant_normal355);
  tcase_add_test(tc, s21_determinant_normal356);
  tcase_add_test(tc, s21_determinant_normal357);
  tcase_add_test(tc, s21_determinant_normal358);
  tcase_add_test(tc, s21_determinant_normal359);
  tcase_add_test(tc, s21_determinant_normal360);
  tcase_add_test(tc, s21_determinant_normal361);
  tcase_add_test(tc, s21_determinant_normal362);
  tcase_add_test(tc, s21_determinant_normal363);
  tcase_add_test(tc, s21_determinant_normal364);
  tcase_add_test(tc, s21_determinant_normal365);
  tcase_add_test(tc, s21_determinant_normal366);
  tcase_add_test(tc, s21_determinant_normal367);
  tcase_add_test(tc, s21_determinant_normal368);
  tcase_add_test(tc, s21_determinant_normal369);
  tcase_add_test(tc, s21_determinant_normal370);
  tcase_add_test(tc, s21_determinant_normal371);
  tcase_add_test(tc, s21_determinant_normal372);
  tcase_add_test(tc, s21_determinant_normal373);
  tcase_add_test(tc, s21_determinant_normal374);
  tcase_add_test(tc, s21_determinant_normal375);
  tcase_add_test(tc, s21_determinant_normal376);
  tcase_add_test(tc, s21_determinant_normal377);
  tcase_add_test(tc, s21_determinant_normal378);
  tcase_add_test(tc, s21_determinant_normal379);
  tcase_add_test(tc, s21_determinant_normal380);
  tcase_add_test(tc, s21_determinant_normal381);
  tcase_add_test(tc, s21_determinant_normal382);
  tcase_add_test(tc, s21_determinant_normal383);
  tcase_add_test(tc, s21_determinant_normal384);
  tcase_add_test(tc, s21_determinant_normal385);
  tcase_add_test(tc, s21_determinant_normal386);
  tcase_add_test(tc, s21_determinant_normal387);
  tcase_add_test(tc, s21_determinant_normal388);
  tcase_add_test(tc, s21_determinant_normal389);
  tcase_add_test(tc, s21_determinant_normal390);
  tcase_add_test(tc, s21_determinant_normal391);
  tcase_add_test(tc, s21_determinant_normal392);
  tcase_add_test(tc, s21_determinant_normal393);
  tcase_add_test(tc, s21_determinant_normal394);
  tcase_add_test(tc, s21_determinant_normal395);
  tcase_add_test(tc, s21_determinant_normal396);
  tcase_add_test(tc, s21_determinant_normal397);
  tcase_add_test(tc, s21_determinant_normal398);
  tcase_add_test(tc, s21_determinant_normal399);
  tcase_add_test(tc, s21_determinant_normal400);
  tcase_add_test(tc, s21_determinant_normal400);
  tcase_add_test(tc, s21_determinant_normal401);
  tcase_add_test(tc, s21_determinant_normal402);
  tcase_add_test(tc, s21_determinant_normal403);
  tcase_add_test(tc, s21_determinant_normal404);
  tcase_add_test(tc, s21_determinant_normal405);
  tcase_add_test(tc, s21_determinant_normal406);
  tcase_add_test(tc, s21_determinant_normal407);
  tcase_add_test(tc, s21_determinant_normal408);
  tcase_add_test(tc, s21_determinant_normal409);
  tcase_add_test(tc, s21_determinant_normal410);
  tcase_add_test(tc, s21_determinant_normal411);
  tcase_add_test(tc, s21_determinant_normal412);
  tcase_add_test(tc, s21_determinant_normal413);
  tcase_add_test(tc, s21_determinant_normal414);
  tcase_add_test(tc, s21_determinant_normal415);
  tcase_add_test(tc, s21_determinant_normal416);
  tcase_add_test(tc, s21_determinant_normal417);
  tcase_add_test(tc, s21_determinant_normal418);
  tcase_add_test(tc, s21_determinant_normal419);
  tcase_add_test(tc, s21_determinant_normal420);
  tcase_add_test(tc, s21_determinant_normal421);
  tcase_add_test(tc, s21_determinant_normal422);
  tcase_add_test(tc, s21_determinant_normal423);
  tcase_add_test(tc, s21_determinant_normal424);
  tcase_add_test(tc, s21_determinant_normal425);
  tcase_add_test(tc, s21_determinant_normal426);
  tcase_add_test(tc, s21_determinant_normal427);
  tcase_add_test(tc, s21_determinant_normal428);
  tcase_add_test(tc, s21_determinant_normal429);
  tcase_add_test(tc, s21_determinant_normal430);
  tcase_add_test(tc, s21_determinant_normal431);
  tcase_add_test(tc, s21_determinant_normal432);
  tcase_add_test(tc, s21_determinant_normal433);
  tcase_add_test(tc, s21_determinant_normal434);
  tcase_add_test(tc, s21_determinant_normal435);
  tcase_add_test(tc, s21_determinant_normal436);
  tcase_add_test(tc, s21_determinant_normal437);
  tcase_add_test(tc, s21_determinant_normal438);
  tcase_add_test(tc, s21_determinant_normal439);
  tcase_add_test(tc, s21_determinant_normal440);
  tcase_add_test(tc, s21_determinant_normal441);
  tcase_add_test(tc, s21_determinant_normal442);
  tcase_add_test(tc, s21_determinant_normal443);
  tcase_add_test(tc, s21_determinant_normal444);
  tcase_add_test(tc, s21_determinant_normal445);
  tcase_add_test(tc, s21_determinant_normal446);
  tcase_add_test(tc, s21_determinant_normal447);
  tcase_add_test(tc, s21_determinant_normal448);
  tcase_add_test(tc, s21_determinant_normal449);
  tcase_add_test(tc, s21_determinant_normal450);
  tcase_add_test(tc, s21_determinant_normal451);
  tcase_add_test(tc, s21_determinant_normal452);
  tcase_add_test(tc, s21_determinant_normal453);
  tcase_add_test(tc, s21_determinant_normal454);
  tcase_add_test(tc, s21_determinant_normal455);
  tcase_add_test(tc, s21_determinant_normal456);
  tcase_add_test(tc, s21_determinant_normal457);
  tcase_add_test(tc, s21_determinant_normal458);
  tcase_add_test(tc, s21_determinant_normal459);
  tcase_add_test(tc, s21_determinant_normal460);
  tcase_add_test(tc, s21_determinant_normal461);
  tcase_add_test(tc, s21_determinant_normal462);
  tcase_add_test(tc, s21_determinant_normal463);
  tcase_add_test(tc, s21_determinant_normal464);
  tcase_add_test(tc, s21_determinant_normal465);
  tcase_add_test(tc, s21_determinant_normal466);
  tcase_add_test(tc, s21_determinant_normal467);
  tcase_add_test(tc, s21_determinant_normal468);
  tcase_add_test(tc, s21_determinant_normal469);
  tcase_add_test(tc, s21_determinant_normal470);
  tcase_add_test(tc, s21_determinant_normal471);
  tcase_add_test(tc, s21_determinant_normal472);
  tcase_add_test(tc, s21_determinant_normal473);
  tcase_add_test(tc, s21_determinant_normal474);
  tcase_add_test(tc, s21_determinant_normal475);
  tcase_add_test(tc, s21_determinant_normal476);
  tcase_add_test(tc, s21_determinant_normal477);
  tcase_add_test(tc, s21_determinant_normal478);
  tcase_add_test(tc, s21_determinant_normal479);
  tcase_add_test(tc, s21_determinant_normal480);
  tcase_add_test(tc, s21_determinant_normal481);
  tcase_add_test(tc, s21_determinant_normal482);
  tcase_add_test(tc, s21_determinant_normal483);
  tcase_add_test(tc, s21_determinant_normal484);
  tcase_add_test(tc, s21_determinant_normal485);
  tcase_add_test(tc, s21_determinant_normal486);
  tcase_add_test(tc, s21_determinant_normal487);
  tcase_add_test(tc, s21_determinant_normal488);
  tcase_add_test(tc, s21_determinant_normal489);
  tcase_add_test(tc, s21_determinant_normal490);
  tcase_add_test(tc, s21_determinant_normal491);
  tcase_add_test(tc, s21_determinant_normal492);
  tcase_add_test(tc, s21_determinant_normal493);
  tcase_add_test(tc, s21_determinant_normal494);
  tcase_add_test(tc, s21_determinant_normal495);
  tcase_add_test(tc, s21_determinant_normal496);
  tcase_add_test(tc, s21_determinant_normal497);
  tcase_add_test(tc, s21_determinant_normal498);
  tcase_add_test(tc, s21_determinant_normal499);
  tcase_add_test(tc, s21_determinant_normal500);
  tcase_add_test(tc, s21_determinant_normal501);
  tcase_add_test(tc, s21_determinant_normal502);
  tcase_add_test(tc, s21_determinant_normal503);
  tcase_add_test(tc, s21_determinant_normal504);
  tcase_add_test(tc, s21_determinant_normal505);
  tcase_add_test(tc, s21_determinant_normal506);
  tcase_add_test(tc, s21_determinant_normal507);
  tcase_add_test(tc, s21_determinant_normal508);
  tcase_add_test(tc, s21_determinant_normal509);
  tcase_add_test(tc, s21_determinant_normal510);
  tcase_add_test(tc, s21_determinant_normal511);
  tcase_add_test(tc, s21_determinant_normal512);
  tcase_add_test(tc, s21_determinant_normal513);
  tcase_add_test(tc, s21_determinant_04);
  tcase_add_test(tc, s21_determinant_06);
  suite_add_tcase(c, tc);
  return c;
}

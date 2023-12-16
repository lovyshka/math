#include "s21_tests.h"

START_TEST(test_1) {
  double input_value1 = 0.18774659;
  ck_assert_double_eq_tol(s21_floor(input_value1), floor(input_value1), 1e-6);
  double input_value2 = 8895945655;
  ck_assert_double_eq_tol(s21_floor(input_value2), floor(input_value2), 1e-6);
  double input_value3 = s21_PI / 3;
  ck_assert_double_eq_tol(s21_floor(input_value3), floor(input_value3), 1e-6);
  double input_value4 = 0.1875974596;
  ck_assert_double_eq_tol(s21_floor(input_value4), floor(input_value4), 1e-6);
}
END_TEST

START_TEST(test_2) {
  double input_value1 = 1;
  ck_assert_double_eq_tol(s21_floor(input_value1), floor(input_value1), 1e-6);
  double input_value2 = -1;
  ck_assert_double_eq_tol(s21_floor(input_value2), floor(input_value2), 1e-6);
}
END_TEST

START_TEST(test_3) {
  double input_value1 = INFINITY;
  ck_assert_double_infinite(s21_floor(input_value1));
  double input_value2 = s21_INF_POS;
  ck_assert_double_infinite(s21_floor(input_value2));
  double input_value3 = s21_INF_NEG;
  ck_assert_double_infinite(s21_floor(input_value3));
}
END_TEST

START_TEST(test_4) {
  double input_value1 = -0.48441757;
  ck_assert_double_eq_tol(s21_floor(input_value1), floor(input_value1), 1e-6);
  double input_value2 = -1587845956;
  ck_assert_double_eq_tol(s21_floor(input_value2), floor(input_value2), 1e-6);
  double input_value3 = -s21_PI / 4;
  ck_assert_double_eq_tol(s21_floor(input_value3), floor(input_value3), 1e-6);
  double input_value4 = -0.587494575;
  ck_assert_double_eq_tol(s21_floor(input_value4), floor(input_value4), 1e-6);
}
END_TEST

START_TEST(test_5) {
  double input_value = s21_NAN;
  ck_assert_double_nan(s21_floor(input_value));
}
END_TEST

Suite *s21_floor_tests(void) {
  Suite *suite = suite_create("s21_floor tests:");
  TCase *tcase_core = tcase_create("s21_floor");

  tcase_add_test(tcase_core, test_1);
  tcase_add_test(tcase_core, test_2);
  tcase_add_test(tcase_core, test_3);
  tcase_add_test(tcase_core, test_4);
  tcase_add_test(tcase_core, test_5);
  suite_add_tcase(suite, tcase_core);

  return suite;
}